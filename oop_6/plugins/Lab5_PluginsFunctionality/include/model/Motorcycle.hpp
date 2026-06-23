#ifndef MOTORCYCLE_HPP
#define MOTORCYCLE_HPP
#include "Vehicle.hpp"
class Motorcycle final : public Vehicle { int m_engineVolume;
public: Motorcycle(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    int engineVolume() const; void setEngineVolume(int v); };
#endif
