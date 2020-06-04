#include "dmxconsole.h"
#include "ui_dmxconsole.h"
#include <QDebug>

DMXconsole::DMXconsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMXconsole)
{
    ui->setupUi(this);
//Btn DMX Streaming
    IsDMXRunning = false;
    ui->BtnStartStreaming->setStyleSheet("background-color:red");
    connect(ui->BtnStartStreaming, SIGNAL(clicked(bool)), this, SLOT(BtnDMXStreaming_Clicked()));
//
    UI_Init();
    DMXBuffer.resize(513);
    DMXBuffer[0] = 0;

    TimerTick = new QTimer(this);
    connect(TimerTick, SIGNAL(timeout()), this, SLOT(DMXTick()));
    TimerTick->start(100);
}


DMXconsole::~DMXconsole()
{
    TimerTick->stop();
    delete ui;
}


void DMXconsole::DMXTick(void)
{
    if(IsDMXRunning == true)
    {
        this->DMXTriggle();
        if(!this->isActiveWindow())
        {
            BtnDMXStreaming_Clicked();
        }
    }
}

void DMXconsole::UI_Init(void)
{
    connect(ui->sl_value0, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value1, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value2, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value3, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value4, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value5, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value6, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value7, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value8, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value9, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));
    connect(ui->sl_value10, SIGNAL(valueChanged(int)), this, SLOT(_updateLb_value0(int)));

    connect(ui->sl_virtualH, SIGNAL(valueChanged(int)), this, SLOT(_syncDMXBuffer(int)));
    connect(ui->chk_SelectAll, SIGNAL(clicked(bool)), this, SLOT(_chk_SelectAll_Changed()));

    ui->grp_index0->setTitle(tr("%1").arg(ui->sl_virtualH->value()+1));
    ui->grp_index1->setTitle(tr("%1").arg(ui->sl_virtualH->value()+2));
    ui->grp_index2->setTitle(tr("%1").arg(ui->sl_virtualH->value()+3));
    ui->grp_index3->setTitle(tr("%1").arg(ui->sl_virtualH->value()+4));
    ui->grp_index4->setTitle(tr("%1").arg(ui->sl_virtualH->value()+5));
    ui->grp_index5->setTitle(tr("%1").arg(ui->sl_virtualH->value()+6));
    ui->grp_index6->setTitle(tr("%1").arg(ui->sl_virtualH->value()+7));
    ui->grp_index7->setTitle(tr("%1").arg(ui->sl_virtualH->value()+8));
    ui->grp_index8->setTitle(tr("%1").arg(ui->sl_virtualH->value()+9));
    ui->grp_index9->setTitle(tr("%1").arg(ui->sl_virtualH->value()+10));
    ui->grp_index10->setTitle(tr("%1").arg(ui->sl_virtualH->value()+11));
}

quint16 DMXconsole::GetIndex(void)
{
    return ui->sl_virtualH->value();
}

