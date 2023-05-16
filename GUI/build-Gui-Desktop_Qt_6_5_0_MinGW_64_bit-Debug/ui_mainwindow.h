/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Task1;
    QPushButton *Task2;
    QPushButton *Task3;
    QPushButton *Check_s_button;
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
        exit->setGeometry(QRect(620, 470, 93, 29));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 200, 406, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Task1 = new QPushButton(layoutWidget);
        Task1->setObjectName("Task1");

        horizontalLayout->addWidget(Task1);

        Task2 = new QPushButton(layoutWidget);
        Task2->setObjectName("Task2");

        horizontalLayout->addWidget(Task2);

        Task3 = new QPushButton(layoutWidget);
        Task3->setObjectName("Task3");

        horizontalLayout->addWidget(Task3);

        Check_s_button = new QPushButton(centralwidget);
        Check_s_button->setObjectName("Check_s_button");
        Check_s_button->setGeometry(QRect(350, 290, 131, 29));
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
        Task2->setText(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        Task3->setText(QCoreApplication::translate("MainWindow", "Task 3", nullptr));
        Check_s_button->setText(QCoreApplication::translate("MainWindow", "Check statistic", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
