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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QColor>
#include <QIcon>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QStandardItem>

#include <QTimer>

#include <debug.h>

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_status(new QLabel),
    m_console(new Console),
    m_settings(new SettingsDialog),
//! [1]
    m_serial(new QSerialPort(this))

//! [1]
{
//! [0]
    m_ui->setupUi(this);
    m_console->setEnabled(false);
    //setCentralWidget(m_console);
    dmxrdm = new  DMXRDM();
    _exit = false;
    dmx = new DMXconsole();

    SetUiAdmin(false);

    loadinfdialog = new LoadingDialog();
    timer_scanDev = new QTimer();
    timer_edit = new QTimer();
    //timer_edit->start(1);
    model = new QStandardItemModel(0, 0, this);
    m_ui->table_Dev->setModel(model);
    setbeginTable();
    ledrgbold = new LEDRGBold();
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);
    m_ui->statusBar->addWidget(m_status);
    initActionsConnections();
    findDev = Find_Dev_All;

    //m_ui->lb_max->setText(LG_CH[MaxHeight]);
    setLanguage(English);
    connect(m_ui->actionEnglish, SIGNAL(triggered()), this, SLOT(setLanguageEnglish()));
    connect(m_ui->actionchina, SIGNAL(triggered()), this, SLOT(setLanguageChina()));
    //m_ui->actionchina->setChecked(false);
    //m_ui->table_Dev->setColumnCount(6);
    //QStringList table_title;
    //table_title <<"UID" << "DMX Address" << "Device type" << "Max Height" << "Min Height" << "Firmware version";
    //m_ui->table_Dev->setHorizontalHeaderLabels(table_title);




    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);


//! [2]
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    connect(m_console, &Console::getData, this, &MainWindow::writeData);
//user

    connect(m_ui->bt_scan, SIGNAL(clicked(bool)), this, SLOT(scan_dev()));
    connect(m_ui->actionScan, &QAction::triggered, this, &MainWindow::scan_dev);
    connect(m_ui->bt_stop, SIGNAL(clicked(bool)), this, SLOT(stopScan()));
    connect(m_ui->actionStop, &QAction::triggered, this, &MainWindow::stopScan);

    connect(dmxrdm, SIGNAL(writeData(QByteArray)), this, SLOT(writeData(QByteArray)));
    connect(dmxrdm, SIGNAL(writeDataBreak(QByteArray, bool)), this, SLOT(writeDataBreak(QByteArray, bool)));
    connect(dmxrdm, SIGNAL(display_UID(QString)), m_ui->txt_UID, SLOT(setText(QString)));

    connect(m_ui->bt_Ping, SIGNAL(clicked(bool)), this, SLOT(ping()));
    connect(timer_scanDev, SIGNAL(timeout()), this, SLOT(timer_ScanDev()));

    connect(m_ui->radioButtonALL, SIGNAL(clicked(bool)), this, SLOT(RadioBt_Clicked()));
    connect(m_ui->radioButtonLED, SIGNAL(clicked(bool)), this, SLOT(RadioBt_Clicked()));
    connect(m_ui->radioButtonOthers, SIGNAL(clicked(bool)), this, SLOT(RadioBt_Clicked()));
    connect(m_ui->radioButtonPump, SIGNAL(clicked(bool)), this, SLOT(RadioBt_Clicked()));

    connect(m_ui->bt_WriteDMXID, SIGNAL(clicked()), this, SLOT(Bt_WriteDMXAdd()));
    connect(m_ui->bt_UpdateFirmware, SIGNAL(clicked()), this, SLOT(Bt_Update_Fw()));
    connect(dmxrdm, SIGNAL(setBaudrate(qint32)), this, SLOT(setBaudRate(qint32)));
    connect(dmxrdm, SIGNAL(closeSerialPort()), this, SLOT(closeSerialPort()));
    connect(m_ui->bt_DMX, SIGNAL(clicked(bool)), this, SLOT(Bt_DMXStream()));
    connect(timer_edit, SIGNAL(timeout()), this, SLOT(TimerEdit()));

    //connect(m_ui->txt_UID, SIGNAL(textChanged(QString)), this, SLOT(EditText()));
    connect(m_ui->txt_MAXH, SIGNAL(textChanged(QString)), this, SLOT(EditTextMAXH()));
    connect(m_ui->txt_MINH, SIGNAL(textChanged(QString)), this, SLOT(EditTextMINH()));
    connect(m_ui->txt_DMXID, SIGNAL(textChanged(QString)), this, SLOT(EditTextDMXAddr()));

    connect(m_ui->BT_Write, SIGNAL(clicked(bool)), this, SLOT(BT_Write()));
    connect(m_ui->BT_Read, SIGNAL(clicked(bool)), this, SLOT(BT_Read()));

    connect(m_ui->bt_DMX, SIGNAL(clicked(bool)), dmx, SLOT(show()));
    connect(dmx, SIGNAL(DMXTriggle()), this, SLOT(_DMXStream()));
    connect(m_ui->actionUser, SIGNAL(triggered()), this, SLOT(actionUser()));
    connect(dmxrdm, SIGNAL(isUser(bool)), this, SLOT(SetUiAdmin(bool)));
    connect(m_ui->BT_WriteUID, SIGNAL(clicked(bool)), this, SLOT(writeUID()));

    connect(m_ui->actionLED_RGB_v1_0, SIGNAL(triggered()), this, SLOT(ledRGB_old()));

    connect(m_ui->BT_ADD_NEW, SIGNAL(clicked(bool)), this, SLOT(BT_ADD_onClick()));
    connect(m_ui->BT_TestDevice, SIGNAL(clicked(bool)), this, SLOT(BT_TesDevice()));
}
//! [3]

MainWindow::~MainWindow()
{
    stopScan();
    delete m_serial;
    delete m_settings;
    delete m_ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = m_settings->settings();

    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    m_serial->setReadBufferSize(100);


    if (m_serial->open(QIODevice::ReadWrite)) {
        //console->setEnabled(true);
        //console->setLocalEchoEnabled(p.localEchoEnabled);
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        //serial->setBreakEnabled(true);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        IsUSARTAvailable = true;
        //this->showConnected();

    } else {
        if(IsUSARTAvailable == true) QMessageBox::critical(this, tr("Error"), m_serial->errorString());
        IsUSARTAvailable = false;
        showStatusMessage(tr("Open error"));
        //this->showDisconnected();
        this->m_settings->ShowSetting();
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    m_console->setEnabled(false);
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About AG Device Manager"),
                       tr("AG Device Manager v3.0\r\n"
                          "Website https://ag-destudio.com/"
                          ""));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    if(m_serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm->delay(500);
    }

    if(m_serial->isOpen())
    {
        /*
        QString _sprint = tr("data send. Size:\t%1. Data").arg(data.size());
        for(int i = 0; i < data.size(); i++)
        {
            _sprint += tr(" %1").arg((quint8)data[i]);
        }
        DEBUG(_sprint);
*/
        m_serial->sendBreak(1);
        //dmxrdm->delay(1);
        m_serial->write(data);
    }
}
//! [6]

