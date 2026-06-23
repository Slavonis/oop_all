#ifndef VAN_PLUGIN_HPP
#define VAN_PLUGIN_HPP
#include "plugin/IVehiclePlugin.hpp"
#include <QObject>
class VanPlugin : public QObject, public IVehiclePlugin {
    Q_OBJECT Q_INTERFACES(IVehiclePlugin)
    Q_PLUGIN_METADATA(IID "com.lab5.IVehiclePlugin/1.0")
public:
    QString type() const override;
    std::unique_ptr<Vehicle> create() const override;
};
#endif
