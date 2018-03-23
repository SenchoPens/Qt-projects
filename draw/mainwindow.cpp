#include "mainwindow.hpp"
#include <QPainter>
#include <QPaintEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    brightness = 10;
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    update();
    switch (event->key()) {
    case Qt::Key_Up:
        brightness += 10;
        break;
    case Qt::Key_Down:
        brightness -= 10;
        break;
    default:
        break;
    }
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    brightness %= 256;
    QColor color(brightness, brightness, brightness);
    p.setPen(QPen(color, 1, Qt::SolidLine));
    p.drawEllipse(QPoint(200,200), 30, 30);
}
