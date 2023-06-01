#include "mytcpserver.h"
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
QString caesar(QString inp, int kluch) {

    QString result;
    for (int i = 0; i < inp.length(); i++) {
        QChar symb = inp[i];
        if ((symb.unicode() >= 32) && (symb.unicode() <= 127)) {
            int asc = symb.unicode() + kluch;
            if (asc > 127) {
                asc = asc % 127 + 32;
            }
            symb = QChar(asc);
        }
        else
        {
            qDebug() << "Неверный ввод!" << symb;
        }
        result += symb;
    }
    return result;
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket *cur_mTcpSocket;
        cur_mTcpSocket = mTcpServer->nextPendingConnection();
        cur_mTcpSocket->write("Hello, World!!! I am echo server!");
        connect(cur_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(cur_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);

        mTcpSocket.append(cur_mTcpSocket);
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
   //std::stringstream flow;
    std::string address = "";
    address = QString::number(cur_mTcpSocket->socketDescriptor()).toStdString();
    qDebug() << cur_mTcpSocket << "\n";
    int kl = res.mid(0, res.indexOf(' ')).toInt();
    QString stroka = res.remove(0, res.indexOf(" ")+1);
    QByteArray cez =  caesar(stroka, kl).toUtf8() ;



    for (int i = 0; i < mTcpSocket.size();  i++){
        mTcpSocket[i]->write(cez);
    }

    //qDebug() << (res.toUtf8()) << "\n";

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *cur_mTcpSocket = (QTcpSocket*)sender();
    cur_mTcpSocket->close();
}
