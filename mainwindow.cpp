#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collaborateur.h"
#include "QMediaPlayer"


#include "projet.h"
#include "QMessageBox"



MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->tabcollaborateurs->setModel(tmpcollaborateur.afficher()); */

 ui->tabcollab->setModel(tmpcollab.afficher());  */

     ui->afficherprojet->setModel(tmpprojet.afficher());
   click = new QMediaPlayer (); /*
   click->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Documents/smartmunicipality/click.mp3"));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    click->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Documents/smartmunicipality/click.mp3"))
            click->play();
    int cin= ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString ville=ui->lineEdit_ville->text();
    int num_tel= ui->lineEdit_tel_num->text().toInt();
    collaborateur c(cin,prenom,nom,adresse,ville,num_tel);
    bool projet=c.ajouter();
    if (projet)
{
        ui->tabecollaborateur->setModel(tmpcollaborateur.afficher());
       QMessageBox::information(nullptr,QObject::tr("Ajouter un collaborateur"),
                                 QObject::tr("collaborateur ajouté.\n"
                                             "Click Cancel to exit "), QMessageBox::Cancel);
    }

}
void MainWindow::on_pb_supprimer_clicked()
{
    int cin=cin->lineEdit_id_2->text().toInt();
    bool projet=tmpcollaborateur.supprimer(cin);
    if(projet)
    {ui->tabcollaborateur->setModel(empcollaborateur.afficher());
        QMessageBox::inforamtion(nullptr,QObject::tr("Supprimer un collaborateur"),
                                 QObject::tr("collaborateursupprimé.\n"
                                             "Click Cancel to exit "), QMessageBox::Cancel);

}
else
    {
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un collaborateur"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit "), QMessageBox::Cancel);
    }




void MainWindow::on_pushButton_14_clicked()
{click->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Documents/smartmunicipality/click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString cin=ui->lineEdit_modifiercincollaborateur->text().toInt();
    QString nom=ui->lineEdit_modifiernom->text();
    QString prenom=ui->lineEdit_modifierprenom->text();
    QString adresse=ui->lineEdit_modifieradresse->text();
    QString ville=ui->lineEdit_modifierville->text();
    int num_tel= ui->lineEdit_modifiertel_num->text().toInt();

    collaborateur c(cin,prenom,nom,adresse,ville,num_tel);
    bool projet=c.modifierfour(cincollaborateur);
    if (projet)
{
     collaborateur tmpcollaborateur;
        ui->tabecollaborateur->setModel(tmpcollaborateur.afficher());
       QMessageBox::information(nullptr,QObject::tr(" modifier"),
                                 QObject::tr("collaborateur modifié.\n"
                                             "Click Cancel to exit "), QMessageBox::Cancel);
    }
else
QMessageBox::critical(nullpte,QObject::tr("modifier"),QObject::tr(erreur .\""Click cancel to exit."),MMessageBox::cancel);

}





void MainWindow::on_pushButton_modifierprojet_clicked()
{
    int num_pro=ui->lineEdit_modifiernum_pro->text().toInt();
    QString titre_pro=ui->lineEdit_modifiertitre_pro->text();
    QString chef_pro=ui->lineEdit_modifierchef_pro->text();
    int budget=ui->lineEdit_modifierbudget->text().toInt();
  projet p(num_pro,titre_pro,chef_pro,budget);
  bool test=p.modifierfour(num_pro);
  if(test)
  { projet tmpfour;
  ui->afficherfour->setModel(tmpFour.afficher());
  QMessageBox::inforamtion(nummpte,Qobject::tr("modifier"),
                    QObject::tr("Succes.\n""click cancel to exit."),QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullpte,Qobject::tr("modifier"),
                QObject::tr("Erreur .\""Clik cancel to exit ."),QMessageBox::Cancel);
}
