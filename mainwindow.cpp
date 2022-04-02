#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
#include<QtSql>
#include<QFileInfo>
#include<QtDebug>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db_conn_open();
    if (setTable())
        ui->label3->setText("Table Created");
    else
    {
        ui->label3->setText("Not created ");
    }
    QDir x;
    ui->label3->setText(x.currentPath());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_login_3_clicked()
{
    QString username = ui->username_3->text();
    QString password = ui->Password_3->text();
    ui->label3->setText(username+password);
    QSqlQuery qry;
    if(qry.exec("Select * from usera where user_name= '"+username+"' and password= '"+password+"'"))
    {
        ui->label3->setText("hey bro here i am");
        int count =0;
        while(qry.next())
        {
            count++;
        }
        if (count<1)
        {
            QMessageBox:: warning(this,"Incorrect Credentials","Please make sure you have entered the correct username and passowrd.");
        }
        else if (count>=1)
        {
            hide();
            firstwindow = new Dialog1(this);
            firstwindow->show();
        }
    }
    else
    {
        QMessageBox:: warning(this,"hey",qry.lastError().text());
    }

}


void MainWindow::on_pushButton_singup_3_clicked()
{
    hide();
    register1 =  new signup(this);
    register1->show();
}
void MainWindow:: db_conn_open()
{
    QDir data("C:/Db");
    if (!data.exists())
    {
        data.mkpath("C:/Db");
    }
    QSqlDatabase info  =  QSqlDatabase::addDatabase("QSQLITE");
    info.setDatabaseName("C:/Db/users_info.db");
    if(!info.open())
        ui->name->setText("Failed to connect to the database.");
    else
        ui->name->setText("connected to the database successfully");
}
bool MainWindow :: setTable()
{
    QSqlQuery table1;
    QString qry="Create Table usersa"
            "("
                "first_name varchar(50),"
                "last_name varchar(50),"
                "username varchar(50),"
               " password1 varchar(50),"
                "email varchar(100)"
            ");";
    if (table1.exec(qry))
        return true;
    return false;

}
