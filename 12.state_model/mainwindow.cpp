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
    Work protect;
    protect.Hour = 8;
    protect.WriteProgram();

    protect.Hour = 9;
    protect.WriteProgram();

    protect.Hour = 10;
    protect.WriteProgram();

    protect.Hour = 11;
    protect.WriteProgram();

    protect.Hour = 12;
    protect.WriteProgram();

    protect.Hour = 13;
    protect.WriteProgram();

    protect.Hour = 14;
    protect.WriteProgram();

    protect.WorkFinish = false;
    protect.Hour = 17;
    protect.WriteProgram();

    protect.Hour = 19;
    protect.WriteProgram();

    protect.Hour = 22;
    protect.WriteProgram();
}
