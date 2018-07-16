#include "dialogHelp.h"
#include "ui_dialogHelp.h"

DialogAjuda::DialogAjuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjuda)
{
    ui->setupUi(this);
    setWindowTitle("Help");
    setWindowIcon(QIcon("icons/help.png"));
}

DialogAjuda::~DialogAjuda()
{
    delete ui;
}
