#include "dashboard.h"
#include "ui_dashboard.h"
#include "mainwindow.h"

#include <QSqlQuery>

Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    MainWindow conn;
    conn.connOpen();
    if(conn.database.open()){
        tbl_model = new QSqlTableModel();
        tbl_model->setTable("users");
        tbl_model->select();
        ui->tableView->setModel(tbl_model);
        ui->tableView->setColumnHidden(4, true);
        ui->tableView->setColumnHidden(5, true);
        ui->tableView->setColumnHidden(6, true);
        tbl_model->setHeaderData(0, Qt::Horizontal, "UserID");
        tbl_model->setHeaderData(1, Qt::Horizontal, "Name");
        tbl_model->setHeaderData(2, Qt::Horizontal, "Email");
        tbl_model->setHeaderData(3, Qt::Horizontal, "Phone");
        conn.connClose();
    }
    QSettings sess;
    QString name = sess.value("name").toString();
    ui->usernameHader->setText("Hello, " + name);

}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_logoutBtn_clicked()
{
    QSettings sess;
    sess.remove("name");
    sess.remove("username");
    sess.remove("userId");
    hide();
    MainWindow *mainw;
    mainw = new MainWindow(this);
    mainw->show();
}
