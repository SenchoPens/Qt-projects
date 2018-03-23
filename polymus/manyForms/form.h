#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
public slots:
    void tic();

private:
    int n;
    QTimer *timer;
    Ui::Form *ui;
};

#endif // FORM_H
