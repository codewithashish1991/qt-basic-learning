#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->phone->setValidator( new QDoubleValidator(0, 100, 2, this) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString isValidate(QString email, QString phone, QString username){
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    QRegExp usernameREX("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[-+_!@#$%^&*.,?]).+$");
    usernameREX.setCaseSensitivity(Qt::CaseInsensitive);
    usernameREX.setPatternSyntax(QRegExp::RegExp);
    QString errorMsg;
    if(!mailREX.exactMatch(email)){
        errorMsg = "Invalid Email Address!";
    }

    if((phone.length() < 9 || phone.length() > 15) && QString(errorMsg).isEmpty()){
        errorMsg = "Phone number should be greater then 9 and less then 15 digits!";
    }

    if(!usernameREX.exactMatch(username) && username.length() < 8 && QString(errorMsg).isEmpty()){
        errorMsg = "Username must contain at least 1 uppercase 1 lowercase and 1 numeric characters and"
                   "minimum 8 characters!";
    }
    return errorMsg;
}

bool MainWindow::isUserExist(QString email, QString username){
    bool rtn = false;
    connOpen();
    if(database.open()){
        QSqlQuery query;
        query.prepare("SELECT name FROM users WHERE email = :email OR username = :username");
        query.bindValue(":username", username);
        query.bindValue(":email", email);
        if(query.exec()){
            if(query.size() > 0){
                rtn = true;
            }
            query.clear();
            query.finish();
        }
    }
    return rtn;
}

void MainWindow::on_registerBtn_clicked()
{
    connOpen();
    if(database.open()){
        QString name = ui->name->text();
        QString email = ui->email->text();
        QString phone = ui->phone->text();
        QString username = ui->username->text();
        QString password = ui->password->text();

        if(name.size() > 0 && email.size() > 0 && phone.size() > 0 && password.size() > 0){
            QString errorMsg = isValidate(email, phone, username);
            bool userExist = false;
            if(QString(errorMsg).isEmpty()){
                userExist = isUserExist(email, username);
            }
            if(QString(errorMsg).isEmpty() && userExist == false){
                QSqlQuery query;
                query.prepare("INSERT INTO users (name, email, phone, username, password) VALUES "
                              "(:name, :email, :phone, :username, :password)");
                query.bindValue(":name", name);
                query.bindValue(":email", email);
                query.bindValue(":phone", phone);
                query.bindValue(":username", username);
                query.bindValue(":password", password);

                if(query.exec()){
                    QMessageBox::information(this, "Registration", "User register successfully!");
                    query.clear();
                    query.finish();
                    ui->name->setText("");
                    ui->email->setText("");
                    ui->phone->setText("");
                    ui->username->setText("");
                    ui->password->setText("");
                }else{

                    QMessageBox::warning(this, "Registration", "Something went wrong!");
                }
            }else{
                if(!QString(errorMsg).isEmpty()){
                    QMessageBox::warning(this, "Error", errorMsg);
                }else if(userExist == true){
                    QMessageBox::warning(this, "Error", "Username or email already register."
                                                        "Please try with another one.");
                }else{}
            }

        }else{
            QMessageBox::warning(this, "Registration", "All fields are required!");
        }
        connClose();
    }else{
        QMessageBox::warning(this, "Connection Information", "Connect Could n't stablished!");
    }
}

void MainWindow::on_loginBtn_clicked()
{
    connOpen();
    if(database.open()){
        QString username = ui->loginUsername->text();
        QString password = ui->loginPassword->text();
        if(username.size() > 0 && password.size() > 0){
            QSqlQuery mquery;
            mquery.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
            mquery.bindValue(":username", username);
            mquery.bindValue(":password", password);
            if(mquery.exec()){
                if(mquery.size() > 0){
                    while (mquery.next()) {
                        QString usernameDB = mquery.value(4).toString();
                        QString nameDB = mquery.value(1).toString();
                        QString userId = mquery.value(0).toString();
                        if(usernameDB.size() > 0){
                            QSettings sess;
                            sess.setValue("userId", userId);
                            sess.setValue("name", nameDB);
                            sess.setValue("username", usernameDB);
                            QMessageBox::information(this, "Logged In as " + usernameDB, "User logged in successfully!");
                            hide();
                            mquery.clear();
                            mquery.finish();
                            dash = new Dashboard(this);
                            dash->show();

                        }else{
                            QMessageBox::warning(this, "Login error ", "Something went wrong!");
                        }
                    }
                }else{
                     QMessageBox::warning(this, "Login error", "Invalid username and password!");
                }
            }else{
                QMessageBox::warning(this, "Connection Error", "Database query could n't execute!");
            }
        }else {
            QMessageBox::warning(this, "Login Error", "Username and Password are required!");
        }
        connClose();
    }else{
        QMessageBox::warning(this, "Connection Error", "Database connection closed!");
    }
}
