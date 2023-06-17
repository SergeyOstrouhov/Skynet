#include <QtTest>

#include "../function.h"
#include <QWidget>

class task_test : public QObject
{
    Q_OBJECT
public:
    task_test();
    ~task_test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();

};

task_test::task_test()
{

}

task_test::~task_test()
{

}

void task_test::test_case1()
{
    QCOMPARE(Parsing("admin 132 yes",330),"Wrong input data - Need 2 parametrs for auth.\n");
}

void task_test::test_case2()
{
    QCOMPARE(Parsing("reg me",330), "Wrong input data - Need 3 parametrs for reg.\n");
}

void task_test::test_case3()
{
    QCOMPARE(Parsing("check my results !",330),"Wrong input data - Dont't need parametrs for checking statisctic.\n");
}

QTEST_APPLESS_MAIN(task_test)

#include "main.moc"
