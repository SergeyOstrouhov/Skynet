#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();
signals:
    void on_closed();
private:
    Ui::Task *ui;
    int a;
    int b;
private slots:
    void on_Ok_clicked();
};

#endif // TASK_H
