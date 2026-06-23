#ifndef TRUCK_HPP
#define TRUCK_HPP
#include "Vehicle.hpp"
class Truck final : public Vehicle { double m_capacity;
public: Truck(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    double capacity() const; void setCapacity(double v); };
#endif
