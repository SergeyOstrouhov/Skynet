#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "auth_form.h"
#include "stat.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_clicked();

 //   void on_pushButton_clicked();

    void on_Task1_clicked();

    void on_actionTask_1_triggered();

    void on_actionTask_2_triggered();

    void on_actionTask_3_triggered();

    void on_actionExit_triggered();

    void on_Tak2_clicked();

    void on_push_Task3_clicked();

    void slot_on_auth_ok(QString log);

    void on_Check_s_button_clicked();

private:
    Ui::MainWindow *ui;
    Auth_form* ui_auth;
    Stat * stat;
};
#endif // MAINWINDOW_H
