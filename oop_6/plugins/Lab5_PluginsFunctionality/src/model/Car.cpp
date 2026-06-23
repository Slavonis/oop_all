#include "model/Car.hpp"
Car::Car() : Vehicle("Car", 2020, 10000), m_doors(4) {}
QString Car::type() const { return "Car"; }
void Car::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_doors; }
void Car::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_doors; }
int Car::doors() const { return m_doors; } void Car::setDoors(int d) { m_doors = d; }
