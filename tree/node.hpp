#ifndef NODE_HPP
#define NODE_HPP

#include <QWidget>
#include <QtWidgets>

class Node : public QWidget {
    Q_OBJECT
private:
    QString nodeName;
    QLabel *nameLabel;
public:
    explicit Node(QString name, QWidget *parent = 0);

signals:

public slots:
};

#endif // NODE_HPP
