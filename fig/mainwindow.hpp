#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QPainter>
#include <QDebug>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);

private:
    int k;
    int x;
    int y;
    int r;

private slots:
    void drawCircle();
    void drawSquare();
    void drawTriangle();
};

#endif // MAINWINDOW_HPP
