#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_HPP
