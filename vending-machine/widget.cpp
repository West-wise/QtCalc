#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#define COFFEE 100
#define TEA 150
#define MILK 200

//int money=0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
}

void Widget::checkMoney()
{
    if(money==0){
        ui->Milk->setEnabled(false);
        ui->Coffee->setEnabled(false);
        ui->Tea->setEnabled(false);
    }
    else{
        ui->Milk->setEnabled(money < MILK ? false : true);
        ui->Tea->setEnabled(money < TEA ? false : true);
        ui->Coffee->setEnabled(money < COFFEE ? false : true);
    }


}

QString Widget::currentMoney(){

    return QString::number(money)+" Won";
}

void Widget::on_pushButton_clicked()
{
    changeMoney(10);
    checkMoney();
}


void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
    checkMoney();
}


void Widget::on_pushButton_3_clicked()
{
  changeMoney(100);
  checkMoney();
}

void Widget::on_pushButton_4_clicked()
{
  changeMoney(500);
  checkMoney();
}

void Widget::on_Coffee_clicked()
{
  changeMoney(-100);
  checkMoney();
}

void Widget::on_Tea_clicked()
{
  changeMoney(-150);
  checkMoney();
}

void Widget::on_Milk_clicked()
{
  changeMoney(-200);
  checkMoney();
}

void Widget::on_Reset_clicked()
{
  QMessageBox mb;
  mb.information(nullptr,"Changes",currentMoney());
  QApplication::quit();
}

