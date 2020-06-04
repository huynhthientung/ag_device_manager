/****************************************************************************
** Meta object code from reading C++ file 'dmxconsole.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dmxconsole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmxconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DMXconsole_t {
    QByteArrayData data[13];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DMXconsole_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DMXconsole_t qt_meta_stringdata_DMXconsole = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DMXconsole"
QT_MOC_LITERAL(1, 11, 10), // "DMXTriggle"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 23), // "BtnDMXStreaming_Clicked"
QT_MOC_LITERAL(4, 47, 7), // "DMXTick"
QT_MOC_LITERAL(5, 55, 16), // "_updateLb_value0"
QT_MOC_LITERAL(6, 72, 3), // "val"
QT_MOC_LITERAL(7, 76, 14), // "_syncDMXBuffer"
QT_MOC_LITERAL(8, 91, 5), // "index"
QT_MOC_LITERAL(9, 97, 22), // "_chk_SelectAll_Changed"
QT_MOC_LITERAL(10, 120, 12), // "FocusChanged"
QT_MOC_LITERAL(11, 133, 3), // "dir"
QT_MOC_LITERAL(12, 137, 28) // "on_BtnStartStreaming_clicked"

    },
    "DMXconsole\0DMXTriggle\0\0BtnDMXStreaming_Clicked\0"
    "DMXTick\0_updateLb_value0\0val\0"
    "_syncDMXBuffer\0index\0_chk_SelectAll_Changed\0"
    "FocusChanged\0dir\0on_BtnStartStreaming_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DMXconsole[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,

       0        // eod
};

void DMXconsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DMXconsole *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DMXTriggle(); break;
        case 1: _t->BtnDMXStreaming_Clicked(); break;
        case 2: _t->DMXTick(); break;
        case 3: _t->_updateLb_value0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->_syncDMXBuffer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->_chk_SelectAll_Changed(); break;
        case 6: _t->FocusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_BtnStartStreaming_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMXconsole::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXconsole::DMXTriggle)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DMXconsole::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DMXconsole.data,
    qt_meta_data_DMXconsole,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DMXconsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DMXconsole::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DMXconsole.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DMXconsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DMXconsole::DMXTriggle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
