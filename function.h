#ifndef FUNCTION_H
#define FUNCTION_H
#include <QByteArray>
#include <QObject>
#endif // FUNCTION_H
#include <QCoreApplication>
QByteArray Parsing(QByteArray a){
    if (a == QByteArray("Hello\n")){
        return "Hi, Sergey!";
    }
    else{return "qwer";}
}
