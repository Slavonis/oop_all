#ifndef AIR_TRANSPORT_H
#define AIR_TRANSPORT_H

#include "transport.h"

class air_transport : public transport {
protected:
    double maxAltitude = 1000.0;
public:
    air_transport(std::string tname = "", double tspeed = 0.0, double taltitude = 0.0);

    nlohmann::json toJson() override;

    void fromJson(const nlohmann::json& j) override;

    std::string getTypeName() override {return "Air Transport";};
    std::string getDisplayString() override;
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, type_t> getFields() override;
    std::map<std::string, std::string> getToChange() override;

};

#endif // AIR_TRANSPORT_H
