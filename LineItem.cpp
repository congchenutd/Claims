#include "ClaimItem.h"
#include "LineItem.h"

LineItem::LineItem(QGraphicsItem* parent)
    : QGraphicsLineItem(parent)
{
    setZValue(-100);
}

void LineItem::setEnds(ClaimItem* start, ClaimItem* end)
{
    _start  = start;
    _end    = end;
    _start  ->addLineItem(this);
    _end    ->addLineItem(this);
    updatePosition();
}

void LineItem::updatePosition()
{
    QLineF line(mapFromItem(_start, 0, 0), mapFromItem(_end, 0, 0));
    setLine(line);
}
