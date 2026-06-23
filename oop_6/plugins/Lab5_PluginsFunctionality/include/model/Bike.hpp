#ifndef BIKE_HPP
#define BIKE_HPP
#include "Vehicle.hpp"
class Bike final : public Vehicle { bool m_hasBasket;
public: Bike(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    bool hasBasket() const; void setHasBasket(bool v); };
#endif
