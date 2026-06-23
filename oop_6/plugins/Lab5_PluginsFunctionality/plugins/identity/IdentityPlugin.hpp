#ifndef IDENTITY_PLUGIN_HPP
#define IDENTITY_PLUGIN_HPP
#include "plugin/IProcessorPlugin.hpp"
#include <QObject>
class IdentityPlugin : public QObject, public IProcessorPlugin {
    Q_OBJECT Q_INTERFACES(IProcessorPlugin)
    Q_PLUGIN_METADATA(IID "com.lab5.IProcessorPlugin/1.0")
public:
    QString    name()                             const override;
    QByteArray process(const QByteArray& data)   const override;
    QByteArray unprocess(const QByteArray& data) const override;
};
#endif
