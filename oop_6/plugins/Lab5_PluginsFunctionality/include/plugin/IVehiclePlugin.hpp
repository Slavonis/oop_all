#ifndef IVEHICLE_PLUGIN_HPP
#define IVEHICLE_PLUGIN_HPP
#include "model/Vehicle.hpp"
#include <QtPlugin>
#include <memory>
class IVehiclePlugin {
public:
    virtual ~IVehiclePlugin() = default;
    virtual QString type() const = 0;
    virtual std::unique_ptr<Vehicle> create() const = 0;
};
Q_DECLARE_INTERFACE(IVehiclePlugin, "com.lab5.IVehiclePlugin/1.0")
#endif
