#include "projet.h"
#include <QDebug>
#include "connexion.h"
projet::projet()
{
    num_pro=0;
    titre_pro="";
    chef_pro="";
    budget=0;
    
    
       
}
projet::projet(int num_pro,QString titre_pro,QString chef_pro,int budget)

{
this->num_pro=num_pro;
this->titre_pro=titre_pro;
this->chef_pro=chef_pro;
this->budget=budget;
}
int projet::get_num_pro(){return num_pro;}
QString projet::get_titre_pro(){ return titre_pro;}
QString projet::get_chef_pro(){return chef_pro;}
int projet::get_budget(){return budget;}
bool projet::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(num_pro);
    query.prepare("INSERT INTO projet(num_pro,titre_pro,chef_pro,budget)""VALUE (:num_pro,:titre_pro,:chef_pro,:budget)");
    query.bindValue(":num_pro",res);
    query.bindValue(":titre_pro",num_pro);
    query.bindValue(":chef_pro",chef_pro);
    query.bindValue(":budget",budget);

    return query.exec();
    
}
QSqlQueryModel * projet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from projet");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num_pro"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("titre_pro"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("chef_pro"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("budget"));
        return model;


}
bool projet::supprimer(int num_pro)
{
    QSqlQuery query;
    QString res=QString::number(num_pro);
    query.prepare("delete from projet where NUM_PRO=:num_pro");
    query.bindValue(":id",num_pro);
    return query.exec();



}


