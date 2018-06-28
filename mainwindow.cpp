#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    QSqlQuery qry;
    qry.exec("select * from User where username='"+username+"' and password='"+password+"'");

    if(qry.next())
    {
        QString name = qry.value(0).toString();
        int id = qry.value(1).toInt();
        QMessageBox::information(this, tr("information"), name);
        qDebug() << name << id;
    }

}
