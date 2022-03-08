#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include"dialog2.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:


    void on_Profile_clicked();

private:
    Ui::Dialog1 *ui;
     Dialog2 *profilewindow;
};

#endif // DIALOG1_H
