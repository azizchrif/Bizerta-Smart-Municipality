#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personel.h"
#include "poste.h"
#include "equipements.h"
#include "evenements.h"
#include "tickets.h"
#include "statistique.h"
#include "statistiques.h"
#include "historique.h"
#include "collaborateur.h"
#include "projet.h"
#include "statistiquess.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)   
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->TABPERSONEL->setModel(pp.afficherperso());
    ui->TABPOSTE->setModel(po.afficherposte());
    ui->pushButton_rechercher_personel->setCheckable(true);
    ui->radioButton_trinom->setCheckable(true);
    ui->radioButton_tri_ID->setCheckable(true);
    ui->Tab_afe->setModel(e.AfficherEquipements());
    ui->Tab_aff->setModel(f.AfficherFournisseurs());
    ui->Tab_afe_2->setModel(ev.AfficherEvenements());
    ui->Tab_aff_2->setModel(t.AfficherTickets());
    ui->Tab_afe_3->setModel(c.AfficherCollaborateur());
    ui->Tab_aff_3->setModel(p.AfficherProjet());

    player= new QMediaPlayer(this);
//controle de saisie
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    ui->ID_aje->setValidator(new QIntValidator(1,999999, this));
    ui->Prix_aje->setValidator(new QIntValidator(1,9999999, this));
    ui->ID_spe->setValidator(new QIntValidator(1,999999, this));
    ui->ID_moe->setValidator(new QIntValidator(1,999999, this));
    ui->Prix_moe->setValidator(new QIntValidator(1,9999999, this));
    ui->Nom_afe->setValidator(validator_String);
    ui->Adresse_afe->setValidator(validator_String);
    ui->ID_afe->setValidator(new QIntValidator(100000,999999, this));
    ui->Tel_afe->setValidator(new QIntValidator(10000000,99999999, this));
    ui->Tel_afe_3->setValidator(new QIntValidator(10000000,99999999, this));
    ui->Tel_afe_5->setValidator(new QIntValidator(10000000,99999999, this));
    ui->ID_mof->setValidator(new QIntValidator(100000,999999, this));
    ui->Nom_mof->setValidator(validator_String);
    ui->Adresse_mof->setValidator(validator_String);
    ui->Tel_mof->setValidator(new QIntValidator(100000,999999, this));
    ui->ID_spf->setValidator(new QIntValidator(1,99999999, this));
    ui->ID_spf_3->setValidator(new QIntValidator(1,99999999, this));
    ui->Nom_aje_2->setValidator(validator_String);
    ui->Type_aje_2->setValidator(validator_String);
    ui->ID_aje_2->setValidator(new QIntValidator(1,99999999, this));
    ui->Date_aje_2->setValidator(new QIntValidator(1,99999999, this));
    ui->ID_moe_2->setValidator(new QIntValidator(1,99999999, this));
    ui->Nom_moe_2->setValidator(validator_String);
    ui->Type_moe_2->setValidator(validator_String);
    ui->Date_moe_2->setValidator(new QIntValidator(1,99999999, this));
    ui->ID_spe_2->setValidator(new QIntValidator(1,999999999, this));
    ui->ID_spf_2->setValidator(new QIntValidator(1,99999999, this));
    ui->Nom_afe_2->setValidator(validator_String);
    ui->Nom_afe_3->setValidator(validator_String);
    ui->Nom_afe_5->setValidator(validator_String);
    ui->Adresse_afe_2->setValidator(validator_String);
    ui->AdresseEmail_afe_3->setValidator(validator_String);
    ui->AdresseEmail_afe_2->setValidator(validator_String);

    ui->ID_afe_2->setValidator(new QIntValidator(100000,999999, this));
    ui->ID_afe_3->setValidator(new QIntValidator(100000,999999, this));
    ui->ID_afe_5->setValidator(new QIntValidator(100000,999999, this));
    ui->Tel_afe_2->setValidator(new QIntValidator(10000000,99999999, this));
    ui->ID_mof_2->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_mof_2->setValidator(validator_String);
    ui->Adresse_mof_2->setValidator(validator_String);
    ui->Nom_aje_8->setValidator(validator_String);
    ui->Nom_aje_9->setValidator(validator_String);
    ui->Tel_mof_2->setValidator(new QIntValidator(1,999999999, this));
    ui->ID_ree->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_ree->setValidator(validator_String);
    ui->etat_ree->setValidator(new QIntValidator(0,1, this));
    ui->ID_ree_2->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_ree_2->setValidator(validator_String);
    ui->etat_ree_2->setValidator(validator_String);
    ui->ID_ree_3->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_ree_3->setValidator(validator_String);
    ui->Adresse_aje_5->setValidator(validator_String);
    ui->Prenom_aje_5->setValidator(validator_String);
    ui->Adresse_aje_6->setValidator(validator_String);
    ui->Prenom_aje_6->setValidator(validator_String);


    ui->etat_ree_3->setValidator(new QIntValidator(1,999999999, this));
    ui->ID_ree_4->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_ree_4->setValidator(validator_String);
    ui->etat_ree_4->setValidator(new QIntValidator(1,999999999, this));
    ui->ID_aje_8->setValidator(new QIntValidator(1,99999999, this));
    ui->ID_aje_9->setValidator(new QIntValidator(1,99999999, this));
    ui->NumTel_aje_5->setValidator(new QIntValidator(1,99999999, this));
    ui->NumTel_aje_6->setValidator(new QIntValidator(1,99999999, this));
    ui->ID_spe_3->setValidator(new QIntValidator(1,999999999, this));
    ui->ID_ree_5->setValidator(new QIntValidator(1,999999999, this));
    ui->Nom_ree_5->setValidator(validator_String);
    ui->etat_ree_5->setValidator(new QIntValidator(10000001,99999999, this));
    ui->etat_ree_6->setValidator(new QIntValidator(10000001,99999999, this));



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
//////////////////////
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
////////////////////

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
//////////////////////////

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
    query.prepare(" UPDATE PERSONEL SET ID='"+ID+"', NOM='"+nom+"', PRENOM='"+prenom+"',TEL='"+tel+"',ADRESSE='"+adresse+"',EMAIL='"+email+"' WHERE ID='"+ID+"'");
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
///////////////////////////////

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
/////////////////////////////////

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
////////////////////////////

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
        initialiserperso();
        QMessageBox::information(nullptr,QObject::tr("Modifier un POSTE"),
                                 QObject::tr("Poste modifié .\n"
                                             "Click Cancel to exit ."),QMessageBox::Cancel);
    }else{
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }

}


