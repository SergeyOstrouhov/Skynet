#include <QCoreApplication>
#include <QDebug>
#include "MeticRegister.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MeticRegister::getInstance()->init("../load.txt");
    MeticRegister::getInstance()->show_metr();
    qDebug() << "Adding values...";
    MeticRegister::getInstance()->add_metr(123,456);
    MeticRegister::getInstance()->show_metr();
    qDebug() << MeticRegister::getInstance()->coutn_cometr(1) << '\n';

    return a.exec();
}
