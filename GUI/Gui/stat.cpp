#include "stat.h"
#include "ui_stat.h"
#include "client_sing.h"

Stat::Stat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat)
{
    connect(SingletonClient::getInstance(),&SingletonClient::stat, this, &Stat::update_stat);
    ui->setupUi(this);
}

Stat::~Stat()
{
    delete ui;
}

void Stat::update_stat(QString stat)
{
     ui->label_stat->setText(stat);
}

void Stat::on_Back_clicked()
{
    close();
    emit on_closed();
}

