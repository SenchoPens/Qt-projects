#ifndef START_HPP
#define START_HPP

#include "ui_start.h"

class Start : public QWidget, private Ui::Start {
    Q_OBJECT
private:
    int record;
    QString recordFileName;

public:
    Ui::Start *ui;
    explicit Start(QWidget *parent = 0);
    void loadRecord();
    void saveRecord(int seconds);
};

#endif // START_HPP
