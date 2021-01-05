#ifndef STATISTIQUESS_H
#define STATISTIQUESS_H
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
using namespace std;

namespace Ui {
class statistiquess;
}

class statistiquess : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquess(QWidget *parent = nullptr);
    int Statistique_partie2() ;
        int Statistique_partie3() ;
         int Statistique_partie4() ;
        void paintEvent(QPaintEvent *) ;

    ~statistiquess();

private:
    Ui::statistiquess *ui;
private slots :
};

#endif // STATISTIQUESS_H
