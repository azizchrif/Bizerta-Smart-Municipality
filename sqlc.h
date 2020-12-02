#ifndef SQLC_H
#define SQLC_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};


#endif // SQLC_H
