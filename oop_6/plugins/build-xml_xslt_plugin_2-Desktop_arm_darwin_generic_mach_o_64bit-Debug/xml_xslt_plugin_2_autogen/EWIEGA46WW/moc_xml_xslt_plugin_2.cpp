/****************************************************************************
** Meta object code from reading C++ file 'xml_xslt_plugin_2.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../xml_xslt_plugin_2/xml_xslt_plugin_2.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xml_xslt_plugin_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN17xml_xslt_plugin_2E_t {};
} // unnamed namespace

template <> constexpr inline auto xml_xslt_plugin_2::qt_create_metaobjectdata<qt_meta_tag_ZN17xml_xslt_plugin_2E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "xml_xslt_plugin_2"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<xml_xslt_plugin_2, qt_meta_tag_ZN17xml_xslt_plugin_2E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject xml_xslt_plugin_2::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17xml_xslt_plugin_2E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17xml_xslt_plugin_2E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17xml_xslt_plugin_2E_t>.metaTypes,
    nullptr
} };

void xml_xslt_plugin_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<xml_xslt_plugin_2 *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *xml_xslt_plugin_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xml_xslt_plugin_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17xml_xslt_plugin_2E_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "proc_interface"))
        return static_cast< proc_interface*>(this);
    if (!strcmp(_clname, "org.qt-project.oop.proc_interface"))
        return static_cast< proc_interface*>(this);
    return QObject::qt_metacast(_clname);
}

int xml_xslt_plugin_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_xml_xslt_plugin_2[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'o',  'o',  'p',  '.',  'p',  'r', 
    'o',  'c',  '_',  'i',  'n',  't',  'e',  'r', 
    'f',  'a',  'c',  'e', 
    // "className"
    0x03,  0x71,  'x',  'm',  'l',  '_',  'x',  's', 
    'l',  't',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '_',  '2', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(xml_xslt_plugin_2, xml_xslt_plugin_2, qt_pluginMetaDataV2_xml_xslt_plugin_2)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_xml_xslt_plugin_2[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'o',  'o',  'p',  '.',  'p',  'r', 
    'o',  'c',  '_',  'i',  'n',  't',  'e',  'r', 
    'f',  'a',  'c',  'e', 
    // "className"
    0x03,  0x71,  'x',  'm',  'l',  '_',  'x',  's', 
    'l',  't',  '_',  'p',  'l',  'u',  'g',  'i', 
    'n',  '_',  '2', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(xml_xslt_plugin_2, xml_xslt_plugin_2)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
