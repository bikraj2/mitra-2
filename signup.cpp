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
    qry.exec("Insert into usersa(first_name,last_name,username,password1,email) values('"+first_name+"','"+last_name+"','"+username+"','"+password+"','"+email+"')");
    if(qry.exec())
    {

        QMessageBox::warning(this,"thiis it","data added");
    }
    else
    {
        QMessageBox::warning(this,"thiis it",qry.lastError().text());
    }
}

