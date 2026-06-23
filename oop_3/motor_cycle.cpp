#include "motor_cycle.h"

motor_cycle::motor_cycle(std::string tname, double tspeed, int twheels) {
    name = tname;
    speed = tspeed;
    wheels = twheels;
}

transport* motor_cycle::create(const std::map<std::string, std::string>& fields) {
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
    return new motor_cycle(localName, localSpeed, wheels);
}


std::map<std::string, std::string> motor_cycle::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Wheels", std::to_string(wheels)});
    return map;
}
