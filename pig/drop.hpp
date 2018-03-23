#ifndef DROP_HPP
#define DROP_HPP

#include <QWidget>
#include <QDebug>
#include "figure.h"

class Drop : public Figure {
    Q_OBJECT
public:
    explicit Drop(int _x, int _y, QImage *_image, QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

private:
    virtual void generateXY();

    int sizeX;
    int sizeY;
    QImage *dropImage;

    virtual void move();

signals:

public slots:
};

#endif // DROP_HPP
