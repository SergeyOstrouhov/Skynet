#ifndef FUNCTION_H
#define FUNCTION_H
#include <QByteArray>
#include <QObject>
#endif // FUNCTION_H
#include <QCoreApplication>
QByteArray auth(QString login, QString password){
    QByteArray res = "1 auth";
    return res;
}
QByteArray reg(QString login, QString password, QString mail){
    QByteArray res = "1 reg";
    return res;
}
QByteArray Parsing(QString a){
    /*if (a.startsWith("Hello")){
        return "Hi, Sergey!";
    }
    else{return "qwer/n";}*/
    //for (auto i:a){return QByteArray(i);}

    QStringList data_from_client_list=a.split(QLatin1Char(' '), Qt::SkipEmptyParts);
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc=="auth")
        {
        if (data_from_client_list.length() == 2) return auth(data_from_client_list.at(0), data_from_client_list.at(1));
        else return "Wrong input data - Need 2 parametrs for auth.\n";
        }
    if (nameOfFunc=="reg")
    {
        if (data_from_client_list.length() == 3) return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
        else return "Wrong input data - Need 3 parametrs for reg.\n";
    }
    else return "wrong syn\n";
}


