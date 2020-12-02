#include "fournisseurs.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Fournisseurs::Fournisseurs()
{
     Nom="";
     Adresse="";
     AdresseEmail="";
     ID=0;
     NumTel=0;

}
Fournisseurs::Fournisseurs(QString Nom,QString Adresse ,QString AdresseEmail,int ID,int NumTel)
{
    this->Nom=Nom;
    this->Adresse=Adresse;
    this->AdresseEmail=AdresseEmail;
    this->ID=ID;
    this->NumTel=NumTel;
}
void Fournisseurs::setNom(QString Nom){this->Nom=Nom; }
void Fournisseurs::setAdresse(QString Adresse){this->Adresse=Adresse; }
void Fournisseurs::setAdresseEmail(QString AdresseEmail){this->AdresseEmail=AdresseEmail; }
void Fournisseurs::setID(int ID){this->ID=ID;}
void Fournisseurs::setNumTel(int NumTel){this->NumTel=NumTel;}
QString Fournisseurs::getNom(){return(Nom);}
QString Fournisseurs::getAdresse(){return(Adresse);}
QString Fournisseurs::getAdresseEmail(){return(AdresseEmail);}
int Fournisseurs::getID(){return(ID);}
int Fournisseurs::getNumTel(){return(NumTel);}
bool Fournisseurs::AjouterFournisseurs()
{
    QSqlQuery query;

    QString ID_string=QString::number(ID);
    QString NumTel_string=QString::number(NumTel);
          query.prepare("INSERT INTO FOURNISSEUR (NOMF,IDF,NUMTELF,ADRESSEF,ADRESSEEMAILF)"
                        "VALUES (:Nom, :ID, :NumTel,:Adresse,:AdresseEmail)");
          query.bindValue(":Nom", Nom);
          query.bindValue(":ID", ID_string);
          query.bindValue(":NumTel", NumTel_string);
          query.bindValue(":Adresse", Adresse);
          query.bindValue(":AdresseEmail", AdresseEmail);

         return query.exec();


}
QSqlQueryModel* Fournisseurs::AfficherFournisseurs()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM FOURNISSEUR");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
  return  model;
}
QSqlQueryModel* Fournisseurs::Afficher_desscNom()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY NOMF DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Afficher_asscNom()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY NOMF ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Afficher_descID()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY IDF DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Afficher_ascID()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY IDF ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Afficher_descAdresse()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY ADRESSEF DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Afficher_ascAdresse()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY ADRESSEF ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

        return model;
    }
QSqlQueryModel* Fournisseurs::Rechercher_ID(int id)
{
    QSqlQuery query;
    query.prepare("select * from FOURNISSEUR where IDF = :id");
    query.bindValue(":id", id);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
        return model;
    }
QSqlQueryModel* Fournisseurs::Rechercher_Adresse(QString Adresse)
{
    QSqlQuery query;
    query.prepare("select * from FOURNISSEUR where ADRESSEF = :Adresse");
    query.bindValue(":Adresse", Adresse);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
        return model;
    }
QSqlQueryModel* Fournisseurs::Rechercher_Nom(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from FOURNISSEUR where NOMF = :Nom");
    query.bindValue(":Nom", Nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AdresseEmail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
        return model;
    }
bool Fournisseurs::SupprimerFournisseurs(int id)
{
QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("DELETE FROM FOURNISSEUR WHERE IDF =:id");
query.bindValue(":id",id);
return query.exec();
}
bool Fournisseurs::ModifierFournisseurs(int id)
{QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("DELETE FROM FOURNISSEUR WHERE IDF =:id");
    query.bindValue(":id",id);
    query.exec();
    QString NumTel_string=QString::number(NumTel);
          query.prepare("INSERT INTO FOURNISSEUR (NOMF,IDF,NUMTELF,ADRESSEF,ADRESSEEMAILF)"
                        "VALUES (:Nom, :ID, :NumTel,:Adresse,:AdresseEmail)");
          query.bindValue(":Nom", Nom);
          query.bindValue(":ID", id);
          query.bindValue(":NumTel", NumTel_string);
          query.bindValue(":Adresse", Adresse);
          query.bindValue(":AdresseEmail", AdresseEmail);

         return query.exec();

}
