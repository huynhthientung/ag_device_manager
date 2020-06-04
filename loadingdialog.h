#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include <QMainWindow>
#include <QMovie>
namespace Ui {
class LoadingDialog;
}

class LoadingDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = 0);
    ~LoadingDialog();
    void showDialog(void);
    void hideDialog(void);
private:
    Ui::LoadingDialog *ui;
    QMovie* movie;
};

#endif // LOADINGDIALOG_H
