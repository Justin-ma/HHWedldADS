#include "ImageShow.h"
#include "ui_2dimageshow.h"
#include <QMessageBox>
#include <qtabwidget.h>
#include <QDebug>
#include "QtAdsOperate.h"
#include "qfile.h"
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QByteArray>
#include<QJsonParseError>
#include<QtCore/QTextCodec>
#pragma comment(lib, "ws2_32.lib")
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
ImageShow::ImageShow(QWidget *wid,QWidget *parent) :
    QWidget(parent),
  ui(new Ui::Widget)
{

    wd = wid;
    winID=(Hlong)wid->winId();

    hv_ModelFileName = "E:/vc/model/model1.shm";
    hv_ImageFile="E:/vc/board/01.png";
    hv_hobjfile = "j.hobj";
	ui->setupUi(this);

	
	//Justin add it.
	ui->spinBoxTungstenTotalNum->installEventFilter(this);	
    ui->spinBoxTungstenWeldNum->installEventFilter(this);
	ui->dSpinBoxWireTotalNum->installEventFilter(this);
	ui->dSpinBoxXSetV->installEventFilter(this);
	ui->dSpinBoxYSetV->installEventFilter(this);
	ui->dSpinBoxVToWXOffset->installEventFilter(this);
	ui->dSpinBoxVToWYOffset->installEventFilter(this);
	ui->lineEditProgramFile->installEventFilter(this);
	ui->spinBoxLayerCount->installEventFilter(this);
	ui->spinBoxCompleteNum->installEventFilter(this);
	ui->spinBoxCurrentNum->installEventFilter(this);
	ui->dSpinBoxLayerDistance->installEventFilter(this);
	plcControl = new QtAdsOperate();	
	timer1=new QTimer(this);
	connect(timer1, &QTimer::timeout, this, &ImageShow::on_timer1Handle);	
	timer2 = new QTimer(this);
	connect(timer2, &QTimer::timeout, this, &ImageShow::on_timer2Handle);
	ui->btnaVertical->setVisible(false);
	isbbV = false;
	isbbL = false;
	isbbRad = false;
	isbbAng = false;
	isLaser = false;
}
  /****************************************************/
ImageShow::~ImageShow()
{
  delete ui;
}
void ImageShow::disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box)
{
  HTuple  hv_ContinueMessage, hv_Row, hv_Column;
  HTuple  hv_Width, hv_Height, hv_Ascent, hv_Descent, hv_TextWidth;
  HTuple  hv_TextHeight;
  hv_ContinueMessage = "Press Run (F5) to continue";
  GetWindowExtents(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Width, &hv_Height);
  GetStringExtents(hv_WindowHandle, (" "+hv_ContinueMessage)+" ", &hv_Ascent, &hv_Descent,
      &hv_TextWidth, &hv_TextHeight);
  disp_message(hv_WindowHandle, hv_ContinueMessage, "window", (hv_Height-hv_TextHeight)-12,
      (hv_Width-hv_TextWidth)-12, hv_Color, hv_Box);
  return;
}
// Chapter: Graphics / Text
// Short Description: This procedure writes a text message.
void ImageShow::disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
    HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{
  // Local control variables
  HTuple  hv_Red, hv_Green, hv_Blue, hv_Row1Part;
  HTuple  hv_Column1Part, hv_Row2Part, hv_Column2Part, hv_RowWin;
  HTuple  hv_ColumnWin, hv_WidthWin, hv_HeightWin, hv_MaxAscent;
  HTuple  hv_MaxDescent, hv_MaxWidth, hv_MaxHeight, hv_R1;
  HTuple  hv_C1, hv_FactorRow, hv_FactorColumn, hv_UseShadow;
  HTuple  hv_ShadowColor, hv_Exception, hv_Width, hv_Index;
  HTuple  hv_Ascent, hv_Descent, hv_W, hv_H, hv_FrameHeight;
  HTuple  hv_FrameWidth, hv_R2, hv_C2, hv_DrawMode, hv_CurrentColor;
  //Prepare window
  GetRgb(hv_WindowHandle, &hv_Red, &hv_Green, &hv_Blue);
  GetPart(hv_WindowHandle, &hv_Row1Part, &hv_Column1Part, &hv_Row2Part, &hv_Column2Part);
  GetWindowExtents(hv_WindowHandle, &hv_RowWin, &hv_ColumnWin, &hv_WidthWin, &hv_HeightWin);
  SetPart(hv_WindowHandle, 0, 0, hv_HeightWin-1, hv_WidthWin-1);
  //
  //default settings
  if (0 != (hv_Row==-1))
  {
    hv_Row = 12;
  }
  if (0 != (hv_Column==-1))
  {
    hv_Column = 12;
  }
  if (0 != (hv_Color==HTuple()))
  {
    hv_Color = "";
  }
  hv_String = ((""+hv_String)+"").TupleSplit("\n");
  //Estimate extentions of text depending on font size.
  GetFontExtents(hv_WindowHandle, &hv_MaxAscent, &hv_MaxDescent, &hv_MaxWidth, &hv_MaxHeight);
  if (0 != (hv_CoordSystem==HTuple("window")))
  {
    hv_R1 = hv_Row;
    hv_C1 = hv_Column;
  }
  else
  {
    //Transform image to window coordinates
    hv_FactorRow = (1.*hv_HeightWin)/((hv_Row2Part-hv_Row1Part)+1);
    hv_FactorColumn = (1.*hv_WidthWin)/((hv_Column2Part-hv_Column1Part)+1);
    hv_R1 = ((hv_Row-hv_Row1Part)+0.5)*hv_FactorRow;
    hv_C1 = ((hv_Column-hv_Column1Part)+0.5)*hv_FactorColumn;
  }
  //
  //Display text box depending on text size
  hv_UseShadow = 1;
  hv_ShadowColor = "gray";
  if (0 != (HTuple(hv_Box[0])==HTuple("true")))
  {
    hv_Box[0] = "#fce9d4";
    hv_ShadowColor = "#f28d26";
  }
  if (0 != ((hv_Box.TupleLength())>1))
  {
    if (0 != (HTuple(hv_Box[1])==HTuple("true")))
    {
      //Use default ShadowColor set above
    }
    else if (0 != (HTuple(hv_Box[1])==HTuple("false")))
    {
      hv_UseShadow = 0;
    }
    else
    {
      hv_ShadowColor = ((const HTuple&)hv_Box)[1];
      //Valid color?
      try
      {
        SetColor(hv_WindowHandle, HTuple(hv_Box[1]));
      }
      // catch (Exception)
      catch (HalconCpp::HException &HDevExpDefaultException)
      {
        HDevExpDefaultException.ToHTuple(&hv_Exception);
        hv_Exception = "Wrong value of control parameter Box[1] (must be a 'true', 'false', or a valid color string)";
        throw HalconCpp::HException(hv_Exception);
      }
    }
  }
  if (0 != (HTuple(hv_Box[0])!=HTuple("false")))
  {
    //Valid color?
    try
    {
      SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      hv_Exception = "Wrong value of control parameter Box[0] (must be a 'true', 'false', or a valid color string)";
      throw HalconCpp::HException(hv_Exception);
    }
    //Calculate box extents
    hv_String = (" "+hv_String)+" ";
    hv_Width = HTuple();
    {
    HTuple end_val93 = (hv_String.TupleLength())-1;
    HTuple step_val93 = 1;
    for (hv_Index=0; hv_Index.Continue(end_val93, step_val93); hv_Index += step_val93)
    {
      GetStringExtents(hv_WindowHandle, HTuple(hv_String[hv_Index]), &hv_Ascent,
          &hv_Descent, &hv_W, &hv_H);
      hv_Width = hv_Width.TupleConcat(hv_W);
    }
    }
    hv_FrameHeight = hv_MaxHeight*(hv_String.TupleLength());
    hv_FrameWidth = (HTuple(0).TupleConcat(hv_Width)).TupleMax();
    hv_R2 = hv_R1+hv_FrameHeight;
    hv_C2 = hv_C1+hv_FrameWidth;
    //Display rectangles
    GetDraw(hv_WindowHandle, &hv_DrawMode);
    SetDraw(hv_WindowHandle, "fill");
    //Set shadow color
    SetColor(hv_WindowHandle, hv_ShadowColor);
    if (0 != hv_UseShadow)
    {
      DispRectangle1(hv_WindowHandle, hv_R1+1, hv_C1+1, hv_R2+1, hv_C2+1);
    }
    //Set box color
    SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
    DispRectangle1(hv_WindowHandle, hv_R1, hv_C1, hv_R2, hv_C2);
    SetDraw(hv_WindowHandle, hv_DrawMode);
  }
  //Write text.
  {
  HTuple end_val115 = (hv_String.TupleLength())-1;
  HTuple step_val115 = 1;
  for (hv_Index=0; hv_Index.Continue(end_val115, step_val115); hv_Index += step_val115)
  {
    hv_CurrentColor = ((const HTuple&)hv_Color)[hv_Index%(hv_Color.TupleLength())];
    if (0 != (HTuple(hv_CurrentColor!=HTuple("")).TupleAnd(hv_CurrentColor!=HTuple("auto"))))
    {
      SetColor(hv_WindowHandle, hv_CurrentColor);
    }
    else
    {
      SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
    }
    hv_Row = hv_R1+(hv_MaxHeight*hv_Index);
    SetTposition(hv_WindowHandle, hv_Row, hv_C1);
    WriteString(hv_WindowHandle, HTuple(hv_String[hv_Index]));
  }
  }
  //Reset changed window settings
  SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
  SetPart(hv_WindowHandle, hv_Row1Part, hv_Column1Part, hv_Row2Part, hv_Column2Part);
  return;
}

