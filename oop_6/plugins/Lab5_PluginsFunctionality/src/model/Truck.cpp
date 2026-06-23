#include "model/Truck.hpp"
Truck::Truck() : Vehicle("Truck", 2020, 30000), m_capacity(10.0) {}
QString Truck::type() const { return "Truck"; }
void Truck::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_capacity; }
void Truck::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_capacity; }
double Truck::capacity() const { return m_capacity; } void Truck::setCapacity(double v) { m_capacity = v; }
