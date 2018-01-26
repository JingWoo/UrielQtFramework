/****************************************************************************
** Meta object code from reading C++ file 'Downloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ThirdPartyLibraries/QSimpleUpdater/src/Downloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Downloader_t {
    QByteArrayData data[23];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Downloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Downloader_t qt_meta_stringdata_Downloader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Downloader"
QT_MOC_LITERAL(1, 11, 16), // "downloadFinished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "url"
QT_MOC_LITERAL(4, 33, 8), // "filepath"
QT_MOC_LITERAL(5, 42, 8), // "setUrlId"
QT_MOC_LITERAL(6, 51, 13), // "startDownload"
QT_MOC_LITERAL(7, 65, 11), // "setFileName"
QT_MOC_LITERAL(8, 77, 4), // "file"
QT_MOC_LITERAL(9, 82, 18), // "setUserAgentString"
QT_MOC_LITERAL(10, 101, 5), // "agent"
QT_MOC_LITERAL(11, 107, 29), // "setUseCustomInstallProcedures"
QT_MOC_LITERAL(12, 137, 6), // "custom"
QT_MOC_LITERAL(13, 144, 8), // "finished"
QT_MOC_LITERAL(14, 153, 12), // "openDownload"
QT_MOC_LITERAL(15, 166, 13), // "installUpdate"
QT_MOC_LITERAL(16, 180, 14), // "cancelDownload"
QT_MOC_LITERAL(17, 195, 8), // "saveFile"
QT_MOC_LITERAL(18, 204, 8), // "received"
QT_MOC_LITERAL(19, 213, 5), // "total"
QT_MOC_LITERAL(20, 219, 14), // "calculateSizes"
QT_MOC_LITERAL(21, 234, 14), // "updateProgress"
QT_MOC_LITERAL(22, 249, 22) // "calculateTimeRemaining"

    },
    "Downloader\0downloadFinished\0\0url\0"
    "filepath\0setUrlId\0startDownload\0"
    "setFileName\0file\0setUserAgentString\0"
    "agent\0setUseCustomInstallProcedures\0"
    "custom\0finished\0openDownload\0installUpdate\0"
    "cancelDownload\0saveFile\0received\0total\0"
    "calculateSizes\0updateProgress\0"
    "calculateTimeRemaining"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Downloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   89,    2, 0x0a /* Public */,
       6,    1,   92,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
       9,    1,   98,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    0,  105,    2, 0x08 /* Private */,
      15,    0,  106,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,
      17,    2,  108,    2, 0x08 /* Private */,
      20,    2,  113,    2, 0x08 /* Private */,
      21,    2,  118,    2, 0x08 /* Private */,
      22,    2,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,

       0        // eod
};

void Downloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Downloader *_t = static_cast<Downloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadFinished((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->setUrlId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->startDownload((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 3: _t->setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setUserAgentString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setUseCustomInstallProcedures((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->finished(); break;
        case 7: _t->openDownload(); break;
        case 8: _t->installUpdate(); break;
        case 9: _t->cancelDownload(); break;
        case 10: _t->saveFile((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 11: _t->calculateSizes((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: _t->updateProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 13: _t->calculateTimeRemaining((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Downloader::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Downloader::downloadFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Downloader::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Downloader.data,
      qt_meta_data_Downloader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Downloader.stringdata0))
        return static_cast<void*>(const_cast< Downloader*>(this));
    return QWidget::qt_metacast(_clname);
}

int Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Downloader::downloadFinished(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