// IMPRIMER POSTE
///////////////////////////////////
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

        QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

        if (path.isEmpty()) return ;
        printer.setOutputFileName(path) ;
        QTextDocument doc;
        doc.setHtml(str) ;
        doc.print(&printer);
        QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                           "Click Cancel to exit ."),QMessageBox::Cancel);


}

// IMPRIMER PERSONEL
//////////////////////////////

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

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

}

// RECHERCHER PERSONEL
////////////////////


void MainWindow::on_pushButton_rechercher_personel_toggled(bool checked)
{
    if(checked){
        QSqlQueryModel * model= new QSqlQueryModel();
                   QSqlQuery q;
                   Personel p;
                   q.prepare("select * from PERSONEL WHERE(ID LIKE '%"+ui->lineEdit_aff_id->text()+"%' or NOM LIKE '%"+ui->lineEdit_aff_id->text()+"%' or PRENOM LIKE '%"+ui->lineEdit_aff_id->text()+"%')");

                   p.rechercherperso(q);
                          q.exec();
                          model->setQuery(q);
                          ui->TABPERSONEL->setModel(p.rechercherperso(q));
    }else
       {
        ui->TABPERSONEL->setModel(pp.afficherperso());
    }
}



// RECHERCHER POSTE
/////////////////////


void MainWindow::on_pushButton_rechercher_poste_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery q;
               Poste po;
               q.prepare("select * from POSTE WHERE(FONCTION LIKE '%"+ui->lineEdit_aff_fonction->text()+"%')");

               po.rechercherposte(q);
                      q.exec();
                      model->setQuery(q);
                      ui->TABPOSTE->setModel(po.rechercherposte(q));
}



// TRI NOM
/////////////////

void MainWindow::on_radioButton_trinom_toggled(bool checked)
{
    if(checked)
    {
        QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select * from PERSONEL ORDER BY NOM ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
           ui->TABPERSONEL->setModel(model);

    }else
    {
        ui->TABPERSONEL->setModel(pp.afficherperso());
    }

}

// TRI ID
//////////////////////

void MainWindow::on_radioButton_tri_ID_toggled(bool checked)
{
    if(checked)
    {
        QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select * from PERSONEL ORDER BY ID");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model ->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
           ui->TABPERSONEL->setModel(model);

    }else
    {
        ui->TABPERSONEL->setModel(pp.afficherperso());
    }

}


//TRI SALAIRE
/////////////////////

void MainWindow::on_radioButton_tri_salaire_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from POSTE ORDER BY SALAIRE");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("fonction"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("heures"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("departement"));

       ui->TABPOSTE->setModel(model);
}

// ACTUALISER
///////////////


void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->TABPERSONEL->setModel(pp.afficherperso());
}


void MainWindow::on_pushButton_actualiser_2_clicked()
{
     ui->TABPOSTE->setModel(po.afficherposte());
}


//SELECTION
//////////////////

void MainWindow::on_TABPERSONEL_activated(const QModelIndex &index)
{

     QString nom,prenom,tel,adresse,email ;
        QString ID=ui->TABPERSONEL->model()->data(index).toString() ;

            QSqlQuery qry;

           qry.prepare("SELECT * FROM PERSONEL  where ID='"+ID+"' or NOM='"+ID+"' or PRENOM='"+ID+"' or TEL='"+ID+"' or ADRESSE='"+ID+"'or EMAIL='"+ID+"'");
        if(qry.exec())
        {
            while (qry.next())

            {

                ui->lineEdit_id->setText(qry.value(0).toString());
                 ui->lineEdit_nom->setText(qry.value(1).toString());
                 ui->lineEdit_prenom->setText(qry.value(2).toString());
                 ui->lineEdit_tel->setText(qry.value(3).toString());
                 ui->lineEdit_adresse->setText(qry.value(4).toString());
                 ui->lineEdit_email->setText(qry.value(5).toString());
            }

        }
        else
        {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
           }


}
//MUSIC
////////

//IMPRIMER
///////////////////////

void MainWindow::on_pushButton_imprimer_personel_3_clicked()
{
    const QString format("<td>%1</td>");
               QString html;
               QAbstractItemModel *md = ui->TABPERSONEL->model();
               html = "<html><body><table border=\"0\">";

               html += "<td></td>";
               for(int column = 0; column < md->columnCount();
                   column++) {
                   QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
                   html += format.arg(data);
               }
               for(int row = 0; row < md->rowCount() ; row++) {
                   html += "<tr>";
                   QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
                   html += format.arg(data);
                   for(int column = 0; column < md->columnCount();
                       column++) {
                       QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                       html += format.arg(data);
                   }
                   html += "</tr>";
               }
               html += "</table></body></html>";

               QPrinter printer;
               QPrintDialog *dialog = new QPrintDialog(&printer);
               if(dialog->exec() == QDialog::Accepted) {
                   QTextDocument document;
                   document.setHtml(html);
                   document.print(&printer);
               }

}

void MainWindow::on_pushButton_imprimer_poste_2_clicked()
{
    const QString format("<td>%1</td>");
               QString html;
               QAbstractItemModel *md = ui->TABPOSTE->model();
               html = "<html><body><table border=\"0\">";

               html += "<td></td>";
               for(int column = 0; column < md->columnCount();
                   column++) {
                   QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
                   html += format.arg(data);
               }
               for(int row = 0; row < md->rowCount() ; row++) {
                   html += "<tr>";
                   QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
                   html += format.arg(data);
                   for(int column = 0; column < md->columnCount();
                       column++) {
                       QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                       html += format.arg(data);
                   }
                   html += "</tr>";
               }
               html += "</table></body></html>";

               QPrinter printer;
               QPrintDialog *dialog = new QPrintDialog(&printer);
               if(dialog->exec() == QDialog::Accepted) {
                   QTextDocument document;
                   document.setHtml(html);
                   document.print(&printer);
               }

}



