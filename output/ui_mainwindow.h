/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionScan;
    QAction *actionStop;
    QAction *actionDownload_Full;
    QAction *actionUser;
    QAction *actionEnglish;
    QAction *actionchina;
    QAction *actionLED_RGB_v1_0;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gr_devtype;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonALL;
    QRadioButton *radioButtonPump;
    QRadioButton *radioButtonLED;
    QRadioButton *radioButtonOthers;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *BT_WriteDMXAddr;
    QPushButton *bt_stop;
    QPushButton *pushButton;
    QPushButton *BT_ADD_NEW;
    QPushButton *bt_scan;
    QPushButton *BT_Write;
    QPushButton *BT_Read;
    QPushButton *BT_WriteEEprom;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gr_dev;
    QGridLayout *gridLayout_2;
    QLineEdit *txt_MINH;
    QSpacerItem *verticalSpacer;
    QPushButton *bt_UpdateFirmware;
    QLabel *lb_UID;
    QPushButton *bt_WriteDMXID;
    QPushButton *bt_DMX;
    QLineEdit *txt_DMXID;
    QLineEdit *txt_MAXH;
    QLineEdit *txt_Pos;
    QLabel *lb_DMXID;
    QPushButton *bt_WriteLever;
    QLabel *lb_pos;
    QLineEdit *txt_UID;
    QPushButton *bt_Ping;
    QLabel *lb_max;
    QLabel *lb_min;
    QPushButton *BT_WriteUID;
    QPushButton *BT_TestDevice;
    QTableView *table_Dev;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_Dev;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QMenu *menuLanguage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1088, 640);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowFilePath(QString::fromUtf8(""));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionScan = new QAction(MainWindow);
        actionScan->setObjectName(QString::fromUtf8("actionScan"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/scan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScan->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionDownload_Full = new QAction(MainWindow);
        actionDownload_Full->setObjectName(QString::fromUtf8("actionDownload_Full"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/downloadfull.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDownload_Full->setIcon(icon8);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QString::fromUtf8("actionUser"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/Account and Control.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon9);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionchina = new QAction(MainWindow);
        actionchina->setObjectName(QString::fromUtf8("actionchina"));
        actionLED_RGB_v1_0 = new QAction(MainWindow);
        actionLED_RGB_v1_0->setObjectName(QString::fromUtf8("actionLED_RGB_v1_0"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gr_devtype = new QGroupBox(groupBox);
        gr_devtype->setObjectName(QString::fromUtf8("gr_devtype"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        gr_devtype->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(gr_devtype);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonALL = new QRadioButton(gr_devtype);
        radioButtonALL->setObjectName(QString::fromUtf8("radioButtonALL"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        radioButtonALL->setFont(font1);
        radioButtonALL->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonALL);

        radioButtonPump = new QRadioButton(gr_devtype);
        radioButtonPump->setObjectName(QString::fromUtf8("radioButtonPump"));
        radioButtonPump->setFont(font);

        horizontalLayout_2->addWidget(radioButtonPump);

        radioButtonLED = new QRadioButton(gr_devtype);
        radioButtonLED->setObjectName(QString::fromUtf8("radioButtonLED"));
        radioButtonLED->setFont(font1);

        horizontalLayout_2->addWidget(radioButtonLED);

        radioButtonOthers = new QRadioButton(gr_devtype);
        radioButtonOthers->setObjectName(QString::fromUtf8("radioButtonOthers"));
        radioButtonOthers->setFont(font1);

        horizontalLayout_2->addWidget(radioButtonOthers);


        horizontalLayout->addWidget(gr_devtype);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        BT_WriteDMXAddr = new QPushButton(groupBox_4);
        BT_WriteDMXAddr->setObjectName(QString::fromUtf8("BT_WriteDMXAddr"));

        gridLayout_3->addWidget(BT_WriteDMXAddr, 2, 5, 1, 1);

        bt_stop = new QPushButton(groupBox_4);
        bt_stop->setObjectName(QString::fromUtf8("bt_stop"));
        bt_stop->setMaximumSize(QSize(50, 16777215));
        bt_stop->setFont(font);

        gridLayout_3->addWidget(bt_stop, 2, 0, 1, 1);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 5, 1, 1);

        BT_ADD_NEW = new QPushButton(groupBox_4);
        BT_ADD_NEW->setObjectName(QString::fromUtf8("BT_ADD_NEW"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        BT_ADD_NEW->setFont(font2);

        gridLayout_3->addWidget(BT_ADD_NEW, 1, 3, 1, 1);

        bt_scan = new QPushButton(groupBox_4);
        bt_scan->setObjectName(QString::fromUtf8("bt_scan"));
        bt_scan->setMaximumSize(QSize(50, 16777215));
        bt_scan->setFont(font);

        gridLayout_3->addWidget(bt_scan, 1, 0, 1, 1);

        BT_Write = new QPushButton(groupBox_4);
        BT_Write->setObjectName(QString::fromUtf8("BT_Write"));
        BT_Write->setFont(font);

        gridLayout_3->addWidget(BT_Write, 2, 1, 1, 1);

        BT_Read = new QPushButton(groupBox_4);
        BT_Read->setObjectName(QString::fromUtf8("BT_Read"));
        BT_Read->setFont(font);

        gridLayout_3->addWidget(BT_Read, 1, 1, 1, 1);

        BT_WriteEEprom = new QPushButton(groupBox_4);
        BT_WriteEEprom->setObjectName(QString::fromUtf8("BT_WriteEEprom"));

        gridLayout_3->addWidget(BT_WriteEEprom, 2, 3, 1, 1);


        horizontalLayout->addWidget(groupBox_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        gr_dev = new QGroupBox(centralWidget);
        gr_dev->setObjectName(QString::fromUtf8("gr_dev"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gr_dev->sizePolicy().hasHeightForWidth());
        gr_dev->setSizePolicy(sizePolicy);
        gr_dev->setMaximumSize(QSize(500, 16777215));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        gr_dev->setFont(font3);
        gridLayout_2 = new QGridLayout(gr_dev);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txt_MINH = new QLineEdit(gr_dev);
        txt_MINH->setObjectName(QString::fromUtf8("txt_MINH"));
        QFont font4;
        font4.setPointSize(12);
        txt_MINH->setFont(font4);

        gridLayout_2->addWidget(txt_MINH, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        bt_UpdateFirmware = new QPushButton(gr_dev);
        bt_UpdateFirmware->setObjectName(QString::fromUtf8("bt_UpdateFirmware"));
        QFont font5;
        font5.setPointSize(14);
        bt_UpdateFirmware->setFont(font5);

        gridLayout_2->addWidget(bt_UpdateFirmware, 5, 1, 1, 1);

        lb_UID = new QLabel(gr_dev);
        lb_UID->setObjectName(QString::fromUtf8("lb_UID"));
        lb_UID->setMaximumSize(QSize(100, 30));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        lb_UID->setFont(font6);

        gridLayout_2->addWidget(lb_UID, 0, 0, 1, 1);

        bt_WriteDMXID = new QPushButton(gr_dev);
        bt_WriteDMXID->setObjectName(QString::fromUtf8("bt_WriteDMXID"));
        bt_WriteDMXID->setMaximumSize(QSize(150, 40));
        bt_WriteDMXID->setFont(font2);

        gridLayout_2->addWidget(bt_WriteDMXID, 1, 2, 1, 1);

        bt_DMX = new QPushButton(gr_dev);
        bt_DMX->setObjectName(QString::fromUtf8("bt_DMX"));

        gridLayout_2->addWidget(bt_DMX, 6, 0, 1, 3);

        txt_DMXID = new QLineEdit(gr_dev);
        txt_DMXID->setObjectName(QString::fromUtf8("txt_DMXID"));
        txt_DMXID->setMaximumSize(QSize(230, 40));
        txt_DMXID->setFont(font);

        gridLayout_2->addWidget(txt_DMXID, 1, 1, 1, 1);

        txt_MAXH = new QLineEdit(gr_dev);
        txt_MAXH->setObjectName(QString::fromUtf8("txt_MAXH"));
        txt_MAXH->setMaximumSize(QSize(230, 40));
        txt_MAXH->setFont(font);

        gridLayout_2->addWidget(txt_MAXH, 2, 1, 1, 1);

        txt_Pos = new QLineEdit(gr_dev);
        txt_Pos->setObjectName(QString::fromUtf8("txt_Pos"));
        txt_Pos->setMaximumSize(QSize(230, 40));
        txt_Pos->setFont(font);

        gridLayout_2->addWidget(txt_Pos, 4, 1, 1, 1);

        lb_DMXID = new QLabel(gr_dev);
        lb_DMXID->setObjectName(QString::fromUtf8("lb_DMXID"));
        lb_DMXID->setMaximumSize(QSize(100, 30));
        lb_DMXID->setFont(font6);

        gridLayout_2->addWidget(lb_DMXID, 1, 0, 1, 1);

        bt_WriteLever = new QPushButton(gr_dev);
        bt_WriteLever->setObjectName(QString::fromUtf8("bt_WriteLever"));
        bt_WriteLever->setFont(font4);

        gridLayout_2->addWidget(bt_WriteLever, 3, 2, 1, 1);

        lb_pos = new QLabel(gr_dev);
        lb_pos->setObjectName(QString::fromUtf8("lb_pos"));
        lb_pos->setMaximumSize(QSize(100, 30));
        lb_pos->setFont(font6);

        gridLayout_2->addWidget(lb_pos, 4, 0, 1, 1);

        txt_UID = new QLineEdit(gr_dev);
        txt_UID->setObjectName(QString::fromUtf8("txt_UID"));
        txt_UID->setMaximumSize(QSize(230, 40));
        txt_UID->setFont(font);

        gridLayout_2->addWidget(txt_UID, 0, 1, 1, 1);

        bt_Ping = new QPushButton(gr_dev);
        bt_Ping->setObjectName(QString::fromUtf8("bt_Ping"));
        bt_Ping->setMaximumSize(QSize(200, 40));
        bt_Ping->setFont(font);

        gridLayout_2->addWidget(bt_Ping, 0, 2, 1, 1);

        lb_max = new QLabel(gr_dev);
        lb_max->setObjectName(QString::fromUtf8("lb_max"));
        lb_max->setMaximumSize(QSize(100, 30));
        lb_max->setFont(font6);

        gridLayout_2->addWidget(lb_max, 2, 0, 1, 1);

        lb_min = new QLabel(gr_dev);
        lb_min->setObjectName(QString::fromUtf8("lb_min"));
        lb_min->setFont(font6);

        gridLayout_2->addWidget(lb_min, 3, 0, 1, 1);

        BT_WriteUID = new QPushButton(gr_dev);
        BT_WriteUID->setObjectName(QString::fromUtf8("BT_WriteUID"));
        BT_WriteUID->setFont(font4);

        gridLayout_2->addWidget(BT_WriteUID, 2, 2, 1, 1);

        BT_TestDevice = new QPushButton(gr_dev);
        BT_TestDevice->setObjectName(QString::fromUtf8("BT_TestDevice"));
        BT_TestDevice->setFont(font4);

        gridLayout_2->addWidget(BT_TestDevice, 4, 2, 1, 1);


        gridLayout->addWidget(gr_dev, 1, 1, 1, 1);

        table_Dev = new QTableView(centralWidget);
        table_Dev->setObjectName(QString::fromUtf8("table_Dev"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(table_Dev->sizePolicy().hasHeightForWidth());
        table_Dev->setSizePolicy(sizePolicy1);
        table_Dev->setSortingEnabled(true);

        gridLayout->addWidget(table_Dev, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lb_Dev = new QLabel(groupBox_3);
        lb_Dev->setObjectName(QString::fromUtf8("lb_Dev"));
        lb_Dev->setFont(font3);

        horizontalLayout_3->addWidget(lb_Dev);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(70, 70));

        horizontalLayout_3->addWidget(label_5);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1088, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuTools->addAction(actionUser);
        menuTools->addSeparator();
        menuTools->addAction(actionLED_RGB_v1_0);
        menuHelp->addAction(actionAbout);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionchina);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);
        mainToolBar->addAction(actionScan);
        mainToolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AG DMX Device manager", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", nullptr));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionScan->setText(QApplication::translate("MainWindow", "Scan", nullptr));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        actionDownload_Full->setText(QApplication::translate("MainWindow", "Download Full", nullptr));
        actionUser->setText(QApplication::translate("MainWindow", "User", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUser->setToolTip(QApplication::translate("MainWindow", "actionUser", nullptr));
#endif // QT_NO_TOOLTIP
        actionEnglish->setText(QApplication::translate("MainWindow", "English", nullptr));
        actionchina->setText(QApplication::translate("MainWindow", "\344\270\255\345\233\275", nullptr));
        actionLED_RGB_v1_0->setText(QApplication::translate("MainWindow", "LED RGB v1.0", nullptr));
        groupBox->setTitle(QString());
        gr_devtype->setTitle(QApplication::translate("MainWindow", "Devices type", nullptr));
        radioButtonALL->setText(QApplication::translate("MainWindow", "ALL", nullptr));
        radioButtonPump->setText(QApplication::translate("MainWindow", "Pump", nullptr));
        radioButtonLED->setText(QApplication::translate("MainWindow", "LED", nullptr));
        radioButtonOthers->setText(QApplication::translate("MainWindow", "Others", nullptr));
        groupBox_4->setTitle(QString());
        BT_WriteDMXAddr->setText(QApplication::translate("MainWindow", "Write DMX Adrress", nullptr));
        bt_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Write Level", nullptr));
        BT_ADD_NEW->setText(QApplication::translate("MainWindow", "ADD New", nullptr));
        bt_scan->setText(QApplication::translate("MainWindow", "Scan", nullptr));
        BT_Write->setText(QApplication::translate("MainWindow", "Write", nullptr));
        BT_Read->setText(QApplication::translate("MainWindow", "Read", nullptr));
        BT_WriteEEprom->setText(QApplication::translate("MainWindow", "Write EEprom", nullptr));
        gr_dev->setTitle(QApplication::translate("MainWindow", "Functions", nullptr));
        bt_UpdateFirmware->setText(QApplication::translate("MainWindow", "Update Firmware", nullptr));
        lb_UID->setText(QApplication::translate("MainWindow", "UID", nullptr));
        bt_WriteDMXID->setText(QApplication::translate("MainWindow", "Write DMX ID", nullptr));
        bt_DMX->setText(QApplication::translate("MainWindow", "DMX", nullptr));
        txt_DMXID->setText(QString());
        txt_MAXH->setText(QString());
        txt_Pos->setText(QString());
        lb_DMXID->setText(QApplication::translate("MainWindow", "DMX ID", nullptr));
        bt_WriteLever->setText(QApplication::translate("MainWindow", "Write Level", nullptr));
        lb_pos->setText(QApplication::translate("MainWindow", "Position", nullptr));
        txt_UID->setText(QString());
        bt_Ping->setText(QApplication::translate("MainWindow", "Ping", nullptr));
        lb_max->setText(QApplication::translate("MainWindow", "MAX Height", nullptr));
        lb_min->setText(QApplication::translate("MainWindow", "Min Height", nullptr));
        BT_WriteUID->setText(QApplication::translate("MainWindow", "Write UID", nullptr));
        BT_TestDevice->setText(QApplication::translate("MainWindow", "Test Device", nullptr));
        groupBox_3->setTitle(QString());
        lb_Dev->setText(QApplication::translate("MainWindow", "Others devices", nullptr));
        label_5->setText(QString());
        menuCalls->setTitle(QApplication::translate("MainWindow", "Setting", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
