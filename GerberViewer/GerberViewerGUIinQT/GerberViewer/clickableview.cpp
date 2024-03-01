#include "clickableview.h"

void clickableview::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Map the mouse click position to the scene coordinates
        QPointF scenePos = mapToScene(event->pos());

        // Assuming you have a QGraphicsPixmapItem named 'pixmapItem'
        if (pixmapItem)
        {
            // Map the scene coordinates to the item (pixmap) coordinates
            QPointF itemPos = pixmapItem->mapFromScene(scenePos);

            // Format the output string
            QString output = QString("Clicked at scene position: %1, %2").arg(scenePos.x()).arg(scenePos.y());
            pointer->move(event->pos().x(), event->pos().y());
            x_text->setText(QString("%1").arg(scenePos.x()));
            y_text->setText(QString("%1").arg(scenePos.y()));

        }
    }

    // Call the base class implementation
    QGraphicsView::mousePressEvent(event);
}
