/********************************************************************************
** Form generated from reading UI file 'ledrgbold.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEDRGBOLD_H
#define UI_LEDRGBOLD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LEDRGBold
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *BT_DMXRead;
    QPushButton *BT_DMXWrite;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *edit_DMX_Channel;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_one_one;
    QRadioButton *radio_loop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LEDRGBold)
    {
        if (LEDRGBold->objectName().isEmpty())
            LEDRGBold->setObjectName(QString::fromUtf8("LEDRGBold"));
        LEDRGBold->resize(343, 153);
        QIcon icon;
        icon.addFile(QString::fromUtf8("AG-logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/AG-logo.png"), QSize(), QIcon::Normal, QIcon::On);
        LEDRGBold->setWindowIcon(icon);
        centralwidget = new QWidget(LEDRGBold);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        BT_DMXRead = new QPushButton(groupBox);
        BT_DMXRead->setObjectName(QString::fromUtf8("BT_DMXRead"));
        QFont font;
        font.setPointSize(14);
        BT_DMXRead->setFont(font);

        verticalLayout->addWidget(BT_DMXRead);

        BT_DMXWrite = new QPushButton(groupBox);
        BT_DMXWrite->setObjectName(QString::fromUtf8("BT_DMXWrite"));
        BT_DMXWrite->setFont(font);

        verticalLayout->addWidget(BT_DMXWrite);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 4, 3, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 2, 1, 1);

        edit_DMX_Channel = new QLineEdit(centralwidget);
        edit_DMX_Channel->setObjectName(QString::fromUtf8("edit_DMX_Channel"));
        edit_DMX_Channel->setFont(font);

        gridLayout->addWidget(edit_DMX_Channel, 1, 3, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radio_one_one = new QRadioButton(groupBox_2);
        radio_one_one->setObjectName(QString::fromUtf8("radio_one_one"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        radio_one_one->setFont(font2);

        horizontalLayout->addWidget(radio_one_one);

        radio_loop = new QRadioButton(groupBox_2);
        radio_loop->setObjectName(QString::fromUtf8("radio_loop"));
        radio_loop->setFont(font2);

        horizontalLayout->addWidget(radio_loop);


        gridLayout->addWidget(groupBox_2, 0, 2, 1, 2);

        LEDRGBold->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LEDRGBold);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 343, 21));
        LEDRGBold->setMenuBar(menubar);
        statusbar = new QStatusBar(LEDRGBold);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LEDRGBold->setStatusBar(statusbar);

        retranslateUi(LEDRGBold);

        QMetaObject::connectSlotsByName(LEDRGBold);
    } // setupUi

    void retranslateUi(QMainWindow *LEDRGBold)
    {
        LEDRGBold->setWindowTitle(QApplication::translate("LEDRGBold", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        BT_DMXRead->setText(QApplication::translate("LEDRGBold", "Read", nullptr));
        BT_DMXWrite->setText(QApplication::translate("LEDRGBold", "Write", nullptr));
        label->setText(QApplication::translate("LEDRGBold", "DMX ID", nullptr));
        edit_DMX_Channel->setText(QString());
        groupBox_2->setTitle(QString());
        radio_one_one->setText(QApplication::translate("LEDRGBold", "One-One", nullptr));
        radio_loop->setText(QApplication::translate("LEDRGBold", "Loop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LEDRGBold: public Ui_LEDRGBold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEDRGBOLD_H