//! [7]
void MainWindow::readData()
{
    const QByteArray data = m_serial->readAll();
    //m_console->putData(data);

    QString _sprint;
    _sprint = tr("Data rec. Size: %1, data: ").arg(data.size());
    for(int i = 0; i < data.size(); i++)
    {
        _sprint += tr("%1 ").arg((quint8)data[i]);
    }
    DEBUG(_sprint);
    dmxrdm->RDMRecHandler(data);
}
//! [7]

//! [8]0
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::writeDataBreak(const QByteArray &data, bool _break)
{
    QString _sprint = tr("data send. Size:\t%1. Data").arg(data.size());

    if(m_serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm->delay(500);
    }

    for(int i = 0; i < data.size(); i++)
    {
        _sprint += tr(" %1").arg((quint8)data[i]);
    }
    if(_break)
    {
        m_serial->sendBreak(1);
        dmxrdm->delay(1);
    }
    else {
    }
    m_serial->write(data);
}

void MainWindow::ping()
{
    bool _check = false;
    stopScan();
    m_ui->bt_Ping->setEnabled(false);
    SetStT(tr("Reading..."));
    loadinfdialog->showDialog();
    DeviceInfo dev;
    QString s = m_ui->txt_UID->text().trimmed();
    dmxrdm->setUID(s);
    //dmxrdm->GetDeviceInfo();
    //dmxrdm->askFwV();
    //dmxrdm->askSEQAddress();
    dmxrdm->delay(10);
    if(Row_Counter == 0)
    {
        listDevice.append(dev);
        SetNextRow(dev, Qt::white);
        SelectRow = 0;
        _check = true;
    }

    if(Row_Counter != 0 && SelectRow == 999)
    {
        QMessageBox::information(this, tr("Select device"), tr("No device selected!"));
    }
    else
    if(dmxrdm->RDMPing())
    {
        dmxrdm->delay(10);
        dmxrdm->askDMXAdd();
        dmxrdm->delay(10);
        dmxrdm->askThreshold();
        dmxrdm->delay(10);
        dmxrdm->askSEQAddress();
        dmxrdm->askFwV();
        dmxrdm->askDeviceType();
        SetStT(tr("Device ready!"));
        m_ui->txt_UID->setText(dmxrdm->DeviceInfo.sUID);
        m_ui->txt_DMXID->setText(QString::number(dmxrdm->DeviceInfo.DMXAddr));
        m_ui->txt_MAXH->setText(QString::number(dmxrdm->DeviceInfo.MaxLevel));
        m_ui->txt_MINH->setText(QString::number(dmxrdm->DeviceInfo.MinLevel));
        m_ui->txt_Pos->setText(QString::number(dmxrdm->DeviceInfo.SEQAddr));
        if(_check)
        {
            Row_Counter--;
            SetNextRow(dmxrdm->DeviceInfo, Qt::white);
            listDevice.removeAt(0);
            listDevice.insert(0, dev);
        }
    }
    else {
        QMessageBox::critical(this, tr("ERROR"), tr("Device not found!"));
        SetStT(tr("Device not found!"));
    }

    loadinfdialog->hideDialog();
    m_ui->bt_Ping->setEnabled(true);

}

void MainWindow::timer_ScanDev()
{

}

void MainWindow::stopScan()
{
    //timer_scanDev->stop();

    _ch_scan = false;
}

