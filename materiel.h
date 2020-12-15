#ifndef MATERIEL_H
#define MATERIEL_H
#include <QSqlQueryModel>
#include <QString>
class materiel
{
    QString id;
    QString quantite;
    QString type;



    public:
   materiel();
       materiel(QString,QString,QString);
       ~materiel();

      QString getid();
       void setid(QString);
      QString getquantite();
       void setquantite(QString);


       QString gettype();
       void settype(QString);

       bool ajouter();
       bool supprimer(int);
       bool modifier(QString,QString,QString);
       QSqlQueryModel* afficher();
      materiel recherche_Id(int);
       materiel recherche_nom(QString);
       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();

       QSqlQueryModel * chercher_materiel_par_nom(QString m);
       QSqlQueryModel * chercher_materiel_par_capacite(QString m);

       QSqlQueryModel * chercher_sponsorisation_par_id(QString idd);
};

#endif // MATERIEL_H
