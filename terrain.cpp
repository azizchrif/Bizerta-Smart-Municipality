#include "terrain.h"
#include <QSqlQuery>
Terrain::Terrain(int id,QString emplacement,QString etat,QString nom)
{
    this->id=id;
    this->nom=nom;
     this->emplacement=emplacement;
    this->etat=etat;
}
Terrain::~Terrain()
{

}
 Terrain::Terrain()
 {
   id=0;
     nom="";
     emplacement="";
     etat="";
 }

QString Terrain::getnom(){
    return nom;
}
void Terrain::setnom(QString nom){
    this->nom=nom;
}

int Terrain::getid(){
    return id;
}
void Terrain::setid(int id){
    this->id=id;
}
QString Terrain::getemplacement(){
    return emplacement;
}
void Terrain::setemplacement(QString emplacement){
    this->emplacement=emplacement;
}
QString Terrain::getetat(){
    return etat;
}
void Terrain::setetat(QString etat){
    this->etat=etat;
}





bool Terrain::ajouter(){
    QSqlQuery query;
    query.prepare("insert into terrain (id,emplacement,etat,nom) values (:id,:emplacement,:etat,:nom)");
    query.bindValue(":id",id);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":etat",etat);
    query.bindValue(":nom",nom);

    return query.exec();
}

bool Terrain::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from Terrain where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Terrain where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Terrain::modifier(int idc,QString nom,QString emplacement,QString etat){
    QSqlQuery query;
    query.prepare("update Terrain set nom=:nom,emplacement=:emplacement,etat=:etat where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nom",nom);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":etat",etat);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Terrain::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Terrain");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}


QSqlQueryModel * Terrain::chercher_Terrain_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Terrain WHERE NOM like '"+m+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
        return model ;
    }

 }


QSqlQueryModel * Terrain::chercher_Terrain_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Terrain WHERE nom like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));

        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
        return model ;
    }

 }

QSqlQueryModel* Terrain:: trier()
{
 //order by extract (year from date_naissance)
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Terrain order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    return model;
}

QSqlQueryModel* Terrain:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Terrain order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}
QSqlQueryModel* Terrain::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Terrain WHERE NOM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    return model ;
}


 bool Terrain::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from Terrain where nom= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}





