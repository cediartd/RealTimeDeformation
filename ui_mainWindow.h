/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Thu 20. Feb 17:21:30 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QSpinBox>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGroupBox *groupBox_camera;
    QPushButton *pushButton_stopProcess;
    QPushButton *pushButton_startProcess;
    QLabel *label_FPS;
    QSpinBox *spinBox_fps;
    QComboBox *comboBox_SelectCamera;
    QLabel *label_selectCamera;
    QLabel *label_selectCameraResolution;
    QComboBox *comboBox_SelectCameraResolution;
    QGroupBox *groupBox_reference;
    QPushButton *pushButton_resetReference;
    QPushButton *pushButton_setReference;
    QGroupBox *groupBox_filter;
    QSpinBox *spinBox_guassianBlur;
    QLabel *label_gaussianBlur;
    QGroupBox *groupBox_result;
    QPushButton *pushButton_saveResults;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(190, 560);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(190, 560));
        MainWindow->setMaximumSize(QSize(190, 560));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_camera = new QGroupBox(centralWidget);
        groupBox_camera->setObjectName(QString::fromUtf8("groupBox_camera"));
        groupBox_camera->setGeometry(QRect(10, 10, 171, 221));
        pushButton_stopProcess = new QPushButton(groupBox_camera);
        pushButton_stopProcess->setObjectName(QString::fromUtf8("pushButton_stopProcess"));
        pushButton_stopProcess->setEnabled(false);
        pushButton_stopProcess->setGeometry(QRect(10, 30, 91, 23));
        pushButton_startProcess = new QPushButton(groupBox_camera);
        pushButton_startProcess->setObjectName(QString::fromUtf8("pushButton_startProcess"));
        pushButton_startProcess->setGeometry(QRect(10, 30, 91, 23));
        label_FPS = new QLabel(groupBox_camera);
        label_FPS->setObjectName(QString::fromUtf8("label_FPS"));
        label_FPS->setGeometry(QRect(10, 70, 31, 20));
        spinBox_fps = new QSpinBox(groupBox_camera);
        spinBox_fps->setObjectName(QString::fromUtf8("spinBox_fps"));
        spinBox_fps->setGeometry(QRect(60, 70, 41, 16));
        spinBox_fps->setMinimum(1);
        spinBox_fps->setMaximum(60);
        spinBox_fps->setValue(5);
        comboBox_SelectCamera = new QComboBox(groupBox_camera);
        comboBox_SelectCamera->setObjectName(QString::fromUtf8("comboBox_SelectCamera"));
        comboBox_SelectCamera->setGeometry(QRect(10, 130, 151, 20));
        label_selectCamera = new QLabel(groupBox_camera);
        label_selectCamera->setObjectName(QString::fromUtf8("label_selectCamera"));
        label_selectCamera->setGeometry(QRect(10, 100, 131, 16));
        label_selectCameraResolution = new QLabel(groupBox_camera);
        label_selectCameraResolution->setObjectName(QString::fromUtf8("label_selectCameraResolution"));
        label_selectCameraResolution->setGeometry(QRect(10, 160, 141, 16));
        comboBox_SelectCameraResolution = new QComboBox(groupBox_camera);
        comboBox_SelectCameraResolution->setObjectName(QString::fromUtf8("comboBox_SelectCameraResolution"));
        comboBox_SelectCameraResolution->setGeometry(QRect(10, 190, 151, 20));
        groupBox_reference = new QGroupBox(centralWidget);
        groupBox_reference->setObjectName(QString::fromUtf8("groupBox_reference"));
        groupBox_reference->setGeometry(QRect(10, 250, 171, 71));
        pushButton_resetReference = new QPushButton(groupBox_reference);
        pushButton_resetReference->setObjectName(QString::fromUtf8("pushButton_resetReference"));
        pushButton_resetReference->setEnabled(false);
        pushButton_resetReference->setGeometry(QRect(10, 30, 151, 23));
        pushButton_setReference = new QPushButton(groupBox_reference);
        pushButton_setReference->setObjectName(QString::fromUtf8("pushButton_setReference"));
        pushButton_setReference->setEnabled(true);
        pushButton_setReference->setGeometry(QRect(10, 30, 151, 23));
        groupBox_filter = new QGroupBox(centralWidget);
        groupBox_filter->setObjectName(QString::fromUtf8("groupBox_filter"));
        groupBox_filter->setGeometry(QRect(10, 340, 171, 71));
        spinBox_guassianBlur = new QSpinBox(groupBox_filter);
        spinBox_guassianBlur->setObjectName(QString::fromUtf8("spinBox_guassianBlur"));
        spinBox_guassianBlur->setGeometry(QRect(120, 30, 42, 22));
        spinBox_guassianBlur->setMinimum(0);
        spinBox_guassianBlur->setMaximum(30);
        spinBox_guassianBlur->setValue(3);
        label_gaussianBlur = new QLabel(groupBox_filter);
        label_gaussianBlur->setObjectName(QString::fromUtf8("label_gaussianBlur"));
        label_gaussianBlur->setGeometry(QRect(10, 30, 111, 21));
        groupBox_result = new QGroupBox(centralWidget);
        groupBox_result->setObjectName(QString::fromUtf8("groupBox_result"));
        groupBox_result->setGeometry(QRect(10, 430, 171, 71));
        pushButton_saveResults = new QPushButton(groupBox_result);
        pushButton_saveResults->setObjectName(QString::fromUtf8("pushButton_saveResults"));
        pushButton_saveResults->setEnabled(false);
        pushButton_saveResults->setGeometry(QRect(10, 30, 151, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 190, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        groupBox_camera->setTitle(QApplication::translate("MainWindow", "Camera Image", 0));
        pushButton_stopProcess->setText(QApplication::translate("MainWindow", "Stop Camera", 0));
        pushButton_startProcess->setText(QApplication::translate("MainWindow", "Start Camera", 0));
        label_FPS->setText(QApplication::translate("MainWindow", "FSP: ", 0));
        comboBox_SelectCamera->clear();
        comboBox_SelectCamera->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Primary", 0)
         << QApplication::translate("MainWindow", "Secundary", 0)
        );
        label_selectCamera->setText(QApplication::translate("MainWindow", "Select camera device:", 0));
        label_selectCameraResolution->setText(QApplication::translate("MainWindow", "Select camera resolution:", 0));
        comboBox_SelectCameraResolution->clear();
        comboBox_SelectCameraResolution->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Default", 0)
         << QApplication::translate("MainWindow", "320 x 240", 0)
         << QApplication::translate("MainWindow", "640 x 480", 0)
         << QApplication::translate("MainWindow", "800 x 600", 0)
         << QApplication::translate("MainWindow", "1024 x 768", 0)
         << QApplication::translate("MainWindow", "1280 x 720", 0)
         << QApplication::translate("MainWindow", "1920 x 1080", 0)
        );
        groupBox_reference->setTitle(QApplication::translate("MainWindow", "Reference Image", 0));
        pushButton_resetReference->setText(QApplication::translate("MainWindow", "Reset Reference Image", 0));
        pushButton_setReference->setText(QApplication::translate("MainWindow", "Set Reference Image", 0));
        groupBox_filter->setTitle(QApplication::translate("MainWindow", "Filter Image", 0));
        label_gaussianBlur->setText(QApplication::translate("MainWindow", "- Gaussian blur ratio:", 0));
        groupBox_result->setTitle(QApplication::translate("MainWindow", "Results", 0));
        pushButton_saveResults->setText(QApplication::translate("MainWindow", "Save Results", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