void MainWindow::set_table()
{

    //int pos = m_ui->table_Dev->rowCount();

    if(dmxrdm->RDMPing())
    {
        //m_ui->table_Dev->insertRow(m_ui->table_Dev->rowCount());
        //m_ui->table_Dev->setItem(pos, TableUID, new QTableWidgetItem(dmxrdm->DeviceInfo.sUID));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askDMXAdd())
    {
        //DEBUG(QString::number(dmxrdm->DeviceInfo.DMXAddr));
        //m_ui->table_Dev->setItem(pos, TableDMXAdd, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.DMXAddr)));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askDeviceType())
    {
        //m_ui->table_Dev->setItem(pos, TableDevType, new QTableWidgetItem(dmxrdm->DeviceInfo.DeviceName));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askThreshold())
    {
        //m_ui->table_Dev->setItem(pos, TableMinH, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.MinLevel)));
        //m_ui->table_Dev->setItem(pos, TableMaxH, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.MaxLevel)));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askFwV())
    {
        //m_ui->table_Dev->setItem(pos, TableFwV, new QTableWidgetItem(dmxrdm->DeviceInfo.FwVName));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askSEQAddress())
    {

    }
    if(dmxrdm->askEPROM())
    {

    }
    listDevice.append(dmxrdm->DeviceInfo);
    DEBUG(dmxrdm->DeviceInfo.sUID);
    SetNextRow(dmxrdm->DeviceInfo, Qt::white);
    //m_ui->table_Dev->setItem(pos, TableDMXAdd, new QTableWidgetItem("1"));
    //m_ui->table_Dev->setItem(pos, TableDevType, new QTableWidgetItem("pump"));
    //m_ui->table_Dev->setItem(pos, TableFwV, new QTableWidgetItem("v3.0"));
}

void MainWindow::writeEEprom(DeviceInfo dev, quint16 row)
{
    m_ui->table_Dev->selectRow(row);
    dmxrdm->setUID(dev.sUID);
    dmxrdm->writeEEprom(dev.EEprom);
    dmxrdm->delay(5000);
    //bool check = true;
    if(dmxrdm->askEPROM())
    {
        for(int i = 0; i < 10; i++)
        {
            if(dev.EEprom[i] == dmxrdm->DeviceInfo.EEprom[i])
            {
                //check = false;
                SetCell(EEprom0 + i, row, dev.EEprom[i], Qt::white);
            }
            else {
                SetCell(EEprom0 + i, row, dev.EEprom[i], Qt::red);
            }
        }
    }
}

void MainWindow::writeDMXAdd(DeviceInfo dev, quint16 row)
{
    m_ui->table_Dev->selectRow(row);
    dmxrdm->setUID(dev.sUID);
    dmxrdm->setDMXID(dev.DMXAddr);
    dmxrdm->delay(5000);
    if(dmxrdm->askDMXAdd())
    {
        if(dmxrdm->DeviceInfo.DMXAddr == dev.DMXAddr)
        {
            SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::white);
        }
        else {
            SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::red);
        }
    }
    else {
        SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::red);
    }
}

void MainWindow::writeLever(DeviceInfo dev, quint16 row)
{
    m_ui->table_Dev->selectRow(row);
    dmxrdm->setUID(dev.sUID);
    dmxrdm->setLever(dev.MaxLevel, dev.MinLevel);
    dmxrdm->delay(5000);
    if(dmxrdm->askThreshold())
    {
        if(dmxrdm->DeviceInfo.MaxLevel == dev.MaxLevel && dmxrdm->DeviceInfo.MinLevel == dev.MinLevel)
        {
            SetCell(TableMaxH, row, dev.MaxLevel, Qt::white);
            SetCell(TableMinH, row, dev.MinLevel, Qt::white);
        }
        else {
            SetCell(TableMaxH, row, dev.MaxLevel, Qt::red);
            SetCell(TableMinH, row, dev.MinLevel, Qt::red);
        }
    }
    else {
        SetCell(TableMaxH, row, dev.MaxLevel, Qt::red);
        SetCell(TableMinH, row, dev.MinLevel, Qt::red);
    }
}

void MainWindow::scan_dev()
{


    listDevice.clear();
    setbeginTable();
    uid_scaner.resize(6);
    memset(uid_count, 255, 6);
    //int row_count = m_ui->table_Dev->rowCount();
    //m_ui->table_Dev->removeRow(0);
    //for(int i = 0; i < row_count; i++)
    //{
        //m_ui->table_Dev->removeRow(i);
    //}
    //m_ui->table_Dev->clear();
    m_ui->bt_scan->setEnabled(false);
    m_ui->actionScan->setEnabled(false);
    QStringList table_title;
    //table_title <<"UID" << "DMX Address" << "Device type" << "Max Height" << "Min Height" << "Firmware version";
    //m_ui->table_Dev->setHorizontalHeaderLabels(table_title);
    memset(_devfind, false, 6);
    _pos_Dev_count = 0;
    _ch_scan = true;
    //timer_scanDev->start(50);
    if(IsUSARTAvailable == false)
    {
        openSerialPort();
    }
    else {
        for(uid_count[0] = 0; uid_count[0] < 255; uid_count[0]++)
        {
            memset(uid_count+1, 255, 5);
            _setScan();
            dmxrdm->delay(1);
            if(dmxrdm->scanDevCheck())
            {
                for(uid_count[1] = 0; uid_count[1] < 255; uid_count[1]++)
                {
                    _setScan();
                    dmxrdm->delay(1);
                    if(dmxrdm->scanDevCheck() || uid_count[1] == 0)
                    {
                        for(uid_count[2] = 0; uid_count[2] < 255; uid_count[2]++)
                        {
                            _setScan();
                            dmxrdm->delay(1);
                            if(dmxrdm->scanDevCheck() || uid_count[2] == 0)
                            {
                                for(uid_count[3] = 0; uid_count[3] < 255; uid_count[3]++)
                                {
                                    _setScan();
                                    dmxrdm->delay(1);
                                    if(dmxrdm->scanDevCheck() || uid_count[3] == 0)
                                    {
                                        for(uid_count[4] = 0; uid_count[4] < 255; uid_count[4]++)
                                        {
                                            _setScan();
                                            dmxrdm->delay(1);
                                            if(dmxrdm->scanDevCheck())
                                            {
                                                for(uid_count[5] = 0; uid_count[5] < 255; uid_count[5]++)
                                                {
                                                    //_setScan();
                                                    memcpy(uid_scaner.data(), uid_count, 6);
                                                    class UID uid(uid_scaner);
                                                    dmxrdm->setUID(uid.toString());
                                                    showStatusMessage("Scanning " + uid.toString());
                                                    SetStT("Scanning " + uid.toString());
                                                    //if(dmxrdm->scanDevCheck())
                                                    if(dmxrdm->RDMPing())
                                                    {
                                                        set_table();
                                                        //_ch_scan = false;
                                                    }
                                                    if(_ch_scan == false)
                                                    {
                                                        if(_exit == true)
                                                        {
                                                            qApp->quit();
                                                        }
                                                        break;
                                                    }

                                                }
                                            }
                                            if(_ch_scan == false)
                                            {
                                                if(_exit == true)
                                                {
                                                    qApp->quit();
                                                }
                                                break;
                                            }
                                        }
                                    }
                                    if(_ch_scan == false)
                                    {
                                        if(_exit == true)
                                        {
                                            qApp->quit();
                                        }
                                        break;
                                    }
                                }
                            }
                            if(_ch_scan == false)
                            {
                                if(_exit == true)
                                {
                                    qApp->quit();
                                }
                                break;
                            }
                        }
                    }
                    if(_ch_scan == false)
                    {
                        if(_exit == true)
                        {
                            qApp->quit();
                        }
                        break;
                    }
                }
            }
            if(_ch_scan == false)
            {
                if(_exit == true)
                {
                    qApp->quit();
                }
                break;
            }
        }
    }

    m_ui->bt_scan->setEnabled(true);
    m_ui->actionScan->setEnabled(true);
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionClear, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::_setScan()
{
    memcpy(uid_scaner.data(), uid_count, 6);
    class UID uid(uid_scaner);
    dmxrdm->setUID(uid.toString());

    dmxrdm->scanDev();
    dmxrdm->delay(30);
    if(!dmxrdm->scanDevCheck())
    {
        dmxrdm->scanDev();
        dmxrdm->delay(10);
    }
    if(!dmxrdm->scanDevCheck())
    {
        dmxrdm->delay(10);
        dmxrdm->scanDev();
    }

    showStatusMessage("Scanning " + uid.toString());
    SetStT("Scanning " + uid.toString());



}

void MainWindow::setbeginTable()
{
    Row_Counter = 0;
    model->clear();
    if(dmxrdm->isAdmin())
    {
        if(language == English)
        {
            for (int i = 0; i < NumberOfTableCollum; i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
            }
        }
        else if (language == Chinese) {
            for (int i = 0; i < NumberOfTableCollum; i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndexCH[i]));
            }
        }

    }
    else {
        if(language == English)
        {
            for (int i = 0; i < TableMaxH; i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
            }
        }
        else if (language == Chinese) {
            for (int i = 0; i < TableMaxH; i++) {
                model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndexCH[i]));
            }
        }
    }
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::SetCell(quint16 x, quint16 y, QString data, QColor color)
{
    QStandardItem *row = new QStandardItem(data);
    row->setBackground(color);
    model->setItem(y,x,row);
}

void MainWindow::SetCell(quint16 x, quint16 y, quint32 data, QColor color)
{
    QStandardItem  *row = new QStandardItem ();//QString::number(data,10));
    QVariant t(data);
    row->setData(t, Qt::EditRole);
    //row->setForeground(color);
    row->setBackground(color);
    model->setItem(y,x,row);
}

QString MainWindow::GetCell(quint16 x, quint16 y)
{
    QStandardItem *row;
    row = model->item(y,x);
    return row->text();
}

