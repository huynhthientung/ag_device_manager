/****************************************************************************
** Meta object code from reading C++ file 'qtdmxlib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtdmxlib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtdmxlib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DMXRDM_t {
    QByteArrayData data[22];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DMXRDM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DMXRDM_t qt_meta_stringdata_DMXRDM = {
    {
QT_MOC_LITERAL(0, 0, 6), // "DMXRDM"
QT_MOC_LITERAL(1, 7, 9), // "writeData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "data"
QT_MOC_LITERAL(4, 23, 14), // "writeDataBreak"
QT_MOC_LITERAL(5, 38, 6), // "_break"
QT_MOC_LITERAL(6, 45, 11), // "display_UID"
QT_MOC_LITERAL(7, 57, 4), // "sUID"
QT_MOC_LITERAL(8, 62, 18), // "display_DMXChannel"
QT_MOC_LITERAL(9, 81, 10), // "DMXChannel"
QT_MOC_LITERAL(10, 92, 19), // "display_DMXLowLever"
QT_MOC_LITERAL(11, 112, 8), // "lowlever"
QT_MOC_LITERAL(12, 121, 20), // "display_DMXHighLever"
QT_MOC_LITERAL(13, 142, 9), // "highlever"
QT_MOC_LITERAL(14, 152, 18), // "display_SEQAddress"
QT_MOC_LITERAL(15, 171, 3), // "add"
QT_MOC_LITERAL(16, 175, 11), // "setBaudrate"
QT_MOC_LITERAL(17, 187, 2), // "br"
QT_MOC_LITERAL(18, 190, 15), // "closeSerialPort"
QT_MOC_LITERAL(19, 206, 6), // "isUser"
QT_MOC_LITERAL(20, 213, 2), // "is"
QT_MOC_LITERAL(21, 216, 8) // "timer_pw"

    },
    "DMXRDM\0writeData\0\0data\0writeDataBreak\0"
    "_break\0display_UID\0sUID\0display_DMXChannel\0"
    "DMXChannel\0display_DMXLowLever\0lowlever\0"
    "display_DMXHighLever\0highlever\0"
    "display_SEQAddress\0add\0setBaudrate\0"
    "br\0closeSerialPort\0isUser\0is\0timer_pw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DMXRDM[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       6,    1,   77,    2, 0x06 /* Public */,
       8,    1,   80,    2, 0x06 /* Public */,
      10,    1,   83,    2, 0x06 /* Public */,
      12,    1,   86,    2, 0x06 /* Public */,
      14,    1,   89,    2, 0x06 /* Public */,
      16,    1,   92,    2, 0x06 /* Public */,
      18,    0,   95,    2, 0x06 /* Public */,
      19,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    3,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DMXRDM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DMXRDM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->writeDataBreak((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->display_UID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->display_DMXChannel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->display_DMXLowLever((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->display_DMXHighLever((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->display_SEQAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setBaudrate((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 8: _t->closeSerialPort(); break;
        case 9: _t->isUser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->timer_pw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMXRDM::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::writeData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(const QByteArray & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::writeDataBreak)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::display_UID)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::display_DMXChannel)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::display_DMXLowLever)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::display_DMXHighLever)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::display_SEQAddress)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::setBaudrate)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::closeSerialPort)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::isUser)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DMXRDM::staticMetaObject = { {
    &QPlainTextEdit::staticMetaObject,
    qt_meta_stringdata_DMXRDM.data,
    qt_meta_data_DMXRDM,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DMXRDM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DMXRDM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DMXRDM.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int DMXRDM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DMXRDM::writeData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DMXRDM::writeDataBreak(const QByteArray & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DMXRDM::display_UID(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DMXRDM::display_DMXChannel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DMXRDM::display_DMXLowLever(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DMXRDM::display_DMXHighLever(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DMXRDM::display_SEQAddress(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DMXRDM::setBaudrate(qint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DMXRDM::closeSerialPort()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void DMXRDM::isUser(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
