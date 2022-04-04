#include "forgotpassword.h"
#include "ui_forgotpassword.h"

ForgotPassword::ForgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}


void ForgotPassword::on_pushButton_clicked()
{
    QString username2,DOB,nickname;
    username2=ui->username3->text();
    qDebug() << username2;
    qDebug() <<"hey you";
}

