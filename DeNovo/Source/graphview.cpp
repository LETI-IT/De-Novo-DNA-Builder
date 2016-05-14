#include "graphview.h"
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include "vertex.h"

GraphView::GraphView(QWidget *parent) : QWidget(parent)
{
    selectedIndex = "";
}

void GraphView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

    for (std::map<string, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
    {
        auto left = *it;
        for (std::map<string, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
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
    for (std::map<string, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it)
    {
      auto el = *it;
      Vertex2D value = el.second;
      QPoint p = QPoint(value.x, value.y);
      painter.drawEllipse(p, CIRCLE_RAD, CIRCLE_RAD);
    }
    painter.end();
}

void GraphView::setGraph(IGraph<string> *igraph)
{
    position.clear();
    this->graph = igraph;
    selectedIndex = "";

    for(AbstractIterator<string> *it = graph->begin(VERTEX); **it != **graph->end(VERTEX); ++*it) {
        Vertex<string>& el = dynamic_cast<Vertex<string>&>(const_cast<AbstractComponent<string>&>(**it));
        string id = el.getValue();
        position[id] = Vertex2D(CIRCLE_RAD, CIRCLE_RAD);
    }

    update();
}

void GraphView::setPos(map<string, Vertex2D> new_pos) {
    this->position = new_pos;
    update();
}

IGraph<string>* GraphView::getGraph() {
    return graph;
}

map<string, Vertex2D> GraphView::getPos() {
    return position;
}

void GraphView::mouseMoveEvent(QMouseEvent *event)
{
    if (selectedIndex != "") {
        QPointF pf = event->localPos();
        position[selectedIndex] = Vertex2D(pf.x(), pf.y());
        update();
    }
}

void GraphView::mousePressEvent(QMouseEvent *event)
{
    QPointF pf = event->localPos();
    QPoint pos = QPoint(pf.x(), pf.y());
    for (std::map<string, Vertex2D>::iterator it = position.begin(); it != position.end(); ++it) {
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

