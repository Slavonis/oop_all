#ifndef XML_XSLT_PLUGIN_H
#define XML_XSLT_PLUGIN_H
#include <QObject>
#include "../../proc_interface.h"
#include "xml_xslt_plugin_global.h"
#include <nlohmann/json.hpp>

class XML_XSLT_PLUGIN_EXPORT xml_xslt_plugin : public QObject, public proc_interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID p_iid)
    Q_INTERFACES(proc_interface)

public:
    xml_xslt_plugin();

    QString getPluginName() const override { return "XML XSLT Transformer"; }

    std::string processBeforeSave(const nlohmann::json& jsonData) override;
    nlohmann::json processAfterLoad(const std::string& xmlStr) override;
private:
    std::string m_rootTagName;
    QString m_xsltTemplateMode;
};
#endif // XML_XSLT_PLUGIN_H
