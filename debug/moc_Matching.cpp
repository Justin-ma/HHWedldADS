/****************************************************************************
** Meta object code from reading C++ file 'Matching.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Matching.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Matching.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Matching_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Matching_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Matching_t qt_meta_stringdata_Matching = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Matching"
QT_MOC_LITERAL(1, 9, 15), // "sSendStartMatch"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "str"
QT_MOC_LITERAL(4, 30, 15), // "sSendSetDeviate"
QT_MOC_LITERAL(5, 46, 13), // "sSendOneMatch"
QT_MOC_LITERAL(6, 60, 14) // "sSendManyMatch"

    },
    "Matching\0sSendStartMatch\0\0str\0"
    "sSendSetDeviate\0sSendOneMatch\0"
    "sSendManyMatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Matching[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Matching::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Matching *_t = static_cast<Matching *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sSendStartMatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sSendSetDeviate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sSendOneMatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sSendManyMatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Matching::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Matching::sSendStartMatch)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Matching::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Matching::sSendSetDeviate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Matching::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Matching::sSendOneMatch)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Matching::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Matching::sSendManyMatch)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Matching::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Matching.data,
      qt_meta_data_Matching,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Matching::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Matching::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Matching.stringdata0))
        return static_cast<void*>(const_cast< Matching*>(this));
    return QWidget::qt_metacast(_clname);
}

int Matching::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Matching::sSendStartMatch(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Matching::sSendSetDeviate(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Matching::sSendOneMatch(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Matching::sSendManyMatch(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
