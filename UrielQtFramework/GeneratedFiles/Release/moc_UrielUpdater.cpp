/****************************************************************************
** Meta object code from reading C++ file 'UrielUpdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThirdPartyLibraries/QSimpleUpdater/UrielUpdater/UrielUpdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UrielUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UrielUpdater_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UrielUpdater_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UrielUpdater_t qt_meta_stringdata_UrielUpdater = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UrielUpdater"
QT_MOC_LITERAL(1, 13, 11), // "resetFields"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "checkForUpdates"
QT_MOC_LITERAL(4, 42, 15), // "updateChangelog"
QT_MOC_LITERAL(5, 58, 3), // "url"
QT_MOC_LITERAL(6, 62, 14), // "displayAppcast"
QT_MOC_LITERAL(7, 77, 5) // "reply"

    },
    "UrielUpdater\0resetFields\0\0checkForUpdates\0"
    "updateChangelog\0url\0displayAppcast\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UrielUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    2,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    5,    7,

       0        // eod
};

void UrielUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UrielUpdater *_t = static_cast<UrielUpdater *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetFields(); break;
        case 1: _t->checkForUpdates(); break;
        case 2: _t->updateChangelog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->displayAppcast((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject UrielUpdater::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UrielUpdater.data,
      qt_meta_data_UrielUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UrielUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UrielUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UrielUpdater.stringdata0))
        return static_cast<void*>(const_cast< UrielUpdater*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UrielUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
