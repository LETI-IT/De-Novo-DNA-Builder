#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include "digraph.h"
#include <QFileDialog>
#include <QTextStream>
#include <QStringList>
#include <fstream>
#include <QDebug>

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
    connect(ui->actionImport_kmers, SIGNAL(triggered(bool)), this, SLOT(loadFromKmers()));
    connect(ui->actionFind_Euler_Path, SIGNAL(triggered(bool)), this, SLOT(checkEuler()));
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

           IGraph<string> *p_digraph = new Digraph<string>();
//           while (!in.atEnd()) {
               auto line = in.readAll();
               qDebug() << line;
               QRegExp rx("(\\ |\\n|\\n\r)");
               auto items = line.split(rx);
               for (int i = 0; i < items.size(); i=i+2) {
                   auto first = items[i];
                   auto second = items[i+1];
                   p_digraph->add_link(items[i].toStdString(), items[i+1].toStdString());
               }
//           }
           ui->graph->setGraph(p_digraph);
           inputFile.close();
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
           inputFile.close();
           string id;
           int x, y;
           map<string, Vertex2D> new_pos;
           while (!in.atEnd()) {
               auto line = in.readLine();
               auto items = line.split(" ");
               for (int i = 0; i < items.size(); i=i+3) {
                   id = items[i].toStdString();
                   x = items[i+1].toInt();
                   y = items[i+2].toInt();
                   new_pos[id] = Vertex2D(x, y);
               }
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
           map<string, Vertex2D> position = ui->graph->getPos();
           for (std::map<string, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
           {
//             auto el = *it;
               pair<string, Vertex2D> el = *it;
             stm << el.first << " " << el.second.x << " " << el.second.y << " ";
           }
           string str = stm.str();
           datFile.write(str.c_str(), str.length());
           datFile.close();
        }
    }
}

void MainWindow::loadFromKmers() {
    QString filePath = QFileDialog::getOpenFileName(
                       this, tr("Open File"), "",
                       tr("Text (*.txt)"));

    if (filePath.isEmpty())
        return;

    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       QString content = in.readAll();
       inputFile.close();
       string str = content.toStdString();
       std::istringstream stm(str);
       try {
            IGraph<string> *p_digraph = DeBrojinGraphGenerator::generate(stm);
            //TODO: for string graph or generic
            ui->graph->setGraph(p_digraph);
       } catch (DeBrujnGraphException& e) {
           QMessageBox messageBox;
           messageBox.critical(0, "Error", e.what());
           messageBox.setFixedSize(500, 200);
       }

    }

}

void MainWindow::checkEuler() {
    Digraph<string>* graph = dynamic_cast<Digraph<string>*>(ui->graph->getGraph());
    vector<string> euCycle = EulerianCercuit::getEulerianCircuitVerticies(graph);
    cout << "Eulerian cycle: ";
    for (typename vector<string>::iterator it = euCycle.begin(); it != euCycle.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
