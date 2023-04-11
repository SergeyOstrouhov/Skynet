#include <QCoreApplication>
#include "mytcpserver.h"
//#include "Db_sing.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
//    qDebug()<< MyDataBase::getInstance()->query("SELECT * FROM User");
//    qDebug()<< MyDataBase::getInstance()->query("SELECT name FROM sqlite_master WHERE type='table';");
    return a.exec();
}
