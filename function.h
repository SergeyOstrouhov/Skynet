#ifndef FUNCTION_H
#define FUNCTION_H
#include <QByteArray>
#include <QObject>
#endif // FUNCTION_H
#include <QCoreApplication>
#define print(a) qDebug() << a
QByteArray auth(QString login, QString password){
    QByteArray res = "1 auth";
    print("a");
    return res;
}
QByteArray reg(QString login, QString password, QString mail){
    QByteArray res = "1 reg";
    return res;
}
QByteArray check_stat(){
    QByteArray res = "1 check";
    return res;
}
QByteArray check_stat_all(){
    QByteArray res = "1 check";
    return res;
}
QByteArray out(){
    QByteArray res = "1 log out";
    return res;
}
QByteArray send_answ(QString task, QString var, QString answer){
    QByteArray res = "1 send answer";
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
    if (nameOfFunc=="check")
    {
        if (data_from_client_list.length() == 0) return check_stat();
        else return "Wrong input data - Dont't need parametrs for checking statisctic.\n";
    }
    if (nameOfFunc=="out")
    {
        if (data_from_client_list.length() == 0) return out();
        else return "Wrong input data - Dont't need parametrs for log out.\n";
    }
    if (nameOfFunc=="send_answ")
    {
        if (data_from_client_list.length() == 1) return send_answ(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
        else return "Wrong input data - Need 1 parametrs for send answer.\n";
    }
    else return "wrong syn\n";
}


