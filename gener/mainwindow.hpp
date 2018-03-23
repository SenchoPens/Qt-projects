#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ui_mainwindow.h"
#include <QTimer>
#include <QVector>

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    void chooseName();
    QTimer *decreaseTimer;

public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
};

#endif // MAINWINDOW_HPP
