#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include "cloud.hpp"
#include "figure.h"
#include "ui_mainwindow.h"
#include "start.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    uint width;
    uint height;
    uint seconds;
    Ui::MainWindow *ui;
    Pig *cloud;
    QTimer *drawTimer;
    QTimer *moveTimer;
    QTimer *secondsTimer;
    Start *start;

    virtual void paintEvent(QPaintEvent *event);
    void startTimers();
    void startMenu();

private slots:
    void endOfGame(QString message);
    //void moveFigures();
    void increaseSecs();
    void startGame();
};

#endif // MAINWINDOW_HPP
