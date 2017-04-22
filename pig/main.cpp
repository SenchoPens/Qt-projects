#include <QApplication>
#include <iostream>

#include "mainwindow.hpp"
//#include "mainwindow.h"
//#include "list.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*
    std::cout << "starting..." << std::endl;
    List<int> *a;
    std::cout << "created class List" << std::endl;
    a->append(1);
    */
}
