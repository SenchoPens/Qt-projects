#ifndef TREE_HPP
#define TREE_HPP

#include <QWidget>
#include "node.hpp"
#include "parentnode.hpp"

class Tree : public QWidget {
    Q_OBJECT
public:
    explicit Tree(QWidget *parent = 0);

signals:

public slots:
};

#endif // TREE_HPP
