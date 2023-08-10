#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = 0;
    void changeMoney(int diff);  //chemal case , snake
    void checkMoney();
    QString currentMoney();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_Coffee_clicked();
    void on_Tea_clicked();
    void on_Milk_clicked();

    void on_Reset_clicked();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
