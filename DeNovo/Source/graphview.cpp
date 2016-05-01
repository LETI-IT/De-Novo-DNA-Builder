#include "graphview.h"
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include "vertex.h"

GraphView::GraphView(QWidget *parent) : QWidget(parent)
{
    selectedIndex = -1;
}

void GraphView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

    for (std::map<int, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
    {
        auto left = *it;
        for (std::map<int, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
        {
          auto right = *it;
          if (graph->is_linked(left.first, right.first)) {
            auto lPoint = QPoint(left.second.x, left.second.y);
            auto rPoint = QPoint(right.second.x, right.second.y);
            painter.drawLine(lPoint, rPoint);
          }
        }
    }

    painter.setPen(QPen(Qt::yellow, 2));
    for (std::map<int, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
    {
      auto el = *it;
      Vertex2D value = el.second;
      QPoint p = QPoint(value.x, value.y);
      painter.drawEllipse(p, CIRCLE_RAD, CIRCLE_RAD);
    }
    painter.end();
}

void GraphView::setGraph(IGraph<int> *igraph)
{
    position.clear();
    this->graph = igraph;
    selectedIndex = -1;

    for(AbstractIterator<int> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it) {
        Vertex<int>& el = dynamic_cast<Vertex<int>&>(const_cast<AbstractComponent<int>&>(**it));
        int id = el.getValue();
        position[id] = Vertex2D(CIRCLE_RAD, CIRCLE_RAD);
    }

    update();
}

void GraphView::setPos(map<int, Vertex2D> new_pos) {
    this->position = new_pos;
    update();
}

IGraph<int>* GraphView::getGraph() {
    return graph;
}

map<int, Vertex2D> GraphView::getPos() {
    return position;
}

void GraphView::mouseMoveEvent(QMouseEvent *event)
{
    if (selectedIndex != -1) {
        QPointF pf = event->localPos();
        position[selectedIndex] = Vertex2D(pf.x(), pf.y());
        update();
    }
}

void GraphView::mousePressEvent(QMouseEvent *event)
{
    QPointF pf = event->localPos();
    QPoint pos = QPoint(pf.x(), pf.y());
    for (std::map<int, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it) {
        auto el = *it;
        Vertex2D p = el.second;
        QPoint left = QPoint(p.x - CIRCLE_RAD, p.y - CIRCLE_RAD);
        QSize size = QSize(2 * CIRCLE_RAD, 2 * CIRCLE_RAD);
        QRect r = QRect(left, size);
        if (this->isIntersect(r, pos))
        {
            selectedIndex = el.first;
            return;
        }
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

