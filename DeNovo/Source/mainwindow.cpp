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

    if (!loadGraphFromFile()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Возникла ошибка при считывании из файла");
        messageBox.setFixedSize(500, 200);
    }
}

bool MainWindow::loadGraphFromFile() {
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
               if (items.size() % 2 != 0)
                   return false;
               for (int i = 0; i < items.size(); i=i+2) {
                   auto first = items[i].toStdString();
                   auto second = items[i+1].toStdString();
                   if (first.size() == 0 || second.size() == 0)
                       return false;
                   p_digraph->add_link(first, second);
               }
//           }
           ui->graph->setGraph(p_digraph);
           inputFile.close();
           return true;
        }
    }

    return false;
}

void MainWindow::saveGraph() {

}

void MainWindow::loadPosition() {
   if (!loadPositionFromFile()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Возникла ошибка при записи в файл");
        messageBox.setFixedSize(500, 200);
   }
}

bool MainWindow::loadPositionFromFile()
{
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
               QRegExp rx("(\\ |\\n|\\n\r)");
               auto items = line.split(rx);
               if (items.size() % 3 != 0)
                   return false;
               for (int i = 0; i < items.size(); i=i+3) {
                   bool flag = false;
                   id = items[i].toStdString();
                   if (id.size() == 0)
                       return false;
                   x = items[i+1].toInt(&flag, 10);
                   if (!flag || x < 0 || x > ui->graph->width()) {
                        return false;
                   }
                   y = items[i+2].toInt(&flag, 10);
                   if (!flag || y < 0 || y > ui->graph->height()) {
                        return false;
                   }
                   new_pos[id] = Vertex2D(x, y);
               }
           }

           ui->graph->setPos(new_pos);
           return true;
        }
    }

    return false;
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
           return;
        }
    }

    QMessageBox messageBox;
    messageBox.critical(0, "Error", "Возникла ошибка при записи в файл");
    messageBox.setFixedSize(500, 200);
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
    if (EulerianCercuit::isEulerian(graph)) {
        vector<string> euCycle = EulerianCercuit::getEulerianCircuitVerticies(graph);
        QString result = QString();
        for (typename vector<string>::iterator it = euCycle.begin(); it != euCycle.end(); ++it) {
            result = result.append(QString::fromStdString(*it)).append(" -> ");
        }

        QMessageBox messageBox;
        messageBox.setWindowTitle("Эйлеров цикл найден");
        messageBox.setText(result);
        messageBox.setFixedSize(500, 200);
    } else {
        QMessageBox messageBox;
        messageBox.critical(0, "Эйлеров цикл не найден", "");
        messageBox.setFixedSize(500, 200);
    }
}
