#include "signup.h"
#include "ui_signup.h"
#include <QtSql>
#include<QMessageBox>
#include<mainwindow.h>
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
    QString first_name,last_name,email,username,password,date;
    first_name=ui->lineEdit->text();
    last_name=ui->lineEdit_2->text();
    email=ui->lineEdit_3->text();
    username=ui->lineEdit_5->text();
    password=(ui->lineEdit_6->text());
    date = ui->lineEdit_4->text();

    encrypt(password);
    QSqlQuery qry;
    qry.exec("Insert into newer(first_name,last_name,username,password1,email,DOB) values('"+first_name+"','"+last_name+"','"+username+"','"+password+"','"+email+"','"+date+"')");
    if(qry.exec())
    {

        QMessageBox::warning(this,"thiis it","data added");
    }
    else
    {
        QMessageBox::warning(this,"thiis it",qry.lastError().text());
    }
}
void signup::encrypt(QString &string_encrypt)
{

    QString p_text = string_encrypt;
    int k=598658, value,ascii;
    qDebug()<<k;
    for (int i = 0; i < p_text.size(); i++)
    {
        ascii = (p_text[i]).QChar::unicode();
        if (ascii >= 48 && ascii <= 57)
        {
            value = ((ascii + k - 48) % 10 + 48);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            value = ((ascii + k - 65) % 26 + 65);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            value = ((ascii + k - 97) % 26 + 97);
            string_encrypt[i] = static_cast<char>(value);
        }
        else
        {
            string_encrypt[i] = static_cast<char>(ascii);
        }
    }
}



void signup::on_pushButton_2_clicked()
{
    this->hide();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

