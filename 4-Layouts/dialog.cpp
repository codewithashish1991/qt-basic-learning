#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sbumit_clicked()
{
    QString subjet = ui->subjet->text();
    QString to = ui->to->text();
    QString from = ui->from->text();
    QString msg = ui->msg->toPlainText();
    QString res;
    res += "Subject: " + subjet + "\n";
    res += "To: " + to + "\n";
    res += "From: " + from + "\n";
    res += "Message: " + msg + "\n";

    QMessageBox::about(this, "Submitted values are:", res);
}
