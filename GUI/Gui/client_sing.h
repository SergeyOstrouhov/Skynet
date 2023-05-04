#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#pragma once
#include <QObject>
#include <QTcpSocket>

class SingletonClient;

class SingletonClientDestroyer
{
    private:
        SingletonClient * p_instance;
    public:
        ~SingletonClientDestroyer();
        void initialize(SingletonClient * p);
};


class SingletonClient: public QObject
{
    Q_OBJECT
    private:
        static SingletonClient * p_instance;
        static SingletonClientDestroyer destroyer;
        QTcpSocket * socket ;


    private slots:
        void slot_read_from_server();


    protected:
        explicit SingletonClient(QObject*parent=nullptr);
        SingletonClient(const SingletonClient& )=delete;
        SingletonClient& operator = (SingletonClient &)=delete;
        ~SingletonClient();
        friend class SingletonClientDestroyer;
    public:
        QString login;
        bool send_to_server(QString req);
        static SingletonClient* getInstance();
signals:
        void auth_ok(QString);
        void stat(QString);
        void stat_all(QString);
};

//SingletonClient * SingletonClient::p_instance;
//SingletonClientDestroyer SingletonClient::destroyer;
//SingletonClient * SingletonClientDestroyer::p_instance;

#endif // SINGLETONCLIENT_H
