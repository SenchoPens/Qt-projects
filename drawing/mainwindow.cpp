#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"

inline int sqr(int x) {
    return x * x;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    this->hide();
    ui->setupUi(this);
    start = new Start();
    start->show();
    start->loadRecord();
    qsrand(time(NULL));
    figureN = 20;
    playerN = 1;
    ui->gameOver->hide();

    balls.reserve(figureN);
    for (int i = 0; i < (figureN-1); i++)
        balls.append(new Figure(this));

    ctrlFigure = new ControlFigure(this);
    balls.append(ctrlFigure);

    connect(start->ui->newGameButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(start->ui->newGameButton, SIGNAL(clicked(bool)), start, SLOT(close()));
}



void MainWindow::increaseSecs() {
    ui->timeAliveTimer->display(QString::number(seconds++));
}

void MainWindow::startGame() {
    generateTimers();

    seconds = 1;
    connect(secondsTimer, SIGNAL(timeout()), this, SLOT(increaseSecs()));

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveFigures()));
    for (int i = 0; i < figureN; i++) {
        connect(drawTimer, SIGNAL(timeout()), balls.at(i), SLOT(update()));
    }
    this->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    ctrlFigure->keyMove(event);
}

void MainWindow::moveFigures() {
    for (int i = 0; i < figureN; i++) {
        for (int j = 0; j < figureN; j++) {
            if (i != j) {
                intersection(balls.at(i), balls.at(j));
            }
        }
        balls.at(i)->moveFigure();
    }
    for (int i = 0; i < figureN; i++) {
        checkHealth(i);
    }
    if (balls.length() == 1) {
        endOfGame("YOU WON!!!");
    }
}

void MainWindow::intersection(Figure *fig1, Figure *fig2) {
    if (fig1->isDead() || fig2->isDead())
        return;

    int x1 = fig1->getX();
    int x2 = fig2->getX();
    int y1 = fig1->getY();
    int y2 = fig2->getY();

    int r1 = fig1->getR();
    int r2 = fig2->getR();

    if (sqr(r1 + r2) >= sqr(x1 - x2) + sqr(y1 - y2)) {
        damage(fig1, fig2);
        fig1->intersect();
        fig2->intersect();
    }
}

void MainWindow::damage(Figure *fig1, Figure *fig2) {
    int h1 = 3 * sqr(fig1->getR());
    int h2 = 3 * sqr(fig2->getR());
    if (h1 < h2) {
        fig1->damage(5);
        fig2->heal(5);
    } else if (h2 > h1) {
        fig1->heal(5);
        fig2->damage(5);
    } else {
        int chance = qrand() % 2;
        fig1->health(chance * 4 - 2);
        fig2->health((1 - chance) * 4 - 2);
    }
}

void MainWindow::checkHealth(int figId) {
    Figure *fig = balls.at(figId);
    if (not fig->isDead())
        return;
    figureN -= 1;
    balls.remove(figId);
    if (fig==ctrlFigure) {
        ctrlFigure->hide();
        endOfGame("GAME OVER");
    } else {
        fig->deleteLater();
    }
}

void MainWindow::generateTimers() {
    moveTimer = new QTimer();
    moveTimer->start(10);

    drawTimer = new QTimer();
    drawTimer->start(20);

    secondsTimer = new QTimer();
    secondsTimer->start(1000);
}

void MainWindow::endOfGame(QString message) {
    ui->gameOver->setText(message);
    ui->gameOver->show();
    secondsTimer->stop();
    start->saveRecord(seconds);
    QTimer::singleShot(2000, this, SLOT(close()));
}

MainWindow::~MainWindow() {
    for (int i = 0; i < figureN; i++)
        balls[i]->deleteLater();

    delete ui;
}
