#ifndef PERSONEL_H
#define PERSONEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>




class Personel
{
public:
    Personel();
    Personel(QString,QString,QString,QString,QString,QString);
    void setnom(QString n){nom=n;}
    void setprenom(QString n){prenom=n;}
    void setID(QString n){ID=n;}
    void setadresse(QString n){adresse=n;}
    void settel(QString n){tel=n;}
    void setemail(QString n){email=n;}

    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getID(){return ID;}
    QString getadresse(){return adresse;}
    QString gettel(){return tel;}
    QString getemail(){return email;}
   bool ajouterperso();
   QSqlQueryModel *afficherperso();
   QSqlQueryModel *rechercherperso(QSqlQuery);
   QSqlQueryModel *tri_nom();


   bool supprimerperso(QString);
   bool verif_id(QString);
   bool verif_nom(QString);
   bool verif_email(QString);



private:
    QString ID,nom,prenom,adresse,tel,email;

};

#endif // PERSONEL_H
