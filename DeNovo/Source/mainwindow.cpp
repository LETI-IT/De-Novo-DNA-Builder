#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include "digraph.h"
#include <QFileDialog>
#include <QTextStream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::gray);
    ui->graph->setAutoFillBackground(true);
    ui->graph->setPalette(Pal);

//    IGraph<int> *p_digraph = new Digraph<int>();
//    const string str = "1 2  1 7  1 8  "
//                "2 3  2 6  2 10  "
//                "3 4  3 5  3 11  "
//                "6 10  6 12  "
//                "8 9  8 12  "
//                "9 10  9 11  "
//                "11 7  "
//                "12 5";
//    std::istringstream stm(str);
//    p_digraph->add_links(stm);
//    ui->graph->setGraph(p_digraph);

    connect(ui->actionLoad_graph, SIGNAL(triggered(bool)), this, SLOT(loadGraph()));
    connect(ui->actionLoad_position, SIGNAL(triggered(bool)), this, SLOT(loadPosition()));
    connect(ui->actionSave_position, SIGNAL(triggered(bool)), this, SLOT(savePosition()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadGraph() {
    QString filePath = QFileDialog::getOpenFileName(
                       this, tr("Open File"), "",
                       tr("Text (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile inputFile(filePath);
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           QString content = in.readAll();
           inputFile.close();
           string str = content.toStdString();
           std::istringstream stm(str);
           IGraph<int> *p_digraph = new Digraph<int>();
           p_digraph->add_links(stm);
           ui->graph->setGraph(p_digraph);
        }
    }
}

void MainWindow::saveGraph() {

}

void MainWindow::loadPosition() {
    QString filePath = QFileDialog::getOpenFileName(
                       this, tr("Open File"), "",
                       tr("Text (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile inputFile(filePath);
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           QString content = in.readAll();
           inputFile.close();
           string str = content.toStdString();
           std::istringstream stm(str);
           int id, x, y;
           map<int, Vertex2D> new_pos;
           while (stm >> id >> x >> y) {
             new_pos[id] = Vertex2D(x, y);
           }
           ui->graph->setPos(new_pos);
        }
    }
}

void MainWindow::savePosition() {
    QString filePath = QFileDialog::getOpenFileName(
                       this, tr("Open File"), "",
                       tr("Text (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile inputFile(filePath);
        if (inputFile.open(QIODevice::ReadOnly))
        {
           std::ostringstream stm;
//           auto path =  filePath.toStdString().c_str();
           const char* path =  filePath.toStdString().c_str();
           std::ofstream datFile(path, std::ofstream::out);
//           auto position = ui->graph->getPos();
           map<int, Vertex2D> position = ui->graph->getPos();
           for (std::map<int, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
           {
//             auto el = *it;
               pair<int, Vertex2D> el = *it;
             stm << el.first << " " << el.second.x << " " << el.second.y << " ";
           }
           string str = stm.str();
           datFile.write(str.c_str(), str.length());
           datFile.close();
        }
    }
}
