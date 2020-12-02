#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class projet 
{public:
    projet();
    projet(int,QString,QString,int);
    int get_num_pro();
    QString get_titre_pro();
    QString get_chef_pro();
    int get_budget();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
        QString titre_pro,chef_pro;
        int num_pro,budget; 
};

#endif // PROJET_H
