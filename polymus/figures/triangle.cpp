#include "triangle.hpp"
#include "QPainter"


Triangle::Triangle(QWidget *parent):Figure(parent)
{

}

void Triangle::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::green,1,Qt::SolidLine));
    p.drawLine(QPoint(x-20,y-20), QPoint(x+20,y-20));
    p.drawLine(QPoint(x+20,y-20), QPoint(x,y));
    p.drawLine(QPoint(x,y), QPoint(x-20,y-20));
    //p.translate(10,10);
}

void Triangle::moveFigure()
{
    QPainter p(this);
    update();

    if (y>=0)
    {
        y--;
    }
    else
    {
        y+=399;
    }
}
