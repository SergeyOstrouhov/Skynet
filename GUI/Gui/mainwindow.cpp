#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new Auth_form;
    connect(ui_auth, &Auth_form::auth_ok,
            this, &MainWindow::slot_on_auth_ok);
    ui_auth->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_clicked()
{

    this->close();
}


void MainWindow::on_Task1_clicked()
{
    qDebug()<<"task 1";
}
void MainWindow::slot_on_auth_ok(QString log){
//    ui->label_log->setText(log);
    this->show();
}

void MainWindow::on_actionTask_1_triggered()
{
    this->on_Task1_clicked();
}


void MainWindow::on_actionTask_2_triggered()
{
    this->on_Tak2_clicked();
}


void MainWindow::on_actionTask_3_triggered()
{
    this->on_push_Task3_clicked();
}


void MainWindow::on_actionExit_triggered()
{
    this->on_exit_clicked();
}


void MainWindow::on_Tak2_clicked()
{
    qDebug()<<"task 2";
}


void MainWindow::on_push_Task3_clicked()
{
    qDebug()<<"task 3";
}

