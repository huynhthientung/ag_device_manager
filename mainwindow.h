/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dmxconsole.h"
#include "ledrgbold.h"

#include <QMainWindow>
#include <QSerialPort>
#include <qtdmxlib.h>
#include <loadingdialog.h>
#include <qtablewidget.h>
#include <QStandardItem>

QT_BEGIN_NAMESPACE

extern DMXRDM *dmxrdm;

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:


private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void writeDataBreak(const QByteArray &data, bool _break);
    void ping();
    void timer_ScanDev();
    void stopScan();
    void set_table();
    void writeEEprom(DeviceInfo dev, quint16 row);
    void writeDMXAdd(DeviceInfo dev, quint16 row);
    void writeLever(DeviceInfo dev, quint16 row);
    void writeUID();
private slots:
    void scan_dev();
    void on_table_Dev_clicked(const QModelIndex &index);
    void RadioBt_Clicked();
    void Bt_WriteDMXAdd();
    void Bt_Update_Fw();
    void setBaudRate(qint32 br);
    void on_table_Dev_activated(const QModelIndex &index);
    void on_table_Dev_entered(const QModelIndex &index);
    void on_table_Dev_pressed(const QModelIndex &index);
    void on_table_Dev_viewportEntered();
    void Bt_DMXStream();
    void TimerEdit();
    void EditTextDMXAddr();
    void EditTextMAXH();
    void EditTextMINH();
    void BT_WriteAll();
    void Write1Device(DeviceInfo dev, quint16 row);
    void BT_Write();
    void Read1Device(DeviceInfo dev, quint16 row);
    void BT_Read();
    void _DMXStream();
    void actionUser();
    void SetUiAdmin(bool user);
    void ledRGB_old();
    void closeEvent (QCloseEvent *event);
    void BT_ADD_onClick();
    void BT_TesDevice();

private:
    void initActionsConnections();
    void _setScan();
    void setbeginTable();
    bool IsUSARTAvailable;

private:
    void showStatusMessage(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QLabel *m_status = nullptr;
    Console *m_console = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
    QStandardItemModel mode_table;
    QStandardItemModel *model;
    QList<DeviceInfo> listDevice;


    DMXconsole *dmx;
    LEDRGBold *ledrgbold;

private:
    bool _exit = false;

    LoadingDialog *loadinfdialog;

    QTimer *timer_scanDev;
    QTimer *timer_edit;
    quint8 uid_count[6];
    QByteArray uid_scaner;
    bool _devfind[6];
    int _pos_Dev_count = 0;
    bool _ch_scan = false;
    typedef enum
    {
        TablePos,
        TableUID,
        TableDMXAdd,
        TableDevType,
        TableFwV,
        TableMaxH,
        TableMinH,
        EEprom0,
        EEprom1,
        EEprom2,
        EEprom3,
        EEprom4,
        EEprom5,
        EEprom6,
        EEprom7,
        EEprom8,
        EEprom9,
        NumberOfTableCollum
    }RowTable;
    const QString strCollumIndex[NumberOfTableCollum] =
    {
        "Position",
        "UID",
        "DMX Address",
        "Device type",
        "Firmware version",
        "Max Height",
        "Min Height",
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"
    };
    const QString strCollumIndexCH[NumberOfTableCollum] =
    {
        "位子",
        "UID",
        "DMX地址码",
        "设备种类",
        "Firmware version",
        "Max Height",
        "Min Height",
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"
    };
    quint16 Row_Counter;
    void SetCell(quint16 x, quint16 y, QString data, QColor color);
    void SetCell(quint16 x, quint16 y, quint32 data, QColor color);
    QString GetCell(quint16 x, quint16 y);
    QString GetCell(QModelIndex index);
    void SetNextRow(DeviceInfo devInfo, QColor color);
    void SetRow(DeviceInfo devInfo, quint16 row, QColor color);
    void SetStT(QString s);
    quint16 SelectRow = 999;

    //QString s = "地址码";

private:
    typedef enum
    {
        Find_Dev_All,
        Find_Dev_Pump,
        Find_Dev_LED,
        Find_Dev_Others
    }FIND_DEV;
    FIND_DEV findDev;

private:
    typedef enum{
        AGDeviceManager,
        Settings,
        Connect,        //ok
        Disconnect,     //ok
        Tools,
        Configure,      //ok
        Clean,
        Helps,
        About,//ok
        Devicestype,    //ok
        All,    //ok
        Pump,//ok
        LED,    //ok
        Others, //ok
        Scan, //ok
        Stop, //ok
        Read, //ok
        Write, //ok
        Ping,   //ok
        WriteDMXAddress,
        WriteLevel,
        UID,
        DMXAddress, //ok
        MaxHeight,  //ok
        MinHeight,  //ok
        Position,   //ok
        Connecttoserialport,
        Disconnecttoserialport,
        LG_Count
    }LG_DEF;
    QString LG_EN[LG_Count] = {
        "AG Device Manager",
        "Settings",
        "Connect",
        "Disconnect",
        "Tools",
        "Configure",
        "Clean",
        "Helps",
        "About",
        "Devices type",
        "All",
        "Pump",
        "LED",
        "Others",
        "Scan",
        "Stop",
        "Read",
        "Write",
        "Ping",
        "Write DMX Address",
        "Write Level",
        "UID",
        "DMX Address",
        "Max Height",
        "Min Height",
        "Position",
        "Connect to serial port",
        "Disconnect to serial port",
    };
    QString LG_CH[LG_Count] = {
        "AG设备管理",
        "设置",
        "连接",
        "断开",
        "工具",
        "配置",
        "清理",
        "帮助",
        "关于",
        "设备种类",
        "所有设备",
        "水泵设备",
        "照明设备",
        "其他设备",
        "扫描",
        "停止",
        "读取",
        "写码",
        "搜索",
        "写DMX地址",
        "写喷高",
        "UID",
        "DMX地址码",
        "最高喷高",
        "最低喷高",
        "位子",
        "切断串口连接",
        "连接串口连接"
    };
    typedef enum
    {
        English,
        Chinese
    }LANGUAGE;
    void setLanguage(LANGUAGE lg);
    LANGUAGE language;
private slots:
    void setLanguageEnglish();
    void setLanguageChina();
    void on_BT_WriteDMXAddr_clicked();
    void on_BT_WriteEEprom_clicked();
    void on_pushButton_clicked();

};

#endif // MAINWINDOW_H
