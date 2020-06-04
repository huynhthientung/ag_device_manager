#include "qtdmxlib.h"
#include "debug.h"
#include "mainwindow.h"

#include <QEventLoop>
#include <QMessageBox>
#include <QThread>
#include <QTime>
#include <QTimer>

#include <QFileDevice>
#include <QFileDialog>
#include <QUrl>
#include <QDesktopServices>
#include <QProcess>
#include <qdir.h>



qtdmxlib::qtdmxlib()
{

}

DMXRDM::DMXRDM()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_pw()));
    timer->start(1000);
}

void DMXRDM::RDMRecHandler(QByteArray data)
{
    quint16 check_sum = 0;
    quint8 RDM_size;
    QByteArray gUID, data_temp;
    //data_temp.resize(1);
    data_temp[0] = 1;
    /*
    QString _sprint = tr("data rec. Size:\t%1. Data").arg(data.size());
    for(int i = 0; i < data.size(); i++)
    {
        _sprint += tr(" %1").arg((quint8)data[i]);
    }
    DEBUG(_sprint);
*/
    if(rdm_cmd == cmd_Disc && data[0] == (char)0){
        _DevScan = true;
        _isscan = false;
    }

    if((quint8)data[0] == rdm_rq[0] && (quint8)data[1] == rdm_rq[1] && data.size() > 15)
    {
        _isRec = true;
        RDM_size = (quint8) data[0];
        for(int i = 3; i < data.size() - 4; i++)
        {
            check_sum += (quint16) data[i];
        }

        check_sum &= 0x00FF;
        if(rdm_cmd == cmd_Ping)
        {

            gUID.resize(6);
            gUID = data.mid(9, 6);
            UID UID(gUID);
            DeviceInfo.sUID = UID.toString();
            DeviceInfo.bUID = gUID;
        }
        else if(rdm_cmd == cmd_AskDMXSlot)
        {
            quint16 _dmxSlot;
            _dmxSlot = ((((quint16)data[17]<<8)&0xFF00)|(((quint16)data[18])&0x00FF));
            DeviceInfo.DMXAddr = _dmxSlot;

        }
        else if (rdm_cmd == cmd_AskDevType) {

            DeviceInfo.DeviceType = (quint8) data[17];
            DeviceInfo.DeviceName = DeviceInfo.GetDeviceTypeName(DeviceInfo.DeviceType);
            //DEBUG(DeviceInfo.DeviceName);
        }
        else if (rdm_cmd == cmd_AskThreshold){
            quint8 low, high;
            low = (quint8) data[18];
            high = (quint8) data[17];
            DeviceInfo.MaxLevel = high;
            DeviceInfo.MinLevel = low;
        }
        else if (rdm_cmd == cmd_GetFwVersion) {
            DeviceInfo.FWVersion = (quint8) data[17];
            DeviceInfo.FwVName = DeviceInfo.GetFirmwareName(DeviceInfo.FWVersion);
            //DEBUG(DeviceInfo.FwVName);
        }
        else if (rdm_cmd == cmd_GetSEQAddress) {
            quint16 disc = ((((quint16)data[17])<<8)&0xFF00)|(((quint16)data[18])&0x00FF);
            //DEBUG(QString::number(disc));
            DeviceInfo.SEQAddr = (quint16) disc;
        }
        else if (rdm_cmd == cmd_ReadMemory) {

            QString _sprint = tr("data rec. Size:\t%1. Data").arg(data.size());
            for(int i = 0; i < data.size(); i++)
            {
                _sprint += tr(" %1").arg((quint8)data[i]);
            }
            DEBUG(_sprint);

            memcpy(DeviceInfo.EEprom, data.data() + 17, 10);
            _sprint = tr("EEPROM");
            for(int i = 0; i < 10; i++)
            {
                _sprint += tr(" %1").arg((quint8)DeviceInfo.EEprom[i]);
            }
            DEBUG(_sprint);
        }
        else if (rdm_cmd == cmd_SetMode) {
            _isRec = true;
        }

        /*
        check_sum &= 0x00FF;
        if(RDM_size == data.size() - 4 && check_sum + data[data.size() - 1])
        {

            if(rdm_cmd == cmd_Ping)
            {
                gUID.resize(6);
                gUID = data.mid(9, 6);
                UID UID(gUID);
                DeviceInfo.sUID = UID.toString();
                DeviceInfo.bUID = gUID;
                if(!_isscan){
                    emit display_UID(DeviceInfo.sUID);
                    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDMXSlot, data_temp));
                    rdm_cmd = cmd_AskDMXSlot;
                }
                else {
                    DEBUG("find ok");
                    _DevScan = true;
                    _isscan = false;
                }
            }
            else if (rdm_cmd == cmd_AskDMXSlot) {
                int _dmxSlot;
                _dmxSlot = (int)((((quint16)data[17]<<8)&0xFF00)|(((quint16)data[18])&0x00FF));
                //DEBUG(QString::number(_dmxSlot));
                emit display_DMXChannel(QString::number(_dmxSlot));
                emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskThreshold, data_temp));
                rdm_cmd = cmd_AskThreshold;
            }
            else if (rdm_cmd == cmd_AskThreshold) {
                int low, high;
                low = (quint8) data[18];
                high = (quint8) data[17];
                emit display_DMXLowLever(QString::number(low));
                emit display_DMXHighLever(QString::number(high));
                emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetSEQAddress, data_temp));
                rdm_cmd = cmd_GetSEQAddress;
            }
            else if (rdm_cmd == cmd_GetSEQAddress) {
                int disc = ((((quint16)data[17])<<8)&0xFF00)|(((quint16)data[18])&0x00FF);
                //DEBUG(QString::number(disc));
                emit display_SEQAddress(QString::number(disc));
            }

            else if(rdm_cmd == cmd_RstDev) {

            }
            _isRecRDM = true;
        }*/
    }
    //LED old
    if(rdm_led_old == LED_OLD_READ)
    {
        LedOldCheckData = true;
        ChannelLEDOld = (quint16) data[0];
        ChannelLEDOld = (ChannelLEDOld - 1)*4 + 1;
        rdm_led_old = LED_OLD_NULL;
        //DEBUG(QString::number(ChannelLEDOld));
    }
    else if (rdm_led_old == LED_OLD_WRITE) {
        LedOldCheckData = true;
        rdm_led_old = LED_OLD_NULL;
        QString s = "data send... ";
        s += "size: " + QString::number(data.size()) + ", data: ";
        for (int i = 0; i < data.size(); i++) {
            s += QString::number(data[i]) + " ";

        }
        DEBUG(s);
    }
}




