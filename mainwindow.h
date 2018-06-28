#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QPixmap>
#include <QMessageBox>

#include "registrationwindow.h"

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
    void on_pushButton_signup_clicked();
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    RegistrationWindow *registration_window_;
    QSqlDatabase database_;
};

#endif // MAINWINDOW_H
