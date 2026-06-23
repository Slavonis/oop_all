#ifndef ELECTRIC_SCOOTER_HPP
#define ELECTRIC_SCOOTER_HPP
#include "Vehicle.hpp"
class ElectricScooter final : public Vehicle { int m_battery;
public: ElectricScooter(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    int battery() const; void setBattery(int v); };
#endif
