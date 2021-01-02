#include <sqlc.h>


Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("firas");
    db.setPassword("firas");

    if(db.open())
    {
    test=true;}

    return test;
}
