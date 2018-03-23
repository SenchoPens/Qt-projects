#include "form.hpp"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form) {
    ui->setupUi(this);
}
