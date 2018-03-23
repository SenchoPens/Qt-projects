#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    startUi = new Form();
    startUi->show();
    startUi->setAttribute(Qt::WA_DeleteOnClose);
    x = 0;
    QPushButton* button = ui->mainButton;
    //connect(startUi, SIGNAL(), this, SLOT(hide()));
    this->hide();
}

void MainWindow::increase() {
    ui->lcdNumber->display(x++);
}
