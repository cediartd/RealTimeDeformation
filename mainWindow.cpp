#include "mainwindow.h"
#include "ui_mainWindow.h"
#include <QDateTime>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Move the main window to top left computer screen.
    QWidget::move(QPoint(0,0));
    setWindowTitle("RTD v1.0");

    // Camera initilization.
    camera = cvCreateCameraCapture(0);
    assert(camera);
    cameraDefaultWidth = cvGetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH);
    cameraDefaultHeight = cvGetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT);
    QString comboBoxText = QString("Default (").append(QString::number(cameraDefaultWidth)).append(QString(" x ").append(QString::number(cameraDefaultHeight)).append(QString(")")));
    ui->comboBox_SelectCameraResolution->setItemText(0, comboBoxText);

    // Interface initialization.
    ui->actionHelp->setIcon(QIcon("icons/help.png"));
    ui->actionAbout->setIcon(QIcon("icons/about.png"));
    ui->pushButton_stopProcess->setVisible(false);
    ui->pushButton_resetReference->setVisible(false);
    ui->statusBar->showMessage("Loading...", 5000);

    // Variables initialization.
    imageBool = false;

    // Connect signals
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(show_about()));
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(show_help()));
}

MainWindow::~MainWindow(){
    cvReleaseCapture(&camera);

    if (ui->pushButton_stopProcess->isEnabled()){
        killTimer(timer);
        cvDestroyWindow("Online image");
        cvDestroyWindow("Reference image");
        cvDestroyWindow("Difference image");
        cvDestroyWindow("Filtered image");
    }
    if (imageBool){
        cvReleaseImage(&imgCam);
        cvReleaseImage(&imgCamGray);
        cvReleaseImage(&imgDiff);
        cvReleaseImage(&imgRef);
        cvReleaseImage(&imgFilter);
    }
    delete ui;
}

// **********************************************************************************************
// **** Timer Event *****************************************************************************
// **********************************************************************************************

void MainWindow::timerEvent(QTimerEvent *){
    imgCam = cvQueryFrame(camera);

    cvShowImage("Online image", imgCam);
    cvResizeWindow("Online image", imagesWidth, imagesHeight);

    cvShowImage("Reference image", imgRef);
    cvResizeWindow("Reference image", imagesWidth, imagesHeight);

    cvCvtColor(imgCam, imgCamGray, CV_RGB2GRAY);
    cvAbsDiff(imgCamGray, imgRef, imgDiff);
    cvShowImage("Difference image", imgDiff);
    cvResizeWindow("Difference image", imagesWidth, imagesHeight);

    cvSmooth(imgDiff, imgFilter, CV_BLUR, (ui->spinBox_guassianBlur->value() * 2 + 1), (ui->spinBox_guassianBlur->value() * 2 + 1), 0, 0);
    cvShowImage("Filtered image", imgFilter);
    cvResizeWindow("Filtered image", imagesWidth, imagesHeight);
}

// **********************************************************************************************