void DMXRDM::GetDeviceInfo()
{
    QByteArray data;
    data.resize(1);
    data[0] = 1;
    _isRec = false;
    rdm_cmd = cmd_Ping;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
        delay(50);
    }

}

void DMXRDM::setUID(QString newUID)
{
    int count = 0, pos = 0;
    do
    {
        pos = newUID.indexOf(':', pos) + 1;
        count++;
    }while(pos > 0);
    //DEBUG("count: " + QString::number(count));
    if(newUID.isEmpty() || newUID.isNull() || count != 6)
        newUID = "255:255:255:255:255:255";
    DeviceInfo.sUID = newUID;
    UID UID(newUID);
    DeviceInfo.bUID = UID.toQByteArray();
}

void DMXRDM::setUID(QByteArray newUID)
{
    DeviceInfo.bUID = newUID;
    UID UID(newUID);
    DeviceInfo.sUID = UID.toString();
}

bool DMXRDM::isRecRDM()
{
    return  _isRecRDM;
}

void DMXRDM::setDMXID(quint16 DMXID)
{
    QByteArray temp;
    temp.resize(3);
    temp[0] = 1;
    temp[1] = (char)DMXID&0xFF;
    temp[2] = (char)((DMXID>>8)&0xFF);
    DEBUG(tr("DMX ID: %1, data 0: %2, data 2: %3").arg(DMXID).arg((int)temp[0]).arg((int)temp[1]));
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_SetDMXSlot, temp));
    rdm_cmd = cmd_null;
}

