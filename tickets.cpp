#include "tickets.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Tickets::Tickets()
{
     Titre="";
     Num=0;
     Prix=0;
     Description="";

}
Tickets::Tickets(int Num,QString Titre, int Prix,QString Description)
{
    this->Num=Num;
    this->Titre=Titre;
    this->Prix=Prix;
    this->Description=Description;
    //test
}
void Tickets::setTitre(QString Titre){this->Titre=Titre; }
void Tickets::setNum(int Num){this->Num=Num;}
void Tickets::setPrix(int Prix){this->Prix=Prix;}
void Tickets::setDescription(QString Description){this->Description=Description; }
QString Tickets::getTitre(){return(Titre);}
int Tickets::getNum(){return(Num);}
int Tickets::getPrix(){return(Prix);}
QString Tickets::getDescription(){return(Description);}
bool Tickets::AjouterTickets()
{
    QSqlQuery query;

    QString Num_string=QString::number(Num);
    QString Prix_string=QString::number(Prix);

          query.prepare("INSERT INTO T_TICKET (NUMT,TITRET,PRIXT,DESCT)"
                        "VALUES (:Num, :Titre, :Prix,:Description)");
          query.bindValue(":Num", Num_string);
          query.bindValue(":Titre", Titre);
          query.bindValue(":Description", Description);
          query.bindValue(":Prix", Prix_string);
         return query.exec();


}
QSqlQueryModel* Tickets::AfficherTickets()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM T_TICKET");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
  return  model;
}
QSqlQueryModel* Tickets::Afficher_descNum()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY NUMT DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

        return model;
    }
QSqlQueryModel* Tickets::Afficher_ascNum()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY NUMT ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        return model;
    }
QSqlQueryModel* Tickets::Afficher_descTitre()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY TITRET DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

        return model;
    }
QSqlQueryModel* Tickets::Afficher_ascTitre()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY TITRET ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

        return model;
    }
QSqlQueryModel* Tickets::Afficher_descPrix()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY PRIXT DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

        return model;
    }
QSqlQueryModel* Tickets::Afficher_ascPrix()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from T_TICKET ORDER BY PRIXT ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        return model;
    }
QSqlQueryModel* Tickets::Rechercher_Num(int num)
{
    QSqlQuery query;
    query.prepare("select * from T_TICKET where NUMT = :num");
    query.bindValue(":num", num);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        return model;
    }
QSqlQueryModel* Tickets::Rechercher_Prix(int Prix)
{
    QSqlQuery query;
    query.prepare("select * from T_TICKET where PRIXT = :Prix");
    query.bindValue(":Prix",Prix);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        return model;
    }
QSqlQueryModel* Tickets::Rechercher_Titre(QString Nom)
{
    QSqlQuery query;
    query.prepare("select * from T_TICKET where TITRET = :Nom");
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
bool Tickets::SupprimerTickets(int id)
{
QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("DELETE FROM T_TICKET WHERE NUMT =:id");
query.bindValue(":id",id);
return query.exec();
}
bool Tickets::ModifierTickets()
{

    QSqlQuery query;
    QString Num_string= QString::number(Num);
    QString Prix_string=QString::number(Prix);
       query.prepare("UPDATE T_TICKET set NUMT=:Num, TITRET=:Titre, PRIXT=:Prix,  DESCT=:Description where NUMT=:Num");

       query.bindValue(":Num", Num_string);
       query.bindValue(":Titre", Titre);
       query.bindValue(":Prix", Prix_string);
       query.bindValue(":Description", Description);

       return query.exec();

}
