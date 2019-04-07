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
    Resume *a = new Resume("大鸟");
    a->SetPersonalInfo("男","29");
    a->SetWorkExperience("1998-2006","XX公司");

    Resume *b = a->Clone();
    b->SetWorkExperience("2007-2008","YY公司");

    Resume *c = a->Clone();
    c->SetName("jedi");
    c->SetPersonalInfo("男","18");

    a->Display();
    b->Display();
    c->Display();

    qDebug()<<endl<<"----------测试赋值运算符----------"<<endl;
    c->SetWorkExperience("2010-1019","ZZZ公司");
    *a = *c;
    c->SetWorkExperience("2010-1019","AAA公司");
    a->Display();

    //说明默认的赋值运算符就是浅拷贝
}
