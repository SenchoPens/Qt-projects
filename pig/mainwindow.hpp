#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QDebug>

#include "figure.h"
#include "pig.hpp"
#include "cloud.hpp"
#include "drop.hpp"

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
    uint nDrops;

    Ui::MainWindow *ui;
    Start *start;

    Cloud *cloud;
    Pig *pig;
    QList<Drop*> *drops;
    QImage *dropImage;

    QTimer *drawTimer;
    QTimer *moveTimer;
    QTimer *secondsTimer;
    QTimer *newDropTimer;

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *event);

    void startTimers();
    void startMenu();

    void generateFigures();
    void connectFigures();

    void generateDrop();
    void connectDrop(Drop *drop);

private slots:
    void endOfGame(QString message);
    void increaseSecs();
    void startGame();
    void moveFigures();
    void makeDrop();
};

#endif // MAINWINDOW_HPP
