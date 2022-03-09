#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog1.h"
#include "signup.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_pushButton_login_3_clicked();

    void on_pushButton_singup_3_clicked();

private:
    Ui::MainWindow *ui;
    Dialog1 *firstwindow;
    signup * register1;

};
#endif // MAINWINDOW_H
