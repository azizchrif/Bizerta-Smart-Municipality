#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    bool test= c.createconnect();
    if (test)
    {
        w.show();}
    else
            QMessageBox::information(nullptr,QObject::tr("database is open"),
                                     QObject::tr("connection successful.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);

}
    else    {
            QMessageBox:: critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("connection failed.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);
            }

    w.show();
    return a.exec();
}
