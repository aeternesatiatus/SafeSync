/****************************************************************************
** Meta object code from reading C++ file 'sync.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ScriptsClass/sync.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sync.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sync_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sync_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sync_t qt_meta_stringdata_sync = {
    {
QT_MOC_LITERAL(0, 0, 4), // "sync"
QT_MOC_LITERAL(1, 5, 17), // "clientUserChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "clientDirChanged"
QT_MOC_LITERAL(4, 41, 17), // "serverUserChanged"
QT_MOC_LITERAL(5, 59, 21), // "serverHostnameChanged"
QT_MOC_LITERAL(6, 81, 18), // "serverDailyChanged"
QT_MOC_LITERAL(7, 100, 14) // "cwrsyncChanged"

    },
    "sync\0clientUserChanged\0\0clientDirChanged\0"
    "serverUserChanged\0serverHostnameChanged\0"
    "serverDailyChanged\0cwrsyncChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sync[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void sync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sync *_t = static_cast<sync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientUserChanged(); break;
        case 1: _t->clientDirChanged(); break;
        case 2: _t->serverUserChanged(); break;
        case 3: _t->serverHostnameChanged(); break;
        case 4: _t->serverDailyChanged(); break;
        case 5: _t->cwrsyncChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::clientUserChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::clientDirChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::serverUserChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::serverHostnameChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::serverDailyChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (sync::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sync::cwrsyncChanged)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject sync::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sync.data,
      qt_meta_data_sync,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sync::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sync::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sync.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sync::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void sync::clientUserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sync::clientDirChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void sync::serverUserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void sync::serverHostnameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void sync::serverDailyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void sync::cwrsyncChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
