#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    
    void on_pushButton_6_clicked();
    

    void on_pushButton_clicked();


    void on_pushButton_ajouter1_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_14_released();

    void on_pushButton_modifierprojet_clicked();

private:
    Ui::MainWindow *ui;
    collaborateur tmpcollaborateur;
    QMediaPlayer * click;

};
#endif // MAINWINDOW_H
