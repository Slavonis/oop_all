#include "IdentityPlugin.hpp"

QString IdentityPlugin::name() const { return "No Compression"; }

QByteArray IdentityPlugin::process(const QByteArray& data)   const { return data; }
QByteArray IdentityPlugin::unprocess(const QByteArray& data) const { return data; }
