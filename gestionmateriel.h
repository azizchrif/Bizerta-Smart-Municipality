#ifndef GESTIONMATERIEL_H
#define GESTIONMATERIEL_H

#include <QDialog>
#include "materiel.h"
namespace Ui {
class gestionmateriel;
}

class gestionmateriel : public QDialog
{
    Q_OBJECT

public:
    explicit gestionmateriel(QWidget *parent = nullptr);
    ~gestionmateriel();

private slots:
    void on_btn_ajouterm_clicked();

    void on_bt_modifm_clicked();

    void on_pushButton_clicked();

    void on_btn_refresh_clicked();

    void on_pushButton_6_clicked();

    void on_btn_pdf_clicked();

    void on_tri_nom_clicked();

    void on_tri_id_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestionmateriel *ui;
    materiel tmpm;
};

#endif // GESTIONMATERIEL_H
