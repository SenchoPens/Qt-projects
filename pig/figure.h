#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QPen>
#include <cmath>

class Figure : public QWidget {
    Q_OBJECT
protected:
    const uint maxHealth = 1500;
    int x;
    int y;
    uint r;
    int vy;
    int vx;
    uint height;
    uint width;

    uint colorR;
    uint colorG;
    uint colorB;
    uint colorR2;
    uint colorG2;
    uint colorB2;

    void generateColors();
    int getHealth();
    uint generateColor();
    virtual void move();
    virtual void generateXY();

public:
    Figure(QWidget *parent = 0);
    void intersect();
    void health(int v);
    void heal(uint v);
    void damage(uint v);
    int getX();
    int getY();
    int getR();
    int getVx();
    int getVy();
    bool isDead();
    virtual void paintEvent(QPaintEvent *);

public slots:
    void moveFigure();
    void updateFigure();
};

#endif // CIRCLE_H
