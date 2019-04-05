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
    Operation * oper = operation_factory.createOperate(ui->comboBox_operator->currentText());
    oper->setNumberA(ui->lineEdit_numberA->text().toDouble());
    oper->setNumberB(ui->lineEdit_numberB->text().toDouble());

    double result = oper->GetResult();

    ui->label_result->setText(QString("结果： %1").arg(QString::number(result,'d',6)));
}
