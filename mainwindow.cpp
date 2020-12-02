#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fonctions-sql.h"
#include "sqlc.h"
#include <QSqlQueryModel>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->idevrech->setValidator(new QIntValidator(1, 999, this));
    ui->idt->setValidator(new QIntValidator(1, 999, this));
    ui->nomt->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->typet->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->idtm->setValidator(new QIntValidator(1, 999, this));
    ui->nomdm->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->typem->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->sid->setValidator(new QIntValidator(1, 999, this));
    ui->numt->setValidator(new QIntValidator(1, 999, this));
    ui->titret->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->prixt->setValidator(new QIntValidator(1, 999, this));
    ui->desct->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->idevrech_2->setValidator(new QIntValidator(1, 999, this));
    ui->idms->setValidator(new QIntValidator(1, 999, this));
    ui->titms->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->prixms->setValidator(new QIntValidator(1, 999, this));
    ui->ds->setValidator(new QRegExpValidator(QRegExp("[a-z]{1}[a-z]{0,255}"),NULL));
    ui->sidv->setValidator(new QIntValidator(1, 999, this));

    ui->comboBox->addItem("asc");
    ui->comboBox->addItem("desc");
    ui->comboBox->addItem("A-Z");
    ui->comboBox->addItem("Z-A");

    ui->comboBox_2->addItem("asc");
    ui->comboBox_2->addItem("desc");
    ui->comboBox_2->addItem("A-Z");
    ui->comboBox_2->addItem("Z-A");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    QString id,nom,type,date;
    id=ui->idt->text();
    nom=ui->nomt->text();
    type=ui->typet->text();
    date=ui->datet->text();

    ges.ajoutev(id,nom,type,date);

}

void MainWindow::on_pushButton_4_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    QString num,titre,prix,desc;
    num=ui->numt->text();
    titre=ui->titret->text();
    prix=ui->prixt->text();
    desc=ui->desct->text();

    ges.ajoutt(num,titre,prix,desc);
}

void MainWindow::on_pushButton_5_clicked() //ti
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    QString id,titre,prix,desc;
    id=ui->idms->text();
    titre=ui->titms->text();
    prix=ui->prixms->text();
    desc=ui->ds->text();

    ges.modift(id,titre,prix,desc);


}

void MainWindow::on_pushButton_2_clicked() //ev
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    QString id,nom,type,date;
    id=ui->idtm->text();
    nom=ui->nomdm->text();
    type=ui->typem->text();
    date=ui->datem->text();
    ges.modifev(id,nom,type,date);


}

void MainWindow::on_pushButton_6_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    QString id;
    id=ui->sidv->text();

    ges.suppt(id);


}

void MainWindow::on_pushButton_3_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();
    gestions ges;
    QString id;
    id=ui->sid->text();

    ges.suppev(id);
}

void MainWindow::on_pushButton_7_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    gestions ges;
    int nb1,nb2;
    nb2=ges.tottik();
    nb1=ges.nbticket();
    ui->nbticket->setText(QString::number(nb1));
    ui->nben->setText(QString::number(nb2));
}

void MainWindow::on_pushButton_8_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery query;

        QString mode;
        mode=ui->comboBox->currentText();
        if(mode=="asc" || mode=="desc")
        {
        query.exec("SELECT * FROM T_EV ORDER BY IDT "+mode);
        modal->setQuery(query);
        ui->tabev->setModel(modal);
        }
        else if(mode=="A-Z")
        {
            query.exec("SELECT * FROM T_EV ORDER BY NOMT asc");
            modal->setQuery(query);
            ui->tabev->setModel(modal);
        }
        else if(mode=="Z-A")
        {
            query.exec("SELECT * FROM T_EV ORDER BY NOMT desc");
            modal->setQuery(query);
            ui->tabev->setModel(modal);
        }


}

void MainWindow::on_pushButton_9_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery query;

        query.exec("SELECT * FROM T_EV");
        modal->setQuery(query);
        ui->tabev->setModel(modal);

}

void MainWindow::on_pushButton_10_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    QString idev;
    idev=ui->idevrech->text();
    query.exec("SELECT * FROM T_EV WHERE IDT="+idev);
    modal->setQuery(query);
    ui->tabev->setModel(modal);

}

void MainWindow::on_pushButton_11_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery query;

        QString mode;
        mode=ui->comboBox_2->currentText();
        if(mode=="asc" || mode=="desc")
        {
        query.exec("SELECT * FROM T_TICKET ORDER BY NUMT "+mode);
        modal->setQuery(query);
        ui->tabt->setModel(modal);
        }
        else if(mode=="A-Z")
        {
            query.exec("SELECT * FROM T_TICKET ORDER BY TITRET asc");
            modal->setQuery(query);
            ui->tabt->setModel(modal);
        }
        else if(mode=="Z-A")
        {
            query.exec("SELECT * FROM T_TICKET ORDER BY TITRET desc");
            modal->setQuery(query);
            ui->tabt->setModel(modal);
        }

}

void MainWindow::on_pushButton_12_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    QString idev;
    idev=ui->idevrech_2->text();
    query.exec("SELECT * FROM T_TICKET WHERE NUMT="+idev);
    modal->setQuery(query);
    ui->tabt->setModel(modal);

}

void MainWindow::on_pushButton_13_clicked()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/src/button_effect1.mp3.mp3"));
    sound->play();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.exec("SELECT * FROM T_TICKET ");
    modal->setQuery(query);
    ui->tabt->setModel(modal);
}
