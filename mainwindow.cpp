#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>
#include <QDialog>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include <limits>
//test
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tabc->setModel(e.AfficherEquipements());
 /*   ui->Tabc->setModel(e.AfficherEquipements());
    ui->Nomedit->setValidator(new QIntValidator(0, 5, this));
    ui->IDedit->setValidator(new QIntValidator(1,4, this));
    ui->Etatedit->setValidator(new QIntValidator(101, 522, this));*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{  QString Nom=ui->nom->text();
    int ID=ui->id->text().toInt();
    int Etat=ui->etat->text().toInt();

    Equipements e(Nom,ID,Etat );
    bool test=e.AjouterEquipements();
    QMessageBox msgBox;

    if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->Tabc->setModel(e.AfficherEquipements());}
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
}
void MainWindow::on_Tab_chambres_currentChanged(int index)
{
   ui->Tabc->setModel(e.AfficherEquipements());

};
void MainWindow::on_pushButton_3_clicked()
{
    Equipements E1;
    QMessageBox msg;
         E1.setID(ui->Tabc->model()->data(ui->Tabc->model()->index(rowSelected,0)).toInt());
 //       int reponse = QMessageBox::question(this, "Confirmation de suppression", &"Etes vous sur de supprimer cette colonne ?"[E1.getID()], QMessageBox ::Yes | QMessageBox::No);
       bool test=false;
       test=e.SupprimerEquipements(E1.getID());
       //   if (reponse == QMessageBox::Yes)
         // {
             if(test)
                //{ msg.setText("Suppression avec succes.");
              ui->Tabc->setModel(e.AfficherEquipements());//}
              //else { msg.setText("Echec de suppresion");
          //}     msg.exec();}

}