QString MainWindow::GetCell(QModelIndex index)
{
    QStandardItem *row;
    row = model->item(index.row(), index.column());
    return row->text();
}

void MainWindow::SetNextRow(DeviceInfo devInfo, QColor color)
{
    SetCell(TableUID, Row_Counter, devInfo.sUID, color);
    SetCell(TableDMXAdd, Row_Counter, devInfo.DMXAddr, color);
    SetCell(TableDevType, Row_Counter, devInfo.DeviceName, color);
    SetCell(TableFwV, Row_Counter, devInfo.GetFirmwareName(devInfo.FWVersion), color);
    SetCell(TablePos, Row_Counter, devInfo.SEQAddr, color);
    //SetCell(TableEEPROM, Row_Counter, devInfo.sEEprom(), color);
    if(dmxrdm->isAdmin())
    {
        SetCell(TableMaxH, Row_Counter, devInfo.MaxLevel, color);
        SetCell(TableMinH, Row_Counter, devInfo.MinLevel, color);
        for(int i = 0; i < 10; i++)
        {
            SetCell(EEprom0 + i, Row_Counter, devInfo.EEprom[i], color);
        }
    }


    Row_Counter++;
}

void MainWindow::SetRow(DeviceInfo devInfo, quint16 row, QColor color)
{
    SetCell(TableUID, row, devInfo.sUID, color);
    SetCell(TableDMXAdd, row, devInfo.DMXAddr, color);
    SetCell(TableDevType, row, devInfo.DeviceName, color);
    SetCell(TableFwV, row, devInfo.GetFirmwareName(devInfo.FWVersion), color);
    SetCell(TablePos, row, devInfo.SEQAddr, color);
    //SetCell(TableEEPROM, Row_Counter, devInfo.sEEprom(), color);
    if(dmxrdm->isAdmin())
    {
        SetCell(TableMaxH, row, devInfo.MaxLevel, color);
        SetCell(TableMinH, row, devInfo.MinLevel, color);
        for(int i = 0; i < 10; i++)
        {
            SetCell(EEprom0 + i, row, devInfo.EEprom[i], color);
        }
    }

}

void MainWindow::SetStT(QString s)
{
    m_ui->lb_Dev->setText(s);
}

void MainWindow::setLanguage(MainWindow::LANGUAGE lg)
{
    language = lg;
    setbeginTable();
    if(lg == English)
    {
        this->setWindowTitle(LG_EN[AGDeviceManager]);
        m_ui->lb_max->setText(LG_EN[MaxHeight]);
        m_ui->lb_min->setText(LG_EN[MinHeight]);
        m_ui->actionConnect->setText(LG_EN[Connect]);
        m_ui->actionDisconnect->setText(LG_EN[Disconnect]);
        m_ui->actionConfigure->setText(LG_EN[Configure]);
        m_ui->gr_devtype->setTitle(LG_EN[Devicestype]);
        m_ui->lb_pos->setText(LG_EN[Position]);
        m_ui->lb_DMXID->setText(LG_EN[DMXAddress]);
        m_ui->bt_Ping->setText(LG_EN[Ping]);
        m_ui->radioButtonALL->setText(LG_EN[All]);
        m_ui->radioButtonLED->setText(LG_EN[LED]);
        m_ui->radioButtonPump->setText(LG_EN[Pump]);
        m_ui->radioButtonOthers->setText(LG_EN[Others]);
        m_ui->bt_scan->setText(LG_EN[Scan]);
        m_ui->bt_stop->setText(LG_EN[Stop]);
        m_ui->BT_Read->setText(LG_EN[Read]);
        m_ui->BT_Write->setText(LG_EN[Write]);
        m_ui->bt_WriteDMXID->setText(LG_EN[WriteDMXAddress]);
        m_ui->bt_WriteLever->setText(LG_EN[WriteLevel]);
        m_ui->actionAbout->setText(LG_EN[About]);
        m_ui->actionClear->setText(LG_EN[Clean]);
    }
    if(lg == Chinese)
    {
        this->setWindowTitle(LG_CH[AGDeviceManager]);
        m_ui->lb_max->setText(LG_CH[MaxHeight]);
        m_ui->lb_min->setText(LG_CH[MinHeight]);
        m_ui->actionConnect->setText(LG_CH[Connect]);
        m_ui->actionDisconnect->setText(LG_CH[Disconnect]);
        m_ui->actionConfigure->setText(LG_CH[Configure]);
        m_ui->gr_devtype->setTitle(LG_CH[Devicestype]);
        m_ui->lb_pos->setText(LG_CH[Position]);
        m_ui->lb_DMXID->setText(LG_CH[DMXAddress]);
        m_ui->bt_Ping->setText(LG_CH[Ping]);
        m_ui->radioButtonALL->setText(LG_CH[All]);
        m_ui->radioButtonLED->setText(LG_CH[LED]);
        m_ui->radioButtonPump->setText(LG_CH[Pump]);
        m_ui->radioButtonOthers->setText(LG_CH[Others]);
        m_ui->bt_scan->setText(LG_CH[Scan]);
        m_ui->bt_stop->setText(LG_CH[Stop]);
        m_ui->BT_Read->setText(LG_CH[Read]);
        m_ui->BT_Write->setText(LG_CH[Write]);
        m_ui->bt_WriteDMXID->setText(LG_CH[WriteDMXAddress]);
        m_ui->bt_WriteLever->setText(LG_CH[WriteLevel]);
        m_ui->actionAbout->setText(LG_CH[About]);
        m_ui->actionClear->setText(LG_CH[Clean]);
    }
}

void MainWindow::setLanguageEnglish()
{
    setLanguage(English);
}

void MainWindow::setLanguageChina()
{
    setLanguage(Chinese);
}

void MainWindow::on_table_Dev_clicked(const QModelIndex &index)
{

        //DEBUG(QString::number(index.row()));
    SelectRow= index.row();
    m_ui->table_Dev->selectRow(index.row());
    m_ui->txt_Pos->setText(GetCell(TablePos, index.row()));
    m_ui->txt_UID->setText(GetCell(TableUID, index.row()));
    m_ui->txt_DMXID->setText(GetCell(TableDMXAdd, index.row()));
    SetStT(GetCell(TableDevType, index.row()));
    if(dmxrdm->isAdmin())
    {
        m_ui->txt_MAXH->setText(GetCell(TableMaxH, index.row()));
        m_ui->txt_MINH->setText(GetCell(TableMinH, index.row()));
    }

        //DEBUG(listDevice.at(index.row()).sUID);
        //DEBUG("dev: " + QString::number(listDevice.at(index.row()).DeviceType));
        //DEBUG("PUMP DC " + QString::number(DeviceInfo::DC_PUMP));
}