void MainWindow::on_login_clicked()
{
    QString name,mot_de_passe;
    name=ui->lineEdit_namelogin->text();
    mot_de_passe=ui->lineEdit_motdepasselogin->text();

    QSqlQuery qry ;

    if (qry.exec("select * from LOGIN where nom='"+name+"' and MDP='"+mot_de_passe+"'"))
    {
            int count=0;

            while(qry.next())
    {
            count++;
}

            if (count==1)
    {
           ui->Main_stackedWidget->setCurrentIndex(1);
          // hide();

}
            if (count<1)
    { ui->message->setText("Username or Password incorrect!") ;
}
}
}

void MainWindow::on_Ressources_humaines_button_clicked()
{
    ui->Main_stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_Ajouter_e_clicked()
{

    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QString Nom=ui->Nom_aje->currentText();
        int ID=ui->ID_aje->text().toInt();
        ui->ID_aje->setValidator(new QIntValidator(1,999999, this));
        int Prix=ui->Prix_aje->text().toInt();
        ui->Prix_aje->setValidator(new QIntValidator(1,9999999, this));
        int Etat=ui->Etat_aje->currentText().toInt();

        Equipements e(Nom,ID,Etat,Prix);
        bool test=e.AjouterEquipements();



        if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->Tab_afe->setModel(e.AfficherEquipements());}
         else
             msgBox.setText("Echec d'ajout");
             msgBox.exec();
             QString textajouter;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from EQUIPEMENT");
             textajouter="L'ajout d'un Equipement a la base de donnees de reference = "+QString::number(ID)+" a ete effectue avec succees";
             h.write2(textajouter);
}

void MainWindow::on_Supprimer_e_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_spe->text().toInt();
    ui->ID_spe->setValidator(new QIntValidator(1,999999, this));
    bool test=e.SupprimerEquipements(ID);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Supression avec succes.");
        ui->Tab_afe->setModel(e.AfficherEquipements());//refresh
    }
    else
    msgBox.setText("Echec de supression");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from EQUIPEMENT");
    textajouter="La suppression d'un Equipement a la base de donnees de reference = "+QString::number(ID)+" a ete effectuee avec succees";
    h.write2(textajouter);
}

void MainWindow::on_modifier_e_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
        int ID=ui->ID_moe->text().toInt();
        ui->ID_moe->setValidator(new QIntValidator(1,999999, this));
        QString Nom=ui->Nom_moe->currentText();
        ui->Nom_moe->setValidator(validator_String);
        int Prix=ui->Prix_moe->text().toInt();
        ui->Prix_moe->setValidator(new QIntValidator(1,9999999, this));
        int Etat=ui->Etat_moe->currentText().toInt();


            Equipements e(Nom,ID,Etat,Prix);
            bool test=e.ModifierEquipements();
            if(test)
               {  msgBox.setText("Modification avec succes.");
                 ui->Tab_afe->setModel(e.AfficherEquipements());}
             else
                 msgBox.setText("Echec de modification");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 qry.prepare("select * from EQUIPEMENT");
                 textajouter="La modification d'un Equipement a la base de donnees de reference = "+QString::number(ID)+" a ete effectuee avec succees";
                 h.write2(textajouter);
}

void MainWindow::on_ajouter_f_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Z a-z]+"),this);
    QString Nom=ui->Nom_afe->text();
    ui->Nom_afe->setValidator(validator_String);
    QString AdresseEmail=ui->AdresseEmail_afe->text();
    QString Adresse=ui->Adresse_afe->text();
    ui->Adresse_afe->setValidator(validator_String);
        int ID=ui->ID_afe->text().toInt();
        ui->ID_afe->setValidator(new QIntValidator(100000,999999, this));
        int NumTel=ui->Tel_afe->text().toInt();

        Fournisseurs f(Nom,Adresse , AdresseEmail,ID, NumTel);
        bool test=f.AjouterFournisseurs();
            if(test)
               {  msgBox.setText("Ajout avec succes.");
                 ui->Tab_aff->setModel(f.AfficherFournisseurs());
            }
             else
                 msgBox.setText("Echec d'ajout");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 textajouter="L'ajout d'un Fournisseur a la base de donnees de reference = "+QString::number(ID)+" a ete effectuee avec succees";
                 h.write3(textajouter);


}
void MainWindow::on_modifier_f_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
       QValidator *validator_int=new QRegExpValidator(QRegExp("[1-999999]+"),this);

        int ID=ui->ID_mof->text().toInt();
        ui->ID_mof->setValidator(validator_int);
        QString Nom=ui->Nom_mof->text();
        ui->Nom_mof->setValidator(validator_String);
        QString Adresse=ui->Adresse_mof->text();
        ui->Adresse_mof->setValidator(validator_String);
        QString AdresseEmail=ui->AdresseEmail_mof->text();
        int NumTel=ui->Tel_mof->text().toInt();
        ui->Tel_mof->setValidator(validator_int);

            Fournisseurs f(Nom, Adresse , AdresseEmail,ID,NumTel);
            bool test=f.ModifierFournisseurs();
            if(test)
               {  msgBox.setText("Modification avec succes.");
                 ui->Tab_aff->setModel(f.AfficherFournisseurs());
            }
             else
                 msgBox.setText("Echec d'ajout");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 qry.prepare("select * from FOURNISSEUR");
                 textajouter="La modification d'un Fournisseur a la base de donnees de reference = "+QString::number(ID)+" a ete effectuee avec succees";
                 h.write3(textajouter);
}

void MainWindow::on_Supprimer_f_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_spf->text().toInt();
    ui->ID_spf->setValidator(new QIntValidator(1,99999999, this));
    bool test=f.SupprimerFournisseurs(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff->setModel(f.AfficherFournisseurs());//refresh
        msgBox.setText("Supression avec succes.");
    }
    else
    msgBox.setText("Echec de supression.");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from FOURNISSEUR");
    textajouter="La supression d'un Fournisseur a la base de donnees de reference = "+QString::number(ID)+" a ete effectuee avec succees";
    h.write3(textajouter);
}


void MainWindow::on_TriAsc_e_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_ascprix());
}

void MainWindow::on_TriDesc_e_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_descprix());
}
void MainWindow::on_back_tri_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier->setCurrentIndex(0);
}

void MainWindow::on_Trier_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier->setCurrentIndex(1);
}

