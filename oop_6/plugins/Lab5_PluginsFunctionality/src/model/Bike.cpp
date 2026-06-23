#include "model/Bike.hpp"
Bike::Bike() : Vehicle("Bike", 2020, 500), m_hasBasket(false) {}
QString Bike::type() const { return "Bike"; }
void Bike::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_hasBasket; }
void Bike::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_hasBasket; }
bool Bike::hasBasket() const { return m_hasBasket; } void Bike::setHasBasket(bool v) { m_hasBasket = v; }