void MainWindow::on_pushButton_startProcess_clicked(){
    imageBool = true;

    ui->pushButton_startProcess->setVisible(false);
    ui->pushButton_startProcess->setEnabled(false);
    ui->pushButton_stopProcess->setVisible(true);

    QSize mainWindowSize = QMainWindow::frameSize();
    int mainWindowWidth = mainWindowSize.width();
    int mainWindowHeight = mainWindowSize.height();

    QRect screen = QApplication::desktop()->availableGeometry();
    int screenWidth = screen.width();
    int screenHeight = screen.height();

    // Correction factor about the main window horizontal border.
    int factor1 = 8;
    // Correction factor about the cvWindow horizontal border.
    int factor2 = 20;
    // Correction factor about the main window vertical border.
    int factor3 = mainWindowHeight - QMainWindow::height();

    // Capturing one image from the camera.
    imgCam = cvQueryFrame(camera);

    // Ratio of the height by the width of the camera.
    double cameraRatio = float(imgCam->height) / float(imgCam->width);

    // Create the images.
    imgRef = cvCreateImage(cvGetSize(imgCam), IPL_DEPTH_8U, 1);
    cvZero(imgRef);
    imgCamGray = cvCreateImage(cvGetSize(imgCam), 8, 1);
    imgDiff = cvCreateImage(cvGetSize(imgCam), 8, 1);
    imgFilter = cvCreateImage(cvGetSize(imgCam), 8, 1);

    // Waiting 5 seconds to the camera feedback.
    ui->statusBar->showMessage("Starting...");
    //Sleep(5000);
    ui->statusBar->showMessage("");
    ui->pushButton_stopProcess->setEnabled(true);

    // Calculing width and height of the images.
    imagesWidth = ((screenWidth - mainWindowWidth) / 2) - factor1 - (factor2 * 2);
    imagesHeight = imagesWidth * cameraRatio;

    // In this case, if the calculated image width is bigger than the camera width,
    // the image will be digitally amplified.
    if (imagesWidth > imgCam->width){
        imagesWidth = imgCam->width;
        imagesHeight = imgCam->height;
    }

    // In this case the height of the top and bottom images is bigger than the screen height.
    if ((imagesHeight * 2) > screenHeight){
        imagesHeight = (screenHeight / 2) - (factor3);
        imagesWidth = imagesHeight / cameraRatio;
    }

    // ==========================================================================================
    // ==== Preview 1 ===========================================================================
    // ==========================================================================================

    int preview1_XPosition = mainWindowWidth + factor1;
    int preview1_YPosition = 0;

    cvNamedWindow("Online image", 0);
    cvMoveWindow("Online image", preview1_XPosition, preview1_YPosition);
    cvResizeWindow("Online image", imagesWidth, imagesHeight);


    // ==========================================================================================
    // ==== Preview 2 ===========================================================================
    // ==========================================================================================

    int preview2_XPosition = mainWindowWidth + imagesWidth + (2 * factor2) + (2 * factor1);
    int preview2_YPosition = 5;

    cvNamedWindow("Reference image", 0);
    cvMoveWindow("Reference image", preview2_XPosition, preview2_YPosition);
    cvResizeWindow("Reference image", imagesWidth, imagesHeight);


    // ==========================================================================================
    // ==== Preview 3 ===========================================================================
    // ==========================================================================================

    int preview3_XPosition = mainWindowWidth + factor1;
    int preview3_YPosition = imagesHeight + factor2 + factor3;

    cvNamedWindow("Difference image", 0);
    cvMoveWindow("Difference image", preview3_XPosition, preview3_YPosition);
    cvResizeWindow("Difference image", imagesWidth, imagesHeight);


    // ==========================================================================================
    // ==== Preview 4 ===========================================================================
    // ==========================================================================================

    int preview4_XPosition = mainWindowWidth + imagesWidth + (2 * factor2) + (2 * factor1);
    int preview4_YPosition = imagesHeight + factor2 + factor3;

    cvNamedWindow("Filtered image", 0);
    cvMoveWindow("Filtered image", preview4_XPosition, preview4_YPosition);
    cvResizeWindow("Filtered image", imagesWidth, imagesHeight);


    timer = startTimer(1000/ui->spinBox_fps->value());
}

void MainWindow::on_pushButton_stopProcess_clicked(){
    ui->pushButton_startProcess->setVisible(true);
    ui->pushButton_startProcess->setEnabled(true);
    ui->pushButton_stopProcess->setVisible(false);
    ui->pushButton_stopProcess->setEnabled(false);

    killTimer(timer);

    cvDestroyWindow("Online image");
    cvDestroyWindow("Reference image");
    cvDestroyWindow("Difference image");
    cvDestroyWindow("Filtered image");
}

void MainWindow::on_pushButton_setReference_clicked(){
    ui->pushButton_resetReference->setEnabled(true);
    ui->pushButton_resetReference->setVisible(true);
    ui->pushButton_setReference->setVisible(false);
    ui->pushButton_setReference->setEnabled(false);

    cvCvtColor(imgCam, imgRef, CV_RGB2GRAY);

    ui->pushButton_saveResults->setEnabled(true);
}

void MainWindow::on_pushButton_resetReference_clicked(){
    ui->pushButton_resetReference->setEnabled(false);
    ui->pushButton_resetReference->setVisible(false);
    ui->pushButton_setReference->setVisible(true);
    ui->pushButton_setReference->setEnabled(true);

    cvZero(imgRef);

    ui->pushButton_saveResults->setEnabled(false);
}

