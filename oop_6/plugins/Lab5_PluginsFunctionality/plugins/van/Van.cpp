#include "Van.hpp"
Van::Van() : Vehicle("Van", 2022, 18000), m_payload(1.5) {}
QString Van::type() const { return "Van"; }
void Van::serialize(QDataStream& s) const { s << type() << m_brand << m_year << m_price << m_payload; }
void Van::deserialize(QDataStream& s) { s >> m_brand >> m_year >> m_price >> m_payload; }
double Van::payload() const { return m_payload; } void Van::setPayload(double v) { m_payload = v; }
