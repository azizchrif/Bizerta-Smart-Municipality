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

}
Equipements::Equipements(QString Nom,int ID, int Etat)
{
    this->Nom=Nom;
    this->ID=ID;
    this->Etat=Etat;
    //test
}
void Equipements::setNom(QString Nom){this->Nom=Nom; }
void Equipements::setID(int ID){this->ID=ID;}
void Equipements::setEtat(int Etat){this->Etat=Etat;}
QString Equipements::getNom(){return(Nom);}
int Equipements::getID(){return(ID);}
int Equipements::getEtat(){return(Etat);}
bool Equipements::AjouterEquipements()
{
    QSqlQuery query;

    QString ID_string=QString::number(ID);
    QString Etat_string=QString::number(Etat);

          query.prepare("INSERT INTO EQUIPEMENTS (NOM,ID,ETAT)"
                        "VALUES (:Nom, :ID, :Etat)");
          query.bindValue(":ID", ID_string);
          query.bindValue(":Etat", Etat_string);
          query.bindValue(":Nom", Nom);

         return query.exec();


}
QSqlQueryModel* Equipements::AfficherEquipements()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM EQUIPEMENTS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
  return  model;
}
bool Equipements::SupprimerEquipements(int ID)
{
QSqlQuery query;
query.prepare("DELETE FROM EQUIPEMENTS WHERE ID =:ID");
query.bindValue(":ID",ID);
return query.exec();}
