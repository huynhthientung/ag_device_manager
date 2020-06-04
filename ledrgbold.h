#ifndef LEDRGBOLD_H
#define LEDRGBOLD_H

#include <QMainWindow>
#include "debug.h"
#include "loadingdialog.h"
#include "qtdmxlib.h"

extern DMXRDM *dmxrdm;

namespace Ui {
class LEDRGBold;
}

class LEDRGBold : public QMainWindow
{
    Q_OBJECT

public:
    explicit LEDRGBold(QWidget *parent = nullptr);
    ~LEDRGBold();

private slots:
    void on_BT_DMXRead_clicked();

    void on_BT_DMXWrite_clicked();

    void on_radio_st_check();

private:
    Ui::LEDRGBold *ui;
    //DMXRDM *dmxrdm;
    LoadingDialog *loadingdialog;

};

#endif // LEDRGBOLD_H
