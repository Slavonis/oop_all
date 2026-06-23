#ifndef BOAT_H
#define BOAT_H
#include <QObject>
#include <QtPlugin>
#include "../../transport.h"
#include "boat_global.h"
#include "../water_transport/water_transport.h"

class BOAT_EXPORT boat : public water_transport
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.transport")
    Q_INTERFACES(transport)
public:
    boat(std::string tname = "", double tspeed = 0.0, double tdraft = 0.0);
    std::string getTypeName() override {return "Boat";};
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, std::string> getToChange() override;

};


#endif // BOAT_H
