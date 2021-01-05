#ifndef POSTE_H
#define POSTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Poste
{
public:
    Poste();
    Poste(QString,QString,QString,QString);
    void setfonction(QString n){fonction=n;}
    void setdepartement(QString n){departement=n;}
    void setheures(QString n){heures=n;}
    void setsalaire(QString n){salaire=n;}

    QString getfonction(){return fonction;}
    QString getdepartement(){return departement;}
    QString getheures(){return heures;}
    QString getsalaire(){return salaire;}

     bool ajouterposte();
     bool supprimerposte(QString);
     QSqlQueryModel *afficherposte();
     QSqlQueryModel *rechercherposte(QSqlQuery);


     bool verif_nom(QString);



private:
    QString fonction,departement,salaire,heures;
};

#endif // POSTE_H
