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
    const int CIRCLE_RAD = 20;
    const int ARROW_RAD = 8;
    string selectedIndex;
    IGraph<string> *graph;
    map<string, Vertex2D> position;
    bool isIntersect(QRect r, QPoint p);
    QPoint getArrowCenter(QPoint begin, QPoint end);
public:
    explicit GraphView(QWidget *parent = 0);
    void setGraph(IGraph<string> *);
    void setPos(map<string, Vertex2D>);
    IGraph<string> * getGraph();
    map<string, Vertex2D> getPos();
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // GRAPHVIEW_H
