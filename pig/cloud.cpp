#include "cloud.hpp"

void Cloud::generateXY() {
    r = sizeY / 2;
    x = width / 2;
    y = r + 50;
    vx = 1;
    vy = 0;
}

Cloud::Cloud(QWidget *parent) : Figure(parent) {
    sizeX = 100;
    sizeY = 75;
    generateXY();

    cloudImage = new QImage("cloud.png");
}

void Cloud::paintEvent(QPaintEvent *) {
    QPainter p(this);

    QRectF area = QRectF(x - (sizeX / 2), y - (sizeY / 2), sizeX, sizeY);
    p.drawImage(area, *cloudImage);
}
