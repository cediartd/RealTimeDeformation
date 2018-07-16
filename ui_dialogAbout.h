/********************************************************************************
** Form generated from reading UI file 'dialogAbout.ui'
**
** Created: Thu 20. Feb 17:20:31 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGABOUT_H
#define UI_DIALOGABOUT_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHeaderView>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogSobre
{
public:
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *DialogSobre)
    {
        if (DialogSobre->objectName().isEmpty())
            DialogSobre->setObjectName(QString::fromUtf8("DialogSobre"));
        DialogSobre->resize(500, 300);
        DialogSobre->setMinimumSize(QSize(500, 300));
        DialogSobre->setMaximumSize(QSize(500, 300));
        plainTextEdit = new QPlainTextEdit(DialogSobre);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(13, 10, 471, 281));
        plainTextEdit->setReadOnly(true);

        retranslateUi(DialogSobre);

        QMetaObject::connectSlotsByName(DialogSobre);
    } // setupUi

    void retranslateUi(QDialog *DialogSobre)
    {
        DialogSobre->setWindowTitle(QApplication::translate("DialogSobre", "Dialog", 0));
        plainTextEdit->setPlainText(QApplication::translate("DialogSobre", "Real Time Deformation:\n"
"\n"
"Authors: \n"
"Michel Melo da Silva \n"
"Roberto Alves Braga Jr\n"
"\n"
"Date: \n"
"07/02/2014\n"
"\n"
"Version: \n"
"1.0\n"
"\n"
"Last atualization:\n"
"20/02/2014\n"
"\n"
"Institution: \n"
"Federal University of Lavras\n"
"\n"
"Departament: \n"
"Engineering Department\n"
"\n"
"Setor:\n"
"Centre for Development of Applied Instrumentation in Agriculture\n"
"\n"
"Local: \n"
"Lavras - MG - Brazil\n"
"\n"
"Related Papers:\n"
"--\n"
"--\n"
"\n"
"Contacts: \n"
"michelms@comp.ufla.br\n"
"robbraga@gmail.com", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSobre: public Ui_DialogSobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUT_H
