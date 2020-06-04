/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[62];
    char stringdata0[781];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "openSerialPort"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "closeSerialPort"
QT_MOC_LITERAL(4, 43, 5), // "about"
QT_MOC_LITERAL(5, 49, 9), // "writeData"
QT_MOC_LITERAL(6, 59, 4), // "data"
QT_MOC_LITERAL(7, 64, 8), // "readData"
QT_MOC_LITERAL(8, 73, 11), // "handleError"
QT_MOC_LITERAL(9, 85, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(10, 114, 5), // "error"
QT_MOC_LITERAL(11, 120, 14), // "writeDataBreak"
QT_MOC_LITERAL(12, 135, 6), // "_break"
QT_MOC_LITERAL(13, 142, 4), // "ping"
QT_MOC_LITERAL(14, 147, 13), // "timer_ScanDev"
QT_MOC_LITERAL(15, 161, 8), // "stopScan"
QT_MOC_LITERAL(16, 170, 9), // "set_table"
QT_MOC_LITERAL(17, 180, 11), // "writeEEprom"
QT_MOC_LITERAL(18, 192, 10), // "DeviceInfo"
QT_MOC_LITERAL(19, 203, 3), // "dev"
QT_MOC_LITERAL(20, 207, 3), // "row"
QT_MOC_LITERAL(21, 211, 11), // "writeDMXAdd"
QT_MOC_LITERAL(22, 223, 10), // "writeLever"
QT_MOC_LITERAL(23, 234, 8), // "writeUID"
QT_MOC_LITERAL(24, 243, 8), // "scan_dev"
QT_MOC_LITERAL(25, 252, 20), // "on_table_Dev_clicked"
QT_MOC_LITERAL(26, 273, 11), // "QModelIndex"
QT_MOC_LITERAL(27, 285, 5), // "index"
QT_MOC_LITERAL(28, 291, 15), // "RadioBt_Clicked"
QT_MOC_LITERAL(29, 307, 14), // "Bt_WriteDMXAdd"
QT_MOC_LITERAL(30, 322, 12), // "Bt_Update_Fw"
QT_MOC_LITERAL(31, 335, 11), // "setBaudRate"
QT_MOC_LITERAL(32, 347, 2), // "br"
QT_MOC_LITERAL(33, 350, 22), // "on_table_Dev_activated"
QT_MOC_LITERAL(34, 373, 20), // "on_table_Dev_entered"
QT_MOC_LITERAL(35, 394, 20), // "on_table_Dev_pressed"
QT_MOC_LITERAL(36, 415, 28), // "on_table_Dev_viewportEntered"
QT_MOC_LITERAL(37, 444, 12), // "Bt_DMXStream"
QT_MOC_LITERAL(38, 457, 9), // "TimerEdit"
QT_MOC_LITERAL(39, 467, 15), // "EditTextDMXAddr"
QT_MOC_LITERAL(40, 483, 12), // "EditTextMAXH"
QT_MOC_LITERAL(41, 496, 12), // "EditTextMINH"
QT_MOC_LITERAL(42, 509, 11), // "BT_WriteAll"
QT_MOC_LITERAL(43, 521, 12), // "Write1Device"
QT_MOC_LITERAL(44, 534, 8), // "BT_Write"
QT_MOC_LITERAL(45, 543, 11), // "Read1Device"
QT_MOC_LITERAL(46, 555, 7), // "BT_Read"
QT_MOC_LITERAL(47, 563, 10), // "_DMXStream"
QT_MOC_LITERAL(48, 574, 10), // "actionUser"
QT_MOC_LITERAL(49, 585, 10), // "SetUiAdmin"
QT_MOC_LITERAL(50, 596, 4), // "user"
QT_MOC_LITERAL(51, 601, 10), // "ledRGB_old"
QT_MOC_LITERAL(52, 612, 10), // "closeEvent"
QT_MOC_LITERAL(53, 623, 12), // "QCloseEvent*"
QT_MOC_LITERAL(54, 636, 5), // "event"
QT_MOC_LITERAL(55, 642, 14), // "BT_ADD_onClick"
QT_MOC_LITERAL(56, 657, 12), // "BT_TesDevice"
QT_MOC_LITERAL(57, 670, 18), // "setLanguageEnglish"
QT_MOC_LITERAL(58, 689, 16), // "setLanguageChina"
QT_MOC_LITERAL(59, 706, 26), // "on_BT_WriteDMXAddr_clicked"
QT_MOC_LITERAL(60, 733, 25), // "on_BT_WriteEEprom_clicked"
QT_MOC_LITERAL(61, 759, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0openSerialPort\0\0closeSerialPort\0"
    "about\0writeData\0data\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "writeDataBreak\0_break\0ping\0timer_ScanDev\0"
    "stopScan\0set_table\0writeEEprom\0"
    "DeviceInfo\0dev\0row\0writeDMXAdd\0"
    "writeLever\0writeUID\0scan_dev\0"
    "on_table_Dev_clicked\0QModelIndex\0index\0"
    "RadioBt_Clicked\0Bt_WriteDMXAdd\0"
    "Bt_Update_Fw\0setBaudRate\0br\0"
    "on_table_Dev_activated\0on_table_Dev_entered\0"
    "on_table_Dev_pressed\0on_table_Dev_viewportEntered\0"
    "Bt_DMXStream\0TimerEdit\0EditTextDMXAddr\0"
    "EditTextMAXH\0EditTextMINH\0BT_WriteAll\0"
    "Write1Device\0BT_Write\0Read1Device\0"
    "BT_Read\0_DMXStream\0actionUser\0SetUiAdmin\0"
    "user\0ledRGB_old\0closeEvent\0QCloseEvent*\0"
    "event\0BT_ADD_onClick\0BT_TesDevice\0"
    "setLanguageEnglish\0setLanguageChina\0"
    "on_BT_WriteDMXAddr_clicked\0"
    "on_BT_WriteEEprom_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  249,    2, 0x08 /* Private */,
       3,    0,  250,    2, 0x08 /* Private */,
       4,    0,  251,    2, 0x08 /* Private */,
       5,    1,  252,    2, 0x08 /* Private */,
       7,    0,  255,    2, 0x08 /* Private */,
       8,    1,  256,    2, 0x08 /* Private */,
      11,    2,  259,    2, 0x08 /* Private */,
      13,    0,  264,    2, 0x08 /* Private */,
      14,    0,  265,    2, 0x08 /* Private */,
      15,    0,  266,    2, 0x08 /* Private */,
      16,    0,  267,    2, 0x08 /* Private */,
      17,    2,  268,    2, 0x08 /* Private */,
      21,    2,  273,    2, 0x08 /* Private */,
      22,    2,  278,    2, 0x08 /* Private */,
      23,    0,  283,    2, 0x08 /* Private */,
      24,    0,  284,    2, 0x08 /* Private */,
      25,    1,  285,    2, 0x08 /* Private */,
      28,    0,  288,    2, 0x08 /* Private */,
      29,    0,  289,    2, 0x08 /* Private */,
      30,    0,  290,    2, 0x08 /* Private */,
      31,    1,  291,    2, 0x08 /* Private */,
      33,    1,  294,    2, 0x08 /* Private */,
      34,    1,  297,    2, 0x08 /* Private */,
      35,    1,  300,    2, 0x08 /* Private */,
      36,    0,  303,    2, 0x08 /* Private */,
      37,    0,  304,    2, 0x08 /* Private */,
      38,    0,  305,    2, 0x08 /* Private */,
      39,    0,  306,    2, 0x08 /* Private */,
      40,    0,  307,    2, 0x08 /* Private */,
      41,    0,  308,    2, 0x08 /* Private */,
      42,    0,  309,    2, 0x08 /* Private */,
      43,    2,  310,    2, 0x08 /* Private */,
      44,    0,  315,    2, 0x08 /* Private */,
      45,    2,  316,    2, 0x08 /* Private */,
      46,    0,  321,    2, 0x08 /* Private */,
      47,    0,  322,    2, 0x08 /* Private */,
      48,    0,  323,    2, 0x08 /* Private */,
      49,    1,  324,    2, 0x08 /* Private */,
      51,    0,  327,    2, 0x08 /* Private */,
      52,    1,  328,    2, 0x08 /* Private */,
      55,    0,  331,    2, 0x08 /* Private */,
      56,    0,  332,    2, 0x08 /* Private */,
      57,    0,  333,    2, 0x08 /* Private */,
      58,    0,  334,    2, 0x08 /* Private */,
      59,    0,  335,    2, 0x08 /* Private */,
      60,    0,  336,    2, 0x08 /* Private */,
      61,    0,  337,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    6,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort,   19,   20,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort,   19,   20,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort,   19,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,   54,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSerialPort(); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->about(); break;
        case 3: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->readData(); break;
        case 5: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 6: _t->writeDataBreak((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->ping(); break;
        case 8: _t->timer_ScanDev(); break;
        case 9: _t->stopScan(); break;
        case 10: _t->set_table(); break;
        case 11: _t->writeEEprom((*reinterpret_cast< DeviceInfo(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 12: _t->writeDMXAdd((*reinterpret_cast< DeviceInfo(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 13: _t->writeLever((*reinterpret_cast< DeviceInfo(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 14: _t->writeUID(); break;
        case 15: _t->scan_dev(); break;
        case 16: _t->on_table_Dev_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 17: _t->RadioBt_Clicked(); break;
        case 18: _t->Bt_WriteDMXAdd(); break;
        case 19: _t->Bt_Update_Fw(); break;
        case 20: _t->setBaudRate((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 21: _t->on_table_Dev_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 22: _t->on_table_Dev_entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 23: _t->on_table_Dev_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 24: _t->on_table_Dev_viewportEntered(); break;
        case 25: _t->Bt_DMXStream(); break;
        case 26: _t->TimerEdit(); break;
        case 27: _t->EditTextDMXAddr(); break;
        case 28: _t->EditTextMAXH(); break;
        case 29: _t->EditTextMINH(); break;
        case 30: _t->BT_WriteAll(); break;
        case 31: _t->Write1Device((*reinterpret_cast< DeviceInfo(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 32: _t->BT_Write(); break;
        case 33: _t->Read1Device((*reinterpret_cast< DeviceInfo(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 34: _t->BT_Read(); break;
        case 35: _t->_DMXStream(); break;
        case 36: _t->actionUser(); break;
        case 37: _t->SetUiAdmin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->ledRGB_old(); break;
        case 39: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 40: _t->BT_ADD_onClick(); break;
        case 41: _t->BT_TesDevice(); break;
        case 42: _t->setLanguageEnglish(); break;
        case 43: _t->setLanguageChina(); break;
        case 44: _t->on_BT_WriteDMXAddr_clicked(); break;
        case 45: _t->on_BT_WriteEEprom_clicked(); break;
        case 46: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 47;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
