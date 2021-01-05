#include "collaborateur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Collaborateur::Collaborateur()
{

     Nom="";
     Prenom="";
     Adresse="";
     CIN=0;
     NumTel=0;
}
Collaborateur::Collaborateur(QString Nom,QString Prenom,QString Adresse ,int CIN, int NumTel)
{
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Adresse=Adresse;
    this->CIN=CIN;
    this->NumTel=NumTel;

}
void Collaborateur::setNom(QString Nom){this->Nom=Nom; }
void Collaborateur::setPrenom(QString Prenom){this->Prenom=Prenom; }
void Collaborateur::setAdresse(QString Adresse){this->Adresse=Adresse; }
void Collaborateur::setCIN(int CIN){this->CIN=CIN;}
void Collaborateur::setNumTel(int NumTel){this->NumTel=NumTel;}
QString Collaborateur::getNom(){return(Nom);}
QString Collaborateur::getPrenom(){return(Prenom);}
QString Collaborateur::getAdresse(){return(Adresse);}
int Collaborateur::getCIN(){return(CIN);}
int Collaborateur::getNumTel(){return(NumTel);}
bool Collaborateur::AjouterCollaborateur()
{
    QSqlQuery query;

    QString CIN_string=QString::number(CIN);
    QString NumTel_string=QString::number(NumTel);

          query.prepare("INSERT INTO COLLABORATEUR (CIN,PRENOM,NOM,ADRESSE,NUMTEL)"
                        "VALUES (:CIN,:Prenom,:Nom, :Adresse,:NumTel)");
          query.bindValue(":CIN", CIN_string);
          query.bindValue(":Nom", Nom);
          query.bindValue(":Prenom", Prenom);
          query.bindValue(":Adresse", Adresse);
          query.bindValue(":NumTel", NumTel_string);
         return query.exec();


}
QSqlQueryModel* Collaborateur::AfficherCollaborateur()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM COLLABORATEUR");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
  return  model;
}
QSqlQueryModel* Collaborateur::Afficher_descCIN()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from  COLLABORATEUR ORDER BY CIN DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));

        return model;
    }
QSqlQueryModel* Collaborateur::Afficher_ascCIN()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from COllABORATEUR ORDER BY CIN ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
QSqlQueryModel* Collaborateur::Afficher_descnom()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from  COLLABORATEUR ORDER BY NOM DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));

        return model;
    }
QSqlQueryModel* Collaborateur::Afficher_ascnom()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from COLLABORATEUR ORDER BY NOM ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
QSqlQueryModel* Collaborateur::Afficher_descNumTel()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from COLLABORATEUR ORDER BY NUMTEL DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));

        return model;
    }
QSqlQueryModel* Collaborateur::Afficher_ascNumTel()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from COLLABORATEUR ORDER BY NUMTEL ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
QSqlQueryModel* Collaborateur::Rechercher_CIN(int CIN)
{
    QSqlQuery query;
    query.prepare("select * from COLLABORATEUR where CIN = :CIN");
    query.bindValue(":CIN", CIN);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
QSqlQueryModel* Collaborateur::Rechercher_NumTel(int NumTel)
{
    QSqlQuery query;
    query.prepare("select * from COLLABORATEUR where NUMTEL = :NumTel");
    query.bindValue(":NumTel", NumTel);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
QSqlQueryModel* Collaborateur::Rechercher_Nom(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from COLLABORATEUR where NOM = :Nom");
    query.bindValue(":Nom", Nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NumTel"));
        return model;
    }
bool Collaborateur::SupprimerCollaborateur(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    query.prepare("DELETE FROM COLLABORATEUR WHERE CIN =:cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
bool Collaborateur::ModifierCollaborateur()
{

    QSqlQuery query;
    QString cin_string= QString::number(CIN);
    QString NumTel_string=QString::number(NumTel);
       query.prepare("UPDATE COLLABORATEUR set CIN=:CIN, PRENOM=:Prenom, NOM=:Nom,  ADRESSE=:Adresse,NUMTEL=:NumTel where CIN=:CIN");

       query.bindValue(":CIN", cin_string);
       query.bindValue(":Nom", Nom);
       query.bindValue(":Prenom", Prenom);
       query.bindValue(":Adresse", Adresse);
       query.bindValue(":NumTel", NumTel_string);

       return query.exec();

}

