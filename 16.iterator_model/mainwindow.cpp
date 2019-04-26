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

void MainWindow::on_pushButton_clicked()
{
    Aggregate *a = new Aggregate;
    if((*a)[2])
        qDebug()<<(*a)[2]->name<<endl;

    Iterator It(a);
    obj * oj = It.First();
    if(oj)
        qDebug()<<"oj->:"<<oj->name<<endl;

    obj * oj2 = It.Next();
    if(oj2)
        qDebug()<<"oj2->:"<<oj2->name<<endl;
}
