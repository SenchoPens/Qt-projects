#ifndef FORM_HPP
#define FORM_HPP

#include "ui_form.h"

class Form : public QWidget, private Ui::Form {
    Q_OBJECT
private:
public:
    Ui::Form *ui;
    explicit Form(QWidget *parent = 0);
};

#endif // FORM_HPP
