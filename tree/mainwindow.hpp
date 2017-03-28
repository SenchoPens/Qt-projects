#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QDir>
#include "ui_mainwindow.h"
#include <QFileSystemModel>

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    const QString rootDirPath = "/home/sencho/projects/Qt/tree/example_root_directory/";

    Ui::MainWindow *ui;
    QFileSystemModel *fileModel;

    void displayFiles();

public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void on_fileTree_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_HPP
