#include "air_transport.h"
#include <QString>

air_transport::air_transport(std::string tname, double tspeed, double taltitude){
    name = tname;
    speed = tspeed;
    maxAltitude = taltitude;
}

nlohmann::json air_transport::toJson(){
   nlohmann::json j = transport::toJson(); j["Max Altitude"] = maxAltitude; return j;
}

std::string air_transport::getDisplayString() {
    return transport::getDisplayString() + ", Высота: " + std::to_string(maxAltitude);
}

void air_transport::fromJson(const nlohmann::json& j) {
    transport::fromJson(j); maxAltitude = j.at("maxAltitude").get<double>();
}

std::map<std::string, type_t> air_transport::getFields(){
    std::map<std::string, type_t> field;
    field.insert({"Name", STRING});
    field.insert({"Speed", DOUBLE});
    field.insert({"Max Altitude", DOUBLE});
    return field;
}

transport* air_transport::create(const std::map<std::string, std::string>& fields) {
    std::string localName = "";
    double localSpeed = 0.0;
    double localMaxAltitude = 0.0;
    for (const auto& pair : fields) {
        QString names = QString::fromStdString(pair.first);
        QString value = QString::fromStdString(pair.second);
        if (names == "Name"){
            localName = value.toStdString();
        } else if (names == "Speed"){
            localSpeed = value.toDouble();
        } else if (names == "Max Altitude"){
            localMaxAltitude = value.toDouble();
        }
    }

    return new air_transport(localName, localSpeed, localMaxAltitude);
}

std::map<std::string, std::string> air_transport::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Max Altitude", std::to_string(maxAltitude)});
    return map;
}
