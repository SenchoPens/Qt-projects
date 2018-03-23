#include "drop.hpp"

void Drop::generateXY() {
    r = sizeY / 2;
    vx = 0;
    vy = 2;
}

void Drop::move() {
    if (y >= (height - r)) {
        vy = 0;
    }
    Figure::move();
}

Drop::Drop(int _x, int _y, QImage *_image, QWidget *parent) : Figure(parent) {
    sizeX = 10;
    sizeY = 25;
    x = _x;
    y = _y;
    generateXY();

    dropImage = _image;
}

void Drop::paintEvent(QPaintEvent *) {
    QPainter p(this);

    QRectF area = QRectF(x - (sizeX / 2), y - (sizeY / 2), sizeX, sizeY);
    //QRectF area = QRectF(x - sizeX, y - sizeY, x, y);
    p.drawImage(area, *dropImage);
    //qDebug() << x << y;
    p.drawLine(x - (sizeX / 2), y - (sizeY / 2), x, y);
}
