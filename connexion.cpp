#include "connexion.h"
#include <QDebug>

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetqt");
    db.setUserName("aziz");
    db.setPassword("aziz07");
    if(db.open())
    {
        test=true;
    }
    qDebug()<<db.lastError().text();
    return test;
}
