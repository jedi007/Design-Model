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
    Originator o;
    o.state1 = "状态1-生命99";
    o.state2 = "状态2-体力99";

    Caretaker adminer;
    adminer.SetMement(o.CreateMemento());

    o.state1 = "状态1-生命0";
    o.state2 = "状态2-体力0";
    o.display();

    o.SetMemento(adminer.getMemento());
    o.display();
}
