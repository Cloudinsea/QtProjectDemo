#include "virtual_scope_demo.h"
#include "ui_virtual_scope_demo.h"

Virtual_scope_demo::Virtual_scope_demo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Virtual_scope_demo)
{
    ui->setupUi(this);
}

Virtual_scope_demo::~Virtual_scope_demo()
{
    delete ui;
}
