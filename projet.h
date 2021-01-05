#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Projet
{private:
    QString TitrePro;
    QString ChefPro;
    int Budget;
    int NumPro;


public:
   Projet();
    Projet(QString,QString,int,int);
    bool AjouterProjet();
    bool ModifierProjet();
   QSqlQueryModel* AfficherProjet();
   QSqlQueryModel* Afficher_ascTitrePro();//tri asc
   QSqlQueryModel* Afficher_descTitrePro();//tri desc
   QSqlQueryModel* Afficher_ascNumPro();//tri asc
   QSqlQueryModel* Afficher_descNumPro();//tri desc
   QSqlQueryModel* Afficher_ascBudget();//tri asc
   QSqlQueryModel* Afficher_descBudget();//tri desc
   QSqlQueryModel* Rechercher_NumPro(int NumPro);
   QSqlQueryModel* Rechercher_Budget(int Budget);
   QSqlQueryModel* Rechercher_TitrePro(QString TitrePro);
    bool SupprimerProjet(int NumPro);
    void setTitrePro(QString);
    void setChefPro(QString);
    void setNumPro(int);
    void setBudget(int);
    QString getTitrePro();
    QString getChefPro();
    int getNumPro();
    int getBudget();



};

#endif // PROJET_H
