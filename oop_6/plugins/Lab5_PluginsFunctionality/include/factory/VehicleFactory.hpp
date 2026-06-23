#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP
#include "model/Vehicle.hpp"
#include <QString>
#include <QStringList>
#include <functional>
#include <memory>
#include <unordered_map>
class VehicleFactory {
public:
    using Creator = std::function<std::unique_ptr<Vehicle>()>;
private:
    std::unordered_map<QString, Creator> m_creators;
public:
    void registerVehicle(const QString& type, Creator creator);
    std::unique_ptr<Vehicle> create(const QString& type) const;
    QStringList types() const;
};
#endif
