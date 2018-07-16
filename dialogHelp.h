#ifndef DIALOGAJUDA_H
#define DIALOGAJUDA_H

#include <QDialog>

namespace Ui {
    class DialogAjuda;
}

class DialogAjuda : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjuda(QWidget *parent = 0);
    ~DialogAjuda();

private:
    Ui::DialogAjuda *ui;
};

#endif // DIALOGAJUDA_H
