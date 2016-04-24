#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::gray);
    ui->graph->setAutoFillBackground(true);
    ui->graph->setPalette(Pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}
