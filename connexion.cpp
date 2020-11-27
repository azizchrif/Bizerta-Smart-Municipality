#include "connexion.h"
#include <QSqlDatabase>
#include <QDebug>
connexion::connexion()
{

}
bool connexion::createConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("azizchrif");
    db.setUserName("aziz");
    db.setPassword("aziz07");
    if(db.open())

            test=true;
        return test;

}
