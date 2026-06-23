#include "model/Motorcycle.hpp"
Motorcycle::Motorcycle() : Vehicle("Motorcycle", 2020, 12000), m_engineVolume(600) {}
QString Motorcycle::type() const { return "Motorcycle"; }
void Motorcycle::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_engineVolume; }
void Motorcycle::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_engineVolume; }
int Motorcycle::engineVolume() const { return m_engineVolume; }
void Motorcycle::setEngineVolume(int v) { m_engineVolume = v; }
