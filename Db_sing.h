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
            db.setDatabaseName("..\\Server_221_331\\Users.db");
            //db.setDatabaseName("Users.db");
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
//            if (db.isOpen()) qDebug() << "111";
            while (query_obj.next()){
                vector<QString> qwert;
                QString login = query_obj.value("login").toString();
                QString password = query_obj.value("password").toString();
                qwert.push_back(login);
                qwert.push_back(password);
                //qDebug()<<login <<" " << password<<"\n";
                res.append(login).append('|').append(password).append("||");
            }
            return res;
        }
        void add (QString login, QString password, QString email){
            QSqlQuery query(db);
            query.prepare("INSERT INTO User (login,password,email) VALUES(:login, :password, :email)");
            query.bindValue(":login", login);
            query.bindValue(":password", password);
            query.bindValue(":email", email);
            query.exec();
        }

        void login(QString login, QString socket)
        {
            QSqlQuery query(db);
            query.prepare("UPDATE User SET socket=:socket WHERE login=:login");
            query.bindValue(":socket", socket);
            query.bindValue(":login", login);
            query.exec();
        }

        void logout(QString login)
        {
            QSqlQuery query(db);
            query.prepare("UPDATE User SET socket=NULL WHERE login=:login");
            query.bindValue(":login", login);
            query.exec();
        }
        QByteArray stat(QString socket)
        {
            QSqlQuery query_obj(db);
            query_obj.prepare("Select stat from User where socket="+socket);
            query_obj.exec();
            QByteArray stata = query_obj.value("stat").toByteArray();
            return stata;
        }

};

MyDataBase * MyDataBase::p_instance;
SingletonDestroyer MyDataBase::destroyer;
//MyDataBase * SingletonDestroyer::p_instance;
