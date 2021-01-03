#include "fonctions-sql.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

gestions::gestions(){

}
int gestions::nbticket(){
    QSqlQuery query;
    int nb;
    query.exec("SELECT COUNT(NUMT) FROM T_TICKET");
     while(query.next()){
    nb = query.value(0).toInt();
    }
    return nb;}


int gestions::tottik(){
    QSqlQuery query;
    int nb;
    query.exec("SELECT SUM(PRIXT) FROM T_TICKET");
    query.next();
    nb = query.value(0).toInt();
    return nb;
}

bool gestions::ajoutev(QString id, QString nom, QString type,QString date){
            QSqlQuery query;
            query.exec("INSERT INTO T_EV (IDT, NOMT, TYPET, DATET) VALUES('"+id+"','"+nom+"','"+type+"','"+date+"')");
            return true;
}

bool gestions::modifev(QString id, QString nom, QString type,QString date){
            QSqlQuery query;
            query.exec("UPDATE T_EV SET NOMT='"+nom+"',TYPET='"+type+"',DATET='"+date+"' WHERE IDT="+id);
            return true;
}

bool gestions::suppev(QString id){
            QSqlQuery query;
            query.exec("DELETE FROM T_EV WHERE IDT="+id);
            return true;
}





bool gestions::ajoutt(QString num, QString titre, QString prix,QString desc){
            QSqlQuery query;
            query.exec("INSERT INTO T_TICKET (NUMT, TITRET, PRIXT, DESCT) VALUES("+num+",'"+titre+"',"+prix+",'"+desc+"')");
            return true;
}


bool gestions::modift(QString num, QString titre, QString prix,QString desc){
            QSqlQuery query;
            query.exec("UPDATE T_TICKET SET TITRET='"+titre+"',PRIXT="+prix+",DESCT='"+desc+"' WHERE NUMT="+num);
            return true;
}

bool gestions::suppt(QString id){
            QSqlQuery query;
            query.exec("DELETE FROM T_TICKET WHERE NUMT="+id);
            return true;
}