void MainWindow::on_Triprix_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix->setCurrentIndex(1);
    ui->stackedWidget_etat->setCurrentIndex(0);
    ui->stackedWidget_nom->setCurrentIndex(0);
}

void MainWindow::on_back_triprix_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix->setCurrentIndex(0);
}

void MainWindow::on_trinom_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom->setCurrentIndex(1);
    ui->stackedWidget_etat->setCurrentIndex(0);
    ui->stackedWidget_prix->setCurrentIndex(0);

}
void MainWindow::on_back_trinom_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom->setCurrentIndex(0);
}
void MainWindow::on_Trietat_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat->setCurrentIndex(1);
    ui->stackedWidget_nom->setCurrentIndex(0);
    ui->stackedWidget_prix->setCurrentIndex(0);
}

void MainWindow::on_back_trietat_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_ascnom());
}


void MainWindow::on_TriDesc_en_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_descnom());
}

void MainWindow::on_TriAsc_ee_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_ascetat());
}

void MainWindow::on_TriDesc_ee_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe->setModel(e.Afficher_descetat());
}

void MainWindow::on_Rechercher_ID_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_ree->text().toInt();
    ui->ID_ree->setValidator(new QIntValidator(1,999999999, this));
    bool test=e.Rechercher_ID(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe->setModel(e.Rechercher_ID(ID));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();

}



void MainWindow::on_Rechercher_Nom_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QString Nom=ui->Nom_ree->currentText();
    ui->Nom_ree->setValidator(validator_String);
    bool test=e.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe->setModel(e.Rechercher_Nom(Nom));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}


void MainWindow::on_Rechercher_Etat_clicked()
{
    int count=0;
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Etat = ui->etat_ree->text().toInt();
    ui->etat_ree->setValidator(new QIntValidator(0,1, this));


    bool test=e.Rechercher_Etat(Etat);
    QMessageBox msgBox;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM EQUIPEMENT  where ETAT=Etat ");
    qry.bindValue(":Etat", Etat);
        if(qry.exec())
        {
            while (qry.next())

            {

                count++;
            }

        }
    if(test)
       {if (count!=0)
        {ui->Tab_afe->setModel(e.Rechercher_Etat(Etat));//refresh
        msgBox.setText("Recherche avec succes.");}
        else
            msgBox.setText("Not found.");
        ui->Tab_afe->setModel(e.Rechercher_Etat(Etat));//refresh

    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}


void MainWindow::on_Rechercher_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher->setCurrentIndex(1);
}


void MainWindow::on_Back_rechercher_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher->setCurrentIndex(0);
}
void MainWindow::on_Backtomenu_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Backtomenu_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Trier_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_2->setCurrentIndex(1);
}

void MainWindow::on_back_tri_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_2->setCurrentIndex(0);
}

void MainWindow::on_Triprix_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_2->setCurrentIndex(1);
    ui->stackedWidget_etat_2->setCurrentIndex(0);
    ui->stackedWidget_nom_2->setCurrentIndex(0);
}

void MainWindow::on_back_triprix_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}

void MainWindow::on_trinom_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_2->setCurrentIndex(1);
    ui->stackedWidget_etat_2->setCurrentIndex(0);
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}
void MainWindow::on_back_trinom_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_2->setCurrentIndex(0);
}
void MainWindow::on_Trietat_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_2->setCurrentIndex(1);
    ui->stackedWidget_nom_2->setCurrentIndex(0);
    ui->stackedWidget_prix_2->setCurrentIndex(0);
}
void MainWindow::on_back_trietat_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_2->setCurrentIndex(0);
}
void MainWindow::on_TriAsc_en_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_asscNom());
}

void MainWindow::on_TriDesc_en_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_desscNom());
}

void MainWindow::on_TriAsc_e_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_ascID());
}

void MainWindow::on_TriDesc_e_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_descID());
}

void MainWindow::on_TriAsc_ee_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_ascAdresse());
}

void MainWindow::on_TriDesc_ee_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff->setModel(f.Afficher_descAdresse());
}

void MainWindow::on_Rechercher_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
   ui->stackedWidget_rechercher_2->setCurrentIndex(1);
}

void MainWindow::on_Rechercher_ID_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_ree_2->text().toInt();
    ui->ID_ree_2->setValidator(new QIntValidator(1,999999999, this));
    bool test=f.Rechercher_ID(ID);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_ID(ID));//refresh

    }
    else
    msgBox.setText("Echec de modification.");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Nom_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QString Nom=ui->Nom_ree_2->text();
    ui->Nom_ree_2->setValidator(validator_String);
    bool test=f.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_Nom(Nom));//refresh

    }
    else
    msgBox.setText("Echec de Recherche.");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Etat_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QString Adresse=ui->etat_ree_2->text();
    ui->etat_ree_2->setValidator(validator_String);
    bool test=f.Rechercher_Adresse(Adresse);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff->setModel(f.Rechercher_Adresse(Adresse));//refresh

    }
    else
    msgBox.setText("Echec de recherche.");
    msgBox.exec();
}

void MainWindow::on_Back_rechercher_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_2->setCurrentIndex(0);
}

void MainWindow::on_print_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("ID")+"</td>") ;
    str.append("<td>"+QString("Nom")+"</td>") ;
    str.append("<td>"+QString("Prix")+"</td>") ;
    str.append("<td>"+QString("Etat")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT ID,NOM,PRIX,ETAT FROM EQUIPEMENT");

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

    }
    str.append("</table></center></body></html>") ;

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_print_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("ID")+"</td>") ;
    str.append("<td>"+QString("Nom")+"</td>") ;
    str.append("<td>"+QString("NumTel")+"</td>") ;
    str.append("<td>"+QString("Adresse")+"</td>") ;
    str.append("<td>"+QString("AdresseEmail")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT IDF,NOMF,NUMTELF,ADRESSEF,ADRESSEEMAILF FROM FOURNISSEUR");

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

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");
    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);


}


