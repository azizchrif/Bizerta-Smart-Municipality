#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Fournisseurs
{private:
    QString Nom;
    QString AdresseEmail;
    QString Adresse;
    int ID;
    int NumTel;

public:
   Fournisseurs();
   Fournisseurs(QString,QString,QString,int,int);
    bool AjouterFournisseurs();
    bool ModifierFournisseurs(int);
   QSqlQueryModel* AfficherFournisseurs();
   QSqlQueryModel* Afficher_desscNom();
   QSqlQueryModel* Afficher_asscNom();
   QSqlQueryModel* Afficher_ascID();//tri asc
   QSqlQueryModel* Afficher_descID();//tri desc
   QSqlQueryModel* Afficher_ascAdresse();//tri asc
   QSqlQueryModel* Afficher_descAdresse();//tri desc
   QSqlQueryModel* Rechercher_ID(int id);
   QSqlQueryModel* Rechercher_Adresse(QString Adresse);
   QSqlQueryModel* Rechercher_Nom(QString Nom);
    bool SupprimerFournisseurs(int);
    bool RechercherFournisseurs();
    bool TrierFournisseurs();
    bool Envoyermail();
    void setNom(QString);
    void setAdresseEmail(QString);
    void setAdresse(QString);
    void setID(int);
    void setNumTel(int);
    QString getNom();
    QString getAdresseEmail();
    QString getAdresse();
    int getID();
    int getNumTel();
};

#endif // FOURNISSEURS_H
