/****************************************************************************
** Meta object code from reading C++ file 'ZlibCompressPlugin.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../plugins/zlib_compress/ZlibCompressPlugin.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZlibCompressPlugin.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_ZlibCompressPlugin_t {
    uint offsetsAndSizes[2];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ZlibCompressPlugin_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ZlibCompressPlugin_t qt_meta_stringdata_ZlibCompressPlugin = {
    {
        QT_MOC_LITERAL(0, 18)   // "ZlibCompressPlugin"
    },
    "ZlibCompressPlugin"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ZlibCompressPlugin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject ZlibCompressPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZlibCompressPlugin.offsetsAndSizes,
    qt_meta_data_ZlibCompressPlugin,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ZlibCompressPlugin_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZlibCompressPlugin, std::true_type>
    >,
    nullptr
} };

void ZlibCompressPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *ZlibCompressPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZlibCompressPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZlibCompressPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IProcessorPlugin"))
        return static_cast< IProcessorPlugin*>(this);
    if (!strcmp(_clname, "com.lab5.IProcessorPlugin/1.0"))
        return static_cast< IProcessorPlugin*>(this);
    return QObject::qt_metacast(_clname);
}

int ZlibCompressPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_ZlibCompressPlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1d,  'c',  'o',  'm',  '.',  'l', 
    'a',  'b',  '5',  '.',  'I',  'P',  'r',  'o', 
    'c',  'e',  's',  's',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n',  '/',  '1',  '.',  '0', 
    // "className"
    0x03,  0x72,  'Z',  'l',  'i',  'b',  'C',  'o', 
    'm',  'p',  'r',  'e',  's',  's',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(ZlibCompressPlugin, ZlibCompressPlugin, qt_pluginMetaDataV2_ZlibCompressPlugin)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_ZlibCompressPlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1d,  'c',  'o',  'm',  '.',  'l', 
    'a',  'b',  '5',  '.',  'I',  'P',  'r',  'o', 
    'c',  'e',  's',  's',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n',  '/',  '1',  '.',  '0', 
    // "className"
    0x03,  0x72,  'Z',  'l',  'i',  'b',  'C',  'o', 
    'm',  'p',  'r',  'e',  's',  's',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ZlibCompressPlugin, ZlibCompressPlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
QT_END_MOC_NAMESPACE