void MainWindow::on_Equipements_button_clicked()
{
    ui->Main_stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_Fournisseurs_button_4_clicked()
{
    ui->Main_stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_modifier_e_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
        int ID=ui->ID_moe_2->text().toInt();
        ui->ID_moe_2->setValidator(new QIntValidator(1,99999999, this));
        QString Nom=ui->Nom_moe_2->text();
        ui->Nom_moe_2->setValidator(validator_String);
        QString Type=ui->Type_moe_2->text();
        int Date=ui->Date_moe_2->text().toInt();
        ui->Date_moe_2->setValidator(new QIntValidator(1,99999999, this));



            Evenements e1(ID,Nom,Type,Date);
            bool test=e1.ModifierEvenements();
            if(test)
               {  msgBox.setText("Modification avec succes.");
                 ui->Tab_afe_2->setModel(e1.AfficherEvenements());}
             else
                 msgBox.setText("Echec de modification");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qury;
                 qury.prepare("select * from T_EV");

                 textajouter="La modification d'un evenement a la base de donnees de reference = "+QString::number(ID)+" a ete effectue avec succees";
                 h.write1(textajouter);

}
void MainWindow::on_Ajouter_e_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QString Nom=ui->Nom_aje_2->text();
    QString Type=ui->Type_aje_2->text();
        int ID=ui->ID_aje_2->text().toInt();
        ui->ID_aje_2->setValidator(new QIntValidator(1,99999999, this));
        int Date=ui->Date_aje_2->text().toInt();
        ui->Date_aje_2->setValidator(new QIntValidator(1,99999999, this));

        Evenements e1(ID,Nom,Type,Date);
        bool test=e1.AjouterEvenements();



        if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->Tab_afe_2->setModel(e1.AfficherEvenements());}
         else
             msgBox.setText("Echec d'ajout");
             msgBox.exec();
             QString textajouter;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from T_EV");            
             textajouter="L'ajout d'un evenement a la base de donnees de reference = "+QString::number(ID)+" a ete effectue avec succees";
             h.write1(textajouter);

}




void MainWindow::on_Trier_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_3->setCurrentIndex(1);
}

void MainWindow::on_back_triprix_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_3->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_e_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_ascID());
}

void MainWindow::on_TriDesc_e_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_descID());
}


void MainWindow::on_Triprix_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_3->setCurrentIndex(1);
    ui->stackedWidget_etat_3->setCurrentIndex(0);
    ui->stackedWidget_nom_3->setCurrentIndex(0);
}

void MainWindow::on_trinom_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_3->setCurrentIndex(1);
    ui->stackedWidget_etat_3->setCurrentIndex(0);
    ui->stackedWidget_prix_3->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_ascnom());
}

void MainWindow::on_TriDesc_en_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_descnom());
}

void MainWindow::on_back_trinom_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_3->setCurrentIndex(0);
}

void MainWindow::on_Trietat_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_3->setCurrentIndex(1);
    ui->stackedWidget_nom_3->setCurrentIndex(0);
    ui->stackedWidget_prix_3->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_ee_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_ascDate());
}

void MainWindow::on_TriDesc_ee_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_2->setModel(ev.Afficher_descDate());
}

void MainWindow::on_back_trietat_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_3->setCurrentIndex(0);
}

void MainWindow::on_Backtomenu_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_3->setCurrentIndex(0);
}

void MainWindow::on_Rechercher_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
   ui->stackedWidget_rechercher_3->setCurrentIndex(1);
}

void MainWindow::on_Back_rechercher_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_3->setCurrentIndex(0);
}

void MainWindow::on_Rechercher_ID_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_ree_3->text().toInt();
    ui->ID_ree_3->setValidator(new QIntValidator(1,999999999, this));
    bool test=ev.Rechercher_ID(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe_2->setModel(ev.Rechercher_ID(ID));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Nom_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QString Nom=ui->Nom_ree_3->text();
    ui->Nom_ree_3->setValidator(validator_String);
    bool test=ev.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe_2->setModel(ev.Rechercher_Nom(Nom));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Etat_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Date = ui->etat_ree_3->text().toInt();
    ui->etat_ree_3->setValidator(new QIntValidator(1,999999999, this));


    bool test=ev.Rechercher_date(Date);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe_2->setModel(ev.Rechercher_date(Date));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}



void MainWindow::on_Supprimer_e_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_spe_2->text().toInt();
    ui->ID_spe_2->setValidator(new QIntValidator(1,999999999, this));
    bool test=ev.SupprimerEvenements(ID);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Supression avec succes.");
        ui->Tab_afe_2->setModel(ev.AfficherEvenements());//refresh
    }
    else
    msgBox.setText("Echec de supression");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from T_EV");

    textajouter="La suppression d'un evenement a la base de donnees de reference = "+QString::number(ID)+" a ete effectue avec succees";
    h.write1(textajouter);
}

void MainWindow::on_print_3_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("ID")+"</td>") ;
    str.append("<td>"+QString("Nom")+"</td>") ;
    str.append("<td>"+QString("Type")+"</td>") ;
    str.append("<td>"+QString("Date")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT IDT,NOMT,TYPET,DATET FROM T_EV");

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

    }
    str.append("</table></center></body></html>") ;

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

}

void MainWindow::on_Trier_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_4->setCurrentIndex(1);
}

void MainWindow::on_ajouter_f_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Z a-z]+"),this);
    QString Titre=ui->Nom_afe_2->text();
    ui->Nom_afe_2->setValidator(validator_String);
    QString Description=ui->Adresse_afe_2->text();
    ui->Adresse_afe_2->setValidator(validator_String);
        int Num=ui->ID_afe_2->text().toInt();
        ui->ID_afe_2->setValidator(new QIntValidator(100000,999999, this));
        int Prix=ui->Tel_afe_2->text().toInt();


        Tickets t(Num,Titre ,Prix, Description);
        bool test=t.AjouterTickets();
            if(test)
               {  msgBox.setText("Ajout avec succes.");
                 ui->Tab_aff_2->setModel(t.AfficherTickets());
            }
             else
                 msgBox.setText("Echec d'ajout");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 qry.prepare("select * from T_TICKET");
                 textajouter="L'ajout d'un Ticket a la base de donnees de reference = "+QString::number(Num)+" a ete effectue avec succees";
                 h.write(textajouter);



}