// Local procedures
void ImageShow::vc_shape_matching_teach (HObject ho_ModelImage, HTuple hv_ModelFileName)
{

  // Local iconic variables
  HObject  ho_ROI, ho_ImageROI, ho_ShapeModelImages;
  HObject  ho_ShapeModelRegions, ho_ShapeModel;

  // Local control variables
  HTuple  hv_Pointer, hv_Type, hv_Width, hv_Height;
  HTuple  hv_WindowHandle, hv_AreaModelRegions, hv_RowModelRegions;
  HTuple  hv_ColumnModelRegions, hv_HeightPyramid, hv_i, hv_NumLevels;
  HTuple  hv_ModelID;

  GetImagePointer1(ho_ModelImage, &hv_Pointer, &hv_Type, &hv_Width, &hv_Height);
  if (HDevWindowStack::IsOpen())
    CloseWindow(HDevWindowStack::Pop());
  SetWindowAttr("background_color","white");
  OpenWindow(0,0,hv_Width,hv_Height,0,"","",&hv_WindowHandle);
  HDevWindowStack::Push(hv_WindowHandle);
  if (HDevWindowStack::IsOpen())
    SetPart(HDevWindowStack::GetActive(),0, 0, hv_Height-1, hv_Width-1);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_ModelImage, HDevWindowStack::GetActive());
  //colors and other settings for the visualization
  if (HDevWindowStack::IsOpen())
    SetColor(HDevWindowStack::GetActive(),"yellow");
  if (HDevWindowStack::IsOpen())
    SetDraw(HDevWindowStack::GetActive(),"margin");
  if (HDevWindowStack::IsOpen())
    SetLineWidth(HDevWindowStack::GetActive(),2);
  //* set_display_font (WindowHandle, 14, 'mono', 'true', 'false')
  disp_continue_message(hv_WindowHandle, "black", "true");
  //step 1: select the model object with mouse input
  DrawRegion(&ho_ROI, hv_WindowHandle);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_ROI, HDevWindowStack::GetActive());
  ReduceDomain(ho_ModelImage, ho_ROI, &ho_ImageROI);
  disp_continue_message(hv_WindowHandle, "black", "true");
  //step 2: create the model
  InspectShapeModel(ho_ImageROI, &ho_ShapeModelImages, &ho_ShapeModelRegions, 8,
      15);
  if (HDevWindowStack::IsOpen())
    ClearWindow(HDevWindowStack::GetActive());
  if (HDevWindowStack::IsOpen())
    SetColor(HDevWindowStack::GetActive(),"blue");
  if (HDevWindowStack::IsOpen())
    DispObj(ho_ShapeModelRegions, HDevWindowStack::GetActive());
  AreaCenter(ho_ShapeModelRegions, &hv_AreaModelRegions, &hv_RowModelRegions, &hv_ColumnModelRegions);
  CountObj(ho_ShapeModelRegions, &hv_HeightPyramid);
  {
  HTuple end_val26 = hv_HeightPyramid;
  HTuple step_val26 = 1;
  for (hv_i=1; hv_i.Continue(end_val26, step_val26); hv_i += step_val26)
  {
    if (0 != (HTuple(hv_AreaModelRegions[hv_i-1])>=15))
    {
      hv_NumLevels = hv_i;
    }
  }
  }
  CreateShapeModel(ho_ImageROI, hv_NumLevels, 0, HTuple(360).TupleRad(), "auto",
      "none", "use_polarity", 20, 15, &hv_ModelID);
  GetShapeModelContours(&ho_ShapeModel, hv_ModelID, 1);
  disp_continue_message(hv_WindowHandle, "black", "true");
  //step 3: save shape model as a file
  WriteShapeModel(hv_ModelID, hv_ModelFileName);
  ClearShapeModel(hv_ModelID);
  // dev_update_window(...); only in hdevelop
  return;
}



