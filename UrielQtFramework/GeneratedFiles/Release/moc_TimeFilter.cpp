/****************************************************************************
** Meta object code from reading C++ file 'TimeFilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UrielGui/HomePage/TimeFilter/TimeFilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeFilter_t {
    QByteArrayData data[10];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeFilter_t qt_meta_stringdata_TimeFilter = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TimeFilter"
QT_MOC_LITERAL(1, 11, 16), // "timeFilterSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "TimeFilterEnum"
QT_MOC_LITERAL(4, 44, 1), // "v"
QT_MOC_LITERAL(5, 46, 19), // "onNearlyADayClicked"
QT_MOC_LITERAL(6, 66, 20), // "onNearlyAWeekClicked"
QT_MOC_LITERAL(7, 87, 21), // "onNearlyAMonthClicked"
QT_MOC_LITERAL(8, 109, 20), // "onNearlyAYearClicked"
QT_MOC_LITERAL(9, 130, 12) // "onAllClicked"

    },
    "TimeFilter\0timeFilterSignal\0\0"
    "TimeFilterEnum\0v\0onNearlyADayClicked\0"
    "onNearlyAWeekClicked\0onNearlyAMonthClicked\0"
    "onNearlyAYearClicked\0onAllClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimeFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeFilter *_t = static_cast<TimeFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeFilterSignal((*reinterpret_cast< const TimeFilterEnum(*)>(_a[1]))); break;
        case 1: _t->onNearlyADayClicked(); break;
        case 2: _t->onNearlyAWeekClicked(); break;
        case 3: _t->onNearlyAMonthClicked(); break;
        case 4: _t->onNearlyAYearClicked(); break;
        case 5: _t->onAllClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TimeFilterEnum >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimeFilter::*_t)(const TimeFilterEnum & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimeFilter::timeFilterSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TimeFilter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TimeFilter.data,
      qt_meta_data_TimeFilter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeFilter.stringdata0))
        return static_cast<void*>(const_cast< TimeFilter*>(this));
    return QDialog::qt_metacast(_clname);
}

int TimeFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TimeFilter::timeFilterSignal(const TimeFilterEnum & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
