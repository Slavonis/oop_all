#ifndef IPROCESSOR_PLUGIN_HPP
#define IPROCESSOR_PLUGIN_HPP
#include <QByteArray>
#include <QString>
#include <QtPlugin>

class IProcessorPlugin {
public:
    virtual ~IProcessorPlugin() = default;
    virtual QString name() const = 0;
    virtual QByteArray process(const QByteArray& data) const = 0;
    virtual QByteArray unprocess(const QByteArray& data) const = 0;
};
Q_DECLARE_INTERFACE(IProcessorPlugin, "com.lab5.IProcessorPlugin/1.0")
#endif
