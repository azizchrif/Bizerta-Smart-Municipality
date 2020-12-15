#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "gestionterrain.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_btn_conecter_clicked()
{
    QString username = ui->username->text();
        QString password = ui->password->text();

        if(username ==  "wajdi" && password == "wajdi") {
            QMessageBox::information(this, "Login", "Username and password is correct");

            gestionterrain *w=new  gestionterrain();
            w->show();
            this->hide();

        }
        else {
            QMessageBox::warning(this,"Login", "Username and password is not correct");
        }
}
