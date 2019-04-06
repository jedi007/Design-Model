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
    SchoolGirl * jiaojiao = new SchoolGirl();
    jiaojiao->setName("如花");

    Proxy * daili = new Proxy(jiaojiao);

    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();

    auto_ptr<Proxy> auto_p(daili);
    auto_p->GiveChocolate();

}
