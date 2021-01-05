
#include "evenements.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Evenements::Evenements()
{
     Nom="";
     ID=0;
     Date=0;
     Type="";

}
Evenements::Evenements(int ID,QString Nom,QString Type, int Date)
{
    this->Nom=Nom;
    this->ID=ID;
    this->Date=Date;
    this->Type=Type;
    //test
}
void Evenements::setNom(QString Nom){this->Nom=Nom; }
void Evenements::setID(int ID){this->ID=ID;}
void Evenements::setDate(int Date){this->Date=Date;}
void Evenements::setType(QString Type){this->Type=Type; }
QString Evenements::getNom(){return(Nom);}
int Evenements::getID(){return(ID);}
int Evenements::getDate(){return(Date);}
QString Evenements::getType(){return(Type);}
bool Evenements::AjouterEvenements()
{
    QSqlQuery query;

    QString ID_string=QString::number(ID);
    QString Date_string=QString::number(Date);

          query.prepare("INSERT INTO T_EV (IDT,NOMT,TYPET,DATET)"
                        "VALUES (:ID, :Nom, :Type,:Date)");
          query.bindValue(":ID", ID_string);
          query.bindValue(":Nom", Nom);
          query.bindValue(":Type", Type);
          query.bindValue(":Date", Date_string);
         return query.exec();


}
QSqlQueryModel* Evenements::AfficherEvenements()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM T_EV");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
  return  model;
}
QSqlQueryModel* Evenements::Afficher_descID()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY IDT DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

        return model;
    }
QSqlQueryModel* Evenements::Afficher_ascID()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY IDT ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        return model;
    }
QSqlQueryModel* Evenements::Afficher_descnom()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY NOMT DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

        return model;
    }
QSqlQueryModel* Evenements::Afficher_ascnom()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY NOMT ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

        return model;
    }
QSqlQueryModel* Evenements::Afficher_descDate()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY DATET DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

        return model;
    }
QSqlQueryModel* Evenements::Afficher_ascDate()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_EV ORDER BY DATET ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

        return model;
    }
QSqlQueryModel* Evenements::Rechercher_ID(int id)
{
    QSqlQuery query;
    query.prepare("select * from T_EV where IDT = :id");
    query.bindValue(":id", id);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        return model;
    }
QSqlQueryModel* Evenements::Rechercher_date(int Date)
{
    QSqlQuery query;
    query.prepare("select * from T_EV where DATET = :Date");
    query.bindValue(":Date", Date);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        return model;
    }
QSqlQueryModel* Evenements::Rechercher_Nom(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from T_EV where NOMT = :Nom");
    query.bindValue(":Nom", Nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        return model;
    }
bool Evenements::SupprimerEvenements(int id)
{
QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("DELETE FROM T_EV WHERE IDT =:id");
query.bindValue(":id",id);
return query.exec();
}
bool Evenements::ModifierEvenements()
{

QSqlQuery query;
QString id_string= QString::number(ID);
QString Date_string=QString::number(Date);
   query.prepare("UPDATE T_EV set IDT=:ID, NOMT=:Nom, TYPET=:Type, DATET=:Date where IDT=:ID");

   query.bindValue(":ID", id_string);
   query.bindValue(":Nom", Nom);
   query.bindValue(":Type", Type);
   query.bindValue(":Date", Date_string);

   return query.exec();

}
