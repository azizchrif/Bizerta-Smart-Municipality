#include "login.h"
#include "ui_login.h"
#include<QSqlQuery>
#include<mainwindow.h>

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

