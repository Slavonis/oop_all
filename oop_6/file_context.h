#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

#include "proc_interface.h"
#include <string>
#include <nlohmann/json.hpp>

class file_context
{
private:
    proc_interface* m_strategy;

public:
    file_context() : m_strategy(nullptr) {}

    void setStrategy(proc_interface* strategy) {
        m_strategy = strategy;
    }
    std::string getFileFilter() const {
        return m_strategy ? "XML (*.xml)" : "JSON (*.json)";
    }
    bool hasActiveStrategy() const {
        return m_strategy != nullptr;
    }

    QString getStrategyName() const {
        return m_strategy ? m_strategy->getPluginName() : "";
    }

    std::string executeSave(const nlohmann::json& jsonData) {
        if (m_strategy) {
            return m_strategy->processBeforeSave(jsonData);
        }
        return jsonData.dump(4);
    }

    nlohmann::json executeLoad(const std::string& rawData) {
        if (m_strategy) {
            return m_strategy->processAfterLoad(rawData);
        }
        return nlohmann::json::parse(rawData);
    }
};

#endif // FILE_CONTEXT_H
