#include "transport.h"

transport::transport() {}

std::string transport::getDisplayString() {
    return name + " (" + getTypeName() + ") - Скорость: " + std::to_string(speed);
}

void transport::fromJson(const nlohmann::json& j) {
    name = j.at("Name").get<std::string>();
    speed = j.at("Speed").get<double>();
}

nlohmann::json transport::toJson(){
    return nlohmann::json{{"type", getTypeName()}, {"Name", name}, {"Speed", speed}};
}

std::map<std::string, type_t> transport::getFields(){
    std::map<std::string, type_t> field;
    field.insert({"Name", STRING});
    field.insert({"Speed", DOUBLE});
    return field;
}

transport* transport::create(const std::map<std::string, std::string>& fields) {
    return nullptr; // Базовая реализация
}

std::map<std::string, std::string> transport::getToChange(){}
