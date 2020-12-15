#include "materiel.h"
#include <QSqlQuery>
materiel::materiel(QString id,QString quantite,QString type)
{
    this->id=id;
     this->quantite=quantite;


    this->type=type;
}
materiel::~materiel()
{

}
 materiel::materiel()
 {

 }

QString materiel::getid(){
    return id;
}
void materiel::setid(QString id){
    this->id=id;
}
QString materiel::getquantite(){
    return quantite;
}
void materiel::setquantite(QString quantite){
    this->quantite=quantite;
}
QString materiel::gettype(){
    return type;
}
void materiel::settype(QString type){
    this->type=type;
}





bool materiel::ajouter(){
    QSqlQuery query;
    query.prepare("insert into MATRL (id,quantite,type) values (:id,:quantite,:type)");
    query.bindValue(":id",id);
    query.bindValue(":quantite",quantite);
    query.bindValue(":type",type);

    return query.exec();
}

bool materiel::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from MATRL where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from MATRL where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool materiel::modifier(QString idc,QString quantite,QString type){
    QSqlQuery query;
    query.prepare("update MATRL set quantite=:quantite,type=:type where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":quantite",quantite);
    query.bindValue(":type",type);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * materiel::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from MATRL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}


QSqlQueryModel * materiel::chercher_materiel_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM MATRL WHERE NOM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        return model ;
    }

 }


QSqlQueryModel * materiel::chercher_materiel_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM MATRL WHERE nom like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        return model ;
    }

 }

QSqlQueryModel* materiel:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from MATRL order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}

QSqlQueryModel* materiel:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from MATRL order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}
