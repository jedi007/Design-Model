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
    Person *xm = new Person("小明");

    qDebug()<<"第一种装扮："<<flush;

    Tie tie;
    TShirts tshirts;
    BigUnderpants bigunderpants;

    tie.decorate(xm);
    tshirts.decorate(&tie);
    bigunderpants.decorate(&tshirts);
    bigunderpants.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Person *xh = new Person("小红");

    qDebug()<<"第二种装扮："<<flush;

    BigUnderpants *bigunderpants = new BigUnderpants;
    LeatherShoes *lshoes = new LeatherShoes;
    BusinessSuit *bussuit = new BusinessSuit;

    bigunderpants->decorate(xh);
    lshoes->decorate(bigunderpants);
    bussuit->decorate(lshoes);
    bussuit->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Person *jedi = new Person("jedi");

    qDebug()<<"第三种装扮："<<flush;

    BigUnderpants *bigunderpants = new BigUnderpants;
    LeatherShoes *lshoes = new LeatherShoes;
    BusinessSuit *bussuit = new BusinessSuit;
    TShirts * tshirt = new TShirts;

    bigunderpants->decorate(jedi);
    lshoes->decorate(bigunderpants);
    bussuit->decorate(lshoes);
    tshirt->decorate(bussuit);
    tshirt->show();
}
