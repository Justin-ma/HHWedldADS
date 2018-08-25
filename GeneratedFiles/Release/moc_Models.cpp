/****************************************************************************
** Meta object code from reading C++ file 'Models.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Models.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Models.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Models_t {
    QByteArrayData data[12];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Models_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Models_t qt_meta_stringdata_Models = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Models"
QT_MOC_LITERAL(1, 7, 13), // "sChangeModelR"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "sChangeModelS"
QT_MOC_LITERAL(4, 36, 10), // "sSaveModel"
QT_MOC_LITERAL(5, 47, 12), // "sUpLoadModel"
QT_MOC_LITERAL(6, 60, 9), // "sSendName"
QT_MOC_LITERAL(7, 70, 3), // "str"
QT_MOC_LITERAL(8, 74, 13), // "sChooceModels"
QT_MOC_LITERAL(9, 88, 16), // "slotChangeModelR"
QT_MOC_LITERAL(10, 105, 16), // "slotChangeModelS"
QT_MOC_LITERAL(11, 122, 16) // "slotChooceModels"

    },
    "Models\0sChangeModelR\0\0sChangeModelS\0"
    "sSaveModel\0sUpLoadModel\0sSendName\0str\0"
    "sChooceModels\0slotChangeModelR\0"
    "slotChangeModelS\0slotChooceModels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Models[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Models::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Models *_t = static_cast<Models *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sChangeModelR(); break;
        case 1: _t->sChangeModelS(); break;
        case 2: _t->sSaveModel(); break;
        case 3: _t->sUpLoadModel(); break;
        case 4: _t->sSendName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sChooceModels(); break;
        case 6: _t->slotChangeModelR(); break;
        case 7: _t->slotChangeModelS(); break;
        case 8: _t->slotChooceModels(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Models::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sChangeModelR)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Models::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sChangeModelS)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Models::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sSaveModel)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Models::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sUpLoadModel)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Models::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sSendName)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Models::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Models::sChooceModels)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Models::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Models.data,
      qt_meta_data_Models,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Models::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Models::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Models.stringdata0))
        return static_cast<void*>(const_cast< Models*>(this));
    return QWidget::qt_metacast(_clname);
}

int Models::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Models::sChangeModelR()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Models::sChangeModelS()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Models::sSaveModel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Models::sUpLoadModel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Models::sSendName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Models::sChooceModels()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
