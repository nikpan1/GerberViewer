#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clickable_canvas = new clickableview(this);
    clickable_canvas->pointer = ui->pointer;
    clickable_canvas->x_text = ui->x_text;
    clickable_canvas->y_text = ui->y_text;
    ui->box->addWidget(clickable_canvas);
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

    clickable_canvas->pixmapItem = scene->addPixmap(_pixmap);

    clickable_canvas->setScene(scene);
    clickable_canvas->show();
    pixmap = _pixmap;
    clickable_canvas->scale = pixmap.size();
}



void MainWindow::on_ZoomIn_valueChanged(int value)
{    // Assuming pixmap_item is a QPixmap and pixmapItem is the QGraphicsPixmapItem
    if (clickable_canvas->pixmapItem) {
        // Update the scale of the pixmap

        auto new_pixmap = pixmap.scaled(clickable_canvas->scale * value / 100, Qt::KeepAspectRatio);

        // Set the scaled pixmap back to the QGraphicsPixmapItem
        clickable_canvas->pixmapItem->setPixmap(new_pixmap);
    }
}




void MainWindow::on_canvas_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
    is_current = true;
}




void MainWindow::on_x_text_textChanged()
{
    int x = ui->x_text->toPlainText().toInt();
    int y = ui->y_text->toPlainText().toInt();

    ui->pointer->move(x, y);
}



void MainWindow::on_y_text_textChanged()
{
    int x = ui->x_text->toPlainText().toInt();
    int y = ui->y_text->toPlainText().toInt();

    ui->pointer->move(x, y);
}



void MainWindow::on_addPosButton_clicked()
{
    // id
    ui->pos_table->setItem(pos_counter, 0, new QTableWidgetItem(QString("%1").arg(pos_counter)));
    // FeederType
    ui->pos_table->setItem(pos_counter, 1, new QTableWidgetItem(ui->feeder_text->toPlainText()));
    // XPos
    ui->pos_table->setItem(pos_counter, 2, new QTableWidgetItem(ui->x_text->toPlainText()));
    // YPos
    ui->pos_table->setItem(pos_counter, 3, new QTableWidgetItem(ui->y_text->toPlainText()));

    // is Zero
    if(ui->isZero->isChecked()) {
        ui->pos_table->setItem(pos_counter, 4, new QTableWidgetItem(QString("%1").arg(1)));
    }
    else {
        ui->pos_table->setItem(pos_counter, 4, new QTableWidgetItem(QString("%1").arg(1)));
    }

    if(ui->isHomography->isChecked()) {
        // is homo
        ui->pos_table->setItem(pos_counter, 5, new QTableWidgetItem(QString("%1").arg(1)));

    }
    else {
        // is homo
        ui->pos_table->setItem(pos_counter, 5, new QTableWidgetItem(QString("%1").arg(0)));
    }

    if(ui->isHomography->isChecked() || ui->isZero->isChecked()) {

        // XPos homo
        ui->pos_table->setItem(pos_counter, 6, new QTableWidgetItem(ui->x_text_homo->toPlainText()));
        // YPos homo
        ui->pos_table->setItem(pos_counter, 7, new QTableWidgetItem(ui->y_text_homo->toPlainText()));
    }
    else {
        // YPos homo
        ui->pos_table->setItem(pos_counter, 6, new QTableWidgetItem(QString("%1").arg(0)));
        // YPos homo
        ui->pos_table->setItem(pos_counter, 7, new QTableWidgetItem(QString("%1").arg(0)));
    }

    pos_counter ++;
    ui->pos_table->insertRow(pos_counter);
}

