#include "xml_xslt_plugin.h"

#include <QDomDocument>
#include <QJsonDocument>
#include <sstream>

xml_xslt_plugin::xml_xslt_plugin() : m_rootTagName("transport_list") {}


std::string xml_xslt_plugin::processBeforeSave(const nlohmann::json& jsonData) {
    std::stringstream xml;
    xml << "<" << m_rootTagName << ">\n";
    for (const auto& item : jsonData) {
        xml << "  <item>\n";
        for (auto it = item.begin(); it != item.end(); ++it) {
            xml << "    <" << it.key() << ">";
            if (it.value().is_string()) {
                xml << it.value().get<std::string>();
            } else {
                xml << it.value().dump();
            }
            xml << "</" << it.key() << ">\n";
        }
        xml << "  </item>\n";
    }
    xml << "</" << m_rootTagName << ">\n";

    return xml.str();
}


nlohmann::json xml_xslt_plugin::processAfterLoad(const std::string& xmlStr) {
    nlohmann::json rootJson = nlohmann::json::array();

    std::string itemToken = "<item>";
    size_t pos = 0;

    while ((pos = xmlStr.find(itemToken, pos)) != std::string::npos) {
        size_t endPos = xmlStr.find("</item>", pos);
        if (endPos == std::string::npos) break;

        std::string itemContent = xmlStr.substr(pos + itemToken.length(), endPos - pos - itemToken.length());
        nlohmann::json itemJson = nlohmann::json::object();

        size_t tagPos = 0;
        while ((tagPos = itemContent.find("<", tagPos)) != std::string::npos) {
            size_t closeTag = itemContent.find(">", tagPos);
            if (closeTag == std::string::npos) break;

            std::string tagName = itemContent.substr(tagPos + 1, closeTag - tagPos - 1);
            if (tagName == "/item" || tagName == "/") {
                tagPos = closeTag;
                continue;
            }

            std::string endTag = "</" + tagName + ">";
            size_t endTagPos = itemContent.find(endTag, closeTag);
            if (endTagPos == std::string::npos) break;

            std::string value = itemContent.substr(closeTag + 1, endTagPos - closeTag - 1);

            if (!value.empty() && value[0] == '"') {
                value = value.substr(1, value.length() - 2);
                itemJson[tagName] = value;
            } else {
                try {
                    if (value.find('.') != std::string::npos) {
                        itemJson[tagName] = std::stod(value);
                    } else {
                        itemJson[tagName] = std::stoi(value);
                    }
                } catch (...) {
                    itemJson[tagName] = value;
                }
            }
            tagPos = endTagPos + endTag.length();
        }
        rootJson.push_back(itemJson);
        pos = endPos + 7;
    }

    return rootJson;
}
