#include "ground_transport.h"
#include <QString>

ground_transport::ground_transport(std::string tname, double tspeed, int twheels){
    name = tname;
    speed = tspeed;
    wheels = twheels;
}

nlohmann::json ground_transport::toJson(){
    nlohmann::json j = transport::toJson(); j["Wheels"] = wheels; return j;
}

std::string ground_transport::getDisplayString() {
    return transport::getDisplayString() + ", Колес: " + std::to_string(wheels);
}

void ground_transport::fromJson(const nlohmann::json& j) {
    transport::fromJson(j); wheels = j.at("Wheels").get<int>();
}

std::map<std::string, type_t> ground_transport::getFields(){
    std::map<std::string, type_t> field;
    field.insert({"Name", STRING});
    field.insert({"Speed", DOUBLE});
    field.insert({"Wheels", INT});
    return field;
}

transport* ground_transport::create(const std::map<std::string, std::string>& fields) {
    std::string localName = "";
    double localSpeed = 0.0;
    int wheels = 0.0;
    for (const auto& pair : fields) {
        QString names = QString::fromStdString(pair.first);
        QString value = QString::fromStdString(pair.second);
        if (names == "Name"){
            localName = value.toStdString();
        } else if (names == "Speed"){
            localSpeed = value.toDouble();
        } else if (names == "Wheels"){
            wheels = value.toLong();
        }
    }
    return new ground_transport(localName, localSpeed, wheels);
}

std::map<std::string, std::string> ground_transport::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Wheels", std::to_string(wheels)});
    return map;
}