void MainWindow::RadioBt_Clicked()
{
    setbeginTable();
    if(m_ui->radioButtonALL->isChecked())
    {
        findDev = Find_Dev_All;
        SetStT(tr("Find all device!"));
        for(int i = 0; i < listDevice.size(); i++)
        {
            SetNextRow(listDevice.at(i), Qt::white);
        }
    }
    else if (m_ui->radioButtonLED->isChecked()) {
        findDev = Find_Dev_LED;
        SetStT(tr("Find all LED device!"));
        for(int i = 0; i < listDevice.size(); i++)
        {
            if(listDevice.at(i).DeviceType == DeviceInfo::LIGHT_RGB||
                listDevice.at(i).DeviceType == DeviceInfo::LIGHT_RGBW||
                listDevice.at(i).DeviceType == DeviceInfo::LIGHT_RGBWA)
            {
                //continue;
                SetNextRow(listDevice.at(i), Qt::white);
            }

        }
    }
    else if (m_ui->radioButtonOthers->isChecked()) {
        findDev = Find_Dev_Others;
        SetStT(tr("Find all Other device!"));
    }
    else if (m_ui->radioButtonPump->isChecked()) {
        findDev = Find_Dev_Pump;
        SetStT(tr("Find all pump device!"));
        for(int i = 0; i < listDevice.size(); i++)
        {
            DEBUG("dev: " + QString::number(listDevice.at(i).DeviceType));
            if(listDevice.at(i).DeviceType == DeviceInfo::DC_PUMP)
            {
                SetNextRow(listDevice.at(i), Qt::white);
            }
        }
    }
    //SetTable();
}

void MainWindow::Bt_WriteDMXAdd()
{
    stopScan();
    QString sDMXID = m_ui->txt_DMXID->text();
    loadinfdialog->showDialog();
    dmxrdm->delay(10);
    m_ui->table_Dev->selectRow(SelectRow);
    DeviceInfo dev = listDevice.at(SelectRow);
    dmxrdm->setUID(dev.sUID);
    dmxrdm->setDMXID(dev.DMXAddr);
    SetStT(tr("Writing DMX Address..."));
    dmxrdm->delay(1000);
    SetStT(tr("Waitting device reset..."));
    dmxrdm->delay(4000);
    SetStT(tr("Reading DMX Address..."));
    if(dmxrdm->askDMXAdd())
    {
        if(dmxrdm->DeviceInfo.DMXAddr == dev.DMXAddr)
        {
            SetCell(TableDMXAdd, SelectRow, dev.DMXAddr, Qt::white);
            SetStT(tr("Done!"));
            QMessageBox::information(this, "Done", "Write DMX Address done!");
        }
        else {
            SetCell(TableDMXAdd, SelectRow, dev.DMXAddr, Qt::red);
            SetStT(tr("EEROR write DMXAddres..."));
            QMessageBox::information(this, "ERROR", "Write DMX Address ERROR!");
        }
    }
    else {
        SetCell(TableDMXAdd, SelectRow, dev.DMXAddr, Qt::red);
        SetStT(tr("EEROR write DMXAddres..."));
        QMessageBox::information(this, "ERROR", "Write DMX Address ERROR!");
    }
    dmxrdm->delay(1000);
    loadinfdialog->hideDialog();
}

void MainWindow::Bt_Update_Fw()
{
    stopScan();
    dmxrdm->setUID(m_ui->txt_UID->text().trimmed());
    loadinfdialog->showDialog();
    if(dmxrdm->RDMPing())
    {
        dmxrdm->delay(500);
        dmxrdm->updateFirmware();
        SetStT("Update Firmware!");
    }
    else {
        SetStT("Device not found!");
        QMessageBox::critical(this, tr("ERROR"), tr("Device not found!"));
    }
    loadinfdialog->hideDialog();
}

void MainWindow::setBaudRate(qint32 br)
{
    closeSerialPort();
    SettingsDialog::Settings p = m_settings->settings();
    p.baudRate = br;
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        m_console->setEnabled(true);
        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                              .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                              .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
        showStatusMessage(tr("Open error"));
    }
}


void MainWindow::on_table_Dev_activated(const QModelIndex &index)
{
    DEBUG(QString::number(index.row()));
    DEBUG(QString::number(index.column()));
}

void MainWindow::on_table_Dev_entered(const QModelIndex &index)
{
    DEBUG(QString::number(index.row()));
    DEBUG(QString::number(index.column()));

}

void MainWindow::on_table_Dev_pressed(const QModelIndex &index)
{
    DEBUG(QString::number(index.row()));
    DEBUG(QString::number(index.column()));
}

void MainWindow::on_table_Dev_viewportEntered()
{
    DEBUG("QString::number(index.row())");
    DEBUG("QString::number(index.column())");
}

void MainWindow::Bt_DMXStream()
{
    dmxrdm->askEPROM();
    DEBUG(dmxrdm->DeviceInfo.sEEprom());
}

void MainWindow::TimerEdit()
{
    QString s;
    DeviceInfo dev;
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    if(selectList.count())
    {
        for(quint16 i = 0; i < Row_Counter; i++)
        {
            dev = listDevice.at(i);
            s = GetCell(TableDMXAdd, i);
            if((quint16)s.toInt() != dev.DMXAddr)
            {
                SetCell(TableDMXAdd, i, (quint16)s.toInt(), Qt::yellow);
                dev.DMXAddr = (quint16)s.toInt();
                m_ui->txt_DMXID->setText(s);
            }


            //s = GetCell(TableEEPROM, i);
            //if(s != dev.sEEprom())
            //{
            //    SetCell(TableEEPROM, i, s, Qt::yellow);
            //    //dev. = s;
            //}
            if(dmxrdm->isAdmin())
            {
                s = GetCell(TableMaxH, i);
                if((quint8)s.toInt() != dev.MaxLevel)
                {
                    SetCell(TableMaxH, i, (quint8)s.toInt(), Qt::yellow);
                    dev.MaxLevel = (quint8)s.toInt();
                    m_ui->txt_MAXH->setText(s);
                }
                s = GetCell(TableMinH, i);
                if((quint8)s.toInt() != dev.MinLevel)
                {
                    SetCell(TableMinH, i, (quint8)s.toInt(), Qt::yellow);
                    dev.MinLevel = (quint8)s.toInt();
                    m_ui->txt_MINH->setText(s);
                }
                for(int j = 0; j < 10; j++)
                {
                    s = GetCell(EEprom0 + j, i);
                    if(s.toInt() != dev.EEprom[j])
                    {
                        SetCell(EEprom0 + j, i, (quint8)s.toInt(), Qt::yellow);
                        dev.EEprom[j] = (char)s.toInt();
                    }
                }
            }

            if(SelectRow < 513)
            {

            }
            listDevice.removeAt(i);
            listDevice.insert(i, dev);
        }
    }
}

