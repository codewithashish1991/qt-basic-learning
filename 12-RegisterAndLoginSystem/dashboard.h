#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QSettings>
#include <QSqlTableModel>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT
public:
    explicit Dashboard(QWidget *parent = 0);
    ~Dashboard();

private slots:
    void on_logoutBtn_clicked();

private:
    Ui::Dashboard *ui;
    QSqlTableModel *tbl_model;
};

#endif // DASHBOARD_H
