#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include "figure.hpp"

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    Figure *cloud;

    void generateGrass();
};

#endif // MAINWINDOW_HPP