void MainWindow::on_modifier_f_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
       QValidator *validator_int=new QRegExpValidator(QRegExp("[1-999999]+"),this);

        int Num=ui->ID_mof_2->text().toInt();
        ui->ID_mof_2->setValidator(validator_int);
        QString Titre=ui->Nom_mof_2->text();
        ui->Nom_mof_2->setValidator(validator_String);
        QString Description=ui->Adresse_mof_2->text();
        ui->Adresse_mof_2->setValidator(validator_String);

        int Prix=ui->Tel_mof_2->text().toInt();
        ui->Tel_mof_2->setValidator(validator_int);

            Tickets t(Num,Titre ,Prix, Description);
            bool test=t.ModifierTickets();
                if(test)
                   {  msgBox.setText("Modification avec succes.");
                     ui->Tab_aff_2->setModel(t.AfficherTickets());
                }
                 else
                     msgBox.setText("Echec de modification");
                     msgBox.exec();
                     QString textajouter;
                     historique h;
                     QSqlQuery qry;
                     qry.prepare("select * from T_TICKET");
                     textajouter="La modification d'un Ticket a la base de donnees de reference = "+QString::number(Num)+" a ete effectuee avec succees";
                     h.write(textajouter);

}

void MainWindow::on_Supprimer_f_2_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Num = ui->ID_spf_2->text().toInt();
    ui->ID_spf_2->setValidator(new QIntValidator(1,99999999, this));
    bool test=t.SupprimerTickets(Num);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_2->setModel(t.AfficherTickets());//refresh
        msgBox.setText("Supression avec succes.");
    }
    else
    msgBox.setText("Echec de supression.");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from T_TICKET");
    textajouter="La suppression d'un Ticket a la base de donnees de reference = "+QString::number(Num)+" a ete effectuee avec succees";
    h.write(textajouter);

}

void MainWindow::on_Triprix_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_4->setCurrentIndex(1);
    ui->stackedWidget_etat_4->setCurrentIndex(0);
    ui->stackedWidget_nom_4->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_e_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_ascNum());
}

void MainWindow::on_TriDesc_e_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_descNum());
}

void MainWindow::on_back_triprix_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_4->setCurrentIndex(0);
}

void MainWindow::on_trinom_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_4->setCurrentIndex(1);
    ui->stackedWidget_etat_4->setCurrentIndex(0);
    ui->stackedWidget_prix_4->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_ascTitre());
}

void MainWindow::on_TriDesc_en_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_descTitre());
}

void MainWindow::on_back_trinom_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_4->setCurrentIndex(0);
}

void MainWindow::on_Trietat_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_4->setCurrentIndex(1);
    ui->stackedWidget_nom_4->setCurrentIndex(0);
    ui->stackedWidget_prix_4->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_ee_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_ascPrix());
}

void MainWindow::on_TriDesc_ee_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_2->setModel(t.Afficher_descPrix());
}

void MainWindow::on_back_trietat_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_4->setCurrentIndex(0);
}

void MainWindow::on_back_tri_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_4->setCurrentIndex(0);
}

void MainWindow::on_print_4_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("Num")+"</td>") ;
    str.append("<td>"+QString("Titre")+"</td>") ;
    str.append("<td>"+QString("Prix")+"</td>") ;
    str.append("<td>"+QString("Description")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT NUMT,TITRET,PRIXT,DESCT FROM T_TICKET");

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

    }
    str.append("</table></center></body></html>") ;

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

}

void MainWindow::on_Rechercher_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
   ui->stackedWidget_rechercher_4->setCurrentIndex(1);
}

void MainWindow::on_Back_rechercher_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
   ui->stackedWidget_rechercher_4->setCurrentIndex(0);
}

void MainWindow::on_Rechercher_ID_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Num = ui->ID_ree_4->text().toInt();
    ui->ID_ree_4->setValidator(new QIntValidator(1,999999999, this));
    bool test=t.Rechercher_Num(Num);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_2->setModel(t.Rechercher_Num(Num));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Nom_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QString Nom=ui->Nom_ree_4->text();
    ui->Nom_ree_4->setValidator(validator_String);
    bool test=t.Rechercher_Titre(Nom);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_2->setModel(t.Rechercher_Titre(Nom));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Etat_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Prix=ui->etat_ree_4->text().toInt();
    ui->etat_ree_4->setValidator(new QIntValidator(1,999999999, this));
    bool test=t.Rechercher_Prix(Prix);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_2->setModel(t.Rechercher_Prix(Prix));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Backtomenu_4_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Backtomenu_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Backtomenu_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Backtomenu_7_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_statistique_clicked()
{
    statistique s;
      s.exec();
}



void MainWindow::on_pushButton_clicked()
{
    statistiques s;
    s.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->Tab_aff_2->hide();
    historique h;
    ui->textBrowser->show();
    ui->textBrowser->setPlainText(h.read());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_historique->setCurrentIndex(0);
    ui->Tab_aff_2->show();
    ui->textBrowser->hide();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_historique->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->Tab_afe_2->hide();
    historique h;
    ui->textBrowser_2->show();
    ui->textBrowser_2->setPlainText(h.read1());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_historique_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_historique_2->setCurrentIndex(0);
    ui->Tab_afe_2->show();
    ui->textBrowser_2->hide();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_historique_3->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->Tab_afe->hide();
    historique h;
    ui->textBrowser_3->show();
    ui->textBrowser_3->setPlainText(h.read2());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_historique_3->setCurrentIndex(0);
    ui->Tab_afe->show();
    ui->textBrowser_3->hide();
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_historique_4->setCurrentIndex(1);

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->Tab_aff->hide();
    historique h;
    ui->textBrowser_4->show();
    ui->textBrowser_4->setPlainText(h.read3());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget_historique_4->setCurrentIndex(0);
    ui->Tab_aff->show();
    ui->textBrowser_4->hide();
}



void MainWindow::on_Ajouter_e_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QString Nom=ui->Nom_aje_8->text();
    QString Prenom=ui->Prenom_aje_5->text();
    QString Adresse=ui->Adresse_aje_5->text();
        int CIN=ui->ID_aje_8->text().toInt();
        int NumTel=ui->NumTel_aje_5->text().toInt();
        Collaborateur c(Nom,Prenom, Adresse ,CIN, NumTel);
        bool test=c.AjouterCollaborateur();



        if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->Tab_afe_3->setModel(c.AfficherCollaborateur());}
         else
             msgBox.setText("Echec d'ajout");
             msgBox.exec();
             QString textajouter;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from COLLABORATEUR");
             textajouter="L'ajout d'un Collaborateur a la base de donnees de reference = "+QString::number(CIN)+" a ete effectue avec succees";
             h.write4(textajouter);
}

