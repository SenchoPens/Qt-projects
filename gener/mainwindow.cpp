#include "mainwindow.hpp"
#include <QTimer>
#include <QString>

void MainWindow::chooseName() {
    QString names[4] {"Ars", "Sencho", "Vanya", "Sasha"};
    qsrand(time(NULL));
    ui->nameLabel->setText(names[qrand() % 4]);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    chooseName();

    decreaseTimer = new QTimer;
    decreaseTimer->setInterval(20000);
}
