#ifndef CLOUD_HPP
#define CLOUD_HPP

#include <QWidget>
#include "figure.h"

class Cloud : public Figure {
    Q_OBJECT
public:
    explicit Cloud(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

private:
    virtual void generateXY();

    int sizeX;
    int sizeY;
    QImage *cloudImage;

signals:

public slots:
};

#endif // CLOUD_HPP
