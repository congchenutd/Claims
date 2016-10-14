#include "ClaimElement.h"
#include "ClaimItem.h"
#include "PropertyPrinter.h"
#include "MainWindow.h"
#include "LineItem.h"
#include "GraphicsScene.h"
#include <QFont>
#include <QFontMetrics>
#include <QDebug>

ClaimItem::ClaimItem(QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
{
    setFlags(QGraphicsItem::ItemIsMovable |
             QGraphicsItem::ItemIsSelectable |
             QGraphicsItem::ItemIsFocusable |
             QGraphicsItem::ItemSendsGeometryChanges);
    setBrush(Qt::white);
    _text = new QGraphicsTextItem(this);
    _next = 0;
}

void ClaimItem::setElement(ClaimElement* element)
{
    _element = element;

    _text->setHtml(PersistablePrinter().toHtml(element));
    _text->setFont(QFont("Arial", 14));

    // Set geometry of the polygon and text
    QRectF  rect    = _text->boundingRect();
    double  width   = rect.width();
    double  height  = rect.height();
    int     margin  = 10;
    double  left    = - width  / 2 - margin;
    double  top     = - height / 2 - margin;
    double  bottom  = height / 2 + margin;
    double  right1  = width  / 2;
    double  right2  = width * 0.6;

    QPolygonF polygon;
    polygon << QPointF(left,    top)
            << QPointF(right1,  top)
            << QPointF(right2,  0)
            << QPointF(right1,  bottom)
            << QPointF(left,    bottom)
            << QPointF(left,    top);
    setPolygon(polygon);

    _text->setPos(left + margin, top + margin);
}

ClaimElement* ClaimItem::getElement() const {
    return _element;
}

ClaimItem* ClaimItem::getNextItem() const {
    return _next;
}

void ClaimItem::setNextItem(ClaimItem* next)
{
    _next = next;
    getElement()->setNext(next->getElement());
}

void ClaimItem::addLineItem(LineItem* lineItem) {
    _lineItems << lineItem;
}

QVariant ClaimItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value)
{
    if (change == QGraphicsItem::ItemPositionChange)
    {
        foreach (LineItem* lineItem, _lineItems)
            lineItem->updatePosition();

//        QPointF pos = value.toPointF();
//        if (!scene()->sceneRect().contains(pos))
//        {
//            GraphicsScene* s = static_cast<GraphicsScene*>(scene());
//            s->setSceneRect(0, 0, s->itemsBoundingRect().width(), s->itemsBoundingRect().height());
//        }
//        qDebug() << value.toPoint() << scene()->sceneRect();
    }

    return value;
}
