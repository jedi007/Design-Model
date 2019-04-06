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
    IFactory* factory = new UndergraduateFactory;
    LeiFeng* student1 = factory->CreateLeiFeng();
    qDebug()<<"student1------------------: "<<endl;
    student1->Sweep();
    student1->BuyRice();

    LeiFeng* student2 = factory->CreateLeiFeng();
    qDebug()<<"student2------------------: "<<endl;
    student2->Sweep();
    student2->BuyRice();
    student2->Wash();
}

void MainWindow::on_pushButton_2_clicked()
{
    IFactory* factory = new VolunteerFactory;
    LeiFeng* volunteer1 = factory->CreateLeiFeng();
    qDebug()<<"volunteer1------------------: "<<endl;
    volunteer1->Sweep();
    volunteer1->BuyRice();

    LeiFeng* volunteer2 = factory->CreateLeiFeng();
    qDebug()<<"volunteer2------------------: "<<endl;
    volunteer2->Sweep();
    volunteer2->BuyRice();
    volunteer2->Wash();
}
