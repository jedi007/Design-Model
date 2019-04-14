#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "observer_model.h"

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
    ConcreteSubject *s = new ConcreteSubject;

    s->Attach(new ConcreteObserver(s,"X"));
    s->Attach(new ConcreteObserver(s,"Y"));
    s->Attach(new ConcreteObserver(s,"Z"));

    s->setState("ABCDEFG");
    s->Notify();
}
