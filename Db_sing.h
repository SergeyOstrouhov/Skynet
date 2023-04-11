#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <vector>
#include <string>

using std::vector;
using std::string;

class MyDataBase;

class SingletonDestroyer
{
    private:
        MyDataBase * p_instance;
    public:
        ~SingletonDestroyer() { delete p_instance;}
        void initialize(MyDataBase * p){p_instance = p;}
};


class MyDataBase
{
    private:
        static MyDataBase * p_instance;
        static SingletonDestroyer destroyer;
        QSqlDatabase db;
    protected:
        MyDataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("C:\\Qt\\Server_221_331\\Users.db");
            db.open();
            if(!db.isOpen())
                qDebug()<<db.lastError().text();
        }
        MyDataBase(const MyDataBase& )=delete;
        MyDataBase& operator = (MyDataBase &)= delete;
        ~MyDataBase() {db.close();}
        friend class SingletonDestroyer;
    public:
        static MyDataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new MyDataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        QString query (QString q){
            QSqlQuery query_obj(db);
            query_obj.exec(q);
            QString res="";
            if (db.isOpen()) qDebug() << "111";
            while (query_obj.next()){
                vector<QString> qwert;
                QString login = query_obj.value("login").toString();
                QString password = query_obj.value("password").toString();
                qwert.push_back(login);
                qwert.push_back(password);
                qDebug()<<login <<" " << password<<"\n";
                res.append(login).append('|').append(password).append("||");
            }
            return res;
        }
        void add (std::string q){
            QSqlQuery query_obj(db);
            query_obj.exec(QString::fromStdString(q));
        }


};

MyDataBase * MyDataBase::p_instance;
SingletonDestroyer MyDataBase::destroyer;
//MyDataBase * SingletonDestroyer::p_instance;
