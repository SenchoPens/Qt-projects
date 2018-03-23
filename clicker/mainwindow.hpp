#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include <QTimer>

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QTimer *decreaseTimer;
    void chooseName();
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void decrease();
    void encrease();
};

#endif // MAINWINDOW_HPP
