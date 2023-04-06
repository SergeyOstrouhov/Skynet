#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Auth_form;
}

class Auth_form : public QWidget
{
    Q_OBJECT

public:
    explicit Auth_form(QWidget *parent = nullptr);
    ~Auth_form();

private slots:
    //void on_pushButton_3_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_reg_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_log_clicked();

private:
    Ui::Auth_form *ui;
    bool mode;

    void change_mode(bool);
signals:
    void auth_ok(QString);
};

#endif // AUTH_FORM_H
