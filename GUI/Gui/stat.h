#ifndef STAT_H
#define STAT_H

#include <QWidget>

namespace Ui {
class Stat;
}

class Stat : public QWidget
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = nullptr);
    ~Stat();


private:
    Ui::Stat *ui;
signals:
    void on_closed();
private slots:
    void on_Back_clicked();
    void update_stat(QString);
    void on_stat_all(QString);
    void qwerty();
    void on_stat_all_clicked();
};

#endif // STAT_H
