#include "controlfigure.hpp"

ControlFigure::ControlFigure(QWidget *parent) : Figure(parent) {
    generateXY();
    r = 17;
    brakingK = 0.999;
    colorR2 = 255 - colorR;
    colorG2 = 255 - colorG;
    colorB2 = 255 - colorB;
}

void ControlFigure::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.setRenderHint(p.Antialiasing);
    Qt::PenStyle lineStyle = Qt::SolidLine;
    if (vx == 0 && vy == 0) {
        lineStyle = Qt::DotLine;
    } else {
        p.setBrush(QBrush(QColor(colorR, colorG, colorB), Qt::SolidPattern));
    }
    p.setPen(QPen(QColor(colorR, colorG, colorB), 1, lineStyle));
    p.drawEllipse(QPoint(x, y), r, r);
    p.setPen(QPen(QColor(colorR2, colorG2, colorB2), 4, lineStyle));
    p.drawLine(QPoint(x-r, y-r), QPoint(x+r, y+r));
    p.drawLine(QPoint(x-r, y+r), QPoint(x+r, y-r));
}

int ControlFigure::max(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

int ControlFigure::min(int x, int y) {
    if (x <= y)
        return x;
    return y;
}

void ControlFigure::generateXY() {
    x = width / 2;
    y = height / 2;
    vx = 0;
    vy = 0;
}

void ControlFigure::move() {
    Figure::move();
    vx *= brakingK;
    vy *= brakingK;
}

void ControlFigure::keyMove(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        vy -= moveSpeed;
        break;
    case Qt::Key_S:
        vy += moveSpeed;
        break;
    case Qt::Key_A:
        vx -= moveSpeed;
        break;
    case Qt::Key_D:
        vx += moveSpeed;
        break;
    case Qt::Key_Shift:
        vx /= 2;
        vy /= 2;
        break;
    default:
        break;
    }
}
