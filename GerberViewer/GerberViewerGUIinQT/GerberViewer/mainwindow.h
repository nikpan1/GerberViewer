#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QString>
#include <QStringList>
#include <QFileDialog>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>

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

    QGraphicsScene* scene;

private slots:
    void on_ImportButton_clicked();

    void on_LoadGerberFile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
