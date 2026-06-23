#ifndef BUS_HPP
#define BUS_HPP
#include "Vehicle.hpp"
class Bus final : public Vehicle { int m_seats;
public: Bus(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    int seats() const; void setSeats(int v); };
#endif
