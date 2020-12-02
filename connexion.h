#ifndef CONNECTION_H
#define CONNECTION_H
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>









class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
