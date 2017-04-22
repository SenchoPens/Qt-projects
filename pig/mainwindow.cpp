#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    startMenu();

    // ToDo: remove hard-coded window size
    //ui->centralWidget->resize(width, height);
    width = 800;
    height = 800;
    ui->gameOver->hide();
    update();

    cloud = new Pig(this);

    drawTimer = new QTimer(this);
    moveTimer = new QTimer(this);
    secondsTimer = new QTimer(this);

    connect(drawTimer, SIGNAL(timeout()), cloud, SLOT(moveFigure()));
}

void MainWindow::startTimers() {
    drawTimer->start(20);
}

void MainWindow::startMenu() {
    this->hide();
    start = new Start(this);
    start->show();
    start->loadRecord();
    ui->gameOver->hide();
    connect(start->ui->newGameButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setPen(QPen(QColor(Qt::darkRed), 4));
    p.drawLine(0, height - 1, width, height - 1);
    p.setPen(QPen(QColor(Qt::darkGreen), 1));
    for (uint i = 0; i < width; ++i) {
        if (i % 4 == 0) {
            p.drawLine(i, height, i, height - 10);
        } else if (i % 2 == 0) {
            p.drawLine(i, height, i, height - 5);
        }
    }
}

void MainWindow::endOfGame(QString message) {
    ui->gameOver->setText(message);
    ui->gameOver->show();
    secondsTimer->stop();
    start->saveRecord(seconds);
    QTimer::singleShot(2000, this, SLOT(close()));
}

void MainWindow::startGame() {
    start->close();

    startTimers();

    seconds = 1;
    connect(secondsTimer, SIGNAL(timeout()), this, SLOT(increaseSecs()));

    //connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveFigures()));
    //for (int i = 0; i < figureN; i++) {
    //    connect(drawTimer, SIGNAL(timeout()), balls.at(i), SLOT(update()));
    //}
    this->show();
}

void MainWindow::increaseSecs() {
    ui->timeAliveTimer->display(QString::number(seconds++));
}
