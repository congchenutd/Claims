#ifndef LINEITEM_H
#define LINEITEM_H

#include <QGraphicsLineItem>

class ClaimItem;

class LineItem : public QGraphicsLineItem
{
public:
    LineItem(QGraphicsItem* parent = 0);

    void setEnds(ClaimItem* start, ClaimItem* end);
    void updatePosition();

private:
    ClaimItem* _start;
    ClaimItem* _end;
};

#endif // LINEITEM_H
