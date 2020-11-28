#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personel.h"
#include "poste.h"
#include <QMessageBox>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TABPERSONEL->setModel(pp.afficherperso());
    ui->TABPOSTE->setModel(po.afficherposte());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initialiserperso()
{
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_tel->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_email->clear();
}
void MainWindow::initialiserposte()
{
    ui->lineEdit_fonction->clear();
    ui->lineEdit_heures->clear();
    ui->lineEdit_departement->clear();
    ui->lineEdit_salaire->clear();
}

// AJOUT PERSONEL
void MainWindow::on_pushButton_Ajouterclient_clicked()
{
    QString ID=ui->lineEdit_id->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString tel=ui->lineEdit_tel->text();
    QString adresse =ui->lineEdit_adresse->text();
    QString email=ui->lineEdit_email->text();
    Personel p(ID,nom,prenom,tel,adresse,email);
    if(p.verif_id(ID)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("ID doit contenir 8 chiffres!  \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

    }else if(p.verif_nom(nom)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir un nom valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else if (p.verif_nom(prenom)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir un prenom valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else if (p.verif_nom(adresse)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir une adresse valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else if(p.verif_id(tel)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir un numero de telephone valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else if (p.verif_email(email)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir une adresse mail valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else
    {
             bool test=p.ajouterperso();
             if(test)
       {
        ui->TABPERSONEL->setModel(p.afficherperso());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un Personel"),
                                 QObject::tr("Personel ajouté .\n"
                                             "Click Cancel to exit ."),QMessageBox::Cancel);
        initialiserperso();

        }
    }
}


//SUPP PERSO

void MainWindow::on_pushButton_supprimer_clicked()
{
    Personel p;
    QString id =ui->lineEdit_aff_id->text();
    bool test=p.supprimerperso(id);
    if(test)
    {
        ui->TABPERSONEL->setModel(p.afficherperso());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un personel"),QObject::tr("Persosnel Supprimé .\n"
                                                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un personel"),QObject::tr("Erreur . \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
}

//MODIFIER PERSO

void MainWindow::on_pushButton_modifier_personel_clicked()
{
    QString ID=ui->lineEdit_id->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString tel=ui->lineEdit_tel->text();
    QString adresse =ui->lineEdit_adresse->text();
    QString email=ui->lineEdit_email->text();
    Personel p(ID,nom,prenom,tel,adresse,email);

    QSqlQuery query;
    query.prepare(" UPDATE PERSONEL SET ID='"+ID+"', NOM='"+nom+"', PRENOM='"+prenom+"',TEL='"+tel+"',ADRESSE='"+adresse+"',EMAIL='"+email+"' WHERE ");
    if(query.exec()){
        ui->TABPERSONEL->setModel(p.afficherperso());
        QMessageBox::information(nullptr,QObject::tr("Modifier un Personel"),
                                 QObject::tr("Personel modifié .\n"
                                             "Click Cancel to exit ."),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }

}


//AJOUT POSTE

void MainWindow::on_pushButton_ajoute_rposte_clicked()
{
    QString fonction=ui->lineEdit_fonction->text();
    QString heures=ui->lineEdit_heures->text();
    QString departement=ui->lineEdit_departement->text();
    QString salaire=ui->lineEdit_salaire->text();
    Poste po(fonction,heures,departement,salaire);
    bool test=po.ajouterposte();
    if(po.verif_nom(fonction)==false)
    {
            QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir une fonction valide ! \n"
                                                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
    }else if(po.verif_nom(departement)==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez saisir un departement valide! \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
    }else{

    if(test)
    {
        ui->TABPOSTE->setModel(po.afficherposte());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un Poste"),
                                 QObject::tr("Poste ajouté .\n"
                                             "Click Cancel to exit ."),QMessageBox::Cancel);
        initialiserposte();
    }
}
}


//SUPP POSTE

void MainWindow::on_pushButton_supprimer_poste_clicked()
{
    Poste po;
    QString fonction=ui->lineEdit_aff_fonction->text();
    bool test=po.supprimerposte(fonction);
    if(test)
    {
        ui->TABPOSTE->setModel(po.afficherposte());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un poste"),QObject::tr("Poste Supprimé .\n"
                                                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un poste"),QObject::tr("Erreur . \n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
}


//MODIFIER POSTE

void MainWindow::on_pushButton_modifier_poste_clicked()
{
    QString fonction=ui->lineEdit_fonction->text();
    QString heures=ui->lineEdit_heures->text();
    QString departement=ui->lineEdit_departement->text();
    QString salaire=ui->lineEdit_salaire->text();
    Poste p(fonction,heures,departement,salaire);
    QSqlQuery query;
    query.prepare("UPDATE POSTE SET FONCTION='"+fonction+"', HEURES='"+heures+"', DEPARTEMENT='"+departement+"',SALAIRE='"+salaire+"' WHERE FONCTION= '"+fonction+"'");
    if(query.exec()){
        ui->TABPOSTE->setModel(po.afficherposte());
        QMessageBox::information(nullptr,QObject::tr("Modifier un POSTE"),
                                 QObject::tr("Poste modifié .\n"
                                             "Click Cancel to exit ."),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }

}


// IMPRIMER
void MainWindow::on_pushButton_imprimer_poste_clicked()
{
        QString str;
        str.append("<html><head></head><body><center>"+QString());
        str.append("<table border=1><tr>") ;
        str.append("<td>"+QString("fonction")+"</td>") ;
        str.append("<td>"+QString("heures")+"</td>") ;
        str.append("<td>"+QString("departement")+"</td>") ;
        str.append("<td>"+QString("salaire")+"</td>") ;


        QSqlQuery* query=new QSqlQuery();
        query->exec("SELECT FONCTION,HEURES,DEPARTEMENT,SALAIRE FROM POSTE");

        while(query->next())
        {
        str.append("<tr><td>");
        str.append(query->value(0).toString()) ;
        str.append("</td><td>") ;
        str.append(query->value(1).toString());
        str.append("</td><td>") ;
        str.append(query->value(2).toString());
        str.append("</td><td>") ;
        str.append(query->value(3).toString());
        str.append("</td><td>") ;
        str.append(query->value(4).toString());
        str.append("</td><td>") ;



        }
        str.append("</table></center></body></html>") ;

        QPrinter printer ;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4) ;

        QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","Convertir a PDF","C:/Users/skand/OneDrive/Bureau/Projet/PDF","PDF(*.pdf)");

        if (path.isEmpty()) return ;
        printer.setOutputFileName(path) ;
        QTextDocument doc;
        doc.setHtml(str) ;
        doc.print(&printer);
        QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                           "Click Cancel to exit ."),QMessageBox::Cancel);


}

void MainWindow::on_pushButton_imprimer_personels_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("ID")+"</td>") ;
    str.append("<td>"+QString("NOM")+"</td>") ;
    str.append("<td>"+QString("PRENOM")+"</td>") ;
    str.append("<td>"+QString("TEL")+"</td>") ;
    str.append("<td>"+QString("ADRESSE")+"</td>") ;
    str.append("<td>"+QString("EMAIL")+"</td></tr>") ;

    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT ID,NOM,PRENOM,TEL,ADRESSE,EMAIL FROM PERSONEL");

    while(query->next())
    {
    str.append("<tr><td>");
    str.append(query->value(0).toString()) ;
    str.append("</td><td>") ;
    str.append(query->value(1).toString());
    str.append("</td><td>") ;
    str.append(query->value(2).toString());
    str.append("</td><td>") ;
    str.append(query->value(3).toString());
    str.append("</td><td>") ;
    str.append(query->value(4).toString());
    str.append("</td><td>") ;

    str.append(query->value(5).toString());
    str.append("</td></tr>");

    }
    str.append("</table></center></body></html>") ;

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/Projet/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);


}
