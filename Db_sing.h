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
/**
 * @brief The SingletonDestroyer class
 */
class SingletonDestroyer
{
    private:
    //! Объект базы данных
        MyDataBase * p_instance;
    public:
        //! Деструктор
        ~SingletonDestroyer() { delete p_instance;}
        void initialize(MyDataBase * p){p_instance = p;}
};

/**
 * @brief The MyDataBase class
 */

class MyDataBase
{
    private:
        //!  указатель на объект класса
        static MyDataBase * p_instance;
        //! дестройер объекта
        static SingletonDestroyer destroyer;
        //! База данных, с которой взаимодействует класс
        QSqlDatabase db;
    protected:
        /**
         * @brief MyDataBase
         * Конструктор класса
         */
        MyDataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("C:\\Qt\\Server_221_331\\Skynet\\Users.db");
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
        /**
         * @brief getInstance
         * @return возвращает p_instance
         */
        static MyDataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new MyDataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        /**
         * @brief query
         * @param q - QString строка с запросом
         * @return res - возврат строки с логином и паролем
         */
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
        /**
         * @brief add
         * @param login - QString с логином пользователя
         * @param password - QString с паролем пользователя
         * @param email - QString с почтой пользователя
         * функция нужна для добваления записи в таблицу идентификации
         */
        void add (QString login, QString password, QString email){
            QSqlQuery query(db);
            query.prepare("INSERT INTO User (login,password,email) VALUES(:login, :password, :email)");
            query.bindValue(":login", login);
            query.bindValue(":password", password);
            query.bindValue(":email", email);
            query.exec();
        }
        /**
         * @brief login - функция входа в систему
         * @param login - QString с логином пользователя
         * @param socket - сокет, с которого пришёл запрос на вход
         */
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
            QSqlQuery query(db);
            query.prepare("SELECT task1, task2 FROM User WHERE socket=:socket;");
            query.bindValue(":socket", socket);
            query.exec();
            QString task1;
            QString task2;
            while (query.next()){
                task1 = query.value("task1").toString();
                task2 = query.value("task2").toString();
                qDebug() << "@" << task1 << " & " << task2 << "$\n";
            }
//            QByteArray stata = query.value("stat").toByteArray();
//            qDebug() << query.executedQuery() << "###";
            QByteArray stat = QByteArray::fromStdString((task1+" "+task2).toStdString());
            qDebug()<<stat;
            return "check "+stat;
        }
        QByteArray stat_all()
        {
            QSqlQuery query(db);
            query.prepare("SELECT * FROM User;");
            query.exec();
            QString res="";
            QString task2;
            int ind_1 = query.record().indexOf("task1");
            int ind_2 = query.record().indexOf("task2");
            while (query.next()){
                res+= query.value(ind_1).toString()+" "+query.value(ind_2).toString()+" ";
            }
            //res = "eewwe";
//            QByteArray stata = query.value("stat").toByteArray();
//            qDebug() << query.executedQuery() << "###";
            //QByteArray stat = QByteArray::fromStdString((task1+" "+task2).toStdString());
            //return stat;
            return "stat_all "+res.toUtf8();
        }
        void correct1(QString task, QString cor, QString socket)
        {
            QSqlQuery query(db);
            QString s;
            if (cor == "y"){
             s = "UPDATE User SET task" + task + " = task"+ task +  " + 1 WHERE socket =:socket";}
            else{ s = "UPDATE User SET task" + task + " = task"+ task +  " - 1 WHERE socket =:socket";}
            query.prepare(s);
            query.bindValue(":socket", socket);
            query.exec();
        }

};





//MyDataBase * SingletonDestroyer::p_instance;
