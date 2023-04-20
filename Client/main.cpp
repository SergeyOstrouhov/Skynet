#include <QCoreApplication>
#include "client_sing.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      SingletonClient::getInstance();
  SingletonClient::getInstance()->send_to_server("auth admin 12345");
    return a.exec();
}