void DMXRDM::setDMXUID(QString sUID)
{
    int count = 0, pos = 0;
    do
    {
        pos = sUID.indexOf(':', pos) + 1;
        count++;
    }while(pos > 0);
    DEBUG("count: " + QString::number(count));
    if(sUID.isEmpty() || sUID.isNull() || count != 6)
        QMessageBox::critical(this, tr("Error"), tr("Wrong UID format!"));
    else {
        UID uid = UID(sUID);
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_SetUID, uid.toQByteArray()));
    }
    rdm_cmd = cmd_null;
}

void DMXRDM::setLever(quint8 max, quint8 min)
{
    QByteArray data;
    data.resize(2);
    data[0] = (char) max;
    data[1] = (char)min;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_SetThreshold, data));
    rdm_cmd = cmd_null;
}

void DMXRDM::updateFirmware()
{
    if( DeviceInfo.bUID[0] != (char)255 &&\
        DeviceInfo.bUID[1] != (char)255 &&\
        DeviceInfo.bUID[2] != (char)255 &&\
        DeviceInfo.bUID[3] != (char)255 &&\
        DeviceInfo.bUID[4] != (char)255 &&\
        DeviceInfo.bUID[5] != (char)255 )
    {
        QByteArray data;
        data.resize(1);
        data[0] = 1;
        emit writeData((MakeDataSend(DeviceInfo.bUID, cmd_RstDev, data)));
        rdm_cmd = cmd_RstDev;
        QByteArray data_s;
        data_s.resize(13);
        data_s[0] = (char)126;
        data_s[1] = (char)0;
        data_s[2] = (char)126;
        data_s[3] = (char)224;
        data_s[4] = (char)30;
        data_s[5] = (char)126;
        data_s[6] = (char)152;
        data_s[7] = (char)102;
        data_s[8] = (char)126;
        data_s[9] = (char)126;
        data_s[10] = (char)230;
        data_s[11] = (char)134;
        data_s[12] = (char)230;
        delay(500);
        emit writeData(data_s);
        delay(500);
        emit writeData((MakeDataSend(DeviceInfo.bUID, cmd_RstDev, data)));
        delay(500);
        emit setBaudrate(115200);
        data_s.resize(20);
        data_s[0] = (char)187;
        data_s[1] = (char)0;
        data_s[2] = (char)15;
        data_s[3] = (char)20;
        data_s[4] = (char)0;
        data_s[5] = (char)0;
        data_s[6] = (char)0;
        data_s[7] = (char)0;
        data_s[8] = (char)1;
        data_s[9] = (char)40;
        data_s[10] = (char)160;
        data_s[11] = (char)161;
        data_s[12] = (char)162;
        data_s[13] = (char)163;
        data_s[14] = (char)164;
        data_s[15] = (char)165;
        data_s[16] = (char)166;
        data_s[17] = (char)167;
        data_s[18] = (char)168;
        data_s[19] = (char)169;
        emit writeDataBreak(data_s, false);
        delay(500);
        emit setBaudrate(250000);
        emit closeSerialPort();
        QObject *parent;
        QString program = "./bootloader/STMicroelectronics flash loader.exe";
        QStringList arguments;
        arguments << "-style" << "fusion";
        QProcess *myProcess = new QProcess(parent);
        myProcess->start(program, arguments);
    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("UID 255:255:255:255:255:255 not use or UID is empty"));
    }
}

void DMXRDM::delay(unsigned long ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}

void DMXRDM::scanDev()
{
    QByteArray data;
    data.resize(0);
    //data[0] = 1;
    _DevScan = false;
    _isscan = true;
    rdm_cmd = cmd_Disc;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Disc, data));
}

bool DMXRDM::scanDevCheck()
{

    return  _DevScan;
}

bool DMXRDM::askDMXAdd()
{
    QByteArray gUID, data_temp;
    data_temp[0] = 0;
    rdm_cmd = cmd_AskDMXSlot;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDMXSlot, data_temp));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDMXSlot, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDMXSlot, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDMXSlot, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    //DEBUG(QString::number(DeviceInfo.DMXAddr));
    return true;
}

bool DMXRDM::RDMPing()
{
    QByteArray data;
    data.resize(1);
    data[0] = 1;
    rdm_cmd = cmd_Ping;
    //DeviceInfo.sUID = "";
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
        delay(50);
    }
    /*
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_Ping, data));
        delay(50);
    }
*/
    if(!_isRec)
    {
        return false;
    }
    return true;
}

