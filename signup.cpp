#include "signup.h"
#include "ui_signup.h"
#include <QtSql>
#include<QMessageBox>
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    QString first_name,last_name,email,username,password;
    int age;
    first_name=ui->lineEdit->text();
    last_name=ui->lineEdit_2->text();
    age=(ui->lineEdit_4->text().toInt());
    email=ui->lineEdit_3->text();
    username=ui->lineEdit_5->text();
    password=ui->lineEdit_6->text();
    QSqlQuery qry;
    qry.exec("Insert into usera(first_name,last_name,Age,email,user_name,password) values(?,?,?,?,?,?)");

    qry.addBindValue(first_name);
    qry.addBindValue(last_name);
    qry.addBindValue(age);
    qry.addBindValue(email);
    qry.addBindValue(username);
    qry.addBindValue(password);
    if(qry.exec())
    {

        QMessageBox::warning(this,"thiis it","data added");
    }
    else
    {
        QMessageBox::warning(this,"thiis it",qry.lastError().text());
    }
}

