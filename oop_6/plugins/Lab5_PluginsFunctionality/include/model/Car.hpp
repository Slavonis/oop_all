#ifndef CAR_HPP
#define CAR_HPP
#include "Vehicle.hpp"
class Car final : public Vehicle { int m_doors;
public: Car(); QString type() const override;
    void serialize(QDataStream& s) const override; void deserialize(QDataStream& s) override;
    int doors() const; void setDoors(int d); };
#endif
