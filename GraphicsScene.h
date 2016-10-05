#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject* parent = 0);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);
};

#endif // GRAPHICSSCENE_H
