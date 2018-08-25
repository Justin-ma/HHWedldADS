/****************************************************************************
** Meta object code from reading C++ file 'Calibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Calibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Calibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Calibration_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calibration_t qt_meta_stringdata_Calibration = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Calibration"
QT_MOC_LITERAL(1, 12, 15), // "sSendCoordinate"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "double*"
QT_MOC_LITERAL(4, 37, 2), // "co"
QT_MOC_LITERAL(5, 40, 9), // "sGetIamge"
QT_MOC_LITERAL(6, 50, 8), // "slotSend"
QT_MOC_LITERAL(7, 59, 9) // "slotGetxy"

    },
    "Calibration\0sSendCoordinate\0\0double*\0"
    "co\0sGetIamge\0slotSend\0slotGetxy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calibration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calibration *_t = static_cast<Calibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sSendCoordinate((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 1: _t->sGetIamge(); break;
        case 2: _t->slotSend(); break;
        case 3: _t->slotGetxy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Calibration::*_t)(double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Calibration::sSendCoordinate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Calibration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Calibration::sGetIamge)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Calibration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Calibration.data,
      qt_meta_data_Calibration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Calibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calibration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Calibration.stringdata0))
        return static_cast<void*>(const_cast< Calibration*>(this));
    return QWidget::qt_metacast(_clname);
}

int Calibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Calibration::sSendCoordinate(double * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Calibration::sGetIamge()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
