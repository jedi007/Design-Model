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
    ConcreteImplementorA A;
    A.Operation1();
    A.Operation2();
    qDebug()<<"===============ra begin================="<<endl;

    RefineAction ra;
    ra.SetImplementor(&A);
    ra.operation();

    ConcreteImplementorB B;
    ra.SetImplementor(&B);
    ra.operation();
}
