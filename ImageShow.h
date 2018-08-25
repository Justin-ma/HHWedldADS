#ifndef IMAGESHOW_H
#define IMAGESHOW_H
#include <QTextBrowser>
#include <QLineEdit>
#include <qtimer.h>
#pragma comment(lib, "ws2_32.lib")
#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#  include "QtAdsOperate.h"
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
#include <QWidget>
using namespace HalconCpp;
namespace Ui {
class Widget;
}

class ImageShow : public QWidget
{
    Q_OBJECT
public:
    explicit ImageShow(QWidget *wid,QWidget *parent = 0);
    ImageShow::~ImageShow();

     Hlong winID;
     QWidget *wd;
     // Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen.
     void disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box);
     // Chapter: Graphics / Text
     // Short Description: This procedure writes a text message.
     void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
         HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
     // Local procedures
     void vc_shape_matching_teach (HObject ho_ModelImage, HTuple hv_ModelFileName);
     HTuple   hv_ImageFile,hv_hobjfile;	
private:
   //   Ui::Connect *ui;
    Ui::Widget *ui;
    HObject  ho_ModelImage, ho_ROI, ho_ImageROI, ho_ShapeModelImages;
    HObject  ho_ShapeModelRegions;

    // Local control variables
    HTuple  hv_FGHandle, hv_Pointer;
    HTuple  hv_Type, hv_AreaModelRegions;
    HTuple  hv_RowModelRegions, hv_ColumnModelRegions, hv_HeightPyramid;
    HTuple  hv_i, hv_NumLevels;

    // Local iconic variables
        HObject  ho_Image, ho_Rectangle, ho_ImageReduced;
        HObject  ho_ShapeModel;

        // Local control variables
        HTuple  hv_Width, hv_Height, hv_WindowHandle;
        HTuple  hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2;
        HTuple  hv_ModelID, hv_ModelRow, hv_ModelColumn, hv_ModelAngle;
        HTuple  hv_ModelScore, hv_ModelFileName, hv_OffsetRow, hv_OffsetColumn;

    QTextBrowser *textmoudle;

    //8.24tianjia-----------------------
    double OffsetRow;
    double OffsetColumn;
    double Phi;
    double Length1;
    double Length2;
    int ModelID_Idex;

	//Justin add it
	QtAdsOperate *plcControl;
	QTimer *timer1;
	QTimer *timer2;
	bool isbbV;
	bool isbbL;
	bool isbbRad;
	bool isbbAng;
	bool isLaser;
signals:
    void sProcessPictures();
    void sProcessPictures3();
    void sValueChange(int value,int type);
    void sValueChange3(int value,int type);
    void halconROIValueChange(int value,int type);
    void sChooseImage(int type);
    void sSendParam();
    void sSendParam2();
    void sWriteParameter(QString str);//sWriteParameter

    //8.24tianjia----------------------------
    void writeData(QString str);

public slots:

private slots:

    void on_pushcreatROI_clicked();//roi
    void on_pushshow2_clicked();

    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_6_clicked();
    void on_radioButton_7_clicked();
    void on_btP3SendParam_clicked();

    void on_pushSetParam_clicked();
    void on_pushButtonClean_clicked();//清理pushButtonClean2
    void on_pushButtonClean2_clicked();
    void on_pushshowmatch_clicked();
    void on_pushsetmatchparam_clicked();
    void on_showclear_clicked();
    void on_pushSendRectangle_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_modelcenter_clicked();
    void on_pushButton_Rectangleborder_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_noROI_clicked();
    void on_spinGreediness_valueChanged(double arg1);
    //void on_pushButton_4_clicked();
    void on_pushButtonAngleQ_clicked();
    void on_pushButtonCamRotY_clicked();
    void on_pushButtonCamRotZ_clicked();
    void on_pushButtonStandardmodeSet_clicked();
    void on_pushButtonFetchmodeSet_clicked();
    void on_pushButtonPixDistance_clicked();
	
	//Justin add PLC Control	
	bool eventFilter(QObject *, QEvent *);
	void SetFoucusBackColor(QWidget *contrlObj, QEvent *event);
	void on_btnbbV_clicked();
	void on_btnbbL_clicked();
	void on_btnbbRad_clicked();
	void on_btnbbAng_clicked();
	void on_btnVerticalL_pressed();
	void on_btnVerticalL_released();
	void on_btnVerticalR_pressed();
	void on_btnVerticalR_released();
	void on_btnLevelR_pressed();
	void on_btnLevelR_released();
	void on_btnLevelL_pressed();
	void on_btnLevelL_released();
	void on_btnRaR_pressed();
	void on_btnRaR_released();
	void on_btnRaL_pressed();
	void on_btnRaL_released();
	void on_btnAnR_pressed();
	void on_btnAnR_released();
	void on_btnAnL_pressed();
	void on_btnAnL_released();

	void on_btnZAxisL_pressed();
	void on_btnZAxisL_released();
	void on_btnZAxisR_pressed();
	void on_btnZAxisR_released();
	void on_btnRL_pressed();
	void on_btnRL_released();
	void on_btnRR_pressed();
	void on_btnRR_released();
	void on_btnWR_pressed();
	void on_btnWR_released();
	void on_btnWL_pressed();
	void on_btnWL_released();
	void on_btnStart_pressed();
	void on_btnStart_released();
	void on_btnReset_pressed();
	void on_btnReset_released();
	void on_btnStop_pressed();
	void on_btnStop_released();
	void on_btnWeldMode_clicked();
	void on_btnPause_clicked();
	void on_btnTungstenTotalNum_clicked();
	void on_btnTungstenWeldNum_clicked();
	void on_btnCompleteNum_clicked();
	void on_btnCurrentNum_clicked();
	void on_btnWireTotalNum_clicked();
	void on_btnXSetV_clicked();
	void on_btnYSetV_clicked();
	void on_btnVToWXOffset_clicked();
	void on_btnVToWYOffset_clicked();
	void on_btnAutomatic_pressed();
	void on_btnAutomatic_released();
	void on_btnbbX_pressed();
	void on_btnbbX_released();
	void on_btnbbY_pressed();
	void on_btnbbY_released();
	void on_btnPLCManualAxisPlus_pressed();
	void on_btnPLCManualAxisPlus_released();
	void on_btnPLCManualAxisMinus_pressed();
	void on_btnPLCManualAxisMinus_released();
	void on_btnbStartPro_pressed();
	void on_btnbStartPro_released();
	void on_btnMachineStart_pressed();
	void on_btnMachineStart_released();
	void on_btnPanelphotograph_pressed();
	void on_btnPanelphotograph_released();
	void on_btnOriginBack_clicked();
	void on_btnaLevel_clicked();
	void on_btnManual_pressed();
	void on_btnManual_released();
	void on_btnProgramFile_clicked();
	void on_btnLayerCount_clicked();
	void on_btnLayerDistance_clicked();
	void on_btnaVertical_pressed();
	void on_btnaVertical_released();
	void on_timer1Handle();
	void on_timer2Handle();
	void CalerbrationMethod(bool isInit);
	void on_btnSave_clicked();
	void on_btnLoad_clicked();
	void on_btnLaser_clicked();
	void ReadSetValueToUI();
	void WriteValueFromUI();
};

#endif // IMAGESHOW_H
