#include "dialogAbout.h"
#include "ui_dialogAbout.h"

DialogSobre::DialogSobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSobre)
{
    ui->setupUi(this);
    setWindowTitle("About this program");
    setWindowIcon(QIcon("icons/about.png"));
}

DialogSobre::~DialogSobre()
{
    delete ui;
}
