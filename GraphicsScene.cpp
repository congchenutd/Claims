#include "ClaimElement.h"
#include "ClaimItem.h"
#include "ClaimItemDlg.h"
#include "GraphicsScene.h"
#include "MainWindow.h"

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QMetaObject>
#include <QDebug>

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{
}

void GraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
    QList<QGraphicsItem*> items = selectedItems();
    if (items.isEmpty())
        return;

    if (ClaimItem* item = static_cast<ClaimItem*>(items.front()))
    {
        QMenu menu;

        QList<ClaimElement*> nextElements = item->getElement()->createNextElements();
        foreach (ClaimElement* nextElement, nextElements)
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
