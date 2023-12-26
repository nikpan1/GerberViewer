#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenFileButton_clicked()
{
    QString fileContent;

    QString filePath= QFileDialog::getOpenFileName(this, "Choose File");


    if(filePath.isEmpty())
        return;

    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream in(&file);

    fileContent = in.readAll();

    file.close();


    std::string fn = filePath.toStdString();

    int startFilenameIndex = 0;
    for(int i = fn.size() - 1; i >= 0; i --) {
        if(fn[i] == '/') {
            startFilenameIndex = i + 1;
            break;
        }
    }

    QString filename = QString::fromStdString(fn.substr(startFilenameIndex, fn.size() - 1));


    ui->textEditFilename->clear();
    ui->textEditFilename->setPlainText(filename);

    ui->textEditPreview->clear();
    ui->textEditPreview->setPlainText(fileContent);



    // Create a scene and a view
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(scene, this);
    QGraphicsRectItem *rectangle1= scene->addRect(125, 25, 100, 100);
    QGraphicsRectItem *rectangle2 = scene->addRect(0, 25, 100, 100);
    ui->canvas->setScene(scene);

    // Create a QPainter object
    QPainter painter(ui->canvas);

    // Set the color and style for the rectangle
    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(Qt::blue));

    // Draw a rectangle using the QPainter object
    QRect rect(50, 50, 100, 75);
    painter.drawRect(rect);
}