int Numlevels=3;
int InspectContrast=120;
int Contrast=20;
int  MinContrast=15;

int mAngleStart=0;
double mMinScore=0.6;
int mNumMatches=3;
double mMaxOverlap=0.5;
int mNumLevels=0;
double mGreediness=0.7;

int Modelmode=1;
int roiMode=0;

//确认模板参数
void ImageShow::on_pushSetParam_clicked()
{

     Numlevels= ui->Numlevels->text().toInt();
     InspectContrast= ui->InspectContrast->text().toInt();
     Contrast= ui->Contrast->text().toInt();
     //MinContrast= ui->MinContrast->text().toInt();

     hv_ModelFileName = HTuple(ui->ModelFileName->text().toLatin1().data());//定义模板保存路径
     hv_ImageFile = HTuple(ui->ImageFile->text().toLatin1().data());//定义图像路径
  // qDebug() <<hv_ModelFileName;
   wd->update();
}
//创建ROI模板
void ImageShow::on_pushcreatROI_clicked()
{
    ModelID_Idex=6;
            ReadImage(&ho_ModelImage, hv_ImageFile);
//    if(ho_ModelImage == 0){
//        QMessageBox::warning(this,"警告","没有发现图片");
//        return ;
//    }
    GetImageSize(ho_ModelImage, &hv_Width, &hv_Height);//930 650
    SetWindowAttr("background_color","black");
   // OpenWindow(0,0,hv_Width,hv_Height,winID,"","",&hv_WindowHandle);
    OpenWindow(0,0,650*1280/1024,650,winID,"","",&hv_WindowHandle);
    HDevWindowStack::Push(hv_WindowHandle);
    if (HDevWindowStack::IsOpen())
              SetColor(HDevWindowStack::GetActive(),"red");
    if (HDevWindowStack::IsOpen())
      DispObj(ho_ModelImage, HDevWindowStack::GetActive());
    if (HDevWindowStack::IsOpen())
      SetDraw(HDevWindowStack::GetActive(),"margin");

    DrawRectangle2(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Phi, &hv_Length1, &hv_Length2);

    GenRectangle2(&ho_ROI, hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2);

    WriteObject(ho_ROI, hv_hobjfile);

    ReduceDomain(ho_ModelImage, ho_ROI, &ho_ImageROI);

    InspectShapeModel(ho_ImageROI, &ho_ShapeModelImages, &ho_ShapeModelRegions, Numlevels,
        InspectContrast);
    CreateShapeModel(ho_ImageROI, 10, 0, HTuple(360).TupleRad(), "auto", "none",
        "use_polarity", "auto", "auto", &hv_ModelID);

    SetWindowAttr("background_color","white");
       if (HDevWindowStack::IsOpen())
         SetColor(HDevWindowStack::GetActive(),"blue");

   if (HDevWindowStack::IsOpen())
     DispObj(ho_ShapeModelRegions, HDevWindowStack::GetActive());
 qDebug()<< "ModelID_Idex00 " << ModelID_Idex;
   ModelID_Idex = hv_ModelID[0].D();
 qDebug()<< "ModelID_Idex  11 " << ModelID_Idex;
   FindShapeModel(ho_ModelImage, hv_ModelID, 0, HTuple(360).TupleRad(), 0.4, 1, 0,
        "interpolation", 0, 0.9,  &hv_ModelRow, &hv_ModelColumn, &hv_ModelAngle, &hv_ModelScore);

    WriteShapeModel(hv_ModelID, hv_ModelFileName);

    if(Modelmode==2||Modelmode==1)
    {
      DrawRectangle2(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Phi, &hv_Length1, &hv_Length2);
    }




    hv_OffsetRow = hv_Row-hv_ModelRow;
    hv_OffsetColumn = hv_Column-hv_ModelColumn;

    OffsetRow    = hv_OffsetRow[0].D();
    OffsetColumn = hv_OffsetColumn[0].D();
    Phi          = hv_Phi[0].D();
    Length1      = hv_Length1[0].D();
    Length2      = hv_Length2[0].D();// &hv_Phi, &hv_Length1, &hv_Length2

   ui->textmoudle->append(" OffsetRow:" +QString::number(OffsetRow)+"\n"
                          +" OffsetColumn:" +QString::number(OffsetColumn)+"\n"
                          +" Phi:" +QString::number(Phi)+"\n"
                          +" Length1:" +QString::number(Length1)+"\n"
                          +" Length2:" +QString::number(Length2)+"\n"
                          +" Modelmode:" +QString::number(Modelmode)+"\n"
                          );
    ClearShapeModel(hv_ModelID);
    return;
}
void ImageShow::on_pushSendRectangle_clicked()
{
 writeData("g&" +QString::number(OffsetRow)+
           "&" +QString::number(OffsetColumn)+
           "&" +QString::number(Phi)+
           "&" +QString::number(Length1)+
           "&" +QString::number(Length2)+
           "&" +QString::number(Modelmode));
}

//清理界面按钮
void ImageShow::on_pushButtonClean_clicked()
{
    if (HDevWindowStack::IsOpen())
      ClearWindow(HDevWindowStack::GetActive());
    if (HDevWindowStack::IsOpen())
         CloseWindow(HDevWindowStack::Pop());
    }

void ImageShow::on_showclear_clicked()
{
    ui->textmoudle->clear();
}









