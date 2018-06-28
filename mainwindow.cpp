#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int width = this->width();
    int height = this->height();
    this->setFixedSize(QSize(width, height));

    ui->label_logininfo->setStyleSheet("QLabel {  color : red; }");

    database_ =  QSqlDatabase::addDatabase("QSQLITE");
    database_.setDatabaseName("C:/Qt Projects/QtApp/qt_database.sqlite");
    if(!database_.open()){
        qDebug() << "Failed to open database";
    }

    QPixmap pixmap(":/img/img/login_icon.png");
    ui->label_image->setPixmap(pixmap);
    ui->label_image->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete registration_window_;
    database_.close();
}

void MainWindow::on_pushButton_signup_clicked()
{
    registration_window_ = new RegistrationWindow(this, database_);
    registration_window_->show();
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(!password.isEmpty() && !username.isEmpty())
    {
        QSqlQuery qry;
        qry.exec("select * from User where username='"+username+"' and password='"+password+"'");

        if(qry.next())
        {
            QMessageBox::information(this, tr("Login"), tr("You are logged in"));
        }
        else
        {
            ui->label_logininfo->setText("Incorrect name or password");
        }

        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
    }
    else
    {
        ui->label_logininfo->setText("You have to fill login and password");
    }
}
