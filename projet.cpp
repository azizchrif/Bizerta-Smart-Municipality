#include "projet.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
Projet::Projet()
{
     TitrePro="";
     ChefPro="";
     NumPro=0;
     Budget=0;
}
Projet::Projet(QString TitrePro,QString ChefPro,int NumPro, int Budget)
{
    this->TitrePro=TitrePro;
    this->ChefPro=ChefPro;
    this->NumPro=NumPro;
    this->Budget=Budget;

}
void Projet::setTitrePro(QString TitrePro){this->TitrePro=TitrePro; }
void Projet::setChefPro(QString ChefPro){this->ChefPro=ChefPro; }
void Projet::setNumPro(int NumPro){this->NumPro=NumPro;}
void Projet::setBudget(int Budget){this->Budget=Budget;}
QString Projet::getTitrePro(){return(TitrePro);}
QString Projet::getChefPro(){return(ChefPro);}
int Projet::getNumPro(){return(NumPro);}
int Projet::getBudget(){return(Budget);}
bool Projet::AjouterProjet()
{
    QSqlQuery query;

    QString NumPro_string=QString::number(NumPro);
    QString Budget_string=QString::number(Budget);

          query.prepare("INSERT INTO PROJET (NUMPRO,TITREPRO,CHEFPRO,BUDGET)"
                        "VALUES (:NumPro,:TitrePro,:ChefPro,:Budget)");
          query.bindValue(":NumPro", NumPro_string);
          query.bindValue(":TitrePro",TitrePro);
          query.bindValue(":ChefPro", ChefPro);
          query.bindValue(":Budget", Budget_string);
         return query.exec();


}
QSqlQueryModel* Projet::AfficherProjet()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM PROJET");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
  return  model;
}
QSqlQueryModel* Projet::Afficher_descNumPro()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from  PROJET ORDER BY NUMPRO DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));

        return model;
    }
QSqlQueryModel* Projet::Afficher_ascNumPro()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from PROJET ORDER BY NUMPRO ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
        return model;
    }
QSqlQueryModel* Projet::Afficher_descTitrePro()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from  PROJET ORDER BY TITREPRO DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));

        return model;
    }
QSqlQueryModel* Projet::Afficher_ascTitrePro()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from PROJET ORDER BY TITREPRO ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));

        return model;
    }
QSqlQueryModel* Projet::Afficher_descBudget()//tri desc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from PROJET ORDER BY BUDGET DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));

        return model;
    }
QSqlQueryModel* Projet::Afficher_ascBudget()//tri asc
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("select * from PROJET ORDER BY BUDGET ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
        return model;
    }
QSqlQueryModel* Projet::Rechercher_NumPro(int NumPro)
{
    QSqlQuery query;
    query.prepare("select * from PROJET where NUMPRO = :NumPro");
    query.bindValue(":NumPro", NumPro);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
        return model;
    }
QSqlQueryModel* Projet::Rechercher_Budget(int Budget)
{
    QSqlQuery query;
    query.prepare("select * from PROJET where BUDGET = :Budget");
    query.bindValue(":Budget",Budget);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
        return model;
    }
QSqlQueryModel* Projet::Rechercher_TitrePro(QString TitrePro)
{
    QSqlQuery query;
    query.prepare("select * from PROJET where TITREPRO = :TitrePro");
    query.bindValue(":TitrePro", TitrePro);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumPro"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TitrePro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ChefPro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
        return model;
    }
bool Projet::SupprimerProjet(int NumPro)
{
    QSqlQuery query;
    QString NumPro_string= QString::number(NumPro);
    query.prepare("DELETE FROM PROJET WHERE NUMPRO =:NumPro");
    query.bindValue(":NumPro",NumPro_string);
    return query.exec();
}
bool Projet::ModifierProjet()
{
   QSqlQuery query;
    QString NumPro_string= QString::number(NumPro);
    QString Budget_string=QString::number(Budget);
       query.prepare("UPDATE PROJET set NUMPRO=:NumPro, TITREPRO=:TitrePro, CHEFPRO=:ChefPro,  BUDGET=:Budget where NUMPRO=:NumPro");

          query.bindValue(":NumPro", NumPro_string);
          query.bindValue(":TitrePro",TitrePro);
          query.bindValue(":ChefPro", ChefPro);
          query.bindValue(":Budget", Budget_string);
       return query.exec();

}

