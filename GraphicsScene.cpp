#include "ClaimElement.h"
#include "ClaimItem.h"
#include "ClaimItemDlg.h"
#include "GraphicsScene.h"
#include "LineItem.h"
#include "MainWindow.h"

#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QMetaObject>
#include <QDebug>

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{
    _rect = new QGraphicsRectItem;
    addItem(_rect);
}

void GraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
    if (ClaimItem* item = getSelectedItem())
    {
        QMenu menu;

        QAction* actionEdit = new QAction(tr("Edit"));
        actionEdit->setData(QVariant::fromValue(item->getElement()));
        connect(actionEdit, SIGNAL(triggered()), MainWindow::getInstance(), SLOT(onEditItem()));
        menu.addAction(actionEdit);

        if (ClaimElement* nextElement = item->getElement()->createNextElement())
        {
            QString elementName = nextElement->getDisplayName();
            QAction* action = new QAction(tr("Add %1").arg(elementName));
            action->setData(QVariant::fromValue(nextElement));
            connect(action, SIGNAL(triggered()), MainWindow::getInstance(), SLOT(onAddNextElement()));
            menu.addAction(action);
        }

        QList<ClaimElement*> supportingElements = item->getElement()->createSupportingElements();
        foreach (ClaimElement* supportingElement, supportingElements)
        {
            QString elementName = supportingElement->getDisplayName();
            QAction* action = new QAction(tr("Add %1").arg(elementName));
            action->setData(QVariant::fromValue(supportingElement));
            connect(action, SIGNAL(triggered()), MainWindow::getInstance(), SLOT(onAddSupportingElement()));
            menu.addAction(action);
        }

        menu.exec(event->screenPos());
    }
}

ClaimItem* GraphicsScene::getSelectedItem() const
{
    QList<QGraphicsItem*> items = selectedItems();
    if (items.isEmpty())
        return 0;
    return static_cast<ClaimItem*>(items.front());
}

void GraphicsScene::connectItems(ClaimItem* item, ClaimItem* nextItem)
{
    LineItem* lineItem = new LineItem;
    lineItem->setEnds(item, nextItem);
    addItem(lineItem);
}

void GraphicsScene::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
    QGraphicsScene::setSceneRect(x, y, w, h);
    _rect->setRect(sceneRect());
}

void GraphicsScene::updateSceneRect() {
    setSceneRect(0, 0, itemsBoundingRect().width(), itemsBoundingRect().height());
}
