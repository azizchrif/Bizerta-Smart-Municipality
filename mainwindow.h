#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipements.h"
#include <QtSql>
#include <QWidgetAction>
#include <QSqlDatabase>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Tab_chambres_currentChanged(int index);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Equipements e;
     int rowSelected;
     QSqlDatabase db;
};
#endif // MAINWINDOW_H