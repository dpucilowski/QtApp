#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent, QSqlDatabase &database);
    ~RegistrationWindow();

private slots:
    void on_pushButton_signup_clicked();

private:
    Ui::RegistrationWindow *ui;
    QSqlDatabase database_;
};

#endif // REGISTRATIONWINDOW_H
