/********************************************************************************
** Form generated from reading UI file 'dialogHelp.ui'
**
** Created: Thu 20. Feb 17:20:31 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHELP_H
#define UI_DIALOGHELP_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHeaderView>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAjuda
{
public:
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *DialogAjuda)
    {
        if (DialogAjuda->objectName().isEmpty())
            DialogAjuda->setObjectName(QString::fromUtf8("DialogAjuda"));
        DialogAjuda->resize(400, 400);
        DialogAjuda->setMinimumSize(QSize(400, 400));
        DialogAjuda->setMaximumSize(QSize(400, 400));
        plainTextEdit = new QPlainTextEdit(DialogAjuda);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 381, 381));
        plainTextEdit->setReadOnly(true);

        retranslateUi(DialogAjuda);

        QMetaObject::connectSlotsByName(DialogAjuda);
    } // setupUi

    void retranslateUi(QDialog *DialogAjuda)
    {
        DialogAjuda->setWindowTitle(QApplication::translate("DialogAjuda", "Dialog", 0));
        plainTextEdit->setPlainText(QApplication::translate("DialogAjuda", "Real Time Deformation is software to analyze images, from a computer camera device, based in a reference image.\n"
"\n"
"The main window has four principals groups: camera control, set reference image, filter parameters control and save results.\n"
"\n"
"The groups are:\n"
"\n"
"# Camera Image \n"
"\n"
"In this group, the user can choose the computer camera device operating on his computer, set the camera resolution, control the FPS camera and start/stop the camera.\n"
"\n"
"# Reference Image \n"
"\n"
"It is responsible to set/reset the reference image. The initial reference image is a totally black image. When the button \342\200\234Reset Reference\342\200\235 is pressed, a black image becomes reference image again.\n"
"\n"
"# Filter Image \n"
"\n"
"This group contains all configurable parameters utilized on the filters applied at the filtered image.\n"
"\n"
"# Results\n"
"\n"
"After the reference image has been set, results are able to be saved. It can be done by this group.\n"
"\n"
"For more information abo"
                        "ut this software and his usage, read the user guide.", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAjuda: public Ui_DialogAjuda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHELP_H
