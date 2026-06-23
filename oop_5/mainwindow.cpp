#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./dialog.h"
#include "air_transport.h"
#include "ground_transport.h"
#include "car.h"
#include "motor_cycle.h"
#include "airplane.h"
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QPluginLoader>
#include <QDir>
#include <QMenu>
#include <QInputDialog>
#include <QActionGroup>


classes_t* MainWindow::addClass(transport* object, classes_t *head_te) {
    classes_t* newNode = new classes_t;
    newNode->transport = object;
    newNode->next = head_te;
    head_te = newNode;
    return head_te;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    car* newCar = new car();
    head_reg = addClass(newCar, head_reg);
    air_transport* newAir = new air_transport();
    head_reg = addClass(newAir, head_reg);
    ground_transport* newGround = new ground_transport();
    head_reg = addClass(newGround, head_reg);
    motor_cycle* newMotor= new motor_cycle();
    head_reg = addClass(newMotor, head_reg);
    airplane* newAirplane= new airplane();
    head_reg = addClass(newAirplane, head_reg);
    loadPlugins();
    updateListUI();
    loadProcessingPlugins();
    buildSettingsMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListUI() {
    ui->listWidget->clear();
    for (classes_t *itr = head; itr != nullptr; itr = itr->next){
        ui->listWidget->addItem(QString::fromStdString(itr->transport->getDisplayString()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog dialog(this);
    dialog.addTypes(head_reg);
    if (dialog.exec() == QDialog::Accepted) {
        std::string selectedType = dialog.getSelectedType().toStdString();
        for (classes_t *itr = head_reg; itr != nullptr; itr = itr->next){
            std::string str = itr->transport->getTypeName();
            if (str == selectedType){
                transport* newTransport = itr->transport->create(dialog.getFields());
                head = addClass(newTransport, head);
                break;
            }
        }
    }
    updateListUI();
}


void MainWindow::on_pushButton_4_clicked()
{
    QString filter = m_activeProcessor ? "XML (*.xml)" : "JSON (*.json)";
    QString path = QFileDialog::getSaveFileName(this, "Сохранить файл", "", filter);
        if (path.isEmpty()) return;

        nlohmann::json root = nlohmann::json::array();
        for (classes_t *itr = head; itr != nullptr; itr = itr->next){
            if (itr->transport) {
                root.push_back(itr->transport->toJson());
            }
        }

        std::ofstream fileName(path.toStdString());

        if (m_activeProcessor) {

            std::string xmlData = m_activeProcessor->processBeforeSave(root);
            fileName << xmlData;
        } else {
            fileName << root.dump(4);
        }
}


void MainWindow::on_pushButton_5_clicked()
{
QString filter = m_activeProcessor ? "XML (*.xml)" : "JSON (*.json)";
    QString path = QFileDialog::getOpenFileName(this, "Открыть файл", "", filter);
    if (path.isEmpty()) return;

    std::ifstream file(path.toStdString());
    if (!file.is_open()) return;
    try {
        nlohmann::json root;
        if (m_activeProcessor) {
            std::string rawXml((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            root = m_activeProcessor->processAfterLoad(rawXml);
        } else {
            file >> root;
        }

        head = nullptr;
        for (const auto& item : root) {
            std::string type = item.at("type").get<std::string>();
            std::map<std::string, std::string> fieldsMap;
            for (auto it = item.begin(); it != item.end(); ++it) {
                if (it.key() != "type") {
                    if (it.value().is_string()) {
                        fieldsMap[it.key()] = it.value().get<std::string>();
                    } else {
                        fieldsMap[it.key()] = it.value().dump();
                    }
                }
            }
            transport* newVehicle = nullptr;
            for (classes_t *itr = head_reg; itr != nullptr; itr = itr->next) {
                if (itr->transport && itr->transport->getTypeName() == type) {
                    transport* newTransport = itr->transport->create(fieldsMap);
                    head = addClass(newTransport, head);
                    break;
                }
            }
        }

        updateListUI();
        QMessageBox::information(this, "Успех", "Данные успешно загружены!");

    } catch (const std::exception& e) {
        QString errorMsg = QString("Не удалось прочитать файл: %1").arg(e.what());
        QMessageBox::critical(this, "Ошибка", errorMsg);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->listWidget->currentRow();
    if (index < 0) return;

    classes_t* current = head;
    classes_t* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }
    if (current != nullptr) {
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        //if (current->transport) {
            //delete current->transport;
        //}
        delete current;
        updateListUI();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->listWidget->currentRow();
    if (index < 0) return;

    classes_t* current = head;
    classes_t* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }
    if (current != nullptr) {
        Dialog dialog(this);
        dialog.addTypes(head_reg);
        dialog.addObj(current->transport->getTypeName(), current->transport->getToChange());
        if (dialog.exec() == QDialog::Accepted) {

            std::string selectedType = dialog.getSelectedType().toStdString();
            for (classes_t *itr = head_reg; itr != nullptr; itr = itr->next){
                std::string str = itr->transport->getTypeName();
                if (str == selectedType){
                    transport* newTransport = itr->transport->create(dialog.getFields());
                    head = addClass(newTransport, head);
                    break;
                }
            }
            index = currentIndex + 1;
            current = head;
            previous = nullptr;
            currentIndex = 0;
            while (current != nullptr && currentIndex < index) {
                previous = current;
                current = current->next;
                currentIndex++;
            }
            if (current != nullptr) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
            }
        }
    }
    updateListUI();
}


void MainWindow::loadPlugins() {
    QDir pluginsDir(QCoreApplication::applicationDirPath() + "/plugins");

    for (const QString &fileName : pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();

        if (plugin) {
            transport *transportPlugin = qobject_cast<transport*>(plugin);
            if (transportPlugin) {
                head_reg = addClass(transportPlugin, head_reg);
            }
        }
    }
}

void MainWindow::loadProcessingPlugins() {
    QDir pluginsDir(QCoreApplication::applicationDirPath() + "/processors");
    m_processingPlugins.clear();

    for (const QString &fileName : pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            auto *processor = qobject_cast<proc_interface*>(plugin);
            if (processor) {
                m_processingPlugins.append(processor);
            }
        }
    }
    //buildSettingsMenu();
}

// Динамическое построение меню (Выбор плагина + Настройка параметров на 10 баллов)
 void MainWindow::buildSettingsMenu() {
     ui->menubar->clear();

    QMenu* selectMenu = ui->menubar->addMenu("Режим сохранения");
    QActionGroup* group = new QActionGroup(this);

    QAction* defaultAct = selectMenu->addAction("Стандартный JSON");
    defaultAct->setCheckable(true);
    group->addAction(defaultAct);
    if (!m_activeProcessor) defaultAct->setChecked(true);

    connect(defaultAct, &QAction::triggered, this, [this]() {
        m_activeProcessor = nullptr;
        buildSettingsMenu();
    });


    for (proc_interface* plugin : m_processingPlugins) {
        QAction* act = selectMenu->addAction(plugin->getPluginName());
        act->setCheckable(true);
        group->addAction(act);

        connect(act, &QAction::triggered, this, [this, plugin]() {
            m_activeProcessor = plugin;
            buildSettingsMenu();
        });

        if (m_activeProcessor == plugin) act->setChecked(true);
    }

    // РАЗДЕЛ НАСТРОЕК ПЛАГИНА (ЗАДАНИЕ НА 10 БАЛЛОВ)
    /*if (m_activeProcessor) {
        ui->menubar->addSeparator();
        QMenu* paramsMenu = ui->menubar->addMenu("Параметры плагина");

        for (const std::string& param : m_activeProcessor->getAvailableParameters()) {
            QAction* pAct = paramsMenu->addAction(QString::fromStdString("Изменить " + param));

            connect(pAct, &QAction::triggered, this, [this, param]() {
                bool ok;
                QString value = QInputDialog::getText(this, "Настройки XML",
                                                      QString::fromStdString("Введите значение для " + param + ":"),
                                                      QLineEdit::Normal, "", &ok);
                if (ok && !value.isEmpty()) {
                    m_activeProcessor->setParameter(param, value.toStdString());
                }
            });
        }
    }*/
}
