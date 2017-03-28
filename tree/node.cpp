#include "node.hpp"

Node::Node(QString name, QWidget *parent) : QWidget(parent) {
    nodeName = name;
    nameLabel = new QLabel(this);
    nameLabel->setText(nodeName);
    nameLabel->adjustSize();
    adjustSize();
}
