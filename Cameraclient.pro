#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T16:02:46
#
#-------------------------------------------------

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = Cameraclient
#TEMPLATE = app

SOURCES += main.cpp\
        mainWidget.cpp \
    Calibration.cpp \
    Models.cpp \
    Matching.cpp \
    Simulate.cpp \
    ImageView/widgetscens.cpp \
    ImageView/widgetview.cpp \
    ImageThread.cpp \
    ChooseDialog.cpp \
    ImageShow.cpp \
    HandeyeCalib.cpp \
    Connect.cpp \
    halconImage.cpp

HEADERS  += mainWidget.h \
    Calibration.h \
    Models.h \
    Matching.h \
    Simulate.h \
    ImageView/widgetscens.h \
    ImageView/widgetview.h \
    ImageThread.h \
    ChooseDialog.h \
    ImageShow.h \
    HandeyeCalib.h \
    Connect.h \
    halconImage.h

INCLUDEPATH +="C:\Program Files\MVTec\HALCON-12.0\include"
INCLUDEPATH +="C:\Program Files\MVTec\HALCON-12.0\include\halconcpp"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halcon.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconc.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconcpp.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconcpp10.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconcpp10xl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconcppxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconcxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconx.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\halconxxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginecpp.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginecpp10.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginecpp10xl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginecppxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginexxl.lib"
LIBS        +="C:\Program Files\MVTec\HALCON-12.0\lib\x86sse2-win32\hdevenginex.lib"


QT +=core gui widgets network
CONFIG += C++11

RESOURCES += \
    pixmap.qrc


FORMS    += Ui\2dimageshow.ui
FORMS    += Ui\handeyecalib.ui
FORMS    += Ui\connect.ui
FORMS    += Ui\halconimage.ui
