#ifndef VAN_HPP
#define VAN_HPP
#include "model/Vehicle.hpp"
class Van : public Vehicle { double m_payload;
public: Van(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    double payload() const; void setPayload(double v); };
#endif