//匹配参数设置
void ImageShow::on_pushsetmatchparam_clicked()
{
    /*
    mAngleStart=ui->mAngleStart->text().toInt();
    mMinScore=ui->mMinScore->text().toDouble();
    mNumMatches=ui->mNumMatches->text().toInt();
    mMaxOverlap=ui->mMaxOverlap->text().toDouble();
    mNumLevels=ui->mNumLevels->text().toInt();
    mGreediness=ui->mGreediness->text().toDouble();
    */
}
//模板匹配确认显示按钮
void ImageShow::on_pushshowmatch_clicked()
{
    // Local iconic variables
     HObject  ho_ModelImage, ho_ShapeMode0, ho_ShapeMode1;
     HObject  ho_ShapeMode2, ho_SearchImage, ho_ModelAtNewPosition;

     // Local control variables
     HTuple  hv_Width, hv_Height, hv_WindowHandle;
     HTuple  hv_halconFileName0, hv_halconFileName1, hv_halconFileName2;
     HTuple  hv_ModelID0, hv_ModelID1, hv_ModelID2, hv_halconModelIDTemp;
     HTuple  hv_ModelID, hv_Start, hv_RowCheck, hv_ColumnCheck;
     HTuple  hv_AngleCheck, hv_Score, hv_halconModel, hv_End;
     HTuple  hv_Seconds, hv_tLength, hv_hModelNumber, hv_MovementOfObject;

     //general configuration of HDevelop
     // dev_update_window(...); only in hdevelop
     //image acquisition and window size
     ReadImage(&ho_ModelImage, "E:/vcCam/01.png");
     GetImageSize(ho_ModelImage, &hv_Width, &hv_Height);
     if (HDevWindowStack::IsOpen())
       CloseWindow(HDevWindowStack::Pop());
     SetWindowAttr("background_color","white");
     OpenWindow(0,0,hv_Width,hv_Height,winID,"","",&hv_WindowHandle);
     HDevWindowStack::Push(hv_WindowHandle);
     hv_halconFileName1 = "E:/vcCam/model1.shm";
     ReadShapeModel(hv_halconFileName1, &hv_ModelID1);  
     GetShapeModelContours(&ho_ShapeMode1, hv_ModelID1, 1);
     ReadImage(&ho_SearchImage, "E:/vcCam/01.png");
     CountSeconds(&hv_Start);
      qDebug()<<" mMinScore" << mMinScore;
     FindShapeModels(ho_SearchImage, hv_ModelID1, mAngleStart, HTuple(360).TupleRad(), mMinScore, mNumMatches,
         mMaxOverlap, "least_squares",mNumLevels, mGreediness, &hv_RowCheck, &hv_ColumnCheck, &hv_AngleCheck,
         &hv_Score, &hv_halconModel);
     CountSeconds(&hv_End);
     hv_Seconds = hv_End-hv_Start;
     TupleLength(hv_Score, &hv_tLength);

       if (0 != ((hv_Score.TupleLength())==1))
       {
         if (HDevWindowStack::IsOpen())
           SetColor(HDevWindowStack::GetActive(),"yellow");
         VectorAngleToRigid(0, 0, 0, hv_RowCheck, hv_ColumnCheck, hv_AngleCheck, &hv_MovementOfObject);
         //*         switch (hModelNumber)
         AffineTransContourXld(ho_ShapeMode1, &ho_ModelAtNewPosition, hv_MovementOfObject);

         if (HDevWindowStack::IsOpen())
           DispObj(ho_SearchImage, HDevWindowStack::GetActive());
         if (HDevWindowStack::IsOpen())
           DispObj(ho_ModelAtNewPosition, HDevWindowStack::GetActive());
       }
}
//清理按钮
void ImageShow::on_pushButtonClean2_clicked()
{
    // dev_update_window(...); only in hdevelop
   // CloseFramegrabber(hv_FGHandle);
    if (HDevWindowStack::IsOpen())
      ClearWindow(HDevWindowStack::GetActive());
    if (HDevWindowStack::IsOpen())
      CloseWindow(HDevWindowStack::Pop());
    wd->update();
}
//霍夫最小距离 1

void ImageShow::on_pushshow2_clicked()
{
   emit sProcessPictures3();

}

void ImageShow::on_radioButton_3_clicked()
{
    emit sChooseImage(1);
}

void ImageShow::on_radioButton_4_clicked()
{
     emit sChooseImage(2);
}

void ImageShow::on_radioButton_5_clicked()
{
     emit sChooseImage(3);
}

void ImageShow::on_radioButton_6_clicked()
{
     emit sChooseImage(4);
}

void ImageShow::on_radioButton_7_clicked()
{
     emit sChooseImage(5);
}

void ImageShow::on_btP3SendParam_clicked()
{
    emit sSendParam2();
}







void ImageShow::on_pushButton_clicked()
{
    writeData("H&" + QString::number(ui->doubleSpinTX1->value()) + "&");
}

void ImageShow::on_pushButton_2_clicked()
{
    writeData("I&" + QString::number(ui->doubleSpinTY1->value()) + "&");
}

void ImageShow::on_pushButton_6_clicked()
{
    writeData("J&" + QString::number(ui->spinTX2->value()) + "&");
}

void ImageShow::on_pushButton_3_clicked()
{
    writeData("K&" + QString::number(ui->spinMaxTY2->value()) + "&");
}



void ImageShow::on_pushButton_modelcenter_clicked()
{
    Modelmode=1; //1 单发模板中心到相机
}

void ImageShow::on_pushButton_Rectangleborder_clicked()
{
    Modelmode=2; //2 发边框中心到相机
}

void ImageShow::on_pushButton_11_clicked()
{
    Modelmode=0;
}

void ImageShow::on_pushButton_12_clicked()
{
    roiMode=1;
    writeData("R&" + QString::number(ui->doubleSpinRoiColumn->value()) + "&"
            +QString::number(ui->doubleSpinRoiRow->value()) + "&"
            +QString::number(ui->doubleSpinRoiLength1->value()) + "&"
            +QString::number(ui->doubleSpinRoiLength2->value()) + "&"
            );

}

void ImageShow::on_pushButton_noROI_clicked()
{
    roiMode=0;

}

void ImageShow::on_spinGreediness_valueChanged(double arg1)
{

}



void ImageShow::on_pushButtonAngleQ_clicked()
{
    //doubleSpinAngleQ
     writeData("L&" + QString::number(ui->doubleSpinAngleQ->value()) + "&");
}

void ImageShow::on_pushButtonCamRotY_clicked()
{
      writeData("M&" + QString::number(ui->doubleSpinCamRotY->value()) + "&");
}

