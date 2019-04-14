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
    Director dc;
    Builder *b1 = new ConcreteBuilder1();
    dc.Construct(b1);
    Product * p1 = b1->GetResult();
    p1->Show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Director dc;
    Builder *b2 = new ConcreteBuilder2();
    dc.Construct(b2);
    Product * p2 = b2->GetResult();
    p2->Show();
}
