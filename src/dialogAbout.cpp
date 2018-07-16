#include "dialogAbout.h"
#include "ui_dialogAbout.h"

DialogSobre::DialogSobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSobre)
{
    ui->setupUi(this);
    setWindowTitle("About this program");
}

DialogSobre::~DialogSobre()
{
    delete ui;
}