void ImageShow::on_pushButtonCamRotZ_clicked()
{
    //doubleSpinCamRotZ
    writeData("N&" + QString::number(ui->doubleSpinCamRotZ->value()) + "&");
}


void ImageShow::on_pushButtonStandardmodeSet_clicked()
{
    //spinStandardmode
    writeData("P&" + QString::number(ui->spinStandardmode->value()) + "&");
}

void ImageShow::on_pushButtonFetchmodeSet_clicked()
{
   // spinBoxFetchmode
     writeData("P&" + QString::number(ui->spinBoxFetchmode->value()) + "&");
}

void ImageShow::on_pushButtonPixDistance_clicked()
{
    //doubleSpinPixDistance
     writeData("Q&" + QString::number(ui->doubleSpinPixDistance->value()) + "&");
}

//Justin add the PLC Control Action
void ImageShow::on_btnbbV_clicked()
{
	if (!isbbV)
	{
		isbbV = true;
		plcControl->writeBool(plcControl->m_hBool40, true);
		ui->btnbbV->setText(QString::fromLocal8Bit("允许"));
	}
	else 
	{
		isbbV = false;
		plcControl->writeBool(plcControl->m_hBool40, false);
		ui->btnbbV->setText(QString::fromLocal8Bit("垂直"));
	}
}

void ImageShow::on_btnVerticalL_pressed()
{
	if (isbbV)
	{
		plcControl->writeBool(plcControl->m_hBool1, true);
	}
	
}
void ImageShow::on_btnVerticalL_released()
{
	if (isbbV)
	{
		plcControl->writeBool(plcControl->m_hBool1, false);
	}
}
void ImageShow::on_btnVerticalR_pressed()
{
	if (isbbV)
	{
		plcControl->writeBool(plcControl->m_hBool2, true);
	}
}
void ImageShow::on_btnVerticalR_released()
{
	if (isbbV)
	{
		plcControl->writeBool(plcControl->m_hBool2, false);
	}
}


void ImageShow::on_btnbbL_clicked()
{	
	if (!isbbL)
	{
		isbbL = true;
		plcControl->writeBool(plcControl->m_hBool41, true);
		ui->btnbbL->setText(QString::fromLocal8Bit("允许"));
	}
	else
	{
		isbbL = false;
		plcControl->writeBool(plcControl->m_hBool41, false);
		ui->btnbbL->setText(QString::fromLocal8Bit("水平"));
	}
}
void ImageShow::on_btnLevelR_pressed()
{
	if (isbbL)
	{
		plcControl->writeBool(plcControl->m_hBool3, true);
	}
}
void ImageShow::on_btnLevelR_released()
{
	if (isbbL)
	{
		plcControl->writeBool(plcControl->m_hBool3, false);
	}
}
void ImageShow::on_btnLevelL_pressed()
{
	if (isbbL)
	{
		plcControl->writeBool(plcControl->m_hBool4, true);
	}
}
void ImageShow::on_btnLevelL_released()
{
	if (isbbL)
	{
		plcControl->writeBool(plcControl->m_hBool4, false);
	}
}

void ImageShow::on_btnbbRad_clicked()
{
	if (!isbbRad)
	{
		isbbRad = true;
		plcControl->writeBool(plcControl->m_hBool42, true);
		ui->btnbbRad->setText(QString::fromLocal8Bit("允许"));
	}
	else
	{
		isbbRad = false;
		plcControl->writeBool(plcControl->m_hBool42, false);
		ui->btnbbRad->setText(QString::fromLocal8Bit("半径"));
	}
}

void ImageShow::on_btnRaR_pressed()
{
	if (isbbRad)
	{
		plcControl->writeBool(plcControl->m_hBool5, true);
	}
}
void ImageShow::on_btnRaR_released()
{
	if (isbbRad)
	{
		plcControl->writeBool(plcControl->m_hBool5, false);
	}
}
void ImageShow::on_btnRaL_pressed()
{
	if (isbbRad)
	{
		plcControl->writeBool(plcControl->m_hBool6, true);
	}
}
void ImageShow::on_btnRaL_released()
{
	if (isbbRad)
	{
		plcControl->writeBool(plcControl->m_hBool6, false);
	}
}
void ImageShow::on_btnbbAng_clicked()
{	
	if (!isbbAng)
	{
		isbbAng = true;
		plcControl->writeBool(plcControl->m_hBool43, true);
		ui->btnbbAng->setText(QString::fromLocal8Bit("允许"));
	}
	else
	{
		isbbAng = false;
		plcControl->writeBool(plcControl->m_hBool43, false);
		ui->btnbbAng->setText(QString::fromLocal8Bit("角度"));
	}
}

void ImageShow::on_btnAnR_pressed()
{
	if (isbbAng)
	{
		plcControl->writeBool(plcControl->m_hBool7, true);
	}
}
void ImageShow::on_btnAnR_released()
{
	if (isbbAng)
	{
		plcControl->writeBool(plcControl->m_hBool7, false);
	}
}
void ImageShow::on_btnAnL_pressed()
{
	if (isbbAng)
	{
		plcControl->writeBool(plcControl->m_hBool8, true);
	}
}
void ImageShow::on_btnAnL_released()
{
	if (isbbAng)
	{
		plcControl->writeBool(plcControl->m_hBool8, false);
	}
}

