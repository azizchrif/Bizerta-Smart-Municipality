#include "equipements.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Equipements::Equipements()
{
     Nom="";
     ID=0;
     Etat=0;
     Prix=0;

}
Equipements::Equipements(QString Nom,int ID, int Etat, int Prix)
{
    this->Nom=Nom;
    this->ID=ID;
    this->Etat=Etat;
    this->Prix=Prix;
    //test
}
void Equipements::setNom(QString Nom){this->Nom=Nom; }
void Equipements::setID(int ID){this->ID=ID;}
void Equipements::setEtat(int Etat){this->Etat=Etat;}
void Equipements::setPrix(int Prix){this->Prix=Prix;}
QString Equipements::getNom(){return(Nom);}
int Equipements::getID(){return(ID);}
int Equipements::getEtat(){return(Etat);}
int Equipements::getPrix(){return(Prix);}
bool Equipements::AjouterEquipements()
{
    QSqlQuery query;

    QString ID_string=QString::number(ID);
    QString Etat_string=QString::number(Etat);
    QString Prix_string=QString::number(Prix);

          query.prepare("INSERT INTO EQUIPEMENT (ID,NOM,PRIX,ETAT)"
                        "VALUES (:ID, :Nom, :Prix,:Etat)");
          query.bindValue(":ID", ID_string);
          query.bindValue(":Nom", Nom);
          query.bindValue(":Prix", Prix_string);
          query.bindValue(":Etat", Etat_string);
         return query.exec();


}
QSqlQueryModel* Equipements::AfficherEquipements()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM EQUIPEMENT");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
  return  model;
}
QSqlQueryModel* Equipements::Afficher_descprix()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY PRIX DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Afficher_ascprix()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY PRIX ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Afficher_descnom()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY NOM DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Afficher_ascnom()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY NOM ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Afficher_descetat()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY NOM DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Afficher_ascetat()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY NOM ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

        return model;
    }
QSqlQueryModel* Equipements::Rechercher_ID(int id)
{
    QSqlQuery query;
    query.prepare("select * from EQUIPEMENT where ID = :id");
    query.bindValue(":id", id);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model;
    }
QSqlQueryModel* Equipements::Rechercher_Etat(int Etat)
{
    QSqlQuery query;
    query.prepare("select * from EQUIPEMENT where Etat = :Etat");
    query.bindValue(":Etat", Etat);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model;
    }
QSqlQueryModel* Equipements::Rechercher_Nom(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from EQUIPEMENT where NOM = :Nom");
    query.bindValue(":Nom", Nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
        return model;
    }
bool Equipements::SupprimerEquipements(int id)
{
QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("DELETE FROM EQUIPEMENT WHERE ID =:id");
query.bindValue(":id",id);
return query.exec();
}
bool Equipements::ModifierEquipements()
{

QSqlQuery query;
QString id_string= QString::number(ID);
QString Etat_string=QString::number(Etat);
QString Prix_string=QString::number(Prix);
   query.prepare("UPDATE EQUIPEMENT set ID=:ID, NOM=:Nom, PRIX=:Prix,  ETAT=:Etat where ID=:ID");

   query.bindValue(":ID", id_string);
   query.bindValue(":Nom", Nom);
   query.bindValue(":Prix", Prix_string);
   query.bindValue(":Etat", Etat_string);

   return query.exec();
}
