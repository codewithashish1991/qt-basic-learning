#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ui->listWidget->addItem("HTML");
    // ui->listWidget->addItem("CSS");
    // ui->listWidget->addItem("JavaScript");
    QStringList listItems = {"HTML", "CSS", "JavaScript"};
    foreach (QString litem, listItems) {
       ui->listWidget->addItem(litem);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setTextColor(Qt::red);
}

void Widget::on_pushButton_2_clicked()
{
    QFont font("Times", 15, QFont::Bold);
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setFont(font);
}

void Widget::on_pushButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setBackground(Qt::green);
}
