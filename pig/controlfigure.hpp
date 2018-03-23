#ifndef CONTROLFIGURE_HPP
#define CONTROLFIGURE_HPP

#include <QWidget>
#include "figure.h"

class ControlFigure : public Figure {
    Q_OBJECT
protected:
    int moveSpeed;

    int max(int x, int y);
    int min(int x, int y);
    float brakingK;  // how fast does the ball brake
    virtual void generateXY();
    virtual void move();

public:
    explicit ControlFigure(QWidget *parent = 0);
    virtual void keyMove(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *);

signals:

public slots:
};


#endif // CONTROLFIGURE_HPP
