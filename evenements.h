#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Evenements
{private:
    QString Nom;
    int ID;
    int Date;
     QString Type;

public:
   Evenements();
    Evenements(int,QString,QString,int);
    bool AjouterEvenements();
    bool ModifierEvenements();
   QSqlQueryModel* AfficherEvenements();
   QSqlQueryModel* Afficher_ascnom();//tri asc
   QSqlQueryModel* Afficher_descnom();//tri desc
   QSqlQueryModel* Afficher_ascID();//tri asc
   QSqlQueryModel* Afficher_descID();//tri desc
   QSqlQueryModel* Afficher_ascDate();//tri asc
   QSqlQueryModel* Afficher_descDate();//tri desc
   QSqlQueryModel* Rechercher_ID(int id);
   QSqlQueryModel* Rechercher_date(int Date);
   QSqlQueryModel* Rechercher_Nom(QString Nom);
    bool SupprimerEvenements(int);
    bool Envoyermail();
    void setNom(QString);
    void setID(int);
    void setDate(int);
    void setType(QString);
    QString getNom();
    int getID();
    int getDate();
    QString getType();


};
#endif // EVENEMENTS_H
