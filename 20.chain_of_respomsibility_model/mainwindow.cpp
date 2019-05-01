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
    Handler* h1 = new ConcreteHandler1;
    Handler* h2 = new ConcreteHandler2;
    Handler* h3 = new ConcreteHandler3;

    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);

    int requests[] = {2,5,14,22,18,3,27,20};

    for(int i=0;i<8;++i)
    {
        h1->HandlerRequest(requests[i]);
    }

    //delete h1,h2,h3
}
