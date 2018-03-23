#ifndef PIG_HPP
#define PIG_HPP

#include <QWidget>
#include "figure.h"
#include "controlfigure.hpp"

class Pig : public ControlFigure {
    Q_OBJECT
private:
    virtual void generateXY();
    QImage *pigImage;
    int sizeX;
    int sizeY;

public:
    explicit Pig(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);
    virtual void keyMove(QKeyEvent *);
};

#endif // PIG_HPP
