/********************************************************************************
** Form generated from reading UI file 'dmxconsole.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMXCONSOLE_H
#define UI_DMXCONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DMXconsole
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *grp_index1;
    QVBoxLayout *verticalLayout_2;
    QLabel *lb_value1;
    QSlider *sl_value1;
    QGroupBox *grp_index4;
    QVBoxLayout *verticalLayout_5;
    QLabel *lb_value4;
    QSlider *sl_value4;
    QGroupBox *grp_index2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lb_value2;
    QSlider *sl_value2;
    QGroupBox *grp_index5;
    QVBoxLayout *verticalLayout_6;
    QLabel *lb_value5;
    QSlider *sl_value5;
    QGroupBox *grp_index3;
    QVBoxLayout *verticalLayout_4;
    QLabel *lb_value3;
    QSlider *sl_value3;
    QGroupBox *grp_index0;
    QVBoxLayout *verticalLayout;
    QLabel *lb_value0;
    QSlider *sl_value0;
    QGroupBox *grp_index9;
    QVBoxLayout *verticalLayout_10;
    QLabel *lb_value9;
    QSlider *sl_value9;
    QGroupBox *grp_index8;
    QVBoxLayout *verticalLayout_9;
    QLabel *lb_value8;
    QSlider *sl_value8;
    QGroupBox *grp_index10;
    QVBoxLayout *verticalLayout_11;
    QLabel *lb_value10;
    QSlider *sl_value10;
    QGroupBox *grp_index7;
    QVBoxLayout *verticalLayout_8;
    QLabel *lb_value7;
    QSlider *sl_value7;
    QGroupBox *grp_index6;
    QVBoxLayout *verticalLayout_7;
    QLabel *lb_value6;
    QSlider *sl_value6;
    QPushButton *BtnStartStreaming;
    QSlider *sl_virtualH;
    QCheckBox *chk_SelectAll;

    void setupUi(QDialog *DMXconsole)
    {
        if (DMXconsole->objectName().isEmpty())
            DMXconsole->setObjectName(QString::fromUtf8("DMXconsole"));
        DMXconsole->resize(938, 438);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/AG-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DMXconsole->setWindowIcon(icon);
        gridLayout = new QGridLayout(DMXconsole);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(DMXconsole);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        grp_index1 = new QGroupBox(groupBox);
        grp_index1->setObjectName(QString::fromUtf8("grp_index1"));
        verticalLayout_2 = new QVBoxLayout(grp_index1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lb_value1 = new QLabel(grp_index1);
        lb_value1->setObjectName(QString::fromUtf8("lb_value1"));

        verticalLayout_2->addWidget(lb_value1);

        sl_value1 = new QSlider(grp_index1);
        sl_value1->setObjectName(QString::fromUtf8("sl_value1"));
        sl_value1->setMaximum(255);
        sl_value1->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(sl_value1);


        gridLayout_2->addWidget(grp_index1, 2, 2, 1, 1);

        grp_index4 = new QGroupBox(groupBox);
        grp_index4->setObjectName(QString::fromUtf8("grp_index4"));
        verticalLayout_5 = new QVBoxLayout(grp_index4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lb_value4 = new QLabel(grp_index4);
        lb_value4->setObjectName(QString::fromUtf8("lb_value4"));

        verticalLayout_5->addWidget(lb_value4);

        sl_value4 = new QSlider(grp_index4);
        sl_value4->setObjectName(QString::fromUtf8("sl_value4"));
        sl_value4->setMaximum(255);
        sl_value4->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(sl_value4);


        gridLayout_2->addWidget(grp_index4, 2, 5, 1, 1);

        grp_index2 = new QGroupBox(groupBox);
        grp_index2->setObjectName(QString::fromUtf8("grp_index2"));
        verticalLayout_3 = new QVBoxLayout(grp_index2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lb_value2 = new QLabel(grp_index2);
        lb_value2->setObjectName(QString::fromUtf8("lb_value2"));

        verticalLayout_3->addWidget(lb_value2);

        sl_value2 = new QSlider(grp_index2);
        sl_value2->setObjectName(QString::fromUtf8("sl_value2"));
        sl_value2->setMaximum(255);
        sl_value2->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(sl_value2);


        gridLayout_2->addWidget(grp_index2, 2, 3, 1, 1);

        grp_index5 = new QGroupBox(groupBox);
        grp_index5->setObjectName(QString::fromUtf8("grp_index5"));
        verticalLayout_6 = new QVBoxLayout(grp_index5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lb_value5 = new QLabel(grp_index5);
        lb_value5->setObjectName(QString::fromUtf8("lb_value5"));

        verticalLayout_6->addWidget(lb_value5);

        sl_value5 = new QSlider(grp_index5);
        sl_value5->setObjectName(QString::fromUtf8("sl_value5"));
        sl_value5->setMaximum(255);
        sl_value5->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(sl_value5);


        gridLayout_2->addWidget(grp_index5, 2, 6, 1, 1);

        grp_index3 = new QGroupBox(groupBox);
        grp_index3->setObjectName(QString::fromUtf8("grp_index3"));
        verticalLayout_4 = new QVBoxLayout(grp_index3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lb_value3 = new QLabel(grp_index3);
        lb_value3->setObjectName(QString::fromUtf8("lb_value3"));

        verticalLayout_4->addWidget(lb_value3);

        sl_value3 = new QSlider(grp_index3);
        sl_value3->setObjectName(QString::fromUtf8("sl_value3"));
        sl_value3->setMaximum(255);
        sl_value3->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(sl_value3);


        gridLayout_2->addWidget(grp_index3, 2, 4, 1, 1);

        grp_index0 = new QGroupBox(groupBox);
        grp_index0->setObjectName(QString::fromUtf8("grp_index0"));
        verticalLayout = new QVBoxLayout(grp_index0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lb_value0 = new QLabel(grp_index0);
        lb_value0->setObjectName(QString::fromUtf8("lb_value0"));

        verticalLayout->addWidget(lb_value0);

        sl_value0 = new QSlider(grp_index0);
        sl_value0->setObjectName(QString::fromUtf8("sl_value0"));
        sl_value0->setMaximum(255);
        sl_value0->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(sl_value0);


        gridLayout_2->addWidget(grp_index0, 2, 0, 1, 1);

        grp_index9 = new QGroupBox(groupBox);
        grp_index9->setObjectName(QString::fromUtf8("grp_index9"));
        verticalLayout_10 = new QVBoxLayout(grp_index9);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lb_value9 = new QLabel(grp_index9);
        lb_value9->setObjectName(QString::fromUtf8("lb_value9"));

        verticalLayout_10->addWidget(lb_value9);

        sl_value9 = new QSlider(grp_index9);
        sl_value9->setObjectName(QString::fromUtf8("sl_value9"));
        sl_value9->setMaximum(255);
        sl_value9->setOrientation(Qt::Vertical);

        verticalLayout_10->addWidget(sl_value9);


        gridLayout_2->addWidget(grp_index9, 2, 10, 1, 1);

        grp_index8 = new QGroupBox(groupBox);
        grp_index8->setObjectName(QString::fromUtf8("grp_index8"));
        verticalLayout_9 = new QVBoxLayout(grp_index8);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lb_value8 = new QLabel(grp_index8);
        lb_value8->setObjectName(QString::fromUtf8("lb_value8"));

        verticalLayout_9->addWidget(lb_value8);

        sl_value8 = new QSlider(grp_index8);
        sl_value8->setObjectName(QString::fromUtf8("sl_value8"));
        sl_value8->setMaximum(255);
        sl_value8->setOrientation(Qt::Vertical);

        verticalLayout_9->addWidget(sl_value8);


        gridLayout_2->addWidget(grp_index8, 2, 9, 1, 1);

        grp_index10 = new QGroupBox(groupBox);
        grp_index10->setObjectName(QString::fromUtf8("grp_index10"));
        verticalLayout_11 = new QVBoxLayout(grp_index10);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        lb_value10 = new QLabel(grp_index10);
        lb_value10->setObjectName(QString::fromUtf8("lb_value10"));

        verticalLayout_11->addWidget(lb_value10);

        sl_value10 = new QSlider(grp_index10);
        sl_value10->setObjectName(QString::fromUtf8("sl_value10"));
        sl_value10->setMaximum(255);
        sl_value10->setOrientation(Qt::Vertical);

        verticalLayout_11->addWidget(sl_value10);


        gridLayout_2->addWidget(grp_index10, 2, 11, 1, 1);

        grp_index7 = new QGroupBox(groupBox);
        grp_index7->setObjectName(QString::fromUtf8("grp_index7"));
        verticalLayout_8 = new QVBoxLayout(grp_index7);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lb_value7 = new QLabel(grp_index7);
        lb_value7->setObjectName(QString::fromUtf8("lb_value7"));

        verticalLayout_8->addWidget(lb_value7);

        sl_value7 = new QSlider(grp_index7);
        sl_value7->setObjectName(QString::fromUtf8("sl_value7"));
        sl_value7->setMaximum(255);
        sl_value7->setOrientation(Qt::Vertical);

        verticalLayout_8->addWidget(sl_value7);


        gridLayout_2->addWidget(grp_index7, 2, 8, 1, 1);

        grp_index6 = new QGroupBox(groupBox);
        grp_index6->setObjectName(QString::fromUtf8("grp_index6"));
        verticalLayout_7 = new QVBoxLayout(grp_index6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lb_value6 = new QLabel(grp_index6);
        lb_value6->setObjectName(QString::fromUtf8("lb_value6"));

        verticalLayout_7->addWidget(lb_value6);

        sl_value6 = new QSlider(grp_index6);
        sl_value6->setObjectName(QString::fromUtf8("sl_value6"));
        sl_value6->setMaximum(255);
        sl_value6->setOrientation(Qt::Vertical);

        verticalLayout_7->addWidget(sl_value6);


        gridLayout_2->addWidget(grp_index6, 2, 7, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        BtnStartStreaming = new QPushButton(DMXconsole);
        BtnStartStreaming->setObjectName(QString::fromUtf8("BtnStartStreaming"));
        BtnStartStreaming->setAutoFillBackground(false);

        gridLayout->addWidget(BtnStartStreaming, 0, 0, 1, 1);

        sl_virtualH = new QSlider(DMXconsole);
        sl_virtualH->setObjectName(QString::fromUtf8("sl_virtualH"));
        sl_virtualH->setMaximum(501);
        sl_virtualH->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sl_virtualH, 3, 0, 1, 1);

        chk_SelectAll = new QCheckBox(DMXconsole);
        chk_SelectAll->setObjectName(QString::fromUtf8("chk_SelectAll"));
        chk_SelectAll->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chk_SelectAll, 1, 0, 1, 1);


        retranslateUi(DMXconsole);

        QMetaObject::connectSlotsByName(DMXconsole);
    } // setupUi

    void retranslateUi(QDialog *DMXconsole)
    {
        DMXconsole->setWindowTitle(QApplication::translate("DMXconsole", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("DMXconsole", "512 DMX channels", nullptr));
        grp_index1->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value1->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index4->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value4->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index2->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value2->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index5->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value5->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index3->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value3->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index0->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value0->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index9->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value9->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index8->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value8->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index10->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value10->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index7->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value7->setText(QApplication::translate("DMXconsole", "0", nullptr));
        grp_index6->setTitle(QApplication::translate("DMXconsole", "GroupBox", nullptr));
        lb_value6->setText(QApplication::translate("DMXconsole", "0", nullptr));
        BtnStartStreaming->setText(QApplication::translate("DMXconsole", "DMX stream ON", nullptr));
        chk_SelectAll->setText(QApplication::translate("DMXconsole", "Select All channels", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DMXconsole: public Ui_DMXconsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMXCONSOLE_H
