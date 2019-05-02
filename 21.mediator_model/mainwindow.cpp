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
    ConcreteMediator *mediator = new ConcreteMediator();
    ConcreteColleague1 *c1 = new ConcreteColleague1(mediator);
    ConcreteColleague2 *c2 = new ConcreteColleague2(mediator);

    mediator->colleague1 = c1;
    mediator->colleague2 = c2;

    c1->Send("吃过饭了吗");
    c2->Send("没有呢，你打算请客？");
}
