/****************************************************************************
** Meta object code from reading C++ file 'InvoiceInfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UrielGui/Expense/InvoiceInfo/InvoiceInfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InvoiceInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InvoiceInfo_t {
    QByteArrayData data[19];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InvoiceInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InvoiceInfo_t qt_meta_stringdata_InvoiceInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "InvoiceInfo"
QT_MOC_LITERAL(1, 12, 14), // "transferFinish"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "onCalculateClicked"
QT_MOC_LITERAL(4, 47, 15), // "onCancelClicked"
QT_MOC_LITERAL(5, 63, 11), // "onOKClicked"
QT_MOC_LITERAL(6, 75, 24), // "onAddInvoiceImageClicked"
QT_MOC_LITERAL(7, 100, 28), // "onPreviewInvoiceImageClicked"
QT_MOC_LITERAL(8, 129, 29), // "onOKDeleteInvoiceImageClicked"
QT_MOC_LITERAL(9, 159, 25), // "onAddBuyScreenshotClicked"
QT_MOC_LITERAL(10, 185, 29), // "onPreviewBuyScreenshotClicked"
QT_MOC_LITERAL(11, 215, 30), // "onOKDeleteBuyScreenshotClicked"
QT_MOC_LITERAL(12, 246, 29), // "onAddVerificationImageClicked"
QT_MOC_LITERAL(13, 276, 33), // "onPreviewVerificationImageCli..."
QT_MOC_LITERAL(14, 310, 34), // "onOKDeleteVerificationImageCl..."
QT_MOC_LITERAL(15, 345, 32), // "onUpdateDataTransferProgressSlot"
QT_MOC_LITERAL(16, 378, 18), // "onTransferFinished"
QT_MOC_LITERAL(17, 397, 14), // "QNetworkReply*"
QT_MOC_LITERAL(18, 412, 5) // "reply"

    },
    "InvoiceInfo\0transferFinish\0\0"
    "onCalculateClicked\0onCancelClicked\0"
    "onOKClicked\0onAddInvoiceImageClicked\0"
    "onPreviewInvoiceImageClicked\0"
    "onOKDeleteInvoiceImageClicked\0"
    "onAddBuyScreenshotClicked\0"
    "onPreviewBuyScreenshotClicked\0"
    "onOKDeleteBuyScreenshotClicked\0"
    "onAddVerificationImageClicked\0"
    "onPreviewVerificationImageClicked\0"
    "onOKDeleteVerificationImageClicked\0"
    "onUpdateDataTransferProgressSlot\0"
    "onTransferFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InvoiceInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    2,  102,    2, 0x08 /* Private */,
      16,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void InvoiceInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InvoiceInfo *_t = static_cast<InvoiceInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transferFinish(); break;
        case 1: _t->onCalculateClicked(); break;
        case 2: _t->onCancelClicked(); break;
        case 3: _t->onOKClicked(); break;
        case 4: _t->onAddInvoiceImageClicked(); break;
        case 5: _t->onPreviewInvoiceImageClicked(); break;
        case 6: _t->onOKDeleteInvoiceImageClicked(); break;
        case 7: _t->onAddBuyScreenshotClicked(); break;
        case 8: _t->onPreviewBuyScreenshotClicked(); break;
        case 9: _t->onOKDeleteBuyScreenshotClicked(); break;
        case 10: _t->onAddVerificationImageClicked(); break;
        case 11: _t->onPreviewVerificationImageClicked(); break;
        case 12: _t->onOKDeleteVerificationImageClicked(); break;
        case 13: _t->onUpdateDataTransferProgressSlot((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 14: _t->onTransferFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
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
            typedef void (InvoiceInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InvoiceInfo::transferFinish)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject InvoiceInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InvoiceInfo.data,
      qt_meta_data_InvoiceInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InvoiceInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvoiceInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InvoiceInfo.stringdata0))
        return static_cast<void*>(const_cast< InvoiceInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int InvoiceInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void InvoiceInfo::transferFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
