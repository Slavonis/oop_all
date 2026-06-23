#ifndef MOTOR_CYCLE_H
#define MOTOR_CYCLE_H
#include "ground_transport.h"

class motor_cycle : public ground_transport
{
public:
    motor_cycle(std::string tname = "", double tspeed = 0.0, int twheels = 0);
    std::string getTypeName() override {return "Motorcycle";};
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, std::string> getToChange() override;
};

#endif // MOTOR_CYCLE_H
