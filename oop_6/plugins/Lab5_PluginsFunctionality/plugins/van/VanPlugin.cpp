#include "VanPlugin.hpp"
#include "Van.hpp"
QString VanPlugin::type() const { return "Van"; }
std::unique_ptr<Vehicle> VanPlugin::create() const { return std::make_unique<Van>(); }
