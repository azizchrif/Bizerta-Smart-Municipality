#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Equipements
{private:
    QString Nom;
    int ID;
    int Etat;
    int Prix;

public:
   Equipements();
    Equipements(QString,int,int,int);
    bool AjouterEquipements();
    bool ModifierEquipements();
   QSqlQueryModel* AfficherEquipements();
   QSqlQueryModel* Afficher_ascnom();//tri asc
   QSqlQueryModel* Afficher_descnom();//tri desc
   QSqlQueryModel* Afficher_ascprix();//tri asc
   QSqlQueryModel* Afficher_descprix();//tri desc
   QSqlQueryModel* Afficher_ascetat();//tri asc
   QSqlQueryModel* Afficher_descetat();//tri desc
   QSqlQueryModel* Rechercher_ID(int id);
   QSqlQueryModel* Rechercher_Etat(int Etat);
   QSqlQueryModel* Rechercher_Nom(QString Nom);
   int verifEtat(int Etat) ;
    bool SupprimerEquipements(int);
    bool Envoyermail();
    void setNom(QString);
    void setID(int);
    void setEtat(int);
    void setPrix(int);
    QString getNom();
    int getID();
    int getEtat();
    int getPrix();


};

#endif // EQUIPEMENTS_H
