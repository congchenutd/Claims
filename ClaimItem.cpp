#include "ClaimElement.h"
#include "ClaimItem.h"

#include <QMetaProperty>

ClaimItem::ClaimItem(QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
{
    QPolygonF polygon;
    polygon << QPointF(-100,  50)
            << QPointF( 100,  50)
            << QPointF( 150,  0)
            << QPointF( 100, -50)
            << QPointF(-100, -50)
            << QPointF(-100,  50);
    setPolygon(polygon);

    _text = new QGraphicsTextItem(this);
    _text->setPos(-100, -50);
    _next = 0;
}

void ClaimItem::setClaimElement(ClaimElement* element)
{
    _element = element;

    QStringList lines;
    const QMetaObject* metaObj = element->metaObject();
    lines << QString(metaObj->className()) + "\n";

    int count = metaObj->propertyCount();
    for (int i = 0; i < count; ++i)
    {
        const char* propertyName = metaObj->property(i).name();
        QVariant value = element->property(propertyName);
        if (QString(propertyName) == "objectName")
            continue;
        if (value.type() == QMetaType::QString || value.type() == QMetaType::Double || value.type() == QMetaType::QDate)
            lines << QString(propertyName) + ": " + value.toString();
    }
    _text->setPlainText(lines.join("\n"));
}

void ClaimItem::setNext(ClaimItem* next) {
    _next = next;
}
