#include "factory/VehicleFactory.hpp"
void VehicleFactory::registerVehicle(const QString& type, Creator creator) {
    m_creators[type] = creator;
}
std::unique_ptr<Vehicle> VehicleFactory::create(const QString& type) const {
    return m_creators.at(type)();
}
QStringList VehicleFactory::types() const {
    QStringList r;
    for (const auto& [t, _] : m_creators) r.push_back(t);
    r.sort(); return r;
}
