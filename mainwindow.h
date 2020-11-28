#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personel.h"
#include "poste.h"

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

private:
    Ui::MainWindow *ui;
    Personel pp;
    Poste po;
};
#endif // MAINWINDOW_H
