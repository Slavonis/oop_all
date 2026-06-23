#include "model/ElectricScooter.hpp"
ElectricScooter::ElectricScooter() : Vehicle("Scooter", 2020, 900), m_battery(40) {}
QString ElectricScooter::type() const { return "ElectricScooter"; }
void ElectricScooter::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_battery; }
void ElectricScooter::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_battery; }
int ElectricScooter::battery() const { return m_battery; }
void ElectricScooter::setBattery(int v) { m_battery = v; }