void ImageShow::on_btnZAxisL_pressed()
{
	plcControl->writeBool(plcControl->m_hBool9, true);
}
void ImageShow::on_btnZAxisL_released()
{
	plcControl->writeBool(plcControl->m_hBool9, false);
}
void ImageShow::on_btnZAxisR_pressed()
{
	plcControl->writeBool(plcControl->m_hBool10, true);
}
void ImageShow::on_btnZAxisR_released()
{
	plcControl->writeBool(plcControl->m_hBool10, false);
}
void ImageShow::on_btnRL_pressed()
{
	plcControl->writeBool(plcControl->m_hBool11, true);
}
void ImageShow::on_btnRL_released()
{
	plcControl->writeBool(plcControl->m_hBool11, false);
}
void ImageShow::on_btnRR_pressed()
{
	plcControl->writeBool(plcControl->m_hBool12, true);
}
void ImageShow::on_btnRR_released()
{
	plcControl->writeBool(plcControl->m_hBool12, false);
}
void ImageShow::on_btnWR_pressed()
{
	plcControl->writeBool(plcControl->m_hBool13, true);
}
void ImageShow::on_btnWR_released()
{
	plcControl->writeBool(plcControl->m_hBool13, false);
}
void ImageShow::on_btnWL_pressed()
{
	plcControl->writeBool(plcControl->m_hBool14, true);
}
void ImageShow::on_btnWL_released()
{
	plcControl->writeBool(plcControl->m_hBool14, false);
}
void ImageShow::on_btnStart_pressed()
{
	plcControl->writeBool(plcControl->m_hBool15, true);
}
void ImageShow::on_btnStart_released()
{
	plcControl->writeBool(plcControl->m_hBool15, false);
}
void ImageShow::on_btnReset_pressed()
{
	plcControl->writeBool(plcControl->m_hBool16, true);
}
void ImageShow::on_btnReset_released()
{
	plcControl->writeBool(plcControl->m_hBool16, false);
}
void ImageShow::on_btnStop_pressed()
{
	plcControl->writeBool(plcControl->m_hBool17, true);
}
void ImageShow::on_btnStop_released()
{
	plcControl->writeBool(plcControl->m_hBool17, false);
}

void ImageShow::on_btnWeldMode_clicked()
{
	QString str = ui->btnWeldMode->text();
	if (str == QString::fromLocal8Bit("同心检测"))
	{		
		ui->btnWeldMode->setText(QString::fromLocal8Bit("准备中"));
		plcControl->writeBool(plcControl->m_hBool30, true);
	}
	else
	{		
		ui->btnWeldMode->setText(QString::fromLocal8Bit("同心检测"));
		plcControl->writeBool(plcControl->m_hBool30, false);
	}
}

void ImageShow::on_btnPause_clicked()
{
	QString str = ui->btnPause->text();
	if (str == QString::fromLocal8Bit("暂停"))
	{		
		ui->btnPause->setText(QString::fromLocal8Bit("暂停中"));
		plcControl->writeBool(plcControl->m_hBool18, true);
	}
	else
	{		
		ui->btnPause->setText(QString::fromLocal8Bit("暂停"));
		plcControl->writeBool(plcControl->m_hBool18, false);
	}
}
void ImageShow::on_btnTungstenTotalNum_clicked()
{	
	plcControl->writeInt(plcControl->m_hInt1,ui->spinBoxTungstenTotalNum->text().toInt());	
}

void ImageShow::on_btnTungstenWeldNum_clicked()
{	
	plcControl->writeInt(plcControl->m_hInt2, ui->spinBoxTungstenWeldNum->text().toInt());
}

void ImageShow::on_btnCompleteNum_clicked()
{	
	plcControl->writeInt(plcControl->m_hInt4, ui->spinBoxCompleteNum->text().toInt());
}

void ImageShow::on_btnCurrentNum_clicked()
{	
	plcControl->writeInt(plcControl->m_hInt5, ui->spinBoxCurrentNum->text().toInt());
}

void ImageShow::on_btnWireTotalNum_clicked()
{		
	plcControl->writeFloat(plcControl->m_hFloat1, ui->dSpinBoxWireTotalNum->text().toFloat());
}
void ImageShow::on_btnVToWXOffset_clicked()
{	
	plcControl->writeFloat(plcControl->m_hFloat5, (ui->dSpinBoxVToWXOffset->text().toFloat()));
}
void ImageShow::on_btnVToWYOffset_clicked()
{	
	plcControl->writeFloat(plcControl->m_hFloat6, (ui->dSpinBoxVToWYOffset->text().toFloat()));
}
void ImageShow::on_btnXSetV_clicked()
{	
	plcControl->writeFloat(plcControl->m_hFloat2, (ui->dSpinBoxXSetV->text().toFloat()));
}
void ImageShow::on_btnYSetV_clicked()
{	
	plcControl->writeFloat(plcControl->m_hFloat3, (ui->dSpinBoxYSetV->text().toFloat()));
}
void ImageShow::on_btnLayerCount_clicked()
{	
	timer1->stop();
	plcControl->writeInt(plcControl->m_hInt7, (ui->spinBoxLayerCount->text().toInt()));	
}
void ImageShow::on_btnLayerDistance_clicked()
{	
	plcControl->writeFloat(plcControl->m_hFloat4, ui->dSpinBoxLayerDistance->text().toFloat());	
}

