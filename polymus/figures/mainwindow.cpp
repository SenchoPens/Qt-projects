#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f = new Figure(this);
    t = new Triangle(this);
    p = new Polygon(this);
    vector.append(f);
    timer = new QTimer;
    timer->start(10);
    connect( timer, SIGNAL( timeout() ), p, SLOT(moveFigure()) );
    connect( timer, SIGNAL( timeout() ), t, SLOT(moveFigure()) );
    connect( timer, SIGNAL( timeout() ), f, SLOT(moveFigure()) );
    f->move(100, 100);
}



MainWindow::~MainWindow()
{
    f->deleteLater();
    t->deleteLater();
    p->deleteLater();
    delete ui;
}
