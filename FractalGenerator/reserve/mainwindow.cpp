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

void MainWindow::Auto_Draw(int)
{
    if(ui->checkBox->isChecked())
    {
        ui->widget->update();
    }

    return;
}

void MainWindow::Change_Limit(int)
{
    if(ui->checkBox->isChecked())
    {
        ui->widget->update();
    }

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        ui->horizontalSlider->setRange(0,16);
        break;
    case 1:
        ui->horizontalSlider->setRange(0,16);
        break;
    case 2:
        ui->horizontalSlider->setRange(0,7);
        break;
    case 3:
        ui->horizontalSlider->setRange(0,7);
        break;
    case 4:
        ui->horizontalSlider->setRange(0,7);
        break;
    case 5:
        ui->horizontalSlider->setRange(0,7);
        break;
    case 6:
        ui->horizontalSlider->setRange(0,7);
        break;
    case 7:
        ui->horizontalSlider->setRange(0,8);
        break;
    case 8:
        ui->horizontalSlider->setRange(0,5);
        break;
    }

    return;
}