void MainWindow::on_modifier_e_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QString Nom=ui->Nom_aje_9->text();
    QString Prenom=ui->Prenom_aje_6->text();
    QString Adresse=ui->Adresse_aje_6->text();
        int CIN=ui->ID_aje_9->text().toInt();
        int NumTel=ui->NumTel_aje_6->text().toInt();
        Collaborateur c(Nom,Prenom, Adresse ,CIN, NumTel);
        bool test=c.ModifierCollaborateur();



        if(test)
           {  msgBox.setText("Modification avec succes.");
             ui->Tab_afe_3->setModel(c.AfficherCollaborateur());}
         else
             msgBox.setText("Echec de modification");
             msgBox.exec();
             QString textajouter;
             historique h;
             QSqlQuery qry;
             qry.prepare("select * from COLLABORATEUR");
             textajouter="La modification d'un Collaborateur a la base de donnees de reference = "+QString::number(CIN)+" a ete effectue avec succees";
             h.write4(textajouter);
}

void MainWindow::on_Supprimer_e_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int CIN = ui->ID_spe_3->text().toInt();
    ui->ID_spe_3->setValidator(new QIntValidator(1,999999999, this));
    bool test=c.SupprimerCollaborateur(CIN);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Suppression avec succes.");
        ui->Tab_afe_3->setModel(c.AfficherCollaborateur());//refresh
    }
    else
    msgBox.setText("Echec de supression");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from COLLABORATEUR");
    textajouter="La suppression d'un Collaborateur a la base de donnees de reference = "+QString::number(CIN)+" a ete effectue avec succees";
    h.write4(textajouter);
}

void MainWindow::on_ajouter_f_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Z a-z]+"),this);
    QString TitrePro=ui->Nom_afe_3->text();
    ui->Nom_afe_3->setValidator(validator_String);
    QString ChefPro=ui->AdresseEmail_afe_2->text();
    ui->AdresseEmail_afe_2->setValidator(validator_String);
        int NumPro=ui->ID_afe_3->text().toInt();
        ui->ID_afe->setValidator(new QIntValidator(100000,999999, this));
        int Budget=ui->Tel_afe_3->text().toInt();
        ui->Tel_afe->setValidator(new QIntValidator(1,999999999, this));


        Projet p(TitrePro,ChefPro ,NumPro,Budget);
        bool test=p.AjouterProjet();
            if(test)
               {  msgBox.setText("Ajout avec succes.");
                 ui->Tab_aff_3->setModel(p.AfficherProjet());
            }
             else
                 msgBox.setText("Echec d'ajout");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 qry.prepare("select * from PROJET");
                 textajouter="L'ajout d'un Projet a la base de donnees de reference = "+QString::number(NumPro)+" a ete effectue avec succees";
                 h.write5(textajouter);
}

void MainWindow::on_modifier_f_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QMessageBox msgBox;
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Z a-z]+"),this);
    QString TitrePro=ui->Nom_afe_5->text();
    ui->Nom_afe_5->setValidator(validator_String);
    QString ChefPro=ui->AdresseEmail_afe_3->text();
    ui->AdresseEmail_afe_3->setValidator(validator_String);
        int NumPro=ui->ID_afe_5->text().toInt();
        ui->ID_afe->setValidator(new QIntValidator(100000,999999, this));
        int Budget=ui->Tel_afe_5->text().toInt();
        ui->Tel_afe->setValidator(new QIntValidator(1,999999999, this));


        Projet p(TitrePro,ChefPro ,NumPro,Budget);
        bool test=p.ModifierProjet();
            if(test)
               {  msgBox.setText("Modification avec succes.");
                 ui->Tab_aff_3->setModel(p.AfficherProjet());
            }
             else
                 msgBox.setText("Echec de modification");
                 msgBox.exec();
                 QString textajouter;
                 historique h;
                 QSqlQuery qry;
                 qry.prepare("select * from PROJET");
                 textajouter="La modification d'un Projet a la base de donnees de reference = "+QString::number(NumPro)+" a ete effectue avec succees";
                 h.write5(textajouter);
}

void MainWindow::on_Supprimer_f_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int NumPro = ui->ID_spf_3->text().toInt();
    ui->ID_spf_3->setValidator(new QIntValidator(1,99999999, this));
    bool test=p.SupprimerProjet(NumPro);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_3->setModel(p.AfficherProjet());//refresh
        msgBox.setText("Supression avec succes.");
    }
    else
    msgBox.setText("Echec de supression.");
    msgBox.exec();
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from PROJET");
    textajouter="La suppression d'un Projet a la base de donnees de reference = "+QString::number(NumPro)+" a ete effectue avec succees";
    h.write5(textajouter);
}

void MainWindow::on_Trier_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_5->setCurrentIndex(1);
}

void MainWindow::on_Triprix_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_5->setCurrentIndex(1);
    ui->stackedWidget_etat_5->setCurrentIndex(0);
    ui->stackedWidget_nom_5->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_e_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_ascCIN());
}

void MainWindow::on_TriDesc_e_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_descCIN());
}

void MainWindow::on_back_triprix_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_5->setCurrentIndex(0);
}

void MainWindow::on_back_tri_3_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_5->setCurrentIndex(0);
}

void MainWindow::on_trinom_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_5->setCurrentIndex(1);
    ui->stackedWidget_etat_5->setCurrentIndex(0);
    ui->stackedWidget_prix_5->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_ascnom());
}

void MainWindow::on_TriDesc_en_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_descnom());
}

void MainWindow::on_back_trinom_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_5->setCurrentIndex(0);
}

void MainWindow::on_Trietat_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_5->setCurrentIndex(1);
    ui->stackedWidget_nom_5->setCurrentIndex(0);
    ui->stackedWidget_prix_5->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_ee_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_ascNumTel());
}

void MainWindow::on_TriDesc_ee_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_afe_3->setModel(c.Afficher_descNumTel());
}

void MainWindow::on_back_trietat_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_5->setCurrentIndex(0);
}

void MainWindow::on_print_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("CIN")+"</td>") ;
    str.append("<td>"+QString("Prenom")+"</td>") ;
    str.append("<td>"+QString("Nom")+"</td>") ;
    str.append("<td>"+QString("Adresse")+"</td>") ;
    str.append("<td>"+QString("Numtel")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT CIN,PRENOM,NOM,ADRESSE,NUMTEL FROM COLLABORATEUR");

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

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_Backtomenu_10_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Rechercher_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_5->setCurrentIndex(1);
}

