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

void MainWindow::on_test_slider_valueChanged(int value)
{
    connect(ui->test_slider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

void MainWindow::on_test_slider_actionTriggered(int action)
{

}
