#include "auth_form.h"
#include "ui_auth_form.h"

Auth_form::Auth_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auth_form)
{
    ui->setupUi(this);
    this->mode = true;
    this->change_mode(mode);
}

Auth_form::~Auth_form()
{
    delete ui;
}



void Auth_form::change_mode(bool mode){
    ui->pushButton_reg->setVisible(!mode);
    ui->label_r_pass->setVisible(!mode);
    ui->lineEdit_r_pass->setVisible(!mode);
    ui->pushButton_log->setVisible(mode);
    qDebug()<<mode;

    if(mode)
        ui->pushButton_change->setText("to reg");
    else{
        ui->pushButton_change->setText("to log in");
    }
}


void Auth_form::on_pushButton_change_clicked()
{
    this->change_mode(ui->pushButton_reg->isVisible());
    //ui->lineEdit_login->setVisible(this->mode);
    this->mode = !this->mode;
}


void Auth_form::on_pushButton_reg_clicked()
{
    qDebug()<<"reg "+ui->lineEdit_login->text()+
              ui->lineEdit_pass->text()+" "+
              ui->lineEdit_r_pass->text();
    emit auth_ok(ui->lineEdit_login->text());
    this->close();


}





void Auth_form::on_pushButton_log_clicked()
{
    qDebug()<<"log "+ui->lineEdit_login->text()+
              ui->lineEdit_pass->text();


    emit auth_ok(ui->lineEdit_login->text());
    this->close();
}

