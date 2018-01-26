/****************************************************************************
** Meta object code from reading C++ file 'UrielImageViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UrielGui/CommonDialog/UrielImageViewer/UrielImageViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UrielImageViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UrielImageViewer_t {
    QByteArrayData data[11];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UrielImageViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UrielImageViewer_t qt_meta_stringdata_UrielImageViewer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UrielImageViewer"
QT_MOC_LITERAL(1, 17, 4), // "open"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "saveAs"
QT_MOC_LITERAL(4, 30, 5), // "print"
QT_MOC_LITERAL(5, 36, 4), // "copy"
QT_MOC_LITERAL(6, 41, 5), // "paste"
QT_MOC_LITERAL(7, 47, 6), // "zoomIn"
QT_MOC_LITERAL(8, 54, 7), // "zoomOut"
QT_MOC_LITERAL(9, 62, 10), // "normalSize"
QT_MOC_LITERAL(10, 73, 11) // "fitToWindow"

    },
    "UrielImageViewer\0open\0\0saveAs\0print\0"
    "copy\0paste\0zoomIn\0zoomOut\0normalSize\0"
    "fitToWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UrielImageViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UrielImageViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UrielImageViewer *_t = static_cast<UrielImageViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->saveAs(); break;
        case 2: _t->print(); break;
        case 3: _t->copy(); break;
        case 4: _t->paste(); break;
        case 5: _t->zoomIn(); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->normalSize(); break;
        case 8: _t->fitToWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UrielImageViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UrielImageViewer.data,
      qt_meta_data_UrielImageViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UrielImageViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UrielImageViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UrielImageViewer.stringdata0))
        return static_cast<void*>(const_cast< UrielImageViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int UrielImageViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
