#ifndef TERRAIN_H
#define TERRAIN_H
#include <QString>
#include <QSqlQueryModel>
class Terrain
{
    int id;
    QString emplacement;
     QString etat;
    QString nom;

    public:
   Terrain();
       Terrain(int,QString,QString,QString);
       ~Terrain();
       QSqlQueryModel* recherche_nom(QString );
        bool verifierExnoms(QString );
       int getid();
       void setid(int);
       QString getnom();
       void setnom(QString);
       QString getemplacement();
       void setemplacement(QString);
       QString getetat();
       void setetat(QString);

       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,QString,QString);
       QSqlQueryModel* afficher();
      Terrain recherche_Id(int);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();

       QSqlQueryModel * chercher_Terrain_par_nom(QString m);
       QSqlQueryModel * chercher_Terrain_par_capacite(QString m);

       QSqlQueryModel * chercher_sponsorisation_par_id(QString idd);
};

#endif // TERRAIN_H
