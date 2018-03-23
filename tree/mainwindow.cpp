#include "mainwindow.hpp"
#include <QtWidgets>
#include <QFile>

void MainWindow::displayFiles() {
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(rootDirPath);
    ui->fileTree->setModel(fileModel);
    ui->fileTree->setRootIndex(fileModel->index(rootDirPath));
    for (int i = 1; i < fileModel->columnCount(); i++)
        ui->fileTree->hideColumn(i);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    displayFiles();
}

void MainWindow::on_fileTree_doubleClicked(const QModelIndex &index) {
    QString filePath = fileModel->fileInfo(index).absoluteFilePath();
    QFileInfo fileInfo = QFileInfo(filePath);
    if ((!fileInfo.isReadable()) or (fileInfo.isDir()))
        return;

    QFile *file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString fileContent = "";
    while (!file->atEnd()) {
        QString line = file->readLine();
        fileContent += line;
    }

    QLabel *page = new QLabel();
    page->setAlignment(Qt::AlignTop);
    page->setText(fileContent);
    int tabIndex = ui->fileTabs->addTab(page, fileInfo.fileName());
    ui->fileTabs->setCurrentIndex(tabIndex);
}
