#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QObject>
#include "igraph.h"
#include "vertex2d.h"
#include <QMouseEvent>

class GraphView : public QWidget
{
    Q_OBJECT
private:
    const int CIRCLE_RAD = 10;
    int selectedIndex;
    QPoint p;
    IGraph<Vertex2D> *graph;
    void redraw();
    bool isIntersect(QRect r, QPoint p);
public:
    explicit GraphView(QWidget *parent = 0);
    void setGraph(IGraph<Vertex2D> *);
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // GRAPHVIEW_H
