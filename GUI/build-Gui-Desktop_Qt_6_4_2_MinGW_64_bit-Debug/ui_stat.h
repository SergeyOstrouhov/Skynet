/********************************************************************************
** Form generated from reading UI file 'stat.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_H
#define UI_STAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stat
{
public:
    QPushButton *Back;
    QPushButton *stat_all;
    QLabel *label;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *myform;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_2;
    QLabel *T_1;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLabel *T_2;

    void setupUi(QWidget *Stat)
    {
        if (Stat->objectName().isEmpty())
            Stat->setObjectName("Stat");
        Stat->resize(666, 477);
        Back = new QPushButton(Stat);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(540, 420, 93, 29));
        stat_all = new QPushButton(Stat);
        stat_all->setObjectName("stat_all");
        stat_all->setGeometry(QRect(550, 20, 93, 29));
        label = new QLabel(Stat);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 70, 201, 81));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(Stat);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(120, 160, 411, 231));
        myform = new QHBoxLayout(horizontalLayoutWidget_3);
        myform->setObjectName("myform");
        myform->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_5->addWidget(lineEdit_2);

        T_1 = new QLabel(horizontalLayoutWidget_3);
        T_1->setObjectName("T_1");

        verticalLayout_5->addWidget(T_1);


        myform->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lineEdit = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_4->addWidget(lineEdit);

        T_2 = new QLabel(horizontalLayoutWidget_3);
        T_2->setObjectName("T_2");

        verticalLayout_4->addWidget(T_2);


        myform->addLayout(verticalLayout_4);


        retranslateUi(Stat);

        QMetaObject::connectSlotsByName(Stat);
    } // setupUi

    void retranslateUi(QWidget *Stat)
    {
        Stat->setWindowTitle(QCoreApplication::translate("Stat", "Form", nullptr));
        Back->setText(QCoreApplication::translate("Stat", "Back", nullptr));
        stat_all->setText(QCoreApplication::translate("Stat", "All statistics", nullptr));
        label->setText(QCoreApplication::translate("Stat", "STATISTIC", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Stat", "Task1", nullptr));
        T_1->setText(QCoreApplication::translate("Stat", "TextLabel", nullptr));
        lineEdit->setText(QCoreApplication::translate("Stat", "Task2", nullptr));
        T_2->setText(QCoreApplication::translate("Stat", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stat: public Ui_Stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_H
