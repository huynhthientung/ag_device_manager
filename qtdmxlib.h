#ifndef QTDMXLIB_H
#define QTDMXLIB_H

#include <QtCore/QtGlobal>
#include <QPlainTextEdit>
#include <QTimer>


#define sPassword "1234567"


class qtdmxlib
{
public:
    qtdmxlib();
};


class UID
{
public:
    UID();
    UID(QString UID);
    UID(quint8 UID1,
        quint8 UID2,
        quint8 UID3,
        quint8 UID4,
        quint8 UID5,
        quint8 UID6);
    UID(QByteArray UID);

    QString toString();
    QByteArray toQByteArray();
public:
    const quint8 UIDData[6] = {255, 255, 255, 255, 255, 255};

private:
    QString sUID;
    QByteArray bUID;
};

class DeviceInfo
{
public:
    DeviceInfo();
public:
    quint16 DMXAddr;
    QByteArray bUID;
    QString sUID;
    quint8 MaxLevel;
    quint8 MinLevel;
    quint8 Sensor;
    quint8 SEQAddr;
    quint8 DeviceType;
    QString DeviceName;
    QString strDeviceType;
    quint8 FWVersion;
    QString strFWVersion;
    uint16_t SensorValue;
    uint16_t rawSensorValue;
    uint8_t EEprom[10];
    QString strEEprom;
    QString FwVName;
    QString GetDeviceTypeName(uint8_t DevType);
    QString GetFirmwareName(uint8_t FWVersion);
    QString sEEprom();
    bool setEEprom(QString s);
    typedef enum DEVICE_TYPE
    {
        LIGHT_RGB = 1,
        LIGHT_RGBW = 2,
        LIGHT_RGBWA = 3,
        DC_PUMP = 4,
        AC_PUMP = 5,
        CAPERJET = 6,
        MINILEAPJET = 7,
        YTL_NOZZLE,
        VARIABLE_PATTERN_JET,
        PROPORTIONAL_SWITCH,
        SPLITTER,
        SSR,
        WIND_READER,
        WIND_DMX_CONVERTER,
        LIGHT_RGBWAP,
        UNKNOWN,
        VARIEGATOR,
        Proportional,
        Animatronic1Axis,
        Animatronic2Axis,
        Animatronic3Axis,
        AnimatronicRGB,
        AnimatronicRGBW,
        AnimatronicSpinner,
        Peacock7,
        MUSEAC,
        PopJet,
        Ballerina,
        BallerinaRGB,
        Ballerina_RGBW,
        boostDMX,
        DEVICE_TOTAL
    }DEVICE_TYPE;


    QString DEVICE_NAME[DEVICE_TOTAL] = {
        "",
        "LumiFONS Classic RGB",
        "LumiFONS Classic RGBW",
        "LumiFONS Classic RGBWA",
        "ECOficient Classic 24VDC",
        "PROficient AC",
        "CaperJet",
        "Mini-LeapJet",
        "ANIMATRONIC",
        "Variable Pattern Jet",
        "Proportional Switch",
        "Splitter",
        "SSR",
        "Weather Station",
        "DMX converter",
        "LumiFONS Classic RGBWAP",
        "UNKNOWN",
        "Variegator",
        "Proportional",
        "Animatronic 1-Axis",
        "Animatronic 2-Axis",
        "Animatronic 3-Axis",
        "Animatronic RGB",
        "Animatronic RGBW",
        "Animatronic Spinner",
        "Peacock 7",
        "MUSE AC",
        "Pop Jet",
        "Ballerina",
        "Ballerina RGB",
        "Ballerina RGBW",
        "boost DMX"
    };
};

