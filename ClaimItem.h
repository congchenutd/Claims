#ifndef CLAIMITEM_H
#define CLAIMITEM_H

#include <QGraphicsPolygonItem>

class ClaimElement;
class LineItem;

class ClaimItem : public QGraphicsPolygonItem
{
public:
    ClaimItem(QGraphicsItem* parent = 0);

    ClaimElement* getElement() const;
    void setElement(ClaimElement* element);

    ClaimItem* getNextItem() const;
    void setNextItem(ClaimItem* next);

    void addLineItem(LineItem* lineItem);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);

private:
    ClaimElement*       _element;
    QGraphicsTextItem*  _text;
    ClaimItem*          _next;
    QList<LineItem*>    _lineItems;
};

#endif // CLAIMITEM_H
