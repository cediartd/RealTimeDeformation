#include "dialogHelp.h"
#include "ui_dialogHelp.h"

DialogAjuda::DialogAjuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjuda)
{
    ui->setupUi(this);
    setWindowTitle("Help");
}

DialogAjuda::~DialogAjuda()
{
    delete ui;
}
