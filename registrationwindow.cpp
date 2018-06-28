#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent, QSqlDatabase &database) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow),
    database_(database)
{
    ui->setupUi(this);

    int width = this->width();
    int height = this->height();
    this->setFixedSize(QSize(width, height));

    ui->label_signupinfo->setStyleSheet("QLabel {  color : red; }");
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

    if(!username.isEmpty() && !password.isEmpty() && !rpassword.isEmpty() && !email.isEmpty())
    {
        if(password == rpassword)
        {
            QSqlQuery qry;
            qry.prepare(
                "insert into User(username,password,email,id)"
                "values('"+username+"','"+password+"','"+email+"',NULL)");

            if(qry.exec())
            {
                QMessageBox::information(this, tr("Registartion"), tr("Done"));
            }
            else
            {
                ui->label_signupinfo->setText(qry.lastError().text());
            }
            this->close();
        }
        else
        {
            ui->label_signupinfo->setText("Passwords have to be the same");
        }
    }
    else
    {
        ui->label_signupinfo->setText("You have to fill all fields");
    }

}
