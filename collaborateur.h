#ifndef COLLABORATEUR_H
#define COLLABORATEUR_H
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class collaborateur
{
public:
    collaborateur();
    collaborateur(int,int,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_ville();
    int get_CIN();
    int get_num_tel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
 private:
    QString nom,prenom,adresse,ville;
    int CIN,num_tel;





};

#endif // COLLABORATEUR_H
