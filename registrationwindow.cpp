#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent, QSqlDatabase &database) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow),
    database_(database)
{
    ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_pushButton_signup_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString rpassword = ui->lineEdit_rpassword->text();
    QString email = ui->lineEdit_email->text();


    if(password == rpassword)
    {
        QSqlQuery qry;
        qry.prepare("insert into User(username,password,email) values('"+username+"','"+password+"','"+email+"')");

//        qry.prepare("INSERT INTO User(username,password,email) VALUES(:username,:password,:email)");

//        qry.bindValue(":username", username);
//        qry.bindValue(":password", password);
//        qry.bindValue(":email", email);

        if(qry.exec())
        {
            QMessageBox::information(this, tr("Save"), tr("Done"));
        }
        else
        {
            QMessageBox::critical(this, tr("error::"), qry.lastError().text());
        }
    }
    else
    {
        qDebug() << "Passwords have to be the same!";
    }
}
