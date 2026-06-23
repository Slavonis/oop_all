#include "ZlibCompressPlugin.hpp"
#include <QByteArray>

QString ZlibCompressPlugin::name()  { return "Zlib Compress"; }

QByteArray ZlibCompressPlugin::process(const QByteArray& data)  {
    return qCompress(data, 6);
}

QByteArray ZlibCompressPlugin::unprocess(const QByteArray& data)  {
    return qUncompress(data);
}
