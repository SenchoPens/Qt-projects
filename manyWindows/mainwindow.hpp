#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include "form.hpp"

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    int x;

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *ui;
    Form *startUi;

private slots:
    void increase();
};

#endif // MAINWINDOW_HPP
