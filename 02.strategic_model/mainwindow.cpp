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

void MainWindow::on_pushButton_ReSet_clicked()
{
    ui->label_Result->setText("");
    ui->lineEdit_Number->setText("");
    ui->lineEdit_Price->setText("");
}

void MainWindow::on_pushButton_OK_clicked()
{
    ChargeStrategyController * csc = new ChargeStrategyController(ui->comboBox_crashmodel->currentText());
    double price = ui->lineEdit_Price->text().toDouble();
    double number = ui->lineEdit_Number->text().toDouble();
    double result = csc->GetResult(price*number);

    QString str = QString("单价： %1， 数量： %2， %3， 合计： %4")
                  .arg(ui->lineEdit_Price->text())
                  .arg(ui->lineEdit_Number->text())
                  .arg(ui->comboBox_crashmodel->currentText())
                  .arg(QString::number(result));
    ui->textEdit->append(str);

    ui->label_Result->setText(QString::number(result));
}
