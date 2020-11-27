#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createConnexion();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connexion successfull\n"
                                                                                     "CLick OK to exit"),QMessageBox::Ok);}
    else

    {QMessageBox::information(nullptr,QObject::tr("database is not open"),QObject::tr("connexion failed\n"
                                                                                    "CLick Cancel to exit"),QMessageBox::Cancel);}

        return a.exec();}


