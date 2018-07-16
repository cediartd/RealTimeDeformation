#-------------------------------------------------
#
# Project created by QtCreator 2014-02-19T09:34:49
#
#-------------------------------------------------
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

equals(QT_MAJOR_VERSION,4) {
   message("QT4 used")
}
equals(QT_MAJOR_VERSION,5) {
   message("QT5 used")
}

QT       += core gui

TARGET = RealTimeDeformation
TEMPLATE = app

RC_FILE = mainwindow.rc

win32{
    OPENCV_WIN_DLL_PATH="C:\opencv\build\x86\vc14\bin"
    OPENCV_WIN_INCLUDE_PATH=C:\opencv\build\include

    message("We are asuming that OpenCV libs are located in $$OPENCV_WIN_DLL_PATH")

    LIBS += -lopencv_calib3d2413
    LIBS += -lopencv_contrib2413
    LIBS += -lopencv_core2413
    LIBS += -lopencv_features2d2413
    LIBS += -lopencv_ffmpeg2413
    LIBS += -lopencv_flann2413
    LIBS += -lopencv_gpu2413
    LIBS += -lopencv_highgui2413
    LIBS += -lopencv_imgproc2413
    LIBS += -lopencv_legacy2413
    LIBS += -lopencv_ml2413
    LIBS += -lopencv_nonfree2413
    LIBS += -lopencv_objdetect2413
    LIBS += -lopencv_ocl2413
    LIBS += -lopencv_photo2413
    LIBS += -lopencv_stitching2413
    LIBS += -lopencv_superres2413
    LIBS += -lopencv_video2413
    LIBS += -lopencv_videostab2413

    LIBS += -L$$OPENCV_WIN_DLL_PATH
    INCLUDEPATH = $$OPENCV_WIN_INCLUDE_PATH

    DEFINES += __OS_WINDOWS__

    isEmpty(PREFIX) {
        PREFIX = c:\usr\local
        message("")
        message("The current 'make install' path is $$PREFIX, to change write: qmake PREFIX=/another/path")
    }

}

unix{
    packagesExist(opencv){EXIST_OPENCV="true"}
    isEmpty(EXIST_OPENCV){error("OpenCV is not installed. Try: sudo apt-get install libopencv-dev")}

    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    DEFINES += __OS_UNIX__


    isEmpty(PREFIX) {
        PREFIX = /usr/local
        message("")
        message("To change the current 'make install' path, write: qmake PREFIX=/another/path")
    }
    message("The current 'make install' path is $$PREFIX")
}

SOURCES += main.cpp\
    dialogAbout.cpp \
    dialogHelp.cpp \
    mainWindow.cpp

HEADERS  += mainwindow.h\
    dialogHelp.h \
    dialogAbout.h

FORMS    +=\
    dialogAbout.ui \
    dialogHelp.ui \
    mainWindow.ui
