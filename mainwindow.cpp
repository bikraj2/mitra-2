#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username= ui->username->text();
     QString password= ui->password->text();
     if (username =="Priyanshu" && password =="fun")
     {
         ui->statusbar->showMessage("Login Successful!",3000);
            hide();
            firstwindow= new Dialog1(this);
            firstwindow->show();
      }
     else
     {
            QMessageBox ::warning(this, "LOGIN","Login Unsuccessful!");
     }

}

