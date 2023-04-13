#include "client_sing.h"

SingletonClientDestroyer::~SingletonClientDestroyer() { delete p_instance;}
void SingletonClientDestroyer::initialize(SingletonClient * p){p_instance = p;}

void SingletonClient::slot_read_from_server(){
    QByteArray arr;
    while(socket->bytesAvailable()>0){
        arr.append(socket->readAll());
    }
    qDebug() << arr << "\n";
    if (arr == "auth OK") this->auth_status = true;
    //else this->auth_status = ;
}

SingletonClient::SingletonClient(QObject *parent) :QObject (parent){
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 44444);
    connect(socket, &QTcpSocket::readyRead,
    this, &SingletonClient::slot_read_from_server);

    if(socket->state()==3 || socket->state()==2){
        qDebug() << "client connected";
    } else {
        qDebug() << "client not connected";
    }
}

SingletonClient::~SingletonClient() {socket->close();}

bool SingletonClient::send_to_server(QString req){
    socket->write(req.toUtf8());
    return false;
}

SingletonClient* SingletonClient::getInstance(){
    if (!p_instance)
    {
        p_instance = new SingletonClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

SingletonClient * SingletonClient::p_instance;
SingletonClientDestroyer SingletonClient::destroyer;

