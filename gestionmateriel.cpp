#include "gestionmateriel.h"
#include "ui_gestionmateriel.h"
#include<QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QSqlQuery>
gestionmateriel::gestionmateriel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionmateriel)
{
    ui->setupUi(this);
}

gestionmateriel::~gestionmateriel()
{
    delete ui;
}



void gestionmateriel::on_bt_modifm_clicked()
{
   QString id=ui->id_a_modif->text();


     QString type= ui->nv_tpe->text();
     QString quantite=ui->nv_qt->text();


         materiel p(id,quantite,type);
         bool test=p.modifier(id,quantite,type);
         if(test)
       {
             ui->tabmat->setModel(tmpm.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier materiel"),
                         QObject::tr(" materiel modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionmateriel::on_pushButton_clicked()
{
    QSqlQuery query;

            int id = ui->id_a_supprimer->text().toInt();

            query.prepare("delete from  materiel where id=:id");
            query.bindValue(":id", id);
            bool v =query.exec();
            if(v)
            {ui->tabmat->setModel(tmpm.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer materiel"),
                            QObject::tr(" materiel supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionmateriel::on_btn_refresh_clicked()
{
   ui->tabmat->setModel(tmpm.afficher());
}

void gestionmateriel::on_pushButton_6_clicked()
{

}

void gestionmateriel::on_btn_pdf_clicked()
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
   double xscale = double(ui->tabmat->width() / 65);
   double yscale = double(ui->tabmat->height() / 65);
   painter.scale(xscale, yscale);
   ui->tabmat->render(&painter);
   painter.end();
}
else
{
   qWarning("failed to open file");
  QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
}
} }

void gestionmateriel::on_tri_nom_clicked()
{
ui->tabmat->setModel(tmpm.trier());
}

void gestionmateriel::on_tri_id_clicked()
{
ui->tabmat->setModel(tmpm.trier1());
}

void gestionmateriel::on_pushButton_2_clicked()
{
    QString  id=ui->id_m->text();
     QString  quantite=ui->qt_m->text();

    QString  type= ui->type_m->text();


       materiel p(id,quantite,type);
         bool test=p.ajouter();
         if(test)
       {ui->tabmat->setModel(tmpm.afficher()); //refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                         QObject::tr("materiel ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une materiel"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
