#ifndef ZLIB_COMPRESS_PLUGIN_HPP
#define ZLIB_COMPRESS_PLUGIN_HPP
//#include "../../include/plugin/IProcessorPlugin.hpp"
#include <QString>

class ZlibCompressPlugin {
    //Q_OBJECT Q_INTERFACES(IProcessorPlugin)
    //Q_PLUGIN_METADATA(IID "com.lab5.IProcessorPlugin/1.0")
public:
    QString    name()                            ;
    QByteArray process(const QByteArray& data)   ;
    QByteArray unprocess(const QByteArray& data) ;
};
#endif
