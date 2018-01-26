/****************************************************************************
** Meta object code from reading C++ file 'UrielNetworkAccessManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UrielFileTransfer/NetworkAccessManager/UrielNetworkAccessManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UrielNetworkAccessManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UrielNetworkAccessManager_t {
    QByteArrayData data[13];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UrielNetworkAccessManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UrielNetworkAccessManager_t qt_meta_stringdata_UrielNetworkAccessManager = {
    {
QT_MOC_LITERAL(0, 0, 25), // "UrielNetworkAccessManager"
QT_MOC_LITERAL(1, 26, 5), // "error"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(4, 61, 14), // "uploadProgress"
QT_MOC_LITERAL(5, 76, 9), // "bytesSent"
QT_MOC_LITERAL(6, 86, 10), // "bytesTotal"
QT_MOC_LITERAL(7, 97, 16), // "downloadProgress"
QT_MOC_LITERAL(8, 114, 13), // "bytesReceived"
QT_MOC_LITERAL(9, 128, 13), // "replyFinished"
QT_MOC_LITERAL(10, 142, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 157, 18), // "UrielReplyFinished"
QT_MOC_LITERAL(12, 176, 8) // "finished"

    },
    "UrielNetworkAccessManager\0error\0\0"
    "QNetworkReply::NetworkError\0uploadProgress\0"
    "bytesSent\0bytesTotal\0downloadProgress\0"
    "bytesReceived\0replyFinished\0QNetworkReply*\0"
    "UrielReplyFinished\0finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UrielNetworkAccessManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,
       7,    2,   52,    2, 0x06 /* Public */,
       9,    1,   57,    2, 0x06 /* Public */,
      11,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    5,    6,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    6,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void UrielNetworkAccessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UrielNetworkAccessManager *_t = static_cast<UrielNetworkAccessManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 1: _t->uploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->UrielReplyFinished(); break;
        case 5: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UrielNetworkAccessManager::*_t)(QNetworkReply::NetworkError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UrielNetworkAccessManager::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UrielNetworkAccessManager::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UrielNetworkAccessManager::uploadProgress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UrielNetworkAccessManager::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UrielNetworkAccessManager::downloadProgress)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UrielNetworkAccessManager::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UrielNetworkAccessManager::replyFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UrielNetworkAccessManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UrielNetworkAccessManager::UrielReplyFinished)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject UrielNetworkAccessManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UrielNetworkAccessManager.data,
      qt_meta_data_UrielNetworkAccessManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UrielNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UrielNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UrielNetworkAccessManager.stringdata0))
        return static_cast<void*>(const_cast< UrielNetworkAccessManager*>(this));
    return QObject::qt_metacast(_clname);
}

int UrielNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void UrielNetworkAccessManager::error(QNetworkReply::NetworkError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UrielNetworkAccessManager::uploadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UrielNetworkAccessManager::downloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UrielNetworkAccessManager::replyFinished(QNetworkReply * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UrielNetworkAccessManager::UrielReplyFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
