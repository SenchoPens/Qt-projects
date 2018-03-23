#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    timer = new QTimer;
    n = 0;
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(tic()) );
}

Form::~Form()
{
    delete ui;
}

void Form::tic()
{

    n++;
    ui->lcdNumber->display(n);
}
