#ifndef COLLABORATEUR_H
#define COLLABORATEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Collaborateur
{private:

    QString Nom;
    QString Prenom;
    QString Adresse;
    int CIN;
    int NumTel;


public:
   Collaborateur();
    Collaborateur(QString,QString,QString,int,int);
    bool AjouterCollaborateur();
    bool ModifierCollaborateur();
   QSqlQueryModel* AfficherCollaborateur();
   QSqlQueryModel* Afficher_ascnom();//tri asc
   QSqlQueryModel* Afficher_descnom();//tri desc
   QSqlQueryModel* Afficher_ascCIN();//tri asc
   QSqlQueryModel* Afficher_descCIN();//tri desc
   QSqlQueryModel* Afficher_ascNumTel();//tri asc
   QSqlQueryModel* Afficher_descNumTel();//tri desc
   QSqlQueryModel* Rechercher_CIN(int cin);
   QSqlQueryModel* Rechercher_NumTel(int Etat);
   QSqlQueryModel* Rechercher_Nom(QString Nom);
    bool SupprimerCollaborateur(int cin);
    void setNom(QString);
    void setCIN(int);
    void setNumTel(int);
    void setPrenom(QString);
    void setAdresse(QString);
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    int getCIN();
    int getNumTel();



};


#endif // COLLABORATEUR_H
