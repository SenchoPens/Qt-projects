#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setupUi(this);

    x = 300;
    y = 300;
    r = 30;
    k = 0;

    connect(this->circle, SIGNAL(clicked(bool)), this, SLOT(drawCircle()));
    connect(this->square, SIGNAL(clicked(bool)), this, SLOT(drawSquare()));
    connect(this->triangle, SIGNAL(clicked(bool)), this, SLOT(drawTriangle()));
}
void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(p.Antialiasing);
    int a = 0;
    p.setPen(QPen(QColor(a, a, a), 1, Qt::SolidLine));
    switch(k) {
    case 0:
        p.drawEllipse(QPoint(x, y), r, r);
        break;
    case 1:
        p.drawLine(x, y, x + r, y);
        p.drawLine(x + r, y, x + r, y + r);
        p.drawLine(x + r, y + r, x, y + r);
        p.drawLine(x, y + r, x, y);
        break;
    case 2:
        p.drawLine(x, y, x + r, y);
        p.drawLine(x, y, x + r / 2, y + r);
        p.drawLine(x + r / 2, y + r, x + r, y);
        break;
    default:
        break;
    }
}
void MainWindow::drawCircle() {
    qDebug() << "drawing circle";
    k = 0;
    update();
}

void MainWindow::drawSquare() {
    qDebug() << "drawing square";
    k = 1;
    update();
}

void MainWindow::drawTriangle() {
    qDebug() << "drawing triangle";
    k = 2;
    update();
}
