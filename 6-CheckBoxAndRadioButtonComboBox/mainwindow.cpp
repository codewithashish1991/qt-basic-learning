#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->HappyYesRB->setChecked(true);
    // add new items in combobox
    ui->fromComboBox->addItem("Dehradun");
    ui->fromComboBox->addItem("Haridwar");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitBtn_clicked()
{
    QString name = ui->nameInput->text();
    QString languages;
    QString comma;
    QString happy;
    QString livein = ui->fromComboBox->currentText();
    if(ui->javaCheckbox->isChecked()){
        languages += "Java";
    }

    if(ui->pythonCheckbox->isChecked()){
        if(languages.length() > 0 && comma.length() == 0){
            comma =",";
        }
        languages += comma + " Python";
    }

    if(ui->PhpCheckbox->isChecked()){
        if(languages.length() > 0 && comma.length() == 0){
            comma =",";
        }
        languages += comma + " PHP";
    }

    if(ui->cppCheckbox->isChecked()){
        if(languages.length() > 0 && comma.length() == 0){
            comma =",";
        }
        languages += comma + " C++";
    }

    if(ui->HappyYesRB->isChecked()){
        happy = "Yoo! You are Happy Now";
    }else{
        happy = "Opps! You are not Happy";
    }

    QString result;
    result += "Your name is: " + name + "\n";
    result += "You are related from: " + livein + "\n";
    result += "Your faviourate language are: " + languages + "\n";
    result += happy + "\n";

    QMessageBox::about(this, "Your Information", result);
}
