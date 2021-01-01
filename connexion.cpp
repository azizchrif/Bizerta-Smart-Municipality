#include "connexion.h"

//connexion
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{

    bool test=false;
        db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetqt");
    db.setUserName("aziz");//inserer nom de l'utilisateur
    db.setPassword("aziz07");//inserer mot de passe de cet utilisateur


    if (db.open()) test = true;


    return test;
}

void Connexion::fermerConnexion()
{db.close();}
