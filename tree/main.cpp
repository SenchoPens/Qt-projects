#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    /*
    QWidget *window = new QWidget;

    Node *node = new Node("name");
    ParentNode *parentNode = new ParentNode("asdf");

    QVBoxLayout *list = new QVBoxLayout;
    list->addWidget(node);
    list->addWidget(parentNode);
    window->setLayout(list);
    window->show();
    */
    w.show();

    return a.exec();
}
