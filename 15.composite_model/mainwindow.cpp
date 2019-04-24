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
    Compoent *root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf XB"));

    root->Add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp->Add(comp2);

    root->Add(new Leaf("Leaf C"));

    Leaf *leafD = new Leaf("Leaf D");
    root->Add(leafD);
    root->Remove(leafD);

    root->Display();
}
