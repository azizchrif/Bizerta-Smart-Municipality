#ifndef TICKETS_H
#define TICKETS_H


#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Tickets
{private:
    int Num;
    QString Titre;
    int Prix;
    QString Description;

public:
   Tickets();
    Tickets(int,QString,int,QString);
    bool AjouterTickets();
    bool ModifierTickets();
   QSqlQueryModel* AfficherTickets();
   QSqlQueryModel* Afficher_ascTitre();//tri asc
   QSqlQueryModel* Afficher_descTitre();//tri desc
   QSqlQueryModel* Afficher_ascNum();//tri asc
   QSqlQueryModel* Afficher_descNum();//tri desc
   QSqlQueryModel* Afficher_ascPrix();//tri asc
   QSqlQueryModel* Afficher_descPrix();//tri desc
   QSqlQueryModel* Rechercher_Num(int num);
   QSqlQueryModel* Rechercher_Prix(int Prix);
   QSqlQueryModel* Rechercher_Titre(QString Titre);
    bool SupprimerTickets(int);
    bool Envoyermail();
    void setTitre(QString);
    void setNum(int);
    void setPrix(int);
    void setDescription(QString);
    QString getTitre();
    int getNum();
    int getPrix();
    QString getDescription();


};

#endif // TICKETS_H
