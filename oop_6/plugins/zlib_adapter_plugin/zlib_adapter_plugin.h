#ifndef ZLIB_ADAPTER_PLUGIN_H
#define ZLIB_ADAPTER_PLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <string>

#include "../../proc_interface.h"
#include "../Lab5_PluginsFunctionality/plugins/zlib_compress/ZlibCompressPlugin.hpp"
#include "zlib_adapter_plugin_global.h"

class ZLIB_ADAPTER_PLUGIN_EXPORT zlib_adapter_plugin : public QObject, public proc_interface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID p_iid)
    Q_INTERFACES(proc_interface)

public:
    zlib_adapter_plugin();
    ~zlib_adapter_plugin();
    QString getPluginName() const override;
    std::string processBeforeSave(const nlohmann::json& jsonData) override;
    nlohmann::json processAfterLoad(const std::string& xmlStr) override;

private:
    ZlibCompressPlugin* m_friendPlugin;
};

#endif // ZLIB_ADAPTER_PLUGIN_H
