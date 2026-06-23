#include "ui/MainWindow.hpp"
#include "model/Bus.hpp"
#include "model/Bike.hpp"
#include "model/Car.hpp"
#include "model/ElectricScooter.hpp"
#include "model/Motorcycle.hpp"
#include "model/Truck.hpp"
#include "plugin/IVehiclePlugin.hpp"
#include "plugin/IProcessorPlugin.hpp"
#include "ui/EditVehicleDialog.hpp"

#include <QActionGroup>
#include <QBuffer>
#include <QComboBox>
#include <QCoreApplication>
#include <QDataStream>
#include <QDir>
#include <QDoubleSpinBox>
#include <QFile>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPluginLoader>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    resize(900, 650);
    setupFactory();

    // Settings menu
    auto* settingsMenu  = menuBar()->addMenu("Settings");
    m_processorMenu     = settingsMenu->addMenu("Archiving");
    m_processorGroup    = new QActionGroup(this);
    m_processorGroup->setExclusive(true);

    auto* noneAction = new QAction("None", this);
    noneAction->setCheckable(true);
    noneAction->setChecked(true);
    m_processorGroup->addAction(noneAction);
    m_processorMenu->addAction(noneAction);
    connect(noneAction, &QAction::triggered, this, [this]{ m_activeProcessor = nullptr; });

    m_processorMenu->addSeparator();

    settingsMenu->addSeparator();
    auto* loadPluginAction = settingsMenu->addAction("Load Plugin...");
    connect(loadPluginAction, &QAction::triggered, this, [this]{
        QString path = QFileDialog::getOpenFileName(
            this, "Load Plugin", "",
            "Shared Libraries (*.so *.dll *.dylib)");
        if (!path.isEmpty()) loadPluginFile(path);
    });

    // Central widget
    auto* central = new QWidget(this);
    setCentralWidget(central);
    auto* root    = new QVBoxLayout(central);
    auto* input   = new QHBoxLayout();
    auto* buttons = new QHBoxLayout();

    m_typeCombo = new QComboBox();
    m_typeCombo->addItems(m_factory.types());
    m_brandEdit = new QLineEdit(); m_brandEdit->setPlaceholderText("Brand");
    m_yearSpin  = new QSpinBox(); m_yearSpin->setRange(1900,2100); m_yearSpin->setValue(2024);
    m_priceSpin = new QDoubleSpinBox(); m_priceSpin->setRange(0,1e8); m_priceSpin->setValue(1000);

    input->addWidget(m_typeCombo); input->addWidget(m_brandEdit);
    input->addWidget(m_yearSpin);  input->addWidget(m_priceSpin);

    m_addButton    = new QPushButton("Add");
    m_editButton   = new QPushButton("Edit");
    m_removeButton = new QPushButton("Remove");
    m_saveButton   = new QPushButton("Save");
    m_loadButton   = new QPushButton("Load");

    buttons->addWidget(m_addButton);  buttons->addWidget(m_editButton);
    buttons->addWidget(m_removeButton); buttons->addStretch();
    buttons->addWidget(m_saveButton); buttons->addWidget(m_loadButton);

    m_listWidget = new QListWidget();
    root->addLayout(input); root->addLayout(buttons); root->addWidget(m_listWidget);

    connect(m_addButton,    &QPushButton::clicked, this, [this]{ addVehicle();    });
    connect(m_editButton,   &QPushButton::clicked, this, [this]{ editVehicle();   });
    connect(m_removeButton, &QPushButton::clicked, this, [this]{ removeVehicle(); });
    connect(m_saveButton,   &QPushButton::clicked, this, [this]{ saveVehicles();  });
    connect(m_loadButton,   &QPushButton::clicked, this, [this]{ loadVehicles();  });

    loadPlugins();
    setWindowTitle("Lab 5 - Plugin Functionality (Archiving)");
}

void MainWindow::setupFactory() {
    m_factory.registerVehicle("Car",             []{ return std::make_unique<Car>();             });
    m_factory.registerVehicle("Bike",            []{ return std::make_unique<Bike>();            });
    m_factory.registerVehicle("Truck",           []{ return std::make_unique<Truck>();           });
    m_factory.registerVehicle("Bus",             []{ return std::make_unique<Bus>();             });
    m_factory.registerVehicle("Motorcycle",      []{ return std::make_unique<Motorcycle>();      });
    m_factory.registerVehicle("ElectricScooter", []{ return std::make_unique<ElectricScooter>(); });
}