void MainWindow::EditTextDMXAddr()
{
    DeviceInfo dev = listDevice.at(SelectRow);
    QString s = m_ui->txt_DMXID->text().trimmed();
    if((quint16)s.toInt() != dev.DMXAddr)
    {
        dev.DMXAddr = (quint16)s.toInt();
        SetCell(TableDMXAdd, SelectRow, (quint16)s.toInt(), Qt::yellow);
    }

    listDevice.removeAt(SelectRow);
    listDevice.insert(SelectRow, dev);
}

void MainWindow::EditTextMAXH()
{
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    if(selectList.count())
    {
        DeviceInfo dev = listDevice.at(SelectRow);
        QString s = m_ui->txt_MAXH->text().trimmed();
        if((quint8)s.toInt() != dev.MaxLevel)
        {
            dev.MaxLevel = (quint8)s.toInt();
            SetCell(TableMaxH, SelectRow, (quint8)s.toInt(), Qt::yellow);
        }
        listDevice.removeAt(SelectRow);
        listDevice.insert(SelectRow, dev);
    }

}

void MainWindow::EditTextMINH()
{
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    if(selectList.count())
    {
        DeviceInfo dev = listDevice.at(SelectRow);
        QString s = m_ui->txt_MINH->text().trimmed();
        if((quint8)s.toInt() != dev.MinLevel)
        {
            dev.MinLevel = (quint8)s.toInt();
            SetCell(TableMinH, SelectRow, (quint8)s.toInt(), Qt::yellow);
        }
        listDevice.removeAt(SelectRow);
        listDevice.insert(SelectRow, dev);
    }

}

void MainWindow::BT_WriteAll()
{
    DeviceInfo dev;

    for(quint16 i = 0; i < Row_Counter; i ++)
    {
        dev = listDevice.at(i);
        Write1Device(dev, i);
    }
}

void MainWindow::Write1Device(DeviceInfo dev, quint16 row)
{
    stopScan();
    //loadinfdialog->showDialog();
    m_ui->table_Dev->selectRow(row);
    dmxrdm->setUID(dev.sUID);
    dmxrdm->setDMXID(dev.DMXAddr);
    SetStT(tr("Writing DMX Address..."));
    dmxrdm->delay(1000);
    SetStT(tr("Waitting device reset..."));
    dmxrdm->delay(4000);
    SetStT(tr("Reading DMX Address..."));
    if(dmxrdm->askDMXAdd())
    {
        if(dmxrdm->DeviceInfo.DMXAddr == dev.DMXAddr)
        {
            SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::white);
            SetStT(tr("Writed DMXAddres..."));
        }
        else {
            SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::red);
            SetStT(tr("EEROR write DMXAddres..."));
        }
    }
    else {
        SetCell(TableDMXAdd, row, dev.DMXAddr, Qt::red);
        SetStT(tr("EEROR write DMXAddres..."));
    }

    if(dmxrdm->isAdmin())
    {
        dmxrdm->setDMXID(dev.DMXAddr);
        dmxrdm->delay(100);
        dmxrdm->setLever(dev.MaxLevel, dev.MinLevel);
        SetStT(tr("Writing Lever..."));
        dmxrdm->delay(3000);
        SetStT(tr("Waitting device reset..."));
        dmxrdm->delay(2000);
        SetStT(tr("Reading Lever..."));
        if(dmxrdm->askThreshold())
        {
            if(dmxrdm->DeviceInfo.MaxLevel == dev.MaxLevel && dmxrdm->DeviceInfo.MinLevel == dev.MinLevel)
            {
                SetCell(TableMaxH, row, dev.MaxLevel, Qt::white);
                SetCell(TableMinH, row, dev.MinLevel, Qt::white);
                SetStT(tr("Writed lever!"));
            }
            else {
                SetCell(TableMaxH, row, dev.MaxLevel, Qt::red);
                SetCell(TableMinH, row, dev.MinLevel, Qt::red);
                SetStT(tr("EEROR write lever!"));
            }
        }
        else {
            SetCell(TableMaxH, row, dev.MaxLevel, Qt::red);
            SetCell(TableMinH, row, dev.MinLevel, Qt::red);
            SetStT(tr("EEROR write lever!"));
        }

        dmxrdm->delay(100);
        dmxrdm->writeEEprom(dev.EEprom);
        SetStT(tr("Writing EEPROM..."));
        dmxrdm->delay(3000);
        SetStT(tr("Waitting device reset..."));
        dmxrdm->delay(2000);
        SetStT(tr("Reading EEPROM..."));
        //bool check = true;
        if(dmxrdm->askEPROM())
        {
            for(int i = 0; i < 10; i++)
            {
                if(dev.EEprom[i] == dmxrdm->DeviceInfo.EEprom[i])
                {
                    //check = false;
                    SetCell(EEprom0 + i, row, dev.EEprom[i], Qt::white);
                    SetStT(tr("Write EEprom done!"));
                }
                else {
                    SetCell(EEprom0 + i, row, dev.EEprom[i], Qt::red);
                    SetStT(tr("EEROR Write EEprom!"));
                }
            }
        }
    }

    //loadinfdialog->hideDialog();

}

void MainWindow::BT_Write()
{
    stopScan();
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    DeviceInfo dev;
    if(selectList.count()<= 0)
    {
        m_ui->table_Dev->selectAll();
        selectList = m_ui->table_Dev->selectionModel()->selectedRows();
        if(selectList.count() <= 0)
        {
            QMessageBox::information(this, tr("Write device"), tr("No device selected!"));
            return;
        }
    }
    loadinfdialog->showDialog();
    m_ui->BT_Write->setEnabled(false);

    foreach (QModelIndex index, selectList) {
        DEBUG(QString::number(index.row()));
            dev = listDevice.at(index.row());
            //this->SetRow(dev, index.row(), Qt::green);
            this->Write1Device(dev, index.row());
            //this->SetRow(dev, index.row(), Qt::white);

    }
    m_ui->BT_Write->setEnabled(true);
    loadinfdialog->hideDialog();
    /*
    if(Row_Counter)
    {
        DeviceInfo dev = listDevice.at(SelectRow);
        Write1Device(dev, SelectRow);
    }*/
}

