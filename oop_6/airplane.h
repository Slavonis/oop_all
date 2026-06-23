#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "air_transport.h"

class airplane : public air_transport
{
public:
    airplane(std::string tname = "", double tspeed = 0.0, double taltitude = 0.0);
    std::string getTypeName()  override { return "Airplane"; };
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, std::string> getToChange() override;
};


#endif // AIRPLANE_H
