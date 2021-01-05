#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QPixmap>
#include <QPropertyAnimation>
#include "personel.h"
#include "poste.h"
#include "equipements.h"
#include "fournisseurs.h"
#include "evenements.h"
#include "tickets.h"
#include "ui_mainwindow.h"
#include "historique.h"
#include "collaborateur.h"
#include "projet.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
      MainWindow(QWidget *parent = nullptr);
    void initialiserperso();
    void initialiserposte();

    ~MainWindow();

private slots:
    void on_pushButton_Ajouterclient_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_ajoute_rposte_clicked();

    void on_pushButton_supprimer_poste_clicked();

    void on_pushButton_modifier_poste_clicked();

    void on_pushButton_modifier_personel_clicked();

    void on_pushButton_imprimer_poste_clicked();

    void on_pushButton_imprimer_personels_clicked();

    void on_pushButton_rechercher_personel_toggled(bool checked);

    void on_radioButton_trinom_toggled(bool checked);

    void on_radioButton_tri_ID_toggled(bool checked);

    void on_radioButton_tri_salaire_clicked();

    void on_pushButton_actualiser_clicked();

    void on_TABPERSONEL_activated(const QModelIndex &index);

    void on_pushButton_rechercher_poste_clicked();

    void on_pushButton_actualiser_2_clicked();


    void on_pushButton_imprimer_personel_3_clicked();

    void on_pushButton_imprimer_poste_2_clicked();

    void on_login_clicked();

    void on_Ressources_humaines_button_clicked();

    void on_Ajouter_e_clicked();

    void on_Supprimer_e_clicked();

    void on_modifier_e_clicked();

    void on_ajouter_f_clicked();

    void on_modifier_f_clicked();

    void on_Supprimer_f_clicked();

    void on_Trier_clicked();

    void on_Triprix_clicked();

    void on_TriAsc_e_clicked();

    void on_TriDesc_e_clicked();

    void on_back_triprix_clicked();

    void on_trinom_clicked();

    void on_TriAsc_en_clicked();

    void on_TriDesc_en_clicked();

    void on_back_trinom_clicked();

    void on_Trietat_clicked();

    void on_TriAsc_ee_clicked();

    void on_TriDesc_ee_clicked();

    void on_back_trietat_clicked();

    void on_back_tri_clicked();

    void on_Rechercher_clicked();

    void on_Rechercher_ID_clicked();

    void on_Rechercher_Nom_clicked();

    void on_Rechercher_Etat_clicked();

    void on_Back_rechercher_clicked();

    void on_Backtomenu_clicked();

    void on_print_clicked();

    void on_Trier_2_clicked();

    void on_Triprix_2_clicked();

    void on_TriAsc_e_2_clicked();

    void on_TriDesc_e_2_clicked();

    void on_back_triprix_2_clicked();

    void on_trinom_2_clicked();

    void on_TriAsc_en_2_clicked();

    void on_TriDesc_en_2_clicked();

    void on_back_trinom_2_clicked();

    void on_Trietat_2_clicked();

    void on_TriAsc_ee_2_clicked();

    void on_TriDesc_ee_2_clicked();

    void on_back_trietat_2_clicked();

    void on_back_tri_2_clicked();

    void on_print_2_clicked();

    void on_Backtomenu_2_clicked();

    void on_Rechercher_2_clicked();

    void on_Rechercher_ID_2_clicked();

    void on_Rechercher_Nom_2_clicked();

    void on_Rechercher_Etat_2_clicked();

    void on_Back_rechercher_2_clicked();

    void on_Equipements_button_clicked();

    void on_Ajouter_e_2_clicked();

    void on_Fournisseurs_button_4_clicked();

    void on_Trier_3_clicked();

    void on_back_triprix_3_clicked();

    void on_TriAsc_e_3_clicked();

    void on_TriDesc_e_3_clicked();

    void on_Triprix_3_clicked();

    void on_trinom_3_clicked();

    void on_TriAsc_en_3_clicked();

    void on_TriDesc_en_3_clicked();

    void on_back_trinom_3_clicked();

    void on_Trietat_3_clicked();

    void on_TriAsc_ee_3_clicked();

    void on_TriDesc_ee_3_clicked();

    void on_back_trietat_3_clicked();

    void on_Backtomenu_5_clicked();

    void on_Rechercher_3_clicked();

    void on_Back_rechercher_3_clicked();

    void on_Rechercher_ID_3_clicked();

    void on_Rechercher_Nom_3_clicked();

    void on_Rechercher_Etat_3_clicked();

    void on_modifier_e_2_clicked();

    void on_Supprimer_e_2_clicked();

    void on_print_3_clicked();

    void on_Trier_4_clicked();

    void on_ajouter_f_2_clicked();

    void on_modifier_f_2_clicked();

    void on_Supprimer_f_2_clicked();

    void on_Triprix_4_clicked();

    void on_TriAsc_e_4_clicked();

    void on_TriDesc_e_4_clicked();

    void on_back_triprix_4_clicked();

    void on_trinom_4_clicked();

    void on_TriAsc_en_4_clicked();

    void on_TriDesc_en_4_clicked();

    void on_back_trinom_4_clicked();

    void on_Trietat_4_clicked();

    void on_TriAsc_ee_4_clicked();

    void on_TriDesc_ee_4_clicked();

    void on_back_trietat_4_clicked();

    void on_back_tri_4_clicked();

    void on_print_4_clicked();

    void on_Rechercher_4_clicked();

    void on_Back_rechercher_4_clicked();

    void on_Rechercher_ID_4_clicked();

    void on_Rechercher_Nom_4_clicked();

    void on_Rechercher_Etat_4_clicked();

    void on_Backtomenu_4_clicked();

    void on_Backtomenu_3_clicked();

    void on_Backtomenu_6_clicked();

    void on_Backtomenu_7_clicked();
    void on_statistique_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();
    void on_Ajouter_e_3_clicked();

    void on_modifier_e_3_clicked();

    void on_Supprimer_e_3_clicked();

    void on_ajouter_f_3_clicked();

    void on_TriAsc_e_6_clicked();

    void on_modifier_f_3_clicked();

    void on_Supprimer_f_3_clicked();

    void on_Trier_5_clicked();

    void on_Triprix_5_clicked();

    void on_TriAsc_e_5_clicked();

    void on_TriDesc_e_5_clicked();

    void on_back_triprix_5_clicked();

    void on_back_tri_3_clicked();

    void on_trinom_5_clicked();

    void on_TriAsc_en_5_clicked();

    void on_TriDesc_en_5_clicked();

    void on_back_trinom_5_clicked();

    void on_Trietat_5_clicked();

    void on_TriAsc_ee_5_clicked();

    void on_TriDesc_ee_5_clicked();

    void on_back_trietat_5_clicked();

    void on_print_5_clicked();

    void on_Backtomenu_10_clicked();

    void on_Rechercher_5_clicked();

    void on_Back_rechercher_5_clicked();

    void on_Rechercher_ID_5_clicked();

    void on_Rechercher_Nom_5_clicked();

    void on_Rechercher_Etat_5_clicked();

    void on_Trier_6_clicked();

    void on_Triprix_6_clicked();

    void on_TriDesc_e_6_clicked();

    void on_back_triprix_6_clicked();

    void on_trinom_6_clicked();

    void on_TriAsc_en_6_clicked();

    void on_TriDesc_en_6_clicked();

    void on_back_trinom_6_clicked();

    void on_Trietat_6_clicked();

    void on_TriAsc_ee_6_clicked();

    void on_TriDesc_ee_6_clicked();

    void on_back_trietat_6_clicked();

    void on_back_tri_5_clicked();

    void on_Rechercher_ID_6_clicked();

    void on_Rechercher_Nom_6_clicked();

    void on_Rechercher_Etat_6_clicked();

    void on_Rechercher_6_clicked();

    void on_Back_rechercher_6_clicked();

    void on_print_6_clicked();

    void on_Backtomenu_11_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_Projets_button_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QPropertyAnimation *animation;

    Personel pp;
    Poste po;
    Equipements e;
    Fournisseurs f;
    Evenements ev;
    Tickets t;
    Collaborateur c;
    Projet p;
};
#endif // MAINWINDOW_H
