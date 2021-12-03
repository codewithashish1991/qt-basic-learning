#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dashboard.h"
#include <QMainWindow>

#include <QMessageBox>
#include <QSettings>
#include <QSettings>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase database;
    void connOpen(){
        if(!database.isValid()){
            database = QSqlDatabase::addDatabase("QMYSQL");
            database.setHostName("localhost");
            database.setUserName("root");
            database.setPassword("indiaint");
            database.setDatabaseName("db_qt5");
        }
        if(database.open()){
            qDebug() << "Database connected.";
            return;
        }else{
            qDebug() << "Database could n't connect.";
            return;
        }
    };
    void connClose(){
        {
            database.close();
        }
        // database.removeDatabase(QSqlDatabase::defaultConnection);
        qDebug() << "Database connection closed.";
        return;
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_registerBtn_clicked();
    bool isUserExist(QString email, QString username);

    void on_loginBtn_clicked();

private:
    Ui::MainWindow *ui;
    Dashboard *dash;
};

#endif // MAINWINDOW_H