class DMXRDM : public QPlainTextEdit
{
    Q_OBJECT
public:
    DMXRDM();
    DeviceInfo DeviceInfo;
public:
    void RDMRecHandler(QByteArray data);
    QByteArray RDMSend();
    void GetDeviceInfo();
    void setUID(QString newUID);
    void setUID(QByteArray newUID);
    bool isRecRDM();
    void setDMXID(quint16 DMXID);
    void setDMXUID(QString sUID);
    void setLever(quint8 max, quint8 min);
    void updateFirmware();
    void delay(unsigned long ms);
    void scanDev();
    bool scanDevCheck();
    bool askDMXAdd();
    bool RDMPing();
    bool askDeviceType();
    bool askThreshold();
    bool askFwV();
    bool askSEQAddress();
    bool askEPROM();
    void writeEEprom(quint8 *eeprom);
    void setAdmin(QString Pw);
    bool isAdmin();
    //void UpdataListDev()
    bool SetTestMode();
signals:
    void writeData(const QByteArray &data);
    void writeDataBreak(const QByteArray &data, bool _break);
    void display_UID(QString sUID);
    void display_DMXChannel(QString DMXChannel);
    void display_DMXLowLever(QString lowlever);
    void display_DMXHighLever(QString highlever);
    void display_SEQAddress(QString add);
    void setBaudrate(qint32 br);
    void closeSerialPort();
    void isUser(bool is);
private slots:
    void timer_pw();
private:
    const quint8 rdm_rq[3] = {0xBB, 0x05, 0x0F};
    const quint8 ctrlUID[6] = {40, 20, 116, 151, 103, 16};

    bool _isRecRDM;
    bool _isscan = false;
    bool _isRec = false;

private:
    typedef enum RDM_CMD
    {
        cmd_Ping = 0x00,
        cmd_AskDevType = 0x01,
        cmd_AskSlots = 0x02,
        cmd_AskSensors = 0x03,
        cmd_AskValSensor = 0x04,
        cmd_AskDMXSlot = 0x05,
        cmd_SetDMXSlot = 0x06,
        cmd_SetMode = 0x07,
        cmd_AskUID = 0x08,
        cmd_SetUID = 0x09,
        cmd_Disc = 0xFF,
        cmd_AskThreshold = 0x0A,
        cmd_SetThreshold = 0x0B,
        cmd_RstDev = 0x0C,
        cmd_GetFwVersion = 0x0D,
        cmd_GetSEQAddress = 0x0E,
        cmd_ReadMemory = 0x10,
        cmd_WriteMemory = 0x11,
        cmd_OpenGate = 0x12,
        cmd_ReadInternalMemory = 0x13,
        cmd_WriteInternalMemory = 0x14,
        cmd_null
    }RDM_CMD;
    RDM_CMD rdm_cmd;

    typedef struct
    {
        quint16 DMXAddr;
        QByteArray bUID;
        QString sUID;
        quint8 MaxLevel;
        quint8 MinLevel;
        quint8 SEQAddr;
        quint8 DeviceType;
    }LIST_DEV;


private:
    QByteArray MakeDataSend(QByteArray UID, RDM_CMD cmd, QByteArray data);
    bool _DevScan;
    bool _isFindDev;
    bool _isUser = false;
    QTimer *timer;
    QString sPW;
//led rgb old
public:
    bool askChannel_RGB_old();
    quint16 readChannl_RBB_old();
    bool writeChannel_RGB_old(quint16 channel);
    void writeChannel_RGB_old_Loop(quint16 channel);
private:
    typedef enum
    {
        LED_OLD_READ = 0,
        LED_OLD_WRITE = 1,
        LED_OLD_NULL
    }RDM_LED_OLD;
    RDM_LED_OLD rdm_led_old = LED_OLD_NULL;
    bool LedOldCheckData = false;
    const quint8 RDM_LED_old_read[3]    = {0x55, 0x5A, 0xA5};
    const quint8 RDM_LED_old_write[9]   = {0x55, 0xA5, 0x5A, 0xEE, 0x11, 0xDD, 0x22, 0xCC, 0x33};
    const quint8 RDM_LED_old_write_Loop[9]   = {0x55, 0xA5, 0x5A, 0xEE, 0x11, 0xDD, 0x22, 0xCC, 0xBB};
    const quint8 MCU_POUT_Set[12] = {159, 160, 149, 158, 164, 152, 149, 151, 145, 164, 149, 113};
    quint16 ChannelLEDOld;

};




#endif // QTDMXLIB_H
