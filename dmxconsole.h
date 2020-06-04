#ifndef DMXCONSOLE_H
#define DMXCONSOLE_H

#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QTimer>


namespace Ui {
class DMXconsole;
}


class DMXconsole : public QDialog
{
    Q_OBJECT
signals:
    void DMXTriggle(void);

public:
    explicit DMXconsole(QWidget *parent = 0);
    ~DMXconsole();
    QByteArray DMXBuffer;

private slots:
    void BtnDMXStreaming_Clicked(void);
    void DMXTick(void);

private:
    Ui::DMXconsole *ui;
    QHBoxLayout *layout;
    QTimer *TimerTick;
    bool IsDMXRunning, IsSelectAll;
    void UI_Init(void);
    quint16 GetIndex(void);
private slots:
    void _updateLb_value0(int val);

    void _syncDMXBuffer(int index);
    void _chk_SelectAll_Changed(void);
    void FocusChanged(bool dir);
    void on_BtnStartStreaming_clicked();
};

#endif // DMXCONSOLE_H
