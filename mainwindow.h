#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipements.h"
#include "fournisseurs.h"
#include <QtSql>
#include <QWidgetAction>
#include <QSqlDatabase>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Ajouter_e_clicked();

    void on_Supprimer_e_clicked();

    void on_modifier_e_clicked();

    void on_ajouter_f_clicked();

    void on_modifier_f_clicked();

    void on_Supprimer_f_clicked();


    void on_TriAsc_e_clicked();

    void on_TriDesc_e_clicked();

    void on_Trier_clicked();

    void on_Triprix_clicked();

    void on_back_triprix_clicked();

    void on_trinom_clicked();

    void on_Trietat_clicked();

    void on_back_trietat_clicked();

    void on_back_trinom_clicked();

    void on_back_tri_clicked();

    void on_TriAsc_en_clicked();

    void on_TriDesc_en_clicked();

    void on_TriAsc_ee_clicked();

    void on_TriDesc_ee_clicked();

    void on_Rechercher_ID_clicked();

    void on_Rechercher_Nom_clicked();

    void on_Rechercher_Etat_clicked();

    void on_Rechercher_clicked();

    void on_Back_rechercher_clicked();

    void on_Equipements_button_clicked();

    void on_Fournisseurs_button_clicked();

    void on_Backtomenu_clicked();

    void on_Backtomenu_2_clicked();

    void on_Trier_2_clicked();

    void on_Triprix_2_clicked();

    void on_back_triprix_2_clicked();

    void on_back_tri_2_clicked();

    void on_trinom_2_clicked();

    void on_back_trinom_2_clicked();

    void on_Trietat_2_clicked();

    void on_back_trietat_2_clicked();

    void on_TriAsc_en_2_clicked();

    void on_TriDesc_en_2_clicked();

    void on_TriAsc_e_2_clicked();

    void on_TriDesc_e_2_clicked();

    void on_TriAsc_ee_2_clicked();

    void on_TriDesc_ee_2_clicked();

    void on_Rechercher_2_clicked();

    void on_Rechercher_ID_2_clicked();

    void on_Rechercher_Nom_2_clicked();

    void on_Rechercher_Etat_2_clicked();

    void on_Back_rechercher_2_clicked();

    void on_print_clicked();

    void on_print_2_clicked();

private:
    Ui::MainWindow *ui;
    Equipements e;
    Fournisseurs f;
     int rowSelected;
     QSqlDatabase db;
     QPropertyAnimation *animation;
     QPropertyAnimation *animation1;
     QSequentialAnimationGroup *animationGroup;
};
#endif // MAINWINDOW_H
