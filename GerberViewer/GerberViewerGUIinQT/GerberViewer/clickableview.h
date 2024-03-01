#ifndef CLICKABLEVIEW_H
#define CLICKABLEVIEW_H

#include <QGraphicsView>

class clickableview : public QGraphicsView
{
public:
    clickableview(QWidget* parent=0)
        : QGraphicsView(parent) {};
};

#endif // CLICKABLEVIEW_H
