#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonOpen,SIGNAL(clicked(bool)), this, SLOT(openForm()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openForm()
{

    newForm = new Form;
    newForm->show();

}
