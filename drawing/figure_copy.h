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
    int x;
    int y;
    uint r;
    int vy;
    int vx;
    uint height;
    uint width;
    uint maxHealth;
    void move();

    uint colorR;
    uint colorG;
    uint colorB;
    uint colorR2;
    uint colorG2;
    uint colorB2;
    uint generateColor();
    void generateColors();
    virtual void generateXY();
    int getHealth();

public:
    bool ctrl;
    Figure(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
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

public slots:
    void moveFigure();
    void updateFigure();
};

#endif // CIRCLE_H
