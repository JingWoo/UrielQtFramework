/****************************************************************************
** Meta object code from reading C++ file 'ResearchProject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UrielGui/ResourcePage/ResearchProject/ResearchProject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ResearchProject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResearchProject_t {
    QByteArrayData data[5];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResearchProject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResearchProject_t qt_meta_stringdata_ResearchProject = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ResearchProject"
QT_MOC_LITERAL(1, 16, 16), // "onConfirmClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "onDataFileBrowerClicked"
QT_MOC_LITERAL(4, 58, 24) // "onPaperFileBrowerClicked"

    },
    "ResearchProject\0onConfirmClicked\0\0"
    "onDataFileBrowerClicked\0"
    "onPaperFileBrowerClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResearchProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResearchProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResearchProject *_t = static_cast<ResearchProject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onConfirmClicked(); break;
        case 1: _t->onDataFileBrowerClicked(); break;
        case 2: _t->onPaperFileBrowerClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ResearchProject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ResearchProject.data,
      qt_meta_data_ResearchProject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResearchProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResearchProject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResearchProject.stringdata0))
        return static_cast<void*>(const_cast< ResearchProject*>(this));
    return QDialog::qt_metacast(_clname);
}

int ResearchProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