void MainWindow::loadPlugins() {
    QDir dir(QCoreApplication::applicationDirPath() + "/plugins");
    if (!dir.exists()) return;
    for (const QString& f : dir.entryList(QDir::Files))
        loadPluginFile(dir.absoluteFilePath(f));
}

void MainWindow::loadPluginFile(const QString& path) {
    auto* loader = new QPluginLoader(path, this);
    QObject* obj = loader->instance();
    if (!obj) { delete loader; return; }

    bool used = false;
    if (auto* vp = qobject_cast<IVehiclePlugin*>(obj)) {
        m_factory.registerVehicle(vp->type(), [vp]{ return vp->create(); });
        m_typeCombo->addItem(vp->type());
        used = true;
    }
    if (auto* pp = qobject_cast<IProcessorPlugin*>(obj)) {
        addProcessorAction(pp);
        used = true;
    }
    if (!used) { loader->unload(); delete loader; }
}

void MainWindow::addProcessorAction(IProcessorPlugin* plugin) {
    m_processors.push_back(plugin);

    auto* action = new QAction(plugin->name(), this);
    action->setCheckable(true);
    m_processorGroup->addAction(action);
    m_processorMenu->addAction(action);
    connect(action, &QAction::triggered, this, [this, plugin]{ m_activeProcessor = plugin; });
}

void MainWindow::refreshList() {
    m_listWidget->clear();
    for (const auto& v : m_vehicles)
        m_listWidget->addItem(v->type() + " | " + v->brand() +
            " | " + QString::number(v->year()) +
            " | $" + QString::number(v->price()));
}

void MainWindow::addVehicle() {
    auto v = m_factory.create(m_typeCombo->currentText());
    v->setBrand(m_brandEdit->text()); v->setYear(m_yearSpin->value()); v->setPrice(m_priceSpin->value());
    m_vehicles.push_back(std::move(v)); refreshList();
}

void MainWindow::editVehicle() {
    int row = m_listWidget->currentRow(); if (row < 0) return;
    EditVehicleDialog dlg(m_vehicles[row].get(), this);
    if (dlg.exec()) refreshList();
}

void MainWindow::removeVehicle() {
    int row = m_listWidget->currentRow(); if (row < 0) return;
    m_vehicles.erase(m_vehicles.begin() + row); refreshList();
}

void MainWindow::saveVehicles() {
    QString path = QFileDialog::getSaveFileName(this, "Save", "", "*.bin");
    if (path.isEmpty()) return;

    QByteArray raw;
    {
        QBuffer buf(&raw); buf.open(QIODevice::WriteOnly);
        QDataStream s(&buf);
        s << static_cast<int>(m_vehicles.size());
        for (const auto& v : m_vehicles) v->serialize(s);
    }

    QByteArray data   = m_activeProcessor ? m_activeProcessor->process(raw) : raw;
    QString procName  = m_activeProcessor ? m_activeProcessor->name() : QString("none");

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) return;
    QDataStream fs(&file);
    fs << procName << data;
}

void MainWindow::loadVehicles() {
    QString path = QFileDialog::getOpenFileName(this, "Load", "", "*.bin");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return;
    QDataStream fs(&file);

    QString procName; QByteArray data;
    fs >> procName >> data;

    if (procName != "none") {
        IProcessorPlugin* pp = nullptr;
        for (auto* p : m_processors)
            if (p->name() == procName) { pp = p; break; }
        if (!pp) {
            QMessageBox::warning(this, "Error",
                "Plugin \"" + procName + "\" not loaded. Cannot decompress.");
            return;
        }
        data = pp->unprocess(data);
    }

    QBuffer buf(&data); buf.open(QIODevice::ReadOnly);
    QDataStream s(&buf);
    int count = 0; s >> count;
    m_vehicles.clear();
    for (int i = 0; i < count; ++i) {
        QString type; s >> type;
        auto v = m_factory.create(type);
        v->deserialize(s);
        m_vehicles.push_back(std::move(v));
    }
    refreshList();
}
