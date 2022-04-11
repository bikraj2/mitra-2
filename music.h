#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>

namespace Ui {

class music;
}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();
private slots:
    void on_StartButton_clicked();

    void on_sliderVolume_sliderMoved(int position);

    void on_sliderProgress_sliderMoved(int position);

    void on_StopButton_clicked();

    void on_durationChanged(qint64 position);
    void on_positionChanged(qint64 position);
private:
    Ui::music *ui;
    QMediaPlayer *player;
    QAudioOutput *audio;
};

#endif // MUSIC_H






