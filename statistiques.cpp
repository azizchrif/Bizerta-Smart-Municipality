#include "statistiques.h"
#include "ui_statistiques.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include<iostream>


statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
}
statistiques::~statistiques()
{
    delete ui;
}
int statistiques::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EQUIPEMENT where ETAT =0") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

int statistiques::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EQUIPEMENT where ETAT =1") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}


void statistiques::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-600,this->width()-600);

    painter.setBrush(Qt::red);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText(" en panne") ;
    ui->label_4->setNum(q2) ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("OK") ;
    ui->label_6->setNum(q3) ;
    painter.setBrush(Qt::red);


}

