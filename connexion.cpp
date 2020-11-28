#include "connexion.h"
#include <QDebug>

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A");
    db.setUserName("skander");
    db.setPassword("skander");
    if(db.open())
    {
        test=true;
    }
    qDebug()<<db.lastError().text();
    return test;
}
