#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include <QSqlQueryModel>
#include <QAbstractItemModel>

class Equipements
{private:
    QString Nom;
    int ID;
    int Etat;

public:
   Equipements();
    Equipements(QString,int,int);
    bool AjouterEquipements();
    bool ModifierEquipements();
   QSqlQueryModel* AfficherEquipements();
    bool SupprimerEquipements(int);
    bool RechercherEquipements();
    bool TrierEquipements();
    bool Envoyermail();
    void setNom(QString);
    void setID(int);
    void setEtat(int);
    QString getNom();
    int getID();
    int getEtat();
   // bool QAbstractItemModel::removeRow(int row, Equipements());


};

#endif // EQUIPEMENTS_H
