#ifndef CLICKABLEVIEW_H
#define CLICKABLEVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QTextEdit>

class clickableview : public QGraphicsView
{
public:
    clickableview(QWidget* parent=0)
        : QGraphicsView(parent) {};
    QPixmap* _pixmap;
    QGraphicsPixmapItem* pixmapItem;
    QSize scale;

    QPushButton* pointer;

    QTextEdit* x_text, *y_text;

protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // CLICKABLEVIEW_H
