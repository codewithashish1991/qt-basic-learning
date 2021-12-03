#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
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

void MainWindow::on_aboutBtn_clicked()
{
    QMessageBox::about(this, "About Alert", "I am about alert!");
}

void MainWindow::on_infoBtn_clicked()
{
    QMessageBox::information(this, "Information Alert","I am information!");
}

void MainWindow::on_warningBtn_clicked()
{
    QMessageBox::warning(this, "Warning Alert", "I am warning alert!");
}

void MainWindow::on_questionBtn_clicked()
{
    QMessageBox::question(this, "Question alert", "I am question alert!", QMessageBox::Yes | QMessageBox::No );
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
       QMessageBox::about(this, "About", "I am Ashish. I am a software developer in Allience Web Solutions Pvt. Ltd.\n"
                                         "My role is senior software developer in my company.\n"
                                         "Now I want to work in other countries like: UK, US, Canada.");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
     QMessageBox::aboutQt(this, "About QT");
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter qpr;
    QPrintDialog pdiloag(&qpr, this);
    pdiloag.setWindowTitle("Print Document");
    if(ui->plainTextEdit->textCursor().hasSelection()){
        pdiloag.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
    if(pdiloag.exec() != QDialog::Accepted){
        return;
    }
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helevetica[Croyx]"));
    if(&ok){
        ui->plainTextEdit->setFont(font);
    }
}

void MainWindow::on_actionColor_triggered()
{
    bool ok;
    QColor color = QColorDialog::getColor(Qt::red, this);
    if(&ok){
        ui->plainTextEdit->setTextColor(color);
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "~/");
    ui->plainTextEdit->setText(fileName);
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}
