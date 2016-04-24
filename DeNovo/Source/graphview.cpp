#include "graphview.h"
#include <QPainter>
#include <QBitmap>
#include <QDebug>

void GraphView::redraw()
{
//    AbstractIterator<Vertex2D>* it = this->graph->iterator();
//    while(it->hasNext()) {
//        Vertex2D element = it->next();
//        QPainter painter(this);
//        painter.setPen(QPen(Qt::color1, 2));
//        painter.drawEllipse(QRect(10, 10, 380, 380));
//        painter.end();
//    }

    update();
}

GraphView::GraphView(QWidget *parent) : QWidget(parent)
{
    selectedIndex = -1;
    redraw();
}

void GraphView::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
//    painter.setPen(QPen(Qt::color1, 2));
//    painter.drawEllipse(p, CIRCLE_RAD, CIRCLE_RAD);
//    painter.end();
    if (graph == NULL)
        return;
    QPainter painter(this);
    painter.setPen(QPen(Qt::color1, 2));
    AbstractIterator<Vertex2D>* it = this->graph->iterator();
    int i = 0;
    while(it->hasNext()) {
        Vertex2D el = it->next();
        QPoint nextPoint;
        if (selectedIndex == i) {
            // TODO: Remove it when iterator starts to support indexing
            nextPoint = p;
        } else {
            nextPoint = QPoint(el.x, el.y);
        }
        painter.drawEllipse(nextPoint, CIRCLE_RAD, CIRCLE_RAD);
        i++;
    }
    painter.end();
}

void GraphView::setGraph(IGraph<Vertex2D> *igraph)
{
    this->graph = igraph;
    p = QPoint(10, 10);
    selectedIndex = -1;
    redraw();
}

void GraphView::mouseMoveEvent(QMouseEvent *event)
{
//    if (selectedIndex != -1) {
//        int i = 0;
//        AbstractIterator<Vertex2D>* it = this->graph->iterator();
//        while(it->hasNext()) {
//            Vertex2D el = it->next();
//            if (selectedIndex == i) {
//                QPointF pf = event->localPos();
//                // TODO: Change position of el
//                return;
//            }
//            i++;
//        }
//    }
    if (selectedIndex != -1) {
        QPointF pf = event->localPos();
        p = QPoint(pf.x(), pf.y());
        redraw();
    }
}

void GraphView::mousePressEvent(QMouseEvent *event)
{
    QPointF pf = event->localPos();
    QPoint pos = QPoint(pf.x(), pf.y());

    AbstractIterator<Vertex2D>* it = this->graph->iterator();
    int i = 0;
    while(it->hasNext()) {
        Vertex2D el = it->next();
        QPoint left = QPoint(p.x() - CIRCLE_RAD, p.y() - CIRCLE_RAD);
        QSize size = QSize(2 * CIRCLE_RAD, 2 * CIRCLE_RAD);
        QRect r = QRect(left, size);
        if (this->isIntersect(r, pos))
        {
            selectedIndex = i;
            return;
        }
        i++;
    }
}

void GraphView::mouseReleaseEvent(QMouseEvent *)
{
    selectedIndex = -1;
}

bool GraphView::isIntersect(QRect r, QPoint p)
{
    return p.x()>=r.topLeft().x() && p.y()>=r.topLeft().y()
            && p.x()<=r.bottomRight().x() && p.y()<=r.bottomRight().y();
}