void ImageShow::on_btnAutomatic_pressed()
{
	plcControl->writeBool(plcControl->m_hBool23,true);		
}
void ImageShow::on_btnAutomatic_released()
{
	plcControl->writeBool(plcControl->m_hBool23, false);
	QString strmode = plcControl->readString(plcControl->m_hString1);
	ui->lineEditActMode->setText(strmode);
}
void ImageShow::on_btnManual_pressed()
{
	plcControl->writeBool(plcControl->m_hBool24, true);	
}
void ImageShow::on_btnManual_released()
{
	plcControl->writeBool(plcControl->m_hBool24, false);
	QString strmode = plcControl->readString(plcControl->m_hString1);
	ui->lineEditActMode->setText(strmode);
}
void ImageShow::on_btnbbX_pressed()
{
	plcControl->writeBool(plcControl->m_hBool19, true);
}
void ImageShow::on_btnbbX_released()
{
	plcControl->writeBool(plcControl->m_hBool19, false);
	plcControl->writeInt(plcControl->m_hInt3, 1);
}
void ImageShow::on_btnbbY_pressed()
{
	plcControl->writeBool(plcControl->m_hBool20, true);
}
void ImageShow::on_btnbbY_released()
{
	plcControl->writeBool(plcControl->m_hBool20, false);
	plcControl->writeInt(plcControl->m_hInt3, 2);
}
void ImageShow::on_btnPLCManualAxisPlus_pressed()
{
	plcControl->writeBool(plcControl->m_hBool21, true);
}
void ImageShow::on_btnPLCManualAxisPlus_released()
{
	plcControl->writeBool(plcControl->m_hBool21, false);
}
void ImageShow::on_btnPLCManualAxisMinus_pressed()
{
	plcControl->writeBool(plcControl->m_hBool22, true);
}
void ImageShow::on_btnPLCManualAxisMinus_released()
{
	plcControl->writeBool(plcControl->m_hBool22, false);
}
void ImageShow::on_btnbStartPro_pressed()
{
	plcControl->writeBool(plcControl->m_hBool25, true);
}
void ImageShow::on_btnbStartPro_released()
{
	plcControl->writeBool(plcControl->m_hBool25, false);
}
void ImageShow::on_btnMachineStart_pressed()
{
	plcControl->writeBool(plcControl->m_hBool26, true);
}
void ImageShow::on_btnMachineStart_released()
{
	plcControl->writeBool(plcControl->m_hBool26, false);
}
void ImageShow::on_btnPanelphotograph_pressed()
{
	plcControl->writeBool(plcControl->m_hBool27, true);
}
void ImageShow::on_btnPanelphotograph_released()
{
	plcControl->writeBool(plcControl->m_hBool27, false);
}
void ImageShow::on_btnOriginBack_clicked()
{
	if (QMessageBox::Yes == QMessageBox::question(this,
		tr("Question"),
		QString::fromLocal8Bit("确定要归位吗?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) {
		plcControl->writeBool(plcControl->m_hBool28, true);
	}	
	else {
		plcControl->writeBool(plcControl->m_hBool28, false);
	}


}
void ImageShow::on_btnaLevel_clicked()
{
	QString str = ui->btnaLevel->text();
	if (str == QString::fromLocal8Bit("开始校正"))
	{
		ui->btnaLevel->setText(QString::fromLocal8Bit("校正中"));
		plcControl->writeBool(plcControl->m_hBool29, true);
		ui->btnaVertical->setVisible(true);
		CalerbrationMethod(true);
		timer2->start(2* 1000);
	}
	else
	{
		timer2->stop();
		ui->btnaVertical->setVisible(false);
		ui->btnaLevel->setText(QString::fromLocal8Bit("开始校正"));
		plcControl->writeBool(plcControl->m_hBool29, false);
	}


}


void ImageShow::on_btnLaser_clicked()
{
	if (!isLaser)
	{
		isLaser = true;
		plcControl->writeBool(plcControl->m_hBool44, true);
    }
	else
	{
		isLaser = false;
		plcControl->writeBool(plcControl->m_hBool44, false);
	}
}


void ImageShow::on_btnProgramFile_clicked()
{   
	timer1->stop();
	QString str = ui->lineEditProgramFile->text();
	int index = str.indexOf('.');
	if (index > 0 )
	{
		QString subStr = str.mid(0, index + 1);
		str = subStr + "NC";
		plcControl->writeString(plcControl->m_hString2, str);
	}		
}

void ImageShow::on_btnaVertical_pressed()
{
	plcControl->writeBool(plcControl->m_hBool31, true);	
}
void ImageShow::on_btnaVertical_released()
{	
	plcControl->writeBool(plcControl->m_hBool31, false);
	CalerbrationMethod(false);
}

bool ImageShow::eventFilter(QObject *watched, QEvent *event)
{	
	if (watched == ui->spinBoxTungstenTotalNum)
	{
		SetFoucusBackColor(ui->spinBoxTungstenTotalNum, event);		
	}
	if (watched == ui->spinBoxTungstenWeldNum)
	{
		SetFoucusBackColor(ui->spinBoxTungstenWeldNum, event);
	}
	if (watched == ui->dSpinBoxWireTotalNum)
	{
		SetFoucusBackColor(ui->dSpinBoxWireTotalNum, event);
	}
	if (watched == ui->dSpinBoxXSetV)
	{
		SetFoucusBackColor(ui->dSpinBoxXSetV, event);
	}
	if (watched == ui->dSpinBoxYSetV)
	{
		SetFoucusBackColor(ui->dSpinBoxYSetV, event);
	}
	if (watched == ui->dSpinBoxVToWXOffset)
	{
		SetFoucusBackColor(ui->dSpinBoxVToWXOffset, event);
	}
	if (watched == ui->dSpinBoxVToWYOffset)
	{
		SetFoucusBackColor(ui->dSpinBoxVToWYOffset, event);
	}
	if (watched == ui->lineEditProgramFile)
	{
		SetFoucusBackColor(ui->lineEditProgramFile, event);
	}
	if (watched == ui->spinBoxLayerCount)
	{
		SetFoucusBackColor(ui->spinBoxLayerCount, event);
	}
	if (watched == ui->dSpinBoxLayerDistance)
	{
		SetFoucusBackColor(ui->dSpinBoxLayerDistance, event);
	}
	if (watched == ui->spinBoxCompleteNum)
	{
		SetFoucusBackColor(ui->spinBoxCompleteNum, event);
	}
	if (watched == ui->spinBoxCurrentNum)
	{
		SetFoucusBackColor(ui->spinBoxCurrentNum, event);
	}

	return QWidget::eventFilter(watched, event);
}
void ImageShow::SetFoucusBackColor(QWidget *contrlObj, QEvent *event)
{
	if (event->type() == QEvent::FocusIn)
	{
		timer1->stop();
		QPalette p = QPalette();
		p.setColor(QPalette::Base, Qt::green);
		contrlObj->setPalette(p);
	}
	else if (event->type() == QEvent::FocusOut)
	{
		QPalette p = QPalette();
		p.setColor(QPalette::Base, Qt::white);
		contrlObj->setPalette(p);		
	}
}

void ImageShow::on_timer1Handle()
{	
	int iTotalNum = plcControl->readInt(plcControl->m_hInt1);
	//ui->spinBoxTungstenTotalNum->setValue(iTotalNum);
	int iWeldNum = plcControl->readInt(plcControl->m_hInt2);
	if (iTotalNum == iWeldNum)
	{
		iWeldNum = 0;
	}
	ui->spinBoxTungstenWeldNum->setValue(iWeldNum);

	float fWeldNum = plcControl->readFloat(plcControl->m_hFloat1);
	ui->dSpinBoxWireTotalNum->setValue(fWeldNum);


	int iLaycount = plcControl->readInt(plcControl->m_hInt7);
	ui->spinBoxLayerCount->setValue(iLaycount);
	

	int iCompleteNum = plcControl->readInt(plcControl->m_hInt4);
	ui->spinBoxCompleteNum->setValue(iCompleteNum);
	int iCurrentNum = plcControl->readInt(plcControl->m_hInt5);
	ui->spinBoxCurrentNum->setValue(iCurrentNum);

	float fvx = plcControl->readFloat(plcControl->m_hFloat5);
	ui->dSpinBoxVToWXOffset->setValue(fvx);
	float fvy = plcControl->readFloat(plcControl->m_hFloat6);
	ui->dSpinBoxVToWYOffset->setValue(fvy);
	
	ui->lineEditProgramFile->setText("");
	QString str = plcControl->readString(plcControl->m_hString2);
	ui->lineEditProgramFile->setText(str);

	QString strError = plcControl->readString(plcControl->m_hString3);
	ui->labelErrorCode->setText(strError);
}

void ImageShow::on_timer2Handle()
{
	CalerbrationMethod(false);
}

void ImageShow::CalerbrationMethod(bool isInit)
{
	bool bLC = plcControl->readBool(plcControl->m_hBool32);
	bool bVC1 = plcControl->readBool(plcControl->m_hBool33);
	bool bVC2 = plcControl->readBool(plcControl->m_hBool34);
	bool bVC3 = plcControl->readBool(plcControl->m_hBool35);
	bool bVC4 = plcControl->readBool(plcControl->m_hBool36);
	bool bVC5 = plcControl->readBool(plcControl->m_hBool37);
	bool bVC6 = plcControl->readBool(plcControl->m_hBool38);
	
	if (isInit)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("请向左边一点"));
		ui->btnaVertical->setEnabled(true);
		return;
	}	

	if (bLC && !bVC1 && !bVC2 && !bVC3)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("请向左边一点"));
		ui->btnaVertical->setEnabled(true);
	}
	if (bVC1 && !bVC2 && !bVC3)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("请向右边一点"));
		ui->btnaVertical->setEnabled(true);
	}
	if (bVC1 && bVC2 && !bVC3 && !bVC4)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("水平校正中"));
		ui->btnaVertical->setEnabled(false);
	}
	if (bVC4)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("偏差过大,水平校正失败"));
		ui->btnaVertical->setEnabled(false);
	}
	if (!bVC1 && !bVC2 && bVC3)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("水平校正成功，请取上部一点"));	
		ui->btnaVertical->setEnabled(true);
	}
	if (bVC3 && bVC1 && !bVC2)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("请取下部一点"));	
		ui->btnaVertical->setEnabled(true);
	}
	if (bVC3 && bVC1 && bVC2 && !bVC5 && !bVC6)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("垂直校正中"));
		ui->btnaVertical->setEnabled(false);
	}
	if (bVC6)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("偏差过大，垂直校正失败"));
		ui->btnaVertical->setEnabled(false);
	}
	if (bVC3 && bVC5)
	{
		ui->btnaVertical->setText(QString::fromLocal8Bit("垂直校正成功"));
		ui->btnaVertical->setEnabled(false);
		timer2->stop();
	}
}

