#include "personel.h"
#include <QDebug>
#include <QMessageBox>


Personel::Personel()
{
    nom="";
    prenom="";
    ID="";
    tel="";
    adresse="";
    email="";

}
Personel::Personel(QString ID,QString nom,QString prenom,QString tel,QString adresse,QString email)
{
    this->ID=ID;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->adresse=adresse;
    this->email=email;

}
bool Personel::ajouterperso()
{

    QSqlQuery query;
   // QString res = QString::number(ID);

    query.prepare("INSERT INTO PERSONEL(ID,NOM,PRENOM,TEL,ADRESSE,EMAIL) "
                  "VALUES (:ID, :nom, :prenom, :tel, :adresse, :email)");
    query.bindValue(":ID",ID);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    Personel p(ID,nom,prenom,tel,adresse,email);
    return query.exec();

}
QSqlQueryModel * Personel::afficherperso()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("Select * from PERSONEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    return model;

}
bool Personel::supprimerperso(QString ID)
{
QSqlQuery query;


query.prepare("DELETE FROM PERSONEL WHERE ID = :ID ");
query.bindValue(":ID",ID);
return  query.exec();
}

bool Personel::verif_email(QString ch){
   bool test=false;
   int i;
   for(i=0;i<ch.length();i++)
   {
       if(ch[i]=='@'){
           test=true;
       }
   }
   return  test;
}
bool Personel::verif_id(QString ch_id){
   bool test=true;
   int i;
   if(ch_id.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<ch_id.length();i++){
           if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;
}
bool Personel::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}

