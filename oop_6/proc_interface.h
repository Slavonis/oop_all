#ifndef PROC_INTERFACE_H
#define PROC_INTERFACE_H
#include <QString>
#include <QJsonObject>
#include <QtPlugin>
#include <nlohmann/json.hpp>

class proc_interface
{
public:
    proc_interface();
    virtual ~proc_interface() = default;

    virtual QString getPluginName() const = 0;

    virtual std::string processBeforeSave(const nlohmann::json& jsonData) = 0;

    virtual nlohmann::json processAfterLoad(const std::string& xmlStr) = 0;
};

#define p_iid "org.qt-project.oop.proc_interface"
Q_DECLARE_INTERFACE(proc_interface, p_iid)

#endif // PROC_INTERFACE_H
