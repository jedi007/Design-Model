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
    TemplateClass * t = new ClassA();
    t->TemplateMethod();
}

void MainWindow::on_pushButton_2_clicked()
{
    TemplateClass * t = new ClassB();
    t->TemplateMethod();
}
