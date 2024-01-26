#include "mainwindow.h"
#include "./ui_mainwindow.h"


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

void MainWindow::on_ImportButton_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Import Settings file:",
                                                    QDir::rootPath(), "CSV Files (*csv))");

    QFile mFile(filepath);
    QTextStream inFile(&mFile);

    int cter = 0;
    QString readedLine = inFile.readLine();
    QString listValue = readedLine.split(",");
    ui->tableWidget->setHorizontalHeaderLabels(listValue);


}

