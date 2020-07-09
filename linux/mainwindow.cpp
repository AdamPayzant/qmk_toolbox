#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenButton_clicked()
{
    std::cout << "Open Clicked" << std::endl;
}

void MainWindow::on_FlashButton_clicked()
{
    std::cout << "Flash Clicked" << std::endl;
}

void MainWindow::on_ExitButton_clicked()
{
    std::cout << "Exit Clicked" << std::endl;
}