void DMXconsole::_updateLb_value0(int val)
{
    if(ui->chk_SelectAll->isChecked() == true)
    {
        for(quint16 i = 1; i < 513; i++)
        {
            DMXBuffer[i] = ui->sl_value0->value();
        }
        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value1->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value2->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value3->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value4->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value5->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value6->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value7->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value8->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value9->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value10->setText(tr("%1").arg(ui->sl_value0->value()));

        ui->sl_value1->setValue(ui->sl_value0->value());
        ui->sl_value2->setValue(ui->sl_value0->value());
        ui->sl_value3->setValue(ui->sl_value0->value());
        ui->sl_value4->setValue(ui->sl_value0->value());
        ui->sl_value5->setValue(ui->sl_value0->value());
        ui->sl_value6->setValue(ui->sl_value0->value());
        ui->sl_value7->setValue(ui->sl_value0->value());
        ui->sl_value8->setValue(ui->sl_value0->value());
        ui->sl_value9->setValue(ui->sl_value0->value());
        ui->sl_value10->setValue(ui->sl_value0->value());
    }
    else
    {
        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
        ui->lb_value2->setText(tr("%1").arg(ui->sl_value2->value()));
        ui->lb_value3->setText(tr("%1").arg(ui->sl_value3->value()));
        ui->lb_value4->setText(tr("%1").arg(ui->sl_value4->value()));
        ui->lb_value5->setText(tr("%1").arg(ui->sl_value5->value()));
        ui->lb_value6->setText(tr("%1").arg(ui->sl_value6->value()));
        ui->lb_value7->setText(tr("%1").arg(ui->sl_value7->value()));
        ui->lb_value8->setText(tr("%1").arg(ui->sl_value8->value()));
        ui->lb_value9->setText(tr("%1").arg(ui->sl_value9->value()));
        ui->lb_value10->setText(tr("%1").arg(ui->sl_value10->value()));
        DMXBuffer[GetIndex() + 1] = ui->sl_value0->value();
        DMXBuffer[GetIndex() + 2] = ui->sl_value1->value();
        DMXBuffer[GetIndex() + 3] = ui->sl_value2->value();
        DMXBuffer[GetIndex() + 4] = ui->sl_value3->value();
        DMXBuffer[GetIndex() + 5] = ui->sl_value4->value();
        DMXBuffer[GetIndex() + 6] = ui->sl_value5->value();
        DMXBuffer[GetIndex() + 7] = ui->sl_value6->value();
        DMXBuffer[GetIndex() + 8] = ui->sl_value7->value();
        DMXBuffer[GetIndex() + 9] = ui->sl_value8->value();
        DMXBuffer[GetIndex() + 10] = ui->sl_value9->value();
        DMXBuffer[GetIndex() + 11] = ui->sl_value10->value();
    }
  }


void DMXconsole::_syncDMXBuffer(int index)
{
    ui->sl_value0->setValue(DMXBuffer[index + 1]);
    ui->sl_value1->setValue(DMXBuffer[index + 2]);
    ui->sl_value2->setValue(DMXBuffer[index + 3]);
    ui->sl_value3->setValue(DMXBuffer[index + 4]);
    ui->sl_value4->setValue(DMXBuffer[index + 5]);
    ui->sl_value5->setValue(DMXBuffer[index + 6]);
    ui->sl_value6->setValue(DMXBuffer[index + 7]);
    ui->sl_value7->setValue(DMXBuffer[index + 8]);
    ui->sl_value8->setValue(DMXBuffer[index + 9]);
    ui->sl_value9->setValue(DMXBuffer[index + 10]);
    ui->sl_value10->setValue(DMXBuffer[index + 11]);
    ui->grp_index0->setTitle(tr("%1").arg(ui->sl_virtualH->value()+1));
    ui->grp_index1->setTitle(tr("%1").arg(ui->sl_virtualH->value()+2));
    ui->grp_index2->setTitle(tr("%1").arg(ui->sl_virtualH->value()+3));
    ui->grp_index3->setTitle(tr("%1").arg(ui->sl_virtualH->value()+4));
    ui->grp_index4->setTitle(tr("%1").arg(ui->sl_virtualH->value()+5));
    ui->grp_index5->setTitle(tr("%1").arg(ui->sl_virtualH->value()+6));
    ui->grp_index6->setTitle(tr("%1").arg(ui->sl_virtualH->value()+7));
    ui->grp_index7->setTitle(tr("%1").arg(ui->sl_virtualH->value()+8));
    ui->grp_index8->setTitle(tr("%1").arg(ui->sl_virtualH->value()+9));
    ui->grp_index9->setTitle(tr("%1").arg(ui->sl_virtualH->value()+10));
    ui->grp_index10->setTitle(tr("%1").arg(ui->sl_virtualH->value()+11));
}

void DMXconsole::_chk_SelectAll_Changed(void)
{
    if(ui->chk_SelectAll->isChecked())
        IsSelectAll = true;
    else
        IsSelectAll = false;
}

void DMXconsole::FocusChanged(bool dir)
{

}

void DMXconsole::BtnDMXStreaming_Clicked(void)
{
    if(IsDMXRunning)
    {
        ui->BtnStartStreaming->setText("DMX Stream ON");
        ui->BtnStartStreaming->setStyleSheet("background-color:red");
        IsDMXRunning = false;
    }
    else
    {
        ui->BtnStartStreaming->setText("DMX Stream OFF");
        ui->BtnStartStreaming->setStyleSheet("background-color:lightgreen");
        IsDMXRunning = true;
    }
}



void DMXconsole::on_BtnStartStreaming_clicked()
{

}
