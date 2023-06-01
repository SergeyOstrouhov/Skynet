#include <QtTest>

QString caesar(QString inp, int kluch) {

    QString result;
    for (int i = 0; i < inp.length(); i++) {
        QChar symb = inp[i];
        if ((symb.unicode() >= 32) && (symb.unicode() <= 127)) {
            int asc = symb.unicode() + kluch;
            if (asc > 127) {
                asc = asc % 127 + 32;
            }
            symb = QChar(asc);
        }
        else
        {
            qDebug() << "Неверный ввод!" << symb;
        }
        result += symb;
    }
    return result;
}

class ces_enc : public QObject
{
    Q_OBJECT

public:
    ces_enc();
    ~ces_enc();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();
    void test_case9();
    void test_case10();

};

ces_enc::ces_enc()
{

}

ces_enc::~ces_enc()
{

}

void ces_enc::test_case1()
{
    QCOMPARE("+{}{+}", caesar("sdfdsf", 23));
}
void ces_enc::test_case2()
{
    QCOMPARE("9l<<=", caesar("4g778", 5));
}

void ces_enc::test_case3()
{
    QCOMPARE("|H{B%0", caesar("_+^%gr", 29));
}

void ces_enc::test_case4()
{
    QCOMPARE("78k8:", caesar("45h57", 3));
}

void ces_enc::test_case5()
{
    QCOMPARE("?yAB?\"}:", caesar("0j230rn+", 15));
}

void ces_enc::test_case6()
{
    QCOMPARE("4-0ti-", caesar("4-0ti-", 0));
}

void ces_enc::test_case7()
{
    QCOMPARE("STRG|\u0080", caesar("|}{p&*", 435));
}

void ces_enc::test_case8()
{
    QCOMPARE(";8.w4,8w", caesar("WTJ4PHT4", 67));
}
void ces_enc::test_case9()
{
    QCOMPARE("omzo<=pr", caesar("gerg45hj", 8));
}
void ces_enc::test_case10()
{
    QCOMPARE("w}z*#+A0z", caesar("bhetmu,ze", 21));
}



QTEST_APPLESS_MAIN(ces_enc)

#include "tst_ces_enc.moc"
