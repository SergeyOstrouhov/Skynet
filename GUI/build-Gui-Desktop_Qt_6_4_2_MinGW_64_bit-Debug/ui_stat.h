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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stat
{
public:
    QPushButton *Back;
    QPushButton *stat_all;
    QLabel *label;
    QLabel *label_stat;

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
        label_stat = new QLabel(Stat);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(150, 180, 321, 201));

        retranslateUi(Stat);

        QMetaObject::connectSlotsByName(Stat);
    } // setupUi

    void retranslateUi(QWidget *Stat)
    {
        Stat->setWindowTitle(QCoreApplication::translate("Stat", "Form", nullptr));
        Back->setText(QCoreApplication::translate("Stat", "Back", nullptr));
        stat_all->setText(QCoreApplication::translate("Stat", "All statistics", nullptr));
        label->setText(QCoreApplication::translate("Stat", "STATISTIC", nullptr));
        label_stat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Stat: public Ui_Stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_H
