#include "collaborateur.h"
#include <QDebug>
#include "connexion.h"
collaborateur::collaborateur()
{
    CIN=0;
    nom="";
    prenom="";
    adresse="";
    ville="";
    num_tel=0;
}
collaborateur::collaborateur (int CIN,int num_tel,QString nom,
                             QString prenom,QString adresse,QString ville)
{
     this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->ville=ville;
    this->num_tel=num_tel;

}
    QString collaborateur::get_nom() {return nom;}
    QString collaborateur::get_prenom(){return prenom;}
    QString collaborateur::get_adresse(){return adresse;}
    QString collaborateur::get_ville(){return ville;}
    int collaborateur::get_CIN(){return CIN;}
    int collaborateur::get_num_tel(){return num_tel;}

    bool collaborateur::ajouter()
    {
        QSqlQuery query;
        QString res=QString::number(CIN);
        QString pt=QString::number(num_tel);
        query.prepare("INSERT INTO collaborateur(CIN,NOM,PRENOM,ADRESSE,VILLE,NUM_TEL)"
                      "VALUES(:cin,:nom,:prenom,:adresse,:ville)");
        query.bindValue(":cin",res);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":ville",ville);
        query.bindValue(":tel_num",pt);
        return          query.exec();


    }
    QSqlQueryModel * collaborateur::afficher()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from collaborateur");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ville"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("num_tel"));
        return model;



    }

 bool collaborateur::supprimer(int cin)
{
     QSqlQuery query;
     QString res=QString::number(cin);
             query.prepare("Delete from collaborateur where CIN= :cin ");
             query.bindValue(":cin",res);
             return query.exec();


    }
