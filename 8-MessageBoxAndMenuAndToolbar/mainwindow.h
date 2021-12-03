#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_aboutBtn_clicked();

    void on_infoBtn_clicked();

    void on_questionBtn_clicked();

    void on_warningBtn_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionPrint_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCut_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
