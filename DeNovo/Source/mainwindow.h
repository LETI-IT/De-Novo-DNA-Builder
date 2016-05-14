#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphview.h"
#include "debrojingraphgenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadGraph();
    void saveGraph();
    void loadPosition();
    void savePosition();
    void loadFromKmers();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