void MainWindow::on_Back_rechercher_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_5->setCurrentIndex(0);
}

void MainWindow::on_Rechercher_ID_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_ree_5->text().toInt();
    bool test=c.Rechercher_CIN(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_afe_3->setModel(c.Rechercher_CIN(ID));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Nom_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString Nom=ui->Nom_ree_5->text();
    bool test=c.Rechercher_Nom(Nom);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_afe_3->setModel(c.Rechercher_Nom(Nom));//refresh

    }
    else
    msgBox.setText("Echec de Recherche.");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Etat_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Etat = ui->etat_ree_5->text().toInt();
    ui->etat_ree_5->setValidator(new QIntValidator(10000001,99999999, this));


    bool test=c.Rechercher_NumTel(Etat);
    QMessageBox msgBox;

    if(test)

        {ui->Tab_afe_3->setModel(c.Rechercher_NumTel(Etat));//refresh
        msgBox.setText("Recherche avec succes.");}

    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Trier_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_6->setCurrentIndex(1);
}

void MainWindow::on_Triprix_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_6->setCurrentIndex(1);
    ui->stackedWidget_etat_6->setCurrentIndex(0);
    ui->stackedWidget_nom_6->setCurrentIndex(0);
}
void MainWindow::on_TriAsc_e_6_clicked()
{

    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_ascNumPro());
}
void MainWindow::on_TriDesc_e_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_descNumPro());
}

void MainWindow::on_back_triprix_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_prix_6->setCurrentIndex(0);
}

void MainWindow::on_trinom_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_6->setCurrentIndex(1);
    ui->stackedWidget_etat_6->setCurrentIndex(0);
    ui->stackedWidget_prix_6->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_en_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_ascTitrePro());
}

void MainWindow::on_TriDesc_en_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_descTitrePro());
}

void MainWindow::on_back_trinom_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_nom_6->setCurrentIndex(0);
}

void MainWindow::on_Trietat_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_6->setCurrentIndex(1);
    ui->stackedWidget_nom_6->setCurrentIndex(0);
    ui->stackedWidget_prix_6->setCurrentIndex(0);
}

void MainWindow::on_TriAsc_ee_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_ascBudget());
}

void MainWindow::on_TriDesc_ee_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Tab_aff_3->setModel(p.Afficher_descBudget());
}

void MainWindow::on_back_trietat_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_etat_6->setCurrentIndex(0);
}

void MainWindow::on_back_tri_5_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_trier_6->setCurrentIndex(0);
}

void MainWindow::on_Rechercher_ID_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int ID = ui->ID_ree_6->text().toInt();
    bool test=p.Rechercher_NumPro(ID);
    QMessageBox msgBox;
    if(test)
       {ui->Tab_aff_3->setModel(p.Rechercher_NumPro(ID));//refresh
        msgBox.setText("Recherche avec succes.");
    }
    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Nom_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString Nom=ui->Nom_ree_6->text();
    bool test=p.Rechercher_TitrePro(Nom);
    QMessageBox msgBox;
    if(test)
       {msgBox.setText("Recherche avec succes.");
        ui->Tab_aff_3->setModel(p.Rechercher_TitrePro(Nom));//refresh

    }
    else
    msgBox.setText("Echec de Recherche.");
    msgBox.exec();
}

void MainWindow::on_Rechercher_Etat_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int Etat = ui->etat_ree_6->text().toInt();


    bool test=p.Rechercher_Budget(Etat);
    QMessageBox msgBox;

    if(test)

        {ui->Tab_aff_3->setModel(p.Rechercher_Budget(Etat));//refresh
        msgBox.setText("Recherche avec succes.");}

    else
    msgBox.setText("Erreur de recherche .");
    msgBox.exec();
}

void MainWindow::on_Rechercher_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_6->setCurrentIndex(1);
}

void MainWindow::on_Back_rechercher_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_rechercher_6->setCurrentIndex(0);
}

void MainWindow::on_print_6_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString str;
    str.append("<html><head></head><body><center>"+QString());
    str.append("<table border=1><tr>") ;
    str.append("<td>"+QString("NumPro")+"</td>") ;
    str.append("<td>"+QString("TitrePro")+"</td>") ;
    str.append("<td>"+QString("ChefPro")+"</td>") ;
    str.append("<td>"+QString("Budget")+"</td>") ;
    QSqlQuery* query=new QSqlQuery();
    query->exec("SELECT NUMPRO,TITREPRO,CHEFPRO,BUDGET FROM PROJET");
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

    }
    str.append("</table></center></body></html>") ;

    QPrinter printer ;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4) ;

    QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","C:/Users/skand/OneDrive/Bureau/GestionRH/PDF","PDF(*.pdf)");

    if (path.isEmpty()) return ;
    printer.setOutputFileName(path) ;
    QTextDocument doc;
    doc.setHtml(str) ;
    doc.print(&printer);
    QMessageBox::information(nullptr,QObject::tr("Creation PDF"),QObject::tr("PDF crée .\n"
                                                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_Backtomenu_11_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->Main_stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_31_clicked()
{
    statistiquess s;
    s.exec();

}

void MainWindow::on_pushButton_18_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_historique_5->setCurrentIndex(1);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->Tab_afe_3->hide();
    historique h;
    ui->textBrowser_5->show();
    ui->textBrowser_5->setPlainText(h.read4());
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->Tab_afe_3->show();
    ui->textBrowser_5->hide();
    ui->stackedWidget_historique_5->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
    QMediaPlayer *click;
    click= new QMediaPlayer();
    click->setMedia(QUrl::fromLocalFile("C:/Users/hpprobook/Desktop/wa/Final/Mouse_Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget_historique_6->setCurrentIndex(1);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->Tab_aff_3->hide();
    historique h;
    ui->textBrowser_6->show();
    ui->textBrowser_6->setPlainText(h.read5());
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->Tab_aff_3->show();
    ui->textBrowser_6->hide();
    ui->stackedWidget_historique_6->setCurrentIndex(0);
}

void MainWindow::on_Projets_button_clicked()
{
    ui->Main_stackedWidget->setCurrentIndex(5);
}
