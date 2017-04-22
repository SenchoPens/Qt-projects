#include "cloud.hpp"

void Pig::generateXY() {
    x = width / 2;
    y = 800 - sizeY / 2;
    vy = 0;
    vx = (qrand() % 2 - 1) * moveSpeed;
}

Pig::Pig(QWidget *parent) : ControlFigure(parent) {
    sizeX = 100;
    sizeY = 75;
    generateXY();
    r = sizeY;

    area = new QRectF(x - (sizeX / 2), y - (sizeY / 2), sizeX, sizeY);
    pigImage = new QImage("pig.png");
    update();
}

void Pig::paintEvent(QPaintEvent *event) {
    QPainter p(this);

    p.drawImage(*area, *pigImage);
}

void Pig::keyMove(QKeyEvent *event) {

}
