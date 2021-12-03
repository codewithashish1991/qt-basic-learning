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
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE"); //QMYSQL
    sqlitedb.setDatabaseName("/var/www/html/braham-ii/SqlLiteDB/db_fqt5.sqlite");
    if(!sqlitedb.open()){
        QMessageBox::about(this,"Database connection information", "Database could not connect!");
    }else{
        QMessageBox::about(this,"Database connection information", "Database connected successfully!");
    }
}
