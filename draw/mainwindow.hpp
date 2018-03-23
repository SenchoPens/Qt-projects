#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QPen>
#include <QTimer>

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    int brightness;
    void validate(int button);
public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
protected:
    void paintEvent(QPaintEvent *);
private slots:
};

#endif // MAINWINDOW_HPP
