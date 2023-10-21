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
            startFilenameIndex = i;
            break;
        }
    }

    QString filename = QString::fromStdString(fn.substr(startFilenameIndex, fn.size() - 1));


    ui->textEditFilename->clear();
    ui->textEditFilename->setPlainText(filename);

    ui->textEditPreview->clear();
    ui->textEditPreview->setPlainText(fileContent);
}

