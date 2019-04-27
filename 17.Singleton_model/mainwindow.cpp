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

void MainWindow::on_pushButton_clicked()//懒汉
{
    Singleton::getSingleton()->testi = 999;
    qDebug()<<"Singleton::getSingleton()->testi: "<<Singleton::getSingleton()->testi<<endl;
}

void MainWindow::on_pushButton_2_clicked()//饿汉
{
    singleton::initance()->testi = 888;
    qDebug()<<"singleton::initance()->testi: "<<singleton::initance()->testi<<endl;
}

void MainWindow::on_pushButton_3_clicked()//线程安全的饿汉
{
    safe_singleton::initance()->testi = 777;
    qDebug()<<"safe_singleton::initance()->testi: "<<safe_singleton::initance()->testi<<endl;
}
