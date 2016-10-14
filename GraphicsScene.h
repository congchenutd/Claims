#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class ClaimItem;

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject* parent = 0);
    ClaimItem* getSelectedItem() const;

    void connectItems(ClaimItem* item, ClaimItem* nextItem);

    void setSceneRect(qreal x, qreal y, qreal w, qreal h);
    void updateSceneRect();

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);

private:
    QGraphicsRectItem* _rect;
};

#endif // GRAPHICSSCENE_H
