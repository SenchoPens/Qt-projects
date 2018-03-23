#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    counter = 0;
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(turnPage()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(prevPage()));
    turnPage();
}

void MainWindow::turnPage() {
    if (counter < pages) {
        counter++;
        ui->label->setText(text[counter]);
    }
}

void MainWindow::prevPage() {
    if (counter >= 1) {
        counter--;
        ui->label->setText(text[counter]);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
