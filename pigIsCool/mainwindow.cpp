#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setupUi(this);
    cloud = new Figure();
}

void MainWindow::generateGrass() {

}