void MainWindow::on_pushButton_saveResults_clicked(){
    // Stop timer event.
    killTimer(timer);

    // Get the date and hour to make the filename.
    QDateTime a = QDateTime::currentDateTime();
    QString dateHour = a.toString("yyyyMMdd_hhmmss");

    QString filename;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::currentPath());
    QString auxDir = dir;

    // Save images.
    filename = dateHour;
    filename = filename.append("_originalImage.bmp");
    filename = auxDir.append("/").append(filename);
    cvSaveImage(filename.toLocal8Bit().data(), imgCam);

    filename = dateHour;
    filename = filename.append("_referenceImage.bmp");
    auxDir = dir;
    filename = auxDir.append("/").append(filename);
    cvSaveImage(filename.toLocal8Bit().data(), imgRef);

    filename = dateHour;
    filename = filename.append("_differenceImage.bmp");
    auxDir = dir;
    filename =auxDir.append("/").append(filename);
    cvSaveImage(filename.toLocal8Bit().data(), imgDiff);

    filename = dateHour;
    filename = filename.append("_FilterImage.bmp");
    auxDir = dir;
    filename =auxDir.append("/").append(filename);
    cvSaveImage(filename.toLocal8Bit().data(), imgFilter);

    ui->statusBar->showMessage("Images Saved.", 3000);

    // Restart timer event.
    timer = startTimer(1000/ui->spinBox_fps->value());
}

void MainWindow::on_spinBox_fps_valueChanged(int spinBoxValue)
{
    if(ui->pushButton_stopProcess->isEnabled())
    {
        killTimer(timer);
        timer = startTimer(1000/spinBoxValue);
    }
}

void MainWindow::on_comboBox_SelectCamera_currentIndexChanged(int index)
{
    bool processOn = false;

    // If the camera is on, shut down it.
    if(ui->pushButton_stopProcess->isEnabled())
    {
        on_pushButton_stopProcess_clicked();
        processOn = true;
    }

    // Release the camera.
    cvReleaseCapture(&camera);

    // Camera initialization.
    camera = cvCreateCameraCapture(index);
    assert(camera);
    cameraDefaultWidth = cvGetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH);
    cameraDefaultHeight = cvGetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT);

    // Interface changes.
    ui->comboBox_SelectCameraResolution->setCurrentIndex(0);
    QString comboBoxText = QString("Default (").append(QString::number(cameraDefaultWidth)).
                        append(QString(" x ").append(QString::number(cameraDefaultHeight)).append(QString(")")));
    ui->comboBox_SelectCameraResolution->setItemText(0, comboBoxText);

    if (processOn)
        on_pushButton_startProcess_clicked();
}

void MainWindow::on_comboBox_SelectCameraResolution_currentIndexChanged(int index)
{
    bool processingOn = false;

    if (ui->pushButton_stopProcess->isEnabled())
    {
        on_pushButton_stopProcess_clicked();
        processingOn = true;
    }

    switch (index)
    {
        case 0:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH,  cameraDefaultWidth);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, cameraDefaultHeight);
        break;

        case 1:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH,  320);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 240);
        break;

        case 2:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH,  640);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 480);
        break;

        case 3:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH,  800);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 600);
        break;

        case 4:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH, 1024);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 768);
        break;

        case 5:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH, 1280);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 720);
        break;

        case 6:
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH,  1920);
            cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 1080);
        break;
    }

    if (processingOn)
    {
        imgCam = cvQueryFrame(camera);
        imgCamGray = cvCreateImage(cvGetSize(imgCam), 8, 1);
        imgDiff = cvCreateImage(cvGetSize(imgCam), 8, 1);
        imgFilter = cvCreateImage(cvGetSize(imgCam), 8, 1);
        cvCvtColor(imgCam, imgCamGray, CV_RGB2GRAY);
        imgRef = cvCreateImage(cvGetSize(imgCam), 8, 1);
        cvZero(imgRef);

        on_pushButton_startProcess_clicked();
    }
}

void MainWindow::show_about()
{
    obj_sobre = new DialogSobre(this);
    obj_sobre->exec();
}

void MainWindow::show_help()
{
    obj_ajuda = new DialogAjuda(this);
    obj_ajuda->exec();
}
