#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QObject>
#include "igraph.h"
#include "vertex2d.h"
#include <QMouseEvent>
#include <vector>
#include <map>
using namespace std;

class GraphView : public QWidget
{
    Q_OBJECT
private:
    const int CIRCLE_RAD = 10;
    int selectedIndex;
    IGraph<int> *graph;
    map<int, Vertex2D> position;
    bool isIntersect(QRect r, QPoint p);
public:
    explicit GraphView(QWidget *parent = 0);
    void setGraph(IGraph<int> *);
    void setPos(map<int, Vertex2D>);
    IGraph<int> * getGraph();
    map<int, Vertex2D> getPos();
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // GRAPHVIEW_H
