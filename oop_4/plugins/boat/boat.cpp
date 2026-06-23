#include "boat.h"
#include <QString>

boat::boat(std::string tname, double tspeed, double tdraft) {
    name = tname;
    speed = tspeed;
    draft = tdraft;
}

transport* boat::create(const std::map<std::string, std::string>& fields) {
    std::string localName = "";
    double localSpeed = 0.0;
    double localdraft = 0.0;
    for (const auto& pair : fields) {
        QString names = QString::fromStdString(pair.first);
        QString value = QString::fromStdString(pair.second);
        if (names == "Name"){
            localName = value.toStdString();
        } else if (names == "Speed"){
            localSpeed = value.toDouble();
        } else if (names == "Draft"){
            localdraft = value.toDouble();
        }
    }
    return new boat(localName, localSpeed, localdraft);
}

std::map<std::string, std::string> boat::getToChange() {
    std::map<std::string, std::string> map;
    map.insert({"Name", name});
    map.insert({"Speed", std::to_string(speed)});
    map.insert({"Draft", std::to_string(draft)});
    return map;
}
