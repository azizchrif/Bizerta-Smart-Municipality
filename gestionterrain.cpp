#include "gestionterrain.h"
#include "gestionmateriel.h"
#include "ui_gestionterrain.h"
#include "terrain.h"
#include<QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QSqlQuery>
gestionterrain::gestionterrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionterrain)
{
    ui->setupUi(this);
}

gestionterrain::~gestionterrain()
{
    delete ui;
}

void gestionterrain::on_btn_ajoutert_clicked()
{

    int id=ui->id_t->text().toInt();
           QString nom= ui->id_t->text();
            QString etat= ui->etat_t->text();
           QString emplacement= ui->emplacement_t->text();

         Terrain p(id,emplacement,etat,nom);
         bool test=p.ajouter();
         if(test)
       {ui->tableView->setModel(tmpt.afficher()); //refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter un terrain"),
                         QObject::tr("terrain ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une terrain"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}





void gestionterrain::on_btn_supprimer_t_clicked()
{
    QSqlQuery query;

            int id = ui->id_a_supprimer_s->text().toInt();

            query.prepare("delete from  terrain where id=:id");
            query.bindValue(":id", id);
            bool v =query.exec();
            if(v)
            {ui->tableView->setModel(tmpt.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer un terrain"),
                            QObject::tr(" Sponsorisation supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un terrain"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionterrain::on_btn_refresht_clicked()
{
    ui->tableView->setModel(tmpt.afficher());
}

void gestionterrain::on_btn_tri_nom_t_clicked()
{
    ui->tableView->setModel(tmpt.trier());
}

void gestionterrain::on_btn_tri_id_t_clicked()
{
        ui->tableView->setModel(tmpt.trier1());
}

void gestionterrain::on_tn_pdf_t_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
               printer->setOutputFormat(QPrinter::NativeFormat);
               printer->setPageSize(QPrinter::A4);
               printer->setOrientation(QPrinter::Portrait);
               printer->setFullPage(true);


           QPrintDialog *printDialog = new QPrintDialog(printer,this);
           printDialog->setWindowTitle("Impression PDF");
           if(printDialog->exec())
           {
              QPainter painter;
              if(painter.begin(printer))
              {
                  double xscale = double(ui->tableView->width() / 65);
                  double yscale = double(ui->tableView->height() / 65);
                  painter.scale(xscale, yscale);
                  ui->tableView->render(&painter);
                  painter.end();
              }
              else
              {
                  qWarning("failed to open file");
                 QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
              }
           }
}

void gestionterrain::on_tn_cherchert_clicked()
{
    QString noms = ui->nom_a_chercherp->text();
        if(tmpt.verifierExnoms(noms)==false)
        {QMessageBox::warning(this,"ERREUR","terrain n'existe pas");}
        else
        ui->tableView->setModel(tmpt.recherche_nom(noms));
}

void gestionterrain::on_tn_modifiert_clicked()
{
    int id=ui->ex_id->text().toInt();

    QString nom= ui->v_nom->text();
     QString etat= ui->nv_etat->text();
    QString emplacement= ui->nv_emplacement->text();


          Terrain p(id,emplacement,etat,nom);
         bool test=p.modifier(id,emplacement,etat,nom);
         if(test)
       {
             ui->tableView->setModel(tmpt.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier un Terrain"),
                         QObject::tr(" Terrain modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un Terrain"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}






void gestionterrain::on_pushButton_2_clicked()
{
    QString  id=ui->idm->text();
           QString  quantite=ui->qtm->text();
           QString type=ui->typem->text();

         materiel p(id,quantite,type);
         bool test=p.ajouter();
         if(test)
       {ui->tableView_2->setModel(tmpm.afficher()); //refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel "),
                         QObject::tr("materiel ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une materiel"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionterrain::on_btn_supp_mat_clicked()
{
    QSqlQuery query;

            QString id = ui->id_mat_sup->text();

            query.prepare("delete from  MATRL where id=:id");
            query.bindValue(":id", id);
            bool v =query.exec();
            if(v)
            {ui->tableView->setModel(tmpt.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                            QObject::tr(" materiel supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionterrain::on_refresh_matr_clicked()
{
    ui->tableView_2->setModel(tmpm.afficher());
}

void gestionterrain::on_btn_modifier_mat_clicked()
{
    QString id=ui->id_modif_mat->text();

    QString quantite= ui->nv_qt_m->text();
     QString type= ui->nv_tpe_m->text();



          materiel p(id,quantite,type);
         bool test=p.modifier(id,quantite,type);
         if(test)
       {
             ui->tableView_2->setModel(tmpm.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                         QObject::tr(" materiel modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
