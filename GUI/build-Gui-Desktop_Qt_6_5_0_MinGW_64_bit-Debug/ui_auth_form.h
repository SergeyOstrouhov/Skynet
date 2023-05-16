/********************************************************************************
** Form generated from reading UI file 'auth_form.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_FORM_H
#define UI_AUTH_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Auth_form
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_log;
    QPushButton *pushButton_change;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_log;
    QLabel *label_pas;
    QLabel *label_r_pass;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_r_pass;

    void setupUi(QWidget *Auth_form)
    {
        if (Auth_form->objectName().isEmpty())
            Auth_form->setObjectName("Auth_form");
        Auth_form->resize(400, 300);
        widget = new QWidget(Auth_form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 250, 306, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_reg = new QPushButton(widget);
        pushButton_reg->setObjectName("pushButton_reg");

        horizontalLayout->addWidget(pushButton_reg);

        pushButton_log = new QPushButton(widget);
        pushButton_log->setObjectName("pushButton_log");

        horizontalLayout->addWidget(pushButton_log);

        pushButton_change = new QPushButton(widget);
        pushButton_change->setObjectName("pushButton_change");

        horizontalLayout->addWidget(pushButton_change);

        widget1 = new QWidget(Auth_form);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 60, 351, 93));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_log = new QLabel(widget1);
        label_log->setObjectName("label_log");

        verticalLayout_2->addWidget(label_log);

        label_pas = new QLabel(widget1);
        label_pas->setObjectName("label_pas");

        verticalLayout_2->addWidget(label_pas);

        label_r_pass = new QLabel(widget1);
        label_r_pass->setObjectName("label_r_pass");

        verticalLayout_2->addWidget(label_r_pass);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_login = new QLineEdit(widget1);
        lineEdit_login->setObjectName("lineEdit_login");

        verticalLayout->addWidget(lineEdit_login);

        lineEdit_pass = new QLineEdit(widget1);
        lineEdit_pass->setObjectName("lineEdit_pass");

        verticalLayout->addWidget(lineEdit_pass);

        lineEdit_r_pass = new QLineEdit(widget1);
        lineEdit_r_pass->setObjectName("lineEdit_r_pass");

        verticalLayout->addWidget(lineEdit_r_pass);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Auth_form);

        QMetaObject::connectSlotsByName(Auth_form);
    } // setupUi

    void retranslateUi(QWidget *Auth_form)
    {
        Auth_form->setWindowTitle(QCoreApplication::translate("Auth_form", "Form", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("Auth_form", "Sign in", nullptr));
        pushButton_log->setText(QCoreApplication::translate("Auth_form", "Log in", nullptr));
        pushButton_change->setText(QCoreApplication::translate("Auth_form", "Change", nullptr));
        label_log->setText(QCoreApplication::translate("Auth_form", "Login", nullptr));
        label_pas->setText(QCoreApplication::translate("Auth_form", "Password", nullptr));
        label_r_pass->setText(QCoreApplication::translate("Auth_form", "Password", nullptr));
        lineEdit_login->setPlaceholderText(QCoreApplication::translate("Auth_form", "Login", nullptr));
        lineEdit_pass->setPlaceholderText(QCoreApplication::translate("Auth_form", "Password", nullptr));
        lineEdit_r_pass->setPlaceholderText(QCoreApplication::translate("Auth_form", "Repeat password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth_form: public Ui_Auth_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_FORM_H
