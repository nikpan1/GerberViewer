// mygraphicsview.h
#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>  // Include this header for QMouseEvent
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsView : public QGraphicsView
{
Q_OBJECT

public:
    MyGraphicsView(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // MYGRAPHICSVIEW_H
