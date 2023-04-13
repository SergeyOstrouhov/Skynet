#include <QCoreApplication>
#include "client_sing.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      SingletonClient::getInstance();
  //SingletonClient::getInstance()->send_to_server("auth sergey 44444");
    return a.exec();
}
