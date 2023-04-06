/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTask_1;
    QAction *actionTask_2;
    QAction *actionTask_3;
    QAction *actionExit;
    QWidget *centralwidget;
    QPushButton *exit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Task1;
    QPushButton *Tak2;
    QPushButton *push_Task3;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionTask_1 = new QAction(MainWindow);
        actionTask_1->setObjectName("actionTask_1");
        actionTask_2 = new QAction(MainWindow);
        actionTask_2->setObjectName("actionTask_2");
        actionTask_3 = new QAction(MainWindow);
        actionTask_3->setObjectName("actionTask_3");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(430, 420, 93, 29));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(240, 230, 295, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Task1 = new QPushButton(widget);
        Task1->setObjectName("Task1");

        horizontalLayout->addWidget(Task1);

        Tak2 = new QPushButton(widget);
        Tak2->setObjectName("Tak2");

        horizontalLayout->addWidget(Tak2);

        push_Task3 = new QPushButton(widget);
        push_Task3->setObjectName("push_Task3");

        horizontalLayout->addWidget(push_Task3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuMenu->addAction(actionTask_1);
        menuMenu->addAction(actionTask_2);
        menuMenu->addAction(actionTask_3);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTask_1->setText(QCoreApplication::translate("MainWindow", "Task 1", nullptr));
        actionTask_2->setText(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        actionTask_3->setText(QCoreApplication::translate("MainWindow", "Task 3", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Task1->setText(QCoreApplication::translate("MainWindow", "Task 1", nullptr));
        Tak2->setText(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        push_Task3->setText(QCoreApplication::translate("MainWindow", "Task 3", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
