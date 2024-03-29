#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QString>
#include <QStringList>
#include <QFileDialog>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "clickableview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    clickableview* clickable_canvas;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* pixmap_item;
    QPixmap pixmap;
    QSize scale;
    bool is_current;
    QPushButton* button;

    int pos_counter = 0;

    int zero_x = 0, zero_y = 0;

private slots:
    void on_ImportButton_clicked();

    void on_LoadGerberFile_clicked();

    void on_ZoomIn_valueChanged(int value);

    void on_canvas_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_x_text_textChanged();

    void on_y_text_textChanged();

    void on_addPosButton_clicked();

    void on_generate_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
