#include <map>
#include <ctime>
#include <qDebug>
#include <string>
#include <fstream>

using std::map;
using std::pair;
using std::string;


class MeticRegister;

class MeticRegisterDestroyer
{
    private:
        static MeticRegister * p_instance;
    public:
        ~MeticRegisterDestroyer() { delete p_instance;}
        void initialize(MeticRegister * p){p_instance = p;};
};


class MeticRegister
{
    private:
        static MeticRegister * p_instance;
        static MeticRegisterDestroyer destroyer;
        map<int, pair<int, int>> reg;
    protected:
        MeticRegister(){}
        MeticRegister(const MeticRegister& );
        MeticRegister& operator = (MeticRegister &);
        ~MeticRegister() {}
        friend class MeticRegisterDestroyer;
    public:
        static MeticRegister* getInstance(){
            if (!p_instance)
            {
                p_instance = new MeticRegister();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        bool add_metr(int resp_t, int wait_t)
        {
            int now = std::time(NULL);
            reg.insert(pair<int, pair<int,int>>(now, pair<int, int>(resp_t, wait_t)));
        }
        //вывести на экран все значения, упорядоченные по ключу
        bool show_metr()
        {
            for (const auto &entry: reg) {
                qDebug() << "{" << entry.first << ", " << entry.second << "}";
            }
        }
        //вычислить вспомогательную метрику: возвращает сумму времени ожидания и времени отклика для данного ключа.
        int coutn_cometr(int key)
        {
            pair p = reg.find(key)->second;
            return p.first + p.second;
        }
        //загрузить метрики из файла
        void init(string filename)
        {
            std::ifstream file(filename);
            if (!file.is_open())
            {
                qDebug() << "Ошибка при открытии файла\n";
            }
            int time,resp_t,wait_t;

            while (!file.eof())
            {
                file >> time >> resp_t >> wait_t;
//                qDebug() << a << " " << b << " " << c;
                reg.insert(pair<int, pair<int,int>>(time, pair<int, int>(resp_t, wait_t)));
            }
        }
};

MeticRegister * MeticRegister::p_instance;
MeticRegisterDestroyer MeticRegister::destroyer;
MeticRegister * MeticRegisterDestroyer::p_instance;
