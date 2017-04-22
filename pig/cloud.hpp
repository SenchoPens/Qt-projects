#ifndef CLOUD_HPP
#define CLOUD_HPP

#include <QWidget>
#include "figure.h"
#include "controlfigure.hpp"

class Pig : public ControlFigure {
    Q_OBJECT
private:
    const int moveSpeed = 10;
    virtual void generateXY();
    QImage *pigImage;
    QRectF *area;

    int sizeX;
    int sizeY;

public:
    explicit Pig(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);
    virtual void keyMove(QKeyEvent *event);
};

#endif // CLOUD_HPP
