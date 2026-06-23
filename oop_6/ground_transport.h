#ifndef GROUND_TRANSPORT_H
#define GROUND_TRANSPORT_H
#include "transport.h"

class ground_transport : public transport {
protected:
    int wheels = 4;
public:
    ground_transport(std::string tname = "", double tspeed = 0.0, int twheels = 0);

    nlohmann::json toJson() override;

    void fromJson(const nlohmann::json& j) override;

    std::string getDisplayString() override;
    std::string getTypeName() override {return "Ground Transport";};
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, type_t> getFields() override;
    std::map<std::string, std::string> getToChange() override;

};

#endif // GROUND_TRANSPORT_H
