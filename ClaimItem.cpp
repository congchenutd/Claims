#include "ClaimElement.h"
#include "ClaimItem.h"

#include <QFont>
#include <QFontMetrics>
#include <QMetaProperty>

ClaimItem::ClaimItem(QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    _text = new QGraphicsTextItem(this);
    _next = 0;
}

void ClaimItem::setClaimElement(ClaimElement* element)
{
    _element = element;
    _text->setHtml(formatElement(element));
    _text->setFont(QFont("Arial", 18));

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

void ClaimItem::setNext(ClaimItem* next) {
    _next = next;
}

QString ClaimItem::formatElement(ClaimElement* element) const
{
    QString result;
    const QMetaObject* metaObj = element->metaObject();
    QString title = metaObj->className();
    result += "<H2>" + title + "</H2>";

    QStringList lines;
    int count = metaObj->propertyCount();
    for (int i = 0; i < count; ++i)
    {
        const char* propertyName = metaObj->property(i).name();
        QVariant value = element->property(propertyName);

        // skip objectName and pointers
        if (QString(propertyName) == "objectName" || value.type() == QVariant::UserType)
            continue;

        lines << QString(propertyName) + ": " + value.toString();
    }
    result += "<P>" + lines.join("<BR>") + "</P>";

    return result;
}
