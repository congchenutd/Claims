#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QWidget* parent = 0);

protected:
    void mousePressEvent    (QMouseEvent* event);
    void mouseReleaseEvent  (QMouseEvent* event);

protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // GRAPHICSVIEW_H
