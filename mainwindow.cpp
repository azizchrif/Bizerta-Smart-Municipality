#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include "fournisseurs.h"
#include <QMessageBox>
#include <QDialog>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include <limits>
#include <QPrinter>
#include <QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tab_afe->setModel(e.AfficherEquipements());
    ui->Tab_aff->setModel(f.AfficherFournisseurs());
    animation =new QPropertyAnimation(ui->Equipements_button,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->Equipements_button->geometry());
    animation->setEndValue(QRect(320,120,361,71));
    animation->start();
    animation1 =new QPropertyAnimation(ui->Fournisseurs_button,"geometry");
    animation1->setDuration(10000);
    animation1->setStartValue(ui->Fournisseurs_button->geometry());
    animation1->setEndValue(QRect(320,210,361,71));
    animation1->start();


    /*ui->Nom_aje->setValidator(new QIntValidator(0, 5, this));
    ui->ID_aje->setValidator(new QIntValidator(1,4, this));
    ui->Etat_aje->setValidator(new QIntValidator(101, 522, this));*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_e_clicked()
{
    QMessageBox msgBox;
    QString Nom=ui->Nom_aje->currentText();
        int ID=ui->ID_aje->text().toInt();
        int Prix=ui->Prix_aje->text().toInt();
        int Etat=ui->Etat_aje->currentText().toInt();

        Equipements e(Nom,ID,Etat,Prix);
        bool test=e.AjouterEquipements();



        if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->Tab_afe->setModel(e.AfficherEquipements());}
         else
             msgBox.setText("Echec d'ajout");
             msgBox.exec();
}

void MainWindow::on_Supprimer_e_clicked()
{
    int ID = ui->ID_spe->text().toInt();
    bool test=e.SupprimerEquipements(ID);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Ajout avec succes.");
        ui->Tab_afe->setModel(e.AfficherEquipements());//refresh
    }
    else
    msgBox.setText("Echec de supression");
}

void MainWindow::on_modifier_e_clicked()
{
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);


        int ID=ui->ID_moe->text().toInt();
        QString Nom=ui->Nom_moe->text();
        ui->Nom_moe->setValidator(validator_String);
        int Prix=ui->Prix_moe->text().toInt();
        int Etat=ui->Etat_moe->value();


            Equipements e(Nom,ID,Etat,Prix);
            bool test=e.ModifierEquipements(ID);
            if(test)
               {  msgBox.setText("Modification avec succes.");
                 ui->Tab_afe->setModel(e.AfficherEquipements());}
             else
                 msgBox.setText("Echec de modification");
                 msgBox.exec();
}

void MainWindow::on_ajouter_f_clicked()
{
    QMessageBox msgBox;
    QString Nom=ui->Nom_afe->text();
    QString AdresseEmail=ui->AdresseEmail_afe->text();
    QString Adresse=ui->Adresse_afe->text();
        int ID=ui->ID_afe->text().toInt();
        int NumTel=ui->Tel_afe->text().toInt();


        Fournisseurs f(Nom,Adresse , AdresseEmail,ID, NumTel);
        bool test=f.AjouterFournisseurs();



        if(test)
           {  msgBox.setText("Ajout avec succes.");}
         else
            msgBox.setText("Ajout avec succes.");
}


void MainWindow::on_modifier_f_clicked()
{
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
       QValidator *validator_int=new QRegExpValidator(QRegExp("[1-999999]+"),this);

        int ID=ui->ID_mof->text().toInt();
        ui->ID_mof->setValidator(validator_int);
        QString Nom=ui->Nom_mof->text();
        ui->Nom_mof->setValidator(validator_String);
        QString Adresse=ui->Adresse_mof->text();
        ui->Adresse_mof->setValidator(validator_String);
        QString AdresseEmail=ui->AdresseEmail_mof->text();
        ui->AdresseEmail_mof->setValidator(validator_String);
        int NumTel=ui->Tel_mof->text().toInt();

            Fournisseurs f(Nom, Adresse , AdresseEmail,ID,NumTel);
            bool test=f.ModifierFournisseurs(ID);
            if(test)
               msgBox.setText("Modification avec succes.");
             else
                msgBox.setText("Echec de modification.");
}

void MainWindow::on_Supprimer_f_clicked()
{
    int ID = ui->ID_spf->text().toInt();
    bool test=f.SupprimerFournisseurs(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff->setModel(f.AfficherFournisseurs());//refresh
        msgBox.setText("Supression avec succes.");
    }
    else
    msgBox.setText("Echec de supression.");
}


void MainWindow::on_TriAsc_e_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_ascprix());
}

void MainWindow::on_TriDesc_e_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_descprix());
}
void MainWindow::on_back_tri_clicked()
{
    ui->stackedWidget_trier->setCurrentIndex(0);
}

void MainWindow::on_Trier_clicked()
{
    ui->stackedWidget_trier->setCurrentIndex(1);
}

void MainWindow::on_Triprix_clicked()
{
    ui->stackedWidget_prix->setCurrentIndex(1);
    ui->stackedWidget_etat->setCurrentIndex(0);
    ui->stackedWidget_nom->setCurrentIndex(0);
}

void MainWindow::on_back_triprix_clicked()
{
    ui->stackedWidget_prix->setCurrentIndex(0);
}

void MainWindow::on_trinom_clicked()
{
    ui->stackedWidget_nom->setCurrentIndex(1);
    ui->stackedWidget_etat->setCurrentIndex(0);
    ui->stackedWidget_prix->setCurrentIndex(0);

}
void MainWindow::on_back_trinom_clicked()
{
    ui->stackedWidget_nom->setCurrentIndex(0);
}
void MainWindow::on_Trietat_clicked()
{
    ui->stackedWidget_etat->setCurrentIndex(1);
    ui->stackedWidget_nom->setCurrentIndex(0);
    ui->stackedWidget_prix->setCurrentIndex(0);
}

void MainWindow::on_back_trietat_clicked()
{
    ui->stackedWidget_etat->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_ascnom());
}


void MainWindow::on_TriDesc_en_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_descnom());
}

void MainWindow::on_TriAsc_ee_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_ascetat());
}

void MainWindow::on_TriDesc_ee_clicked()
{
    ui->Tab_afe->setModel(e.Afficher_descetat());
}

void MainWindow::on_Rechercher_ID_clicked()
{
    int ID = ui->ID_ree->text().toInt();
    bool test=e.Rechercher_ID(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe->setModel(e.Rechercher_ID(ID));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");

}


void MainWindow::on_Rechercher_Nom_clicked()
{
    QString Nom=ui->Nom_ree->text();
    bool test=e.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe->setModel(e.Rechercher_Nom(Nom));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
}


void MainWindow::on_Rechercher_Etat_clicked()
{
    int Etat = ui->etat_ree->text().toInt();
    bool test=e.Rechercher_Etat(Etat);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe->setModel(e.Rechercher_Etat(Etat));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
}


void MainWindow::on_Rechercher_clicked()
{
    ui->stackedWidget_rechercher->setCurrentIndex(1);
}


void MainWindow::on_Back_rechercher_clicked()
{
    ui->stackedWidget_rechercher->setCurrentIndex(0);
}

void MainWindow::on_Equipements_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
}

void MainWindow::on_Fournisseurs_button_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
}


void MainWindow::on_Backtomenu_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}

void MainWindow::on_Backtomenu_2_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}


void MainWindow::on_Trier_2_clicked()
{
    ui->stackedWidget_trier_2->setCurrentIndex(1);
}

void MainWindow::on_back_tri_2_clicked()
{
    ui->stackedWidget_trier_2->setCurrentIndex(0);
}

void MainWindow::on_Triprix_2_clicked()
{
    ui->stackedWidget_prix_2->setCurrentIndex(1);
    ui->stackedWidget_etat_2->setCurrentIndex(0);
    ui->stackedWidget_nom_2->setCurrentIndex(0);
}

void MainWindow::on_back_triprix_2_clicked()
{
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}

void MainWindow::on_trinom_2_clicked()
{
    ui->stackedWidget_nom_2->setCurrentIndex(1);
    ui->stackedWidget_etat_2->setCurrentIndex(0);
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}
void MainWindow::on_back_trinom_2_clicked()
{
    ui->stackedWidget_nom_2->setCurrentIndex(0);
}
void MainWindow::on_Trietat_2_clicked()
{
    ui->stackedWidget_etat_2->setCurrentIndex(1);
    ui->stackedWidget_nom_2->setCurrentIndex(0);
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}
void MainWindow::on_back_trietat_2_clicked()
{
    ui->stackedWidget_etat_2->setCurrentIndex(0);
}
void MainWindow::on_TriAsc_en_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_asscNom());
}

void MainWindow::on_TriDesc_en_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_desscNom());
}

void MainWindow::on_TriAsc_e_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_ascID());
}

void MainWindow::on_TriDesc_e_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_descID());
}

void MainWindow::on_TriAsc_ee_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_ascAdresse());
}

void MainWindow::on_TriDesc_ee_2_clicked()
{
    ui->Tab_aff->setModel(f.Afficher_descAdresse());
}

void MainWindow::on_Rechercher_2_clicked()
{
   ui->stackedWidget_rechercher_2->setCurrentIndex(1);
}

void MainWindow::on_Rechercher_ID_2_clicked()
{
    int ID = ui->ID_ree_2->text().toInt();
    bool test=f.Rechercher_ID(ID);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_ID(ID));//refresh

    }
    else
    msgBox.setText("Echec de modification.");
}

void MainWindow::on_Rechercher_Nom_2_clicked()
{
    QString Nom=ui->Nom_ree_2->text();
    bool test=f.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_Nom(Nom));//refresh

    }
    else
    msgBox.setText("Echec de modification.");
}

void MainWindow::on_Rechercher_Etat_2_clicked()
{
    QString Adresse=ui->etat_ree_2->text();
    bool test=f.Rechercher_Adresse(Adresse);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_Adresse(Adresse));//refresh

    }
    else
    msgBox.setText("Echec de modification.");
}

void MainWindow::on_Back_rechercher_2_clicked()
{
    ui->stackedWidget_rechercher_2->setCurrentIndex(0);
}

void MainWindow::on_print_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->Tab_afe->render(&printer);
}

void MainWindow::on_print_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->Tab_aff->render(&printer);
}
