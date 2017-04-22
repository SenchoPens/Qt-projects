#include <QFile>
#include <QTextStream>
#include "start.hpp"

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start) {
    ui->setupUi(this);
    recordFileName = "record.txt";
}

void Start::loadRecord() {
    QFile recordFile(recordFileName);
    if (!recordFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        record = 0;
        return;
    }

    QTextStream in(&recordFile);
    in >> record;
    ui->recordSecondsNumber->display(record);
}

void Start::saveRecord(int seconds) {
    if (seconds <= record)
        return;

    QFile recordFile(recordFileName);
    if (!recordFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&recordFile);
    out << seconds;
}
