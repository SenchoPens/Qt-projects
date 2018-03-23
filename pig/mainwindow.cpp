    #include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    qDebug() << "START";
    ui->setupUi(this);
    startMenu();

    drops = new QList<Drop*>;

    // ToDo: remove hard-coded window size
    //ui->centralWidget->resize(width, height);
    width = 800;
    height = 800;
    nDrops = 20;

    ui->gameOver->hide();
    update();

    dropImage = new QImage("drop.png");
    generateFigures();

    drawTimer = new QTimer(this);
    moveTimer = new QTimer(this);
    secondsTimer = new QTimer(this);
    newDropTimer = new QTimer(this);

    connect(drawTimer, SIGNAL(timeout()), pig, SLOT(moveFigure()));
}

void MainWindow::startTimers() {
    drawTimer->start(20);
    moveTimer->start(1000);
    secondsTimer->start(1000);
    newDropTimer->start(2000);
}

void MainWindow::moveFigures() {
    pig->moveFigure();
    cloud->moveFigure();

    QList<Drop*>::iterator i;
    for (i = drops->begin(); i != drops->end(); i++) {
        (*i)->moveFigure();
    }
    makeDrop();
}

void MainWindow::makeDrop() {
    qDebug() << "making a drop";
    if (drops->length() == nDrops) {
        qDebug() << "removing a drop";
        drops->removeLast();
    }
    generateDrop();
    qDebug() << drops->length();
    update();
}

void MainWindow::generateFigures() {
    qDebug() << "Generating Figures...";
    pig = new Pig(this);
    cloud = new Cloud(this);
    qDebug() << "Generating drops!";
    generateDrop();
}

void MainWindow::connectFigures() {
    qDebug() << "Connecting Figures...";
    connect(drawTimer, SIGNAL(timeout()), pig, SLOT(update()));
    connect(drawTimer, SIGNAL(timeout()), cloud, SLOT(update()));

    //connectDrop(drops->first());
}

void MainWindow::generateDrop() {
    qsrand(time(NULL));
    Drop *drop = new Drop(qrand() % 800, 400, dropImage, this);
    qDebug() << "made a drop";
    drops->append(drop);
}

void MainWindow::connectDrop(Drop *drop) {
    connect(drawTimer, SIGNAL(timeout()), drop, SLOT(update()));
    qDebug() << "connected a drop";
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
    qDebug() << "Ending the game.";
    ui->gameOver->setText(message);
    ui->gameOver->show();
    secondsTimer->stop();
    start->saveRecord(seconds);
    QTimer::singleShot(2000, this, SLOT(close()));
}

void MainWindow::startGame() {
    qDebug() << "Starting the game...";
    start->close();

    startTimers();

    seconds = 1;

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveFigures()));
    connect(secondsTimer, SIGNAL(timeout()), this, SLOT(increaseSecs()));

    connectFigures();
    makeDrop();
    //connect(newDropTimer, SIGNAL(timeout()), this, SLOT(makeDrop()));

    this->show();
}

void MainWindow::startMenu() {
    qDebug() << "Showing start menu...";
    this->hide();
    start = new Start();
    start->show();
    start->loadRecord();
    ui->gameOver->hide();
    connect(start->ui->newGameButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
}

void MainWindow::increaseSecs() {
    ui->timeAliveTimer->display(QString::number(seconds++));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    pig->keyMove(event);
}
