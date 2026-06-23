#ifndef CAR_H
#define CAR_H
#include "ground_transport.h"

class car : public ground_transport
{
public:

    car(std::string tname = "", double tspeed = 0.0, int twheels = 0);
    std::string getTypeName() override {return "Car";};
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, std::string> getToChange() override;

};

#endif // CAR_H
