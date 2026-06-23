#include "model/Bus.hpp"
Bus::Bus() : Vehicle("Bus", 2020, 25000), m_seats(40) {}
QString Bus::type() const { return "Bus"; }
void Bus::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_seats; }
void Bus::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_seats; }
int Bus::seats() const { return m_seats; } void Bus::setSeats(int v) { m_seats = v; }
