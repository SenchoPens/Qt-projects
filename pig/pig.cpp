#include "pig.hpp"

void Pig::generateXY() {
    x = width / 2;
    y = 800 - sizeY / 2;
    r = sizeY / 2;
    vx = 0;
    vy = 0;

    brakingK = 0.999;
    moveSpeed = 5;
}

Pig::Pig(QWidget *parent) : ControlFigure(parent) {
    sizeX = 100;
    sizeY = 75;
    generateXY();

    pigImage = new QImage("pig.png");
}

void Pig::paintEvent(QPaintEvent *event) {
    QPainter p(this);

    QRectF area = QRectF(x - (sizeX / 2), y - (sizeY / 2), sizeX, sizeY);
    p.drawImage(area, *pigImage);
}

void Pig::keyMove(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        vx -= moveSpeed;
        break;
    case Qt::Key_D:
        vx += moveSpeed;
        break;
    default:
        break;
    }
}
