#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
   QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->label->text()+ button->text()).toDouble();


    newLabel = QString::number(labelNumber,'g',15);

    ui->label->setText(newLabel);
}

void MainWindow::binary_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    if (button->text() == "+") {
        operation = ADD;
    }
    else if (button->text() == "-") {
        operation = SUBTRACT;
    }
    else if (button->text() == "x") {
        operation = MULTIPLY;
    }
    else if (button->text() == "/") {
        operation = DIVIDE;
    }

    ui->label->setText("");
}

void MainWindow::on_pushButton_dot_pressed()
{

    ui->label->setText(ui->label->text()+".");


}


void MainWindow::on_pushButton_clear_pressed()
{
    ui->label->setText(" ");
    firstNum = 0.0;
    operation = NONE;
}

void MainWindow::on_pushButton_equals_pressed()
{
    double secondNum = ui->label->text().toDouble();
    double result = 0.0 ;

    switch(operation)
    {
        case ADD:
            result = firstNum + secondNum;
            break;
        case SUBTRACT:
            result = firstNum - secondNum;
            break;
        case MULTIPLY:
            result = firstNum * secondNum;
            break;
        case DIVIDE:
            result = firstNum / secondNum;
            break;
        case NONE:
            return;
    }

    ui->label->setText(QString::number(result, 'f', 1));

     operation = NONE;
}

