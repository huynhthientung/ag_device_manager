#include "ledrgbold.h"
#include "ui_ledrgbold.h"

#include <QMessageBox>
#include <mainwindow.h>

#include "debug.h"

LEDRGBold::LEDRGBold(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LEDRGBold)
{
    ui->setupUi(this);
    this->setWindowTitle("AG LED RGB v1.0");
    loadingdialog = new LoadingDialog();
    ui->radio_one_one->setChecked(true);
    connect(ui->radio_loop, SIGNAL(clicked(bool)), this, SLOT(on_radio_st_check()));
    connect(ui->radio_one_one, SIGNAL(clicked(bool)), this, SLOT(on_radio_st_check()));
}

LEDRGBold::~LEDRGBold()
{
    delete ui;
}

void LEDRGBold::on_BT_DMXRead_clicked()
{
    quint16 channel;
    loadingdialog->showDialog();
    ui->BT_DMXRead->setEnabled(false);
    if(dmxrdm->askChannel_RGB_old())
    {
        channel = dmxrdm->readChannl_RBB_old();
        ui->edit_DMX_Channel->setText(QString::number(channel));
    }
    else {
        QMessageBox::information(this, "ERROR", "Device not found!");
    }
    loadingdialog->hideDialog();
    ui->BT_DMXRead->setEnabled(true);

}

void LEDRGBold::on_BT_DMXWrite_clicked()
{
    if(ui->radio_one_one->isChecked())
    {
        ui->BT_DMXWrite->setEnabled(false);
        quint16 channel = (quint16) ui->edit_DMX_Channel->text().trimmed().toInt();
        if(channel == 1 || (channel - 1)%4 == 0)
        {
            loadingdialog->showDialog();
            channel = (channel - 1)/4 + 1;
            if(dmxrdm->writeChannel_RGB_old(channel))
            {
                QMessageBox::information(this, "Done", "Write channel done!");
            }
            else {
                QMessageBox::information(this, "ERROR", "Can't write channel");
            }

            loadingdialog->hideDialog();
        }
        else {
            QMessageBox::information(this, "INFO", "DMX ID 1, 5, 9, 13, ...!");
        }
        ui->BT_DMXWrite->setEnabled(true);
    }


    if(ui->radio_loop->isChecked())
    {
        ui->BT_DMXWrite->setEnabled(false);
        quint16 channel = (quint16) ui->edit_DMX_Channel->text().trimmed().toInt();
        if(channel == 1 || (channel - 1)%4 == 0)
        {

            loadingdialog->showDialog();
            channel = (channel - 1)/4 + 1;
            dmxrdm->writeChannel_RGB_old_Loop(channel);
            QMessageBox::information(this, "Done", "Write channel done!");
            loadingdialog->hideDialog();
        }
        else {
            QMessageBox::information(this, "INFO", "DMX ID 1, 5, 9, 13, ...!");
        }
        ui->BT_DMXWrite->setEnabled(true);
    }
}

void LEDRGBold::on_radio_st_check()
{
    if(ui->radio_one_one->isChecked())
    {
        ui->BT_DMXRead->setEnabled(true);
    }
    if(ui->radio_loop->isChecked())
    {
        ui->BT_DMXRead->setEnabled(false);
    }
}
