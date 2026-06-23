#include "airplane.h"
#include <QString>

airplane::airplane(std::string tname, double tspeed, double taltitude) {
    name = tname;
    speed = tspeed;
    maxAltitude = taltitude;
}

transport* airplane::create(const std::map<std::string, std::string>& fields) {
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

    return new airplane(localName, localSpeed, localMaxAltitude);
}

std::map<std::string, std::string> airplane::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Max Altitude", std::to_string(maxAltitude)});
    return map;
}
