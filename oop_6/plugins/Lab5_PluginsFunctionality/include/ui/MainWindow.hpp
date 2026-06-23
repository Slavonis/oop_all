#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP
#include "factory/VehicleFactory.hpp"
#include <QMainWindow>
#include <memory>
#include <vector>

class QListWidget; class QComboBox; class QLineEdit;
class QSpinBox; class QDoubleSpinBox; class QPushButton;
class QActionGroup; class QMenu; class IProcessorPlugin;

class MainWindow final : public QMainWindow {
private:
    VehicleFactory m_factory;
    std::vector<std::unique_ptr<Vehicle>> m_vehicles;
    std::vector<IProcessorPlugin*>        m_processors;
    IProcessorPlugin*                     m_activeProcessor = nullptr;

    QListWidget*    m_listWidget;
    QComboBox*      m_typeCombo;
    QLineEdit*      m_brandEdit;
    QSpinBox*       m_yearSpin;
    QDoubleSpinBox* m_priceSpin;
    QPushButton*    m_addButton, *m_editButton, *m_removeButton;
    QPushButton*    m_saveButton, *m_loadButton;
    QMenu*          m_processorMenu;
    QActionGroup*   m_processorGroup;

    void setupFactory();
    void loadPlugins();
    void loadPluginFile(const QString& path);
    void addProcessorAction(IProcessorPlugin* plugin);
    void refreshList();
    void addVehicle(); void editVehicle(); void removeVehicle();
    void saveVehicles(); void loadVehicles();

public:
    explicit MainWindow(QWidget* parent = nullptr);
};
#endif
