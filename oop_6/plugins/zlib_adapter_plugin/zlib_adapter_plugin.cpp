#include "zlib_adapter_plugin.h"

#include <QByteArray>

/*
 * Constructor initializes the companion plugin.
 * In a real lab, you can create it via 'new' if headers are included,
 * or load dynamically via QPluginLoader if it is compiled as a shared library.
 */
zlib_adapter_plugin::zlib_adapter_plugin() {
    m_friendPlugin = new ZlibCompressPlugin();
}

zlib_adapter_plugin::~zlib_adapter_plugin() {
    delete m_friendPlugin;
}

QString zlib_adapter_plugin::getPluginName() const {
    if (m_friendPlugin) {
        return m_friendPlugin->name() + " (Adapted)";
    }
    return "Zlib Compressor [Disconnected]";
}

/*
 * Adapts JSON object to compressed raw string before saving.
 */
std::string zlib_adapter_plugin::processBeforeSave(const nlohmann::json& jsonData) {
    if (!m_friendPlugin) return jsonData.dump();
    std::string jsonStr = jsonData.dump(4);
    QByteArray rawData = QByteArray::fromStdString(jsonStr);
    QByteArray compressedData = m_friendPlugin->process(rawData);
    return compressedData.toStdString();
}

/*
 * Adapts compressed string from file back into nlohmann::json object.
 */
nlohmann::json zlib_adapter_plugin::processAfterLoad(const std::string& xmlStr) {
    if (!m_friendPlugin) return nlohmann::json::parse(xmlStr);
    QByteArray compressedData = QByteArray::fromStdString(xmlStr);
    QByteArray decompressedData = m_friendPlugin->unprocess(compressedData);
    std::string jsonStr = decompressedData.toStdString();
    return nlohmann::json::parse(jsonStr);
}
