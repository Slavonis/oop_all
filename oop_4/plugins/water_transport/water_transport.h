#ifndef WATER_TRANSPORT_H
#define WATER_TRANSPORT_H
#include <QObject>
#include <QtPlugin>
#include "../../transport.h"
#include "water_transport_global.h"


class WATER_TRANSPORT_EXPORT water_transport : public QObject, public transport
{
    //Q_OBJECT
    //Q_PLUGIN_METADATA(IID "org.qt-project.transport")
    //Q_INTERFACES(transport)
protected:
    double draft;
public:
    water_transport();
    water_transport(std::string tname, double tspeed, double tdraft);

    nlohmann::json toJson() override;
    void fromJson(const nlohmann::json& j) override;
    std::string getDisplayString() override;
    std::string getTypeName() override {return "Water Transport";};
    transport* create(const std::map<std::string, std::string>& fields) override;
    std::map<std::string, type_t> getFields() override;
    std::map<std::string, std::string> getToChange() override;

};

#endif // WATER_TRANSPORT_H
