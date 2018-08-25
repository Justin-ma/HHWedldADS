#ifndef HANDEYECALIB_H
#define HANDEYECALIB_H

#include <QWidget>
#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#  if defined(__linux__) && !defined(NO_EXPORT_APP_MAIN)
#    include <X11/Xlib.h>
#  endif
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#  include <stdio.h>
#  include <HALCON/HpThread.h>
#  include <CoreFoundation/CFRunLoop.h>
#endif
using namespace HalconCpp;
namespace Ui {
class HandeyeCalib;
}

class HandeyeCalib : public QWidget
{
    Q_OBJECT

public:
    explicit HandeyeCalib(QWidget *wid,QWidget *parent = 0);
    ~HandeyeCalib();
    void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
        HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
    void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
        HTuple hv_Slant);
    Hlong winID;
    QWidget *wd;
private slots:
    void on_pushButton_clicked();

    void on_btnCalibInternal_clicked();

    void on_pushSetCalibParam_clicked();

    void on_pushButtonClean_clicked();

private:
    Ui::HandeyeCalib *ui;
    HObject  ho_ModelImage;
    HTuple    ho_filepath;

    HTuple ImgPath;
    HTuple CaltabName;
    HTuple ParamePath;
    HTuple FirstImgPath;

    double foucus;
    double Kappa;
    double Sx;
    double Sy;
    double Cx;
    double Cy;
    double Width;
    double Height;


};

#endif // HANDEYECALIB_H
