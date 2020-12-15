#ifndef GESTIONTERRAIN_H
#define GESTIONTERRAIN_H

#include <QDialog>
#include "materiel.h"
#include "terrain.h"
namespace Ui {
class gestionterrain;
}

class gestionterrain : public QDialog
{
    Q_OBJECT

public:
    explicit gestionterrain(QWidget *parent = nullptr);
    ~gestionterrain();

private slots:
    void on_btn_ajoutert_clicked();
    
    void on_btn_rechercher_clicked();
    
    void on_btn_refresh_clicked();
    
    void on_btn_tri_nom_clicked();
    
    void on_btn_tri_id_clicked();
    
    void on_btn_pdf_clicked();
    
    void on_btn_modifier_clicked();
    
    void on_btn_supprimer_clicked();
    
    void on_btn_supprimer_t_clicked();

    void on_btn_refresht_clicked();

    void on_btn_tri_nom_t_clicked();

    void on_btn_tri_id_t_clicked();

    void on_tn_pdf_t_clicked();

    void on_tn_cherchert_clicked();

    void on_tn_modifiert_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_supp_mat_clicked();

    void on_refresh_matr_clicked();

    void on_btn_modifier_mat_clicked();

private:
    Ui::gestionterrain *ui;
    Terrain tmpt;
    materiel tmpm;

};

#endif // GESTIONTERRAIN_H
