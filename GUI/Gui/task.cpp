#include "task.h"
#include "ui_task.h"
#include "client_sing.h"
#include <QRandomGenerator>
Task::Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    this->a = QRandomGenerator::global()->bounded(-10000, 10000);
    this->b = QRandomGenerator::global()->bounded(-10000, 10000);
    QString s1 = QString::number(a);
    QString s2 = QString::number(b);

    ui->label_2->setText(s1 + " + "+s2+" = ?");
}

Task::~Task()
{
    delete ui;
}

void Task::on_Ok_clicked()
{
    QString t = ui->label_2->text();
    QString res = QString::number(a+b);
    if (ui->lineEdit->text() != res){
        ui->label_2->setText(t + " Неверно");
        SingletonClient::getInstance()->send_to_server("send_answ 1 n");
    }
    else{
        ui->label_2->setText(t + " Верно");
        SingletonClient::getInstance()->send_to_server("send_answ 1 y");
    }
    //close();
    //emit on_closed();
}

