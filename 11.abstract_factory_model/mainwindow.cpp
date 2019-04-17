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
    User * u = new User();
    Department *d = new Department();

    IFactory * factory = new SqlserverFactory();//仅改这里一行即可

    IUser * iu = factory->CreateUser();
    iu->insert(u);
    iu->GetUser(1);

    IDepartment *idept = factory->CreateDepartment();
    idept->insert(d);
    idept->GetDepartment(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    User * u = new User();
    Department *d = new Department();

    IFactory * factory = new AccessFactory();//仅改这里一行即可

    IUser * iu = factory->CreateUser();
    iu->insert(u);
    iu->GetUser(1);

    IDepartment *idept = factory->CreateDepartment();
    idept->insert(d);
    idept->GetDepartment(1);
}
