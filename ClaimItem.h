#ifndef CLAIMITEM_H
#define CLAIMITEM_H

#include <QGraphicsPolygonItem>

class ClaimElement;
class QGraphicsTextItem;

class ClaimItem : public QGraphicsPolygonItem
{
public:
    ClaimItem(QGraphicsItem* parent = 0);

    void setClaimElement(ClaimElement* element);
    void setNext(ClaimItem* next);

private:
    QString formatElement(ClaimElement* element) const;

private:
    ClaimElement*       _element;
    QGraphicsTextItem*  _text;
    ClaimItem*          _next;
};

#endif // CLAIMITEM_H
