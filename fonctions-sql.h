#ifndef FONCTIONSSQL_H
#define FONCTIONSSQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class gestions
{
public:
    gestions();
    bool ajoutev(QString id, QString nom, QString type,QString date);
    bool suppev(QString id);
    bool modifev(QString id, QString nom, QString type,QString date);
    QString affichev(QString id, QString nom, QString type,QString date);
    bool ajoutt(QString num, QString titre, QString prix,QString desc);
    bool suppt(QString num);
    bool modift(QString num, QString titre, QString prix,QString desc);
    QString afficht(QString num, QString titre, QString prix,QString desc);
    int nbticket();
    int tottik();
};


#endif // FONCTIONSSQL_H
