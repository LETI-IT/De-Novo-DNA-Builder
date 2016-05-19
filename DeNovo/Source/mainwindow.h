#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphview.h"
#include "debrojingraphgenerator.h"
#include <QMessageBox>
#include "euleriancircuit.h"

namespace Ui {
class MainWindow;
}

/*
 * Base UI component of application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    vector<string> result;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadGraph();
    bool loadGraphFromFile();
    void saveGraph();
    void loadPosition();
    bool loadPositionFromFile();
    void savePosition();
    void loadFromKmers();
    void checkEuler();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
