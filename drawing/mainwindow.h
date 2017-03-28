#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "figure.h"
#include "controlfigure.hpp"
#include "start.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Start *start;
    QTimer *moveTimer;
    QTimer *drawTimer;
    QTimer *secondsTimer;
    ControlFigure *ctrlFigure;
    QVector<Figure*> balls;
    QVector<ControlFigure*> players;
    int figureN;
    int seconds;
    int playerN;

    virtual void keyPressEvent(QKeyEvent *event);
    void intersection(Figure *fig1, Figure *fig2);
    void damage(Figure *fig1, Figure *fig2);
    void checkHealth(int figId);
    void generateTimers();

private slots:
    void endOfGame(QString message);
    void moveFigures();
    void increaseSecs();
    void startGame();
};

#endif //MAINWINDOW_H
