#include "connexion.h"

connection::connection() {}

bool connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("mohamed");
    db.setPassword("mohamed");
 if(db.open())  test=true;
     test=true;


   return test;


}
//void connection::closeConnection(){

  //  db.close();}
