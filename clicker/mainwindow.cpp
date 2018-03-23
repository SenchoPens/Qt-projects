#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    decreaseTimer = new QTimer;
    decreaseTimer->setInterval(2000);
    decreaseTimer->start();
    chooseName();
    connect(decreaseTimer, SIGNAL(timeout()), this, SLOT(decrease()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(encrease()));
}

void MainWindow::chooseName() {
    QString names[4] {"Ars", "Sencho", "Vanya", "Sasha"};
    qsrand(time(NULL));
    ui->nameLabel->setText(names[qrand() % 4]);
}

void MainWindow::decrease() {
    ui->progressBar->setValue(ui->progressBar->value() - 5);
    if (ui->progressBar->value() <= 0)
        close();
}

void MainWindow::encrease() {
    ui->progressBar->setValue(ui->progressBar->value() + 1);
}
