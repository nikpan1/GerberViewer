#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new clickableview(this);
    ui->box->addWidget(canvas);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ImportButton_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Import Settings file:",
                                                    QDir::rootPath(), "CSV Files (*.csv)");

    QFile mFile(filepath);

    if(!mFile.open(QFile::Text | QFile::ReadOnly)) {
        return;
    }

    QTextStream inFile(&mFile);

    int cter = 0;
    QString readedLine = inFile.readLine();
    QStringList listValue = readedLine.split(",");

    ui->FeederTable->setColumnCount(listValue.size());
    ui->FeederTable->setHorizontalHeaderLabels(listValue);

    while(!inFile.atEnd()) {
        QString readedLine = inFile.readLine();
        QStringList listValue = readedLine.split(",");

        cter += 1;
        ui->FeederTable->setRowCount(cter);

        for(int k = 0; k < listValue.size(); k ++ ) {
            ui->FeederTable->setItem(cter - 1, k, new QTableWidgetItem(listValue[k]));
        }

        mFile.flush();
        mFile.close();
    }
}


void MainWindow::on_LoadGerberFile_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Import Gerber data files:",
                                                    QDir::rootPath(), "GB Files (*.bot)");

    QFile mFile(filepath);

    if(!mFile.open(QFile::Text | QFile::ReadOnly)) {
        return;
    }

    mFile.flush();
    mFile.close();

    //view = new QGraphicsView(scene);

    filepath[filepath.size() - 1] = 'g';
    filepath[filepath.size() - 2] = 'n';
    filepath[filepath.size() - 3] = 'p';

    QPixmap _pixmap(filepath);

    if(_pixmap.isNull()) {
        qWarning("File not found");
        return;
    }
    scene=new QGraphicsScene();
    pixmap_item = scene->addPixmap(_pixmap);

    canvas->setScene(scene);
    canvas->show();
    pixmap = _pixmap;
    scale = pixmap.size();
}


void MainWindow::on_ZoomIn_valueChanged(int value)
{    // Assuming pixmap_item is a QPixmap and pixmapItem is the QGraphicsPixmapItem
    if (pixmap_item) {
        // Update the scale of the pixmap

        auto new_pixmap = pixmap.scaled(scale * value / 100, Qt::KeepAspectRatio);

        // Set the scaled pixmap back to the QGraphicsPixmapItem

        pixmap_item->setPixmap(new_pixmap);
    }
}



