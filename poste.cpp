#include "poste.h"

Poste::Poste()
{
    fonction="";
    heures="";
    departement="";
    salaire="";

}
Poste::Poste(QString fonction,QString heures,QString departement,QString salaire)
{
    this->fonction=fonction;
    this->heures=heures;
    this->departement=departement;
    this->salaire=salaire;
}

bool Poste::ajouterposte()
{
    QSqlQuery query;
    query.prepare("INSERT INTO POSTE(FONCTION,HEURES,DEPARTEMENT,SALAIRE) "
                  "VALUES ('"+fonction+"','"+heures+"','"+departement+"','"+salaire+"')");
    query.bindValue(":FONCTION",fonction);
    query.bindValue(":HEURES",heures);
    query.bindValue(":DEPARTEMENT",departement);
    query.bindValue(":SALAIRE",salaire);
    Poste po(fonction,heures,departement,salaire);
    return query.exec();
}

QSqlQueryModel * Poste::afficherposte()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("Select * from POSTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("heures"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
    return model;
}

bool Poste::supprimerposte(QString fonction)
{
    QSqlQuery query;

    query.prepare("DELETE FROM POSTE WHERE Fonction = :fonction");
    query.bindValue(":fonction",fonction);
    return  query.exec();
}



bool Poste::verif_nom(QString n)
{
    bool test=true;
   for(int i=0;i<n.length();i++)
   {
       if(!(((n[i]>='A')&&(n[i]<='Z'))||((n[i]>='a')&&(n[i]<='z'))))
       {
               test=false;
   }
}
   return test;
}

QSqlQueryModel* Poste ::rechercherposte(QSqlQuery q)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery(q);
    return model;
}
