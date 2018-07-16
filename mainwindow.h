#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QDesktopWidget.h"

#include <QDebug>

#include "dialogAbout.h"
#include "dialogHelp.h"

// OpenCV libraries.
#include <opencv/cv.h>
#include <opencv/highgui.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    int timer;
    bool imageBool;

    int imagesWidth;
    int imagesHeight;
    int cameraDefaultWidth;
    int cameraDefaultHeight;

    // * OpenCv objects:
    CvCapture* camera;
    IplImage* imgCam;
    IplImage* imgCamGray;
    IplImage* imgRef;
    IplImage* imgDiff;
    IplImage* imgFilter;

    // Internal class objects:
    DialogAjuda *obj_ajuda;
    DialogSobre *obj_sobre;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *);
    
private slots:
    void on_pushButton_startProcess_clicked();

    void on_pushButton_stopProcess_clicked();

    void on_pushButton_setReference_clicked();

    void on_pushButton_resetReference_clicked();

    void on_pushButton_saveResults_clicked();

    void on_spinBox_fps_valueChanged(int arg1);

    void on_comboBox_SelectCamera_currentIndexChanged(int index);

    void on_comboBox_SelectCameraResolution_currentIndexChanged(int index);

    void show_about();

    void show_help();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
