/****************************************************************************
** Meta object code from reading C++ file 'Connect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Connect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Connect_t {
    QByteArrayData data[25];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connect_t qt_meta_stringdata_Connect = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Connect"
QT_MOC_LITERAL(1, 8, 14), // "sConnectServer"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "strIP"
QT_MOC_LITERAL(4, 30, 4), // "port"
QT_MOC_LITERAL(5, 35, 12), // "ImageThread*"
QT_MOC_LITERAL(6, 48, 4), // "imgt"
QT_MOC_LITERAL(7, 53, 11), // "sDisConnect"
QT_MOC_LITERAL(8, 65, 5), // "sStop"
QT_MOC_LITERAL(9, 71, 9), // "sStopData"
QT_MOC_LITERAL(10, 81, 10), // "sWriteData"
QT_MOC_LITERAL(11, 92, 3), // "str"
QT_MOC_LITERAL(12, 96, 22), // "on_buttonstart_clicked"
QT_MOC_LITERAL(13, 119, 21), // "on_buttonstop_clicked"
QT_MOC_LITERAL(14, 141, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 163, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(16, 187, 21), // "on_btExposure_clicked"
QT_MOC_LITERAL(17, 209, 17), // "on_btGain_clicked"
QT_MOC_LITERAL(18, 227, 22), // "on_spinx0_valueChanged"
QT_MOC_LITERAL(19, 250, 4), // "arg1"
QT_MOC_LITERAL(20, 255, 22), // "on_spindx_valueChanged"
QT_MOC_LITERAL(21, 278, 22), // "on_spiny0_valueChanged"
QT_MOC_LITERAL(22, 301, 22), // "on_spindy_valueChanged"
QT_MOC_LITERAL(23, 324, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(24, 358, 5) // "index"

    },
    "Connect\0sConnectServer\0\0strIP\0port\0"
    "ImageThread*\0imgt\0sDisConnect\0sStop\0"
    "sStopData\0sWriteData\0str\0"
    "on_buttonstart_clicked\0on_buttonstop_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_btExposure_clicked\0on_btGain_clicked\0"
    "on_spinx0_valueChanged\0arg1\0"
    "on_spindx_valueChanged\0on_spiny0_valueChanged\0"
    "on_spindy_valueChanged\0"
    "on_comboBox_2_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   94,    2, 0x06 /* Public */,
       7,    0,  101,    2, 0x06 /* Public */,
       8,    0,  102,    2, 0x06 /* Public */,
       9,    0,  103,    2, 0x06 /* Public */,
      10,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,
      20,    1,  116,    2, 0x08 /* Private */,
      21,    1,  119,    2, 0x08 /* Private */,
      22,    1,  122,    2, 0x08 /* Private */,
      23,    1,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void Connect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Connect *_t = static_cast<Connect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sConnectServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ImageThread*(*)>(_a[3]))); break;
        case 1: _t->sDisConnect(); break;
        case 2: _t->sStop(); break;
        case 3: _t->sStopData(); break;
        case 4: _t->sWriteData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_buttonstart_clicked(); break;
        case 6: _t->on_buttonstop_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_btExposure_clicked(); break;
        case 10: _t->on_btGain_clicked(); break;
        case 11: _t->on_spinx0_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_spindx_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_spiny0_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_spindy_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageThread* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Connect::*_t)(QString , int , ImageThread * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connect::sConnectServer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Connect::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connect::sDisConnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Connect::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connect::sStop)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Connect::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connect::sStopData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Connect::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connect::sWriteData)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Connect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Connect.data,
      qt_meta_data_Connect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Connect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Connect.stringdata0))
        return static_cast<void*>(const_cast< Connect*>(this));
    return QWidget::qt_metacast(_clname);
}

int Connect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Connect::sConnectServer(QString _t1, int _t2, ImageThread * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connect::sDisConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Connect::sStop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Connect::sStopData()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Connect::sWriteData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