void ImageShow::on_btnLoad_clicked()
{
	timer1->stop();
	ReadSetValueToUI();
}

void ImageShow::ReadSetValueToUI()
{
	QFile file("./test.ini");
	if (!file.open(QIODevice::ReadOnly))
	{
		return;
	}
	QTextStream in(&file);

	while (!in.atEnd()) {
		QString onecount = in.readLine();
		QByteArray byteArray = onecount.toLocal8Bit();
		QJsonParseError jsonError;
		QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);

		if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
			if (doucment.isObject()) {
				QJsonObject object = doucment.object();
				if (object.contains("MaxWeldNum")) {
					QJsonValue value = object.value("MaxWeldNum");					
					if (value.isString()) {
						QString strName = value.toString();
						ui->spinBoxTungstenTotalNum->setValue(strName.toInt());						
					}
				}
				if (object.contains("WireTotalNum")) {
					QJsonValue value = object.value("WireTotalNum");					
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxWireTotalNum->setValue(strName.toDouble());
					}
				}
				if (object.contains("LayerCount")) {
					QJsonValue value = object.value("LayerCount");
					if (value.isString()) {
						QString strName = value.toString();
						ui->spinBoxLayerCount->setValue(strName.toInt());
					}
				}
				if (object.contains("XSetV")) {
					QJsonValue value = object.value("XSetV");
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxXSetV->setValue(strName.toDouble());
					}
				}
				if (object.contains("YSetV")) {
					QJsonValue value = object.value("YSetV");
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxYSetV->setValue(strName.toDouble());
					}
				}
				if (object.contains("VToWXOffset")) {
					QJsonValue value = object.value("VToWXOffset");
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxVToWXOffset->setValue(strName.toDouble());
					}
				}
				if (object.contains("VToWYOffset")) {
					QJsonValue value = object.value("VToWYOffset");
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxVToWYOffset->setValue(strName.toDouble());
					}
				}
				if (object.contains("LayerDistance")) {
					QJsonValue value = object.value("LayerDistance");
					if (value.isString()) {
						QString strName = value.toString();
						ui->dSpinBoxLayerDistance->setValue(strName.toDouble());
					}
				}
				if (object.contains("ProgramFile")) {
					QJsonValue value = object.value("ProgramFile");
					if (value.isString()) {
						QString strName = value.toString();
						ui->lineEditProgramFile->setText(strName);
					}
				}
			}
		}
	}
	file.close();
}

void ImageShow::on_btnSave_clicked()
{
	WriteValueFromUI();
	timer1->start(2 * 1000);
}
void ImageShow::WriteValueFromUI()
{
	QFile file("./test.ini");
	file.open(QIODevice::ReadWrite | QIODevice::Truncate);
	QTextStream out(&file);
	if (!ui->spinBoxTungstenTotalNum->text().isEmpty() && !ui->dSpinBoxWireTotalNum->text().isEmpty()) {
		QJsonObject json;
		json.insert("MaxWeldNum", ui->spinBoxTungstenTotalNum->text());
		json.insert("WireTotalNum", ui->dSpinBoxWireTotalNum->text());
		json.insert("LayerCount", ui->spinBoxLayerCount->text());
		json.insert("XSetV", ui->dSpinBoxXSetV->text());
		json.insert("YSetV", ui->dSpinBoxYSetV->text());
		json.insert("VToWXOffset", ui->dSpinBoxVToWXOffset->text());
		json.insert("VToWYOffset", ui->dSpinBoxVToWYOffset->text());
		json.insert("LayerDistance", ui->dSpinBoxLayerDistance->text()); 
		json.insert("ProgramFile", ui->lineEditProgramFile->text());

		QJsonDocument document1;
		document1.setObject(json);
		QByteArray byteArray = document1.toJson(QJsonDocument::Compact);
		QString strJson(byteArray);
		out << strJson;
		out << "\n";
	}

	file.close();
}








