#ifndef PARENTNODE_HPP
#define PARENTNODE_HPP

#include <QWidget>
#include "node.hpp"

class ParentNode : public Node {
    Q_OBJECT
public:
    explicit ParentNode(QString name, QWidget *parent = 0);

signals:

public slots:
};

#endif // PARENTNODE_HPP