bool DMXRDM::askDeviceType()
{
    QByteArray data;
    data.resize(1);
    data[0] = 1;
    rdm_cmd = cmd_AskDevType;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDevType, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDevType, data));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskDevType, data));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    return true;

}

bool DMXRDM::askThreshold()
{
    QByteArray data;
    data.resize(1);
    data[0] = 1;
    rdm_cmd = cmd_AskThreshold;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskThreshold, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskThreshold, data));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_AskThreshold, data));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    return true;
}

bool DMXRDM::askFwV()
{
    QByteArray data;
    data.resize(1);
    data[0] = 1;
    rdm_cmd = cmd_GetFwVersion;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetFwVersion, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetFwVersion, data));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetFwVersion, data));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    return true;
}

bool DMXRDM::askSEQAddress()
{
    QByteArray gUID, data_temp;
    data_temp[0] = 0;
    rdm_cmd = cmd_GetSEQAddress;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetSEQAddress, data_temp));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetSEQAddress, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetSEQAddress, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_GetSEQAddress, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    //DEBUG(QString::number(DeviceInfo.DMXAddr));
    return true;
}

bool DMXRDM::askEPROM()
{
    QByteArray gUID, data_temp;
    data_temp[0] = 0;
    rdm_cmd = cmd_ReadMemory;
    _isRec = false;
    emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data_temp));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data_temp));
        delay(50);
    }
    if(!_isRec)
    {
        return false;
    }
    //DEBUG(QString::number(DeviceInfo.DMXAddr));
    return true;
}

void DMXRDM::writeEEprom(quint8 *eeprom)
{
    QByteArray data;
    data.resize(10);
    memcpy(data.data(), eeprom, 10);
    emit writeData(MakeDataSend(DeviceInfo.bUID, cmd_WriteMemory, data));
    rdm_cmd = cmd_null;
}

void DMXRDM::setAdmin(QString Pw)
{
    if(Pw == sPW)
    {
        _isUser = true;
        emit isUser(_isUser);
    }
}

bool DMXRDM::isAdmin()
{
    return _isUser;
}

bool DMXRDM::SetTestMode()
{
    QByteArray data;
    data.resize(1);
    data[0] = 0;
    _isRec = false;
    rdm_cmd = cmd_SetMode;
    emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data));
    delay(50);
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data));
    }
    if(!_isRec)
    {
        emit writeData(MakeDataSend(DeviceInfo.bUID, rdm_cmd, data));
    }
    if(!_isRec)
    {
        return false;
    }
    return  true;
}

void DMXRDM::timer_pw()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString s;
    s = QString::number(date.day()) + "/" + QString::number(date.month()) + "/" + QString::number(date.year()) + " " + QString::number(time.hour()) + ":" + QString::number(time.minute());
    sPW = "";
    sPW += QString::number(date.day()) + QString::number(date.month()) + QString::number(date.year()) + QString::number(time.hour())+ QString::number(time.minute());
    //DEBUG(sPW);
    //DEBUG(s);
}


QByteArray DMXRDM::MakeDataSend(QByteArray UID, DMXRDM::RDM_CMD cmd, QByteArray data)
{
    _isRecRDM = false;
    QByteArray data_send;
    static quint8 count;
    int data_size = data.size();
    int size = 18 + data.size();
    data_send.resize(size);
    memcpy(data_send.data(), rdm_rq, 2);
    data_send[2] = (char)(size - 4);
    memcpy(data_send.data() + 3, UID.data(), 6);
    memcpy(data_send.data() + 9, ctrlUID, 6);
    data_send[15] = (char) --count;
    data_send[16] = (char) cmd;
    memcpy(data_send.data() + 17, data.data(), (unsigned int)data_size);
    //DEBUG(tr("data 0: %2, data 2: %3").arg((int)data[0]).arg((int)data[1]));
    quint16 check_sum = 0;
    for(int i = 3; i < data_send.size() - 1; i++)
    {
        check_sum += data_send[i];
    }
    check_sum = check_sum & 0x00FF;
    check_sum = (0x00FF -  check_sum)&0xFF;
    data_send[size - 1] = (char) check_sum;
    //DEBUG(QString::number(data_size));
    return  data_send;
}

