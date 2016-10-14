#include "GraphicsScene.h"
#include "GraphicsView.h"
#include <QGraphicsScene>
#include <QDebug>

GraphicsView::GraphicsView(QWidget* parent)
    : QGraphicsView (parent)
{
}

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
    QGraphicsView::mousePressEvent(event);

//    GraphicsScene* s = static_cast<GraphicsScene*>(scene());
//    if (s->getSelectedItem() == 0)
//    {
//        setDragMode(QGraphicsView::ScrollHandDrag);
//    }
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
    QGraphicsView::mouseReleaseEvent(event);
//    GraphicsScene* s = static_cast<GraphicsScene*>(scene());
//    if (s->getSelectedItem() == 0)
//    {
//        setDragMode(QGraphicsView::NoDrag);
//    }
}

void GraphicsView::resizeEvent(QResizeEvent* event)
{
//    fitInView(scene()->itemsBoundingRect(), Qt::KeepAspectRatio);

//    scene()->setSceneRect(scene()->itemsBoundingRect());

    QGraphicsView::resizeEvent(event);
}
