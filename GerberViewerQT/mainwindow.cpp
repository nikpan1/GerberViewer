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