bool DMXRDM::askChannel_RGB_old()
{
    LedOldCheckData = false;
    rdm_led_old = LED_OLD_READ;
    QByteArray data_send;
    data_send.resize(3);
    memcpy(data_send.data(), RDM_LED_old_read, 3);
    emit writeData(data_send);
    delay(1000);
    return LedOldCheckData;
}

quint16 DMXRDM::readChannl_RBB_old()
{
    return ChannelLEDOld;
}

bool DMXRDM::writeChannel_RGB_old(quint16 channel)
{
    QByteArray data_send;
    rdm_led_old = LED_OLD_WRITE;
    LedOldCheckData = false;
    //DEBUG(tr("%1").arg(channel));
    data_send.resize(10);
    memcpy(data_send.data(), RDM_LED_old_write, 9);
    data_send[9] = (char) channel;
    emit writeData(data_send);
    delay(1000);
    return LedOldCheckData;
}

void DMXRDM::writeChannel_RGB_old_Loop(quint16 channel)
{
    QByteArray data_send;
    data_send.resize(12);
    memcpy(data_send.data(), MCU_POUT_Set, 12);
    emit writeDataBreak(data_send, false);
    delay(100);
    for(quint16 i = channel; i < channel + 64; i++)
    {
        if(channel > 65)    break;
        data_send.resize(11);
        memcpy(data_send.data(), RDM_LED_old_write_Loop, 9);
        data_send[9] = (char) i;
        data_send[10] = (char) 0;
        emit writeData(data_send);
        delay(20);
    }
}




UID::UID()
{
    bUID.clear();
    sUID = "";
}

UID::UID(QString UID)
{
    sUID = UID;
    bUID.clear();
}

UID::UID(quint8 UID1, quint8 UID2, quint8 UID3, quint8 UID4, quint8 UID5, quint8 UID6)
{
    bUID.resize(6);
    bUID[0] = (char) UID1;
    bUID[1] = (char) UID2;
    bUID[2] = (char) UID3;
    bUID[3] = (char) UID4;
    bUID[4] = (char) UID5;
    bUID[5] = (char) UID6;
    sUID = "";
}

UID::UID(QByteArray UID)
{
    bUID = UID;
}

QString UID::toString()
{
    sUID = "";
    if(bUID.size())
    {
        for(int i = 0; i < 6; i++)
        {
            sUID += QString::number((quint8)bUID[i]);
            if(i != 5)
            {
                sUID += ":";
            }
        }
    }
    return sUID;
}

QByteArray UID::toQByteArray()
{
    int pos = 0, pos_temp = 0;
    bUID.resize(6);
    //DEBUG(sUID);
    if(sUID != "")
    {
        for(int i = 0; i < 6; i++){
            pos = sUID.indexOf(':', pos) + 1;
            bUID[i] = (char) sUID.mid(pos_temp, pos - pos_temp - 1).toInt();
            //DEBUG("pos: " + QString::number(pos));
            //DEBUG(sUID.mid(pos_temp, pos - pos_temp -1));
            pos_temp = pos;
        }
    }
    return bUID;
}




DeviceInfo::DeviceInfo()
{

}

QString DeviceInfo::GetDeviceTypeName(uint8_t DevType)
{
    if(DevType > DEVICE_TOTAL)
    {
        return "UNKNOWN";
    }
    else {
        return DEVICE_NAME[DevType];
    }
}

QString DeviceInfo::GetFirmwareName(uint8_t FWVersion)
{
    QString s;
    s = QString::number((float)FWVersion/10);
    return s;
}

QString DeviceInfo::sEEprom()
{
    QString s = QString::number((quint8)EEprom[0]);
    for(int i = 1; i < 10; i++)
    {
        s += "," + QString::number((quint8)EEprom[i]);
    }
    return s;
}

bool DeviceInfo::setEEprom(QString s)
{
    int count = 0, pos = 0;
    do
    {
        pos = s.indexOf(',', pos) + 1;
        count++;
    }while(pos > 0);
    if(s.isEmpty() || s.isNull() || count != 9)
    {
        DEBUG("ERR EEprom");
    }
    else {

    }
}
