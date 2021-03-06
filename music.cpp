#include "music.h"
#include "ui_music.h"

music::music(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    player->setAudioOutput(audio);

    connect (player, &QMediaPlayer::positionChanged, this, &music:: on_positionChanged);
    connect (player, &QMediaPlayer::durationChanged, this, &music:: on_durationChanged);

}

music::~music()
{
    delete ui;
}







void music:: on_StartButton_clicked()
{
    // load and play the file
    player->setSource(QUrl::fromLocalFile("C:/Users/Lenovo/OneDrive/Documents/TEMP2-main/songs/moonlight.mp3"));

    player->play();

    qDebug()<< player->errorString();


}




void music::on_StopButton_clicked()
{
    player->stop();

}

void music:: on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}
void music:: on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}


void music::on_sliderVolume_sliderMoved(int position)
{
    audio->setVolume(position);

}


void music::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

