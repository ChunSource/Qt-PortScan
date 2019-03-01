/****************************************************************************
** Meta object code from reading C++ file 'scan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scan_t {
    QByteArrayData data[9];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scan_t qt_meta_stringdata_Scan = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Scan"
QT_MOC_LITERAL(1, 5, 5), // "exist"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 3), // "now"
QT_MOC_LITERAL(4, 16, 8), // "shutdown"
QT_MOC_LITERAL(5, 25, 7), // "process"
QT_MOC_LITERAL(6, 33, 3), // "run"
QT_MOC_LITERAL(7, 37, 2), // "go"
QT_MOC_LITERAL(8, 40, 4) // "test"

    },
    "Scan\0exist\0\0now\0shutdown\0process\0run\0"
    "go\0test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scan[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       1,    2,   56,    2, 0x26 /* Public | MethodCloned */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    2,    2,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Scan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scan *_t = static_cast<Scan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->exist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->shutdown(); break;
        case 3: _t->process((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->run(); break;
        case 5: _t->go(); break;
        case 6: _t->test(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Scan::*_t)(QString , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scan::exist)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Scan::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scan::shutdown)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Scan::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scan::process)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Scan::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Scan.data,
      qt_meta_data_Scan,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Scan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scan.stringdata0))
        return static_cast<void*>(const_cast< Scan*>(this));
    return QThread::qt_metacast(_clname);
}

int Scan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Scan::exist(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void Scan::shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Scan::process(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
