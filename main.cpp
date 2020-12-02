#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
int main(int argc, char *argv[])
{
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/hpprobook/Desktop/Final/Mortified.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.ouvrirConnexion();
    MainWindow w;
    w.show();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connexion successfull\n"
                                                                                     "CLick OK to exit"),QMessageBox::Ok);}
    else

    {QMessageBox::information(nullptr,QObject::tr("database is not open"),QObject::tr("connexion failed\n"
                                                                                    "CLick Cancel to exit"),QMessageBox::Cancel);}

        return a.exec();}


