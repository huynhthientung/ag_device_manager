#include "loadingdialog.h"
#include "ui_loadingdialog.h"
#include <QDebug>
#include <QDir>
#include <QMessageBox>
LoadingDialog::LoadingDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadingDialog)
{
    ui->setupUi(this);
    movie = new QMovie(this);
    ui->lb_loadingImg->setMovie(movie);
    movie->setFileName(":/images/waiting.gif");

    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
        // Something went wrong :(
        qDebug()<<movie->fileName();
        qDebug()<<"cant open loading img";
    }

    // Play GIF

    movie->start();
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}

void LoadingDialog::showDialog(void)
{
    this->show();
}

void LoadingDialog::hideDialog(void)
{
    this->hide();
}
