#include "water_transport.h"

#include <QString>

water_transport::water_transport() {

}

water_transport::water_transport(std::string tname, double tspeed, double tdraft){
    name = tname;
    speed = tspeed;
    draft = tdraft;
}

nlohmann::json water_transport::toJson(){
    nlohmann::json j =  transport::toJson(); j["Draft"] = draft; return j;
}

std::string water_transport::getDisplayString() {
    return transport::getDisplayString() + ", Осадка: " + std::to_string(draft);
}

void water_transport::fromJson(const nlohmann::json& j) {
    transport::fromJson(j);
    draft = j.at("Draft").get<double>();
}

std::map<std::string, type_t> water_transport::getFields(){
    std::map<std::string, type_t> field;
    field.insert({"Name", STRING});
    field.insert({"Speed", DOUBLE});
    field.insert({"Draft", DOUBLE});
    return field;
}

transport* water_transport::create(const std::map<std::string, std::string>& fields) {
    std::string localName = "";
    double localSpeed = 0.0;
    double localDraft = 0.0;
    for (const auto& pair : fields) {
        QString names = QString::fromStdString(pair.first);
        QString value = QString::fromStdString(pair.second);
        if (names == "Name"){
            localName = value.toStdString();
        } else if (names == "Speed"){
            localSpeed = value.toDouble();
        } else if (names == "Draft"){
            localDraft = value.toDouble();
        }
    }
    return new water_transport(localName, localSpeed, localDraft);
}

std::map<std::string, std::string> water_transport::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Draft", std::to_string(draft)});
    return map;
}
