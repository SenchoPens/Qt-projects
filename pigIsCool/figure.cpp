#include "figure.hpp"

inline int healthToR(uint v) {
    return int(ceil(sqrt(v / 3)));
}

Figure::Figure(QWidget *parent) : QWidget(parent) {
    height = 800;
    width = 800;
    r = qrand() % 10 + 15;

    generateXY();

    setMaximumHeight(height);
    setMaximumWidth(width);
    setMinimumHeight(height);
    setMinimumWidth(width);

    generateColors();
}

void Figure::generateColors() {
    colorR = generateColor();
    colorG = generateColor();
    colorB = generateColor();
}

void Figure::generateXY() {
    x = qrand() % (width - 2 * r) + r;
    qsrand(qrand());
    y = qrand() % (height - 2 * r) + r;

    vx = qrand() % 4 + 1;
    qsrand(qrand());
    vy = qrand() % 4 + 1;
}

uint Figure::generateColor() {
    return qrand() % 256;
}

void Figure::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(p.Antialiasing);
    p.setPen(QPen(QColor(colorR, colorG, colorB), 1, Qt::SolidLine));
    p.setBrush(QBrush(QColor(colorR, colorG, colorB), Qt::SolidPattern));
    p.drawEllipse(QPoint(x, y), r, r);
}

void Figure::intersect() {
    vx *= -1;
    vy *= -1;
}

bool Figure::isDead() {
    return r <= 0;
}

void Figure::heal(uint v) {
    if (v+getHealth() < maxHealth) {
        r += healthToR(v);
    }
}

void Figure::damage(uint v) {
    if (getHealth()-v > 0) {
        r -= healthToR(v);
    }
}

void Figure::health(int v) {
    if (v > 0)
        heal(v);
    else if (v < 0)
        damage(-v);
}

int Figure::getHealth() {
    return 3 * r * r;
}

int Figure::getX() {
    return x;
}

int Figure::getY() {
    return y;
}

int Figure::getR() {
    return r;
}

int Figure::getVx() {
    return vx;
}

int Figure::getVy() {
    return vy;
}

void Figure::moveFigure() {
    bool xAtBorder = ((x <= r) || (width - x <= r));
    bool yAtBorder = ((y <= r) || (width - y <= r));
    vx *= -1 * xAtBorder + 1 * (not xAtBorder);
    vy *= -1 * yAtBorder + 1 * (not yAtBorder);
    if ((x <= 0) || (x >= width) || (y <= 0) || (y >= height)) {
        generateXY();
    }
    move();
}

void Figure::updateFigure() {
    update();
}

void Figure::move() {
    x += vx;
    y += vy;
}
