#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // QSQLITE

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("indiaint");
    db.setDatabaseName("db_qt5");
    if(db.open()){
        QMessageBox::about(this, "Database Connection Information", "Database connected succesfully!");
    }else{
        QMessageBox::about(this, "Database Connection Information", "Database could n't connect!");
    }
}