void MainWindow::Read1Device(DeviceInfo dev, quint16 row)
{
    stopScan();
    dmxrdm->setUID(dev.sUID);
    if(dmxrdm->RDMPing())
    {
        //m_ui->table_Dev->insertRow(m_ui->table_Dev->rowCount());
        //m_ui->table_Dev->setItem(pos, TableUID, new QTableWidgetItem(dmxrdm->DeviceInfo.sUID));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askDMXAdd())
    {
        //DEBUG(QString::number(dmxrdm->DeviceInfo.DMXAddr));
        //m_ui->table_Dev->setItem(pos, TableDMXAdd, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.DMXAddr)));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askDeviceType())
    {
        //m_ui->table_Dev->setItem(pos, TableDevType, new QTableWidgetItem(dmxrdm->DeviceInfo.DeviceName));
    }

    dmxrdm->delay(10);
    if(dmxrdm->askFwV())
    {
        //m_ui->table_Dev->setItem(pos, TableFwV, new QTableWidgetItem(dmxrdm->DeviceInfo.FwVName));
    }
    dmxrdm->delay(10);
    if(dmxrdm->askSEQAddress())
    {

    }
    if(dmxrdm->isAdmin())
    {
        dmxrdm->delay(10);
        if(dmxrdm->askThreshold())
        {
            //m_ui->table_Dev->setItem(pos, TableMinH, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.MinLevel)));
            //m_ui->table_Dev->setItem(pos, TableMaxH, new QTableWidgetItem(QString::number(dmxrdm->DeviceInfo.MaxLevel)));
        }
        if(dmxrdm->askEPROM())
        {

        }
    }

    listDevice.removeAt(row);
    listDevice.insert(row, dmxrdm->DeviceInfo);
    SetRow(dmxrdm->DeviceInfo, row, Qt::white);
    //listDevice.append(dmxrdm->DeviceInfo);
    //DEBUG(dmxrdm->DeviceInfo.sUID);
    //SetNextRow(dmxrdm->DeviceInfo, Qt::white);
}

void MainWindow::BT_Read()
{
    stopScan();
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    DeviceInfo dev;
    if(selectList.count()<= 0)
    {
        m_ui->table_Dev->selectAll();
        selectList = m_ui->table_Dev->selectionModel()->selectedRows();
        if(selectList.count() <= 0)
        {
            QMessageBox::information(this, tr("Write device"), tr("No device selected!"));
            return;
        }
    }
    loadinfdialog->showDialog();
    m_ui->BT_Read->setEnabled(false);
    foreach (QModelIndex index, selectList) {
        DEBUG(QString::number(index.row()));
        if(index.row() < Row_Counter)
        {
            dev = listDevice.at(index.row());
            this->Read1Device(dev, (quint16)index.row());
        }
    }
    m_ui->BT_Read->setEnabled(true);
    loadinfdialog->hideDialog();
}

void MainWindow::_DMXStream()
{
    //this->writeBreak();
    stopScan();
    this->writeData(dmx->DMXBuffer);
}

void MainWindow::actionUser()
{
    stopScan();
    bool ok;
    QString sPW;

    sPW = QInputDialog::getText(this, tr("Enter user password"),
                                tr("Password"), QLineEdit::Password,
                                "", &ok);
    if(ok)
    {
        //dmxrdm->SetAdministratorUser(sPW);
        DEBUG(sPW);
        dmxrdm->setAdmin(sPW);
    }
}

void MainWindow::writeUID()
{
    stopScan();
    QString getNewUID;
    bool ok;

    dmxrdm->setUID(m_ui->txt_UID->text().trimmed());
    getNewUID = QInputDialog::getText(this, tr("Enter new UID"),
                                      tr("New UID:"), QLineEdit::Normal,
                                      dmxrdm->DeviceInfo.sUID, &ok);
    loadinfdialog->showDialog();
    if(ok)
    {
        dmxrdm->setDMXUID(getNewUID.trimmed());
        DEBUG(getNewUID);
        dmxrdm->delay(5000);
        dmxrdm->setUID(getNewUID);
        if(dmxrdm->RDMPing())
        {
            QMessageBox::information(this, "Done", "Write UID done!");
        }
        else {
            QMessageBox::critical(this, "ERROR", "Write UID fail!");
        }
    }
    loadinfdialog->hideDialog();
}

void MainWindow::SetUiAdmin(bool user)
{
    stopScan();
    if(!user)
    {
        m_ui->txt_UID->setVisible(true);
        m_ui->txt_MINH->setVisible(false);
        m_ui->txt_MAXH->setVisible(false);
        m_ui->txt_Pos->setVisible(true);
        m_ui->txt_DMXID->setVisible(true);
        m_ui->BT_WriteEEprom->setVisible(false);
        m_ui->bt_DMX->setVisible(true);
        m_ui->bt_Ping->setVisible(true);
        m_ui->bt_scan->setVisible(true);
        m_ui->bt_stop->setVisible(true);
        m_ui->bt_stop->setVisible(true);
        m_ui->BT_WriteEEprom->setVisible(false);
        m_ui->BT_WriteDMXAddr->setVisible(false);
        m_ui->lb_max->setVisible(false);
        m_ui->lb_min->setVisible(false);
        m_ui->bt_WriteLever->setVisible(false);
        m_ui->BT_WriteUID->setVisible(false);
        m_ui->pushButton->setVisible(false);
    }
    else {
        m_ui->txt_UID->setVisible(true);
        m_ui->txt_MINH->setVisible(true);
        m_ui->txt_MAXH->setVisible(true);
        m_ui->txt_Pos->setVisible(true);
        m_ui->txt_DMXID->setVisible(true);
        m_ui->BT_WriteEEprom->setVisible(true);
        m_ui->bt_DMX->setVisible(true);
        m_ui->bt_Ping->setVisible(true);
        m_ui->bt_scan->setVisible(true);
        m_ui->bt_stop->setVisible(true);
        m_ui->bt_stop->setVisible(true);
        m_ui->BT_WriteEEprom->setVisible(true);
        m_ui->BT_WriteDMXAddr->setVisible(true);
        m_ui->lb_max->setVisible(true);
        m_ui->lb_min->setVisible(true);
        m_ui->bt_WriteLever->setVisible(true);
        m_ui->BT_WriteUID->setVisible(true);
        m_ui->pushButton->setVisible(true);
        setbeginTable();
    }

}

void MainWindow::ledRGB_old()
{
    stopScan();
    ledrgbold->show();
}



void MainWindow::on_BT_WriteDMXAddr_clicked()
{
    stopScan();
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    DeviceInfo dev;
    if(selectList.count()<= 0)
    {
        m_ui->table_Dev->selectAll();
        selectList = m_ui->table_Dev->selectionModel()->selectedRows();
        if(selectList.count() <= 0)
        {
            QMessageBox::information(this, tr("Write device"), tr("No device selected!"));
            return;
        }
    }
    loadinfdialog->showDialog();
    m_ui->BT_Write->setEnabled(false);

    foreach (QModelIndex index, selectList) {
        DEBUG(QString::number(index.row()));
            dev = listDevice.at(index.row());
            //this->SetRow(dev, index.row(), Qt::green);
            //this->Write1Device(dev, index.row());
            //this->SetRow(dev, index.row(), Qt::white);
            m_ui->table_Dev->selectRow(index.row());
            dmxrdm->setUID(dev.sUID);
            dmxrdm->setDMXID(dev.DMXAddr);
            SetStT(tr("Writing DMX Address..."));
            dmxrdm->delay(3000);
            SetStT(tr("Waitting device reset..."));
            dmxrdm->delay(2000);
            SetStT(tr("Reading DMX Address..."));
            if(dmxrdm->askDMXAdd())
            {
                if(dmxrdm->DeviceInfo.DMXAddr == dev.DMXAddr)
                {
                    SetCell(TableDMXAdd, index.row(), dev.DMXAddr, Qt::white);
                    SetStT(tr("Writed DMXAddres..."));
                }
                else {
                    SetCell(TableDMXAdd, index.row(), dev.DMXAddr, Qt::red);
                    SetStT(tr("EEROR write DMXAddres..."));
                }
            }
            else {
                SetCell(TableDMXAdd, index.row(), dev.DMXAddr, Qt::red);
                SetStT(tr("EEROR write DMXAddres..."));
            }
    }
    m_ui->BT_Write->setEnabled(true);
    loadinfdialog->hideDialog();
}

void MainWindow::on_BT_WriteEEprom_clicked()
{
    stopScan();
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    DeviceInfo dev;
    if(selectList.count()<= 0)
    {
        m_ui->table_Dev->selectAll();
        selectList = m_ui->table_Dev->selectionModel()->selectedRows();
        if(selectList.count() <= 0)
        {
            QMessageBox::information(this, tr("Write device"), tr("No device selected!"));
            return;
        }
    }
    loadinfdialog->showDialog();
    m_ui->BT_WriteEEprom->setEnabled(false);

    foreach (QModelIndex index, selectList) {
        DEBUG(QString::number(index.row()));
        dev = listDevice.at(index.row());
        //this->SetRow(dev, index.row(), Qt::green);
        //this->Write1Device(dev, index.row());
        //this->SetRow(dev, index.row(), Qt::white);
        m_ui->table_Dev->selectRow(index.row());
        dmxrdm->setUID(dev.sUID);
        dmxrdm->writeEEprom(dev.EEprom);
        SetStT(tr("Writing EEPROM..."));
        dmxrdm->delay(3000);
        SetStT(tr("Waitting device reset..."));
        dmxrdm->delay(2000);
        SetStT(tr("Reading EEPROM..."));
        //bool check = true;
        if(dmxrdm->askEPROM())
        {
            m_ui->table_Dev->selectRow(index.row());
            dmxrdm->setUID(dev.sUID);
            dmxrdm->setDMXID(dev.DMXAddr);
            for(int i = 0; i < 10; i++)
            {
                if(dev.EEprom[i] == dmxrdm->DeviceInfo.EEprom[i])
                {
                    //check = false;
                    SetCell(EEprom0 + i, index.row(), dev.EEprom[i], Qt::white);
                    SetStT(tr("Write EEprom done!"));
                }
                else {
                    SetCell(EEprom0 + i, index.row(), dev.EEprom[i], Qt::red);
                    SetStT(tr("EEROR Write EEprom!"));
                }
            }
        }
    }
    m_ui->BT_WriteEEprom->setEnabled(true);
    loadinfdialog->hideDialog();
}

void MainWindow::on_pushButton_clicked()
{
    stopScan();
    QModelIndexList selectList = m_ui->table_Dev->selectionModel()->selectedRows();
    DeviceInfo dev;
    if(selectList.count()<= 0)
    {
        m_ui->table_Dev->selectAll();
        selectList = m_ui->table_Dev->selectionModel()->selectedRows();
        if(selectList.count() <= 0)
        {
            QMessageBox::information(this, tr("Write device"), tr("No device selected!"));
            return;
        }
    }
    loadinfdialog->showDialog();
    m_ui->pushButton->setEnabled(false);

    foreach (QModelIndex index, selectList) {
        DEBUG(QString::number(index.row()));
        dev = listDevice.at(index.row());
        m_ui->table_Dev->selectRow(index.row());
        dmxrdm->setUID(dev.sUID);
        dmxrdm->setLever(dev.MaxLevel, dev.MinLevel);
        SetStT(tr("Writing Lever..."));
        dmxrdm->delay(3000);
        SetStT(tr("Waitting device reset..."));
        dmxrdm->delay(2000);
        SetStT(tr("Reading Lever..."));
        if(dmxrdm->askThreshold())
        {
            if(dmxrdm->DeviceInfo.MaxLevel == dev.MaxLevel && dmxrdm->DeviceInfo.MinLevel == dev.MinLevel)
            {
                SetCell(TableMaxH, index.row(), dev.MaxLevel, Qt::white);
                SetCell(TableMinH, index.row(), dev.MinLevel, Qt::white);
                SetStT(tr("Writed lever!"));
            }
            else {
                SetCell(TableMaxH, index.row(), dev.MaxLevel, Qt::red);
                SetCell(TableMinH, index.row(), dev.MinLevel, Qt::red);
                SetStT(tr("EEROR write lever!"));
            }
        }
        else {
            SetCell(TableMaxH, index.row(), dev.MaxLevel, Qt::red);
            SetCell(TableMinH, index.row(), dev.MinLevel, Qt::red);
            SetStT(tr("EEROR write lever!"));
        }
    }
    m_ui->pushButton->setEnabled(true);
    loadinfdialog->hideDialog();
}



#include <QCloseEvent>
void MainWindow::closeEvent (QCloseEvent *event)
{

    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "APP_NAME",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();

    } else {
        DEBUG("ok");
        _exit = true;
        _ch_scan = false;
        event->accept();
    }
}

#include "qtdmxlib.h"

void MainWindow::BT_ADD_onClick()
{
    QString n_uid;
    bool ok;
    n_uid = QInputDialog::getText(this, tr("Enter new UID"),
                                tr("Password"), QLineEdit::Normal,
                                "0:0:0:0:0:0", &ok);
    if(ok)
    {
        //dmxrdm->SetAdministratorUser(sPW);
        DEBUG(n_uid);
        dmxrdm->setUID(n_uid);
        listDevice.append(dmxrdm->DeviceInfo);
        dmxrdm->DeviceInfo.DMXAddr = 0;
        dmxrdm->DeviceInfo.FWVersion = 0;
        dmxrdm->DeviceInfo.SEQAddr = 0;
        SetNextRow(dmxrdm->DeviceInfo, Qt::white);
    }
}

void MainWindow::BT_TesDevice()
{
    QString uid = m_ui->txt_UID->text().trimmed();
    loadinfdialog->showDialog();
    m_ui->BT_TestDevice->setEnabled(false);
    dmxrdm->setUID(uid);
    dmxrdm->delay(10);
    if(!dmxrdm->SetTestMode())
    {
        SetStT("Device not found!");
        QMessageBox::critical(this, tr("ERROR"), tr("Device not found!"));
    }
    loadinfdialog->hideDialog();
    m_ui->BT_TestDevice->setEnabled(true);
}
