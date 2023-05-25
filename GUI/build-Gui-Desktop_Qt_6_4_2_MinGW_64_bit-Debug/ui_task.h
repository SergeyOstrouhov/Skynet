/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Ok;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(400, 300);
        lineEdit = new QLineEdit(Task);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 220, 113, 25));
        label = new QLabel(Task);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 40, 63, 20));
        label_2 = new QLabel(Task);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 100, 171, 61));
        Ok = new QPushButton(Task);
        Ok->setObjectName("Ok");
        Ok->setGeometry(QRect(210, 220, 93, 29));

        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Task", nullptr));
        label->setText(QCoreApplication::translate("Task", "Task 1", nullptr));
        label_2->setText(QCoreApplication::translate("Task", "2+2=", nullptr));
        Ok->setText(QCoreApplication::translate("Task", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
