#include "mytcpserver.h"
#include "function.h"
#include <QDebug>
#include <QCoreApplication>
using namespace std;

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 44444)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket *cur_mTcpSocket;
        cur_mTcpSocket = mTcpServer->nextPendingConnection();
        cur_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(cur_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(cur_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.insert(cur_mTcpSocket->socketDescriptor(),cur_mTcpSocket);
        //cur_mTcpSocket->flush();
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *cur_mTcpSocket = (QTcpSocket*)sender();
    QString array;
    QString res;

   while(cur_mTcpSocket->bytesAvailable()>0)
   {
        //array = cur_mTcpSocket->readAll();
        //res.append(array);
        res += cur_mTcpSocket->readAll();

    }

    //array = "";
    //array = QByteArray::fromStdString(res);
   if (res.trimmed().isEmpty()){
       return;
   }
   if (res.trimmed()[0] > 'z'){
       return;
   }

    cur_mTcpSocket->write(Parsing(res.toUtf8()));
    qDebug() << res.size() << "\n";

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *cur_mTcpSocket = (QTcpSocket*)sender();
    cur_mTcpSocket->close();
}
