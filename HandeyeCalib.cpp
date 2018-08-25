#include "HandeyeCalib.h"
#include "ui_handeyecalib.h"
#include<QMessageBox>

HandeyeCalib::HandeyeCalib(QWidget *wid,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandeyeCalib)
{

    ui->setupUi(this);
    wd = wid;
    winID=(Hlong)wd->winId();

    CaltabName   =  HTuple(ui->edit_LCaltabName->text().toLatin1().data());
    FirstImgPath =  HTuple(ui->edit_LFirstImgPath->text().toLatin1().data());
    ImgPath      =  HTuple(ui->edit_LImgPath->text().toLatin1().data());
    ParamePath   =  HTuple(ui->edit_LParamePath->text().toLatin1().data());

    foucus = ui->spin_Focus->value();
    Kappa  = ui->spin_Kappa->value();
    Sx     = ui->spin_Sx->value();
    Sy     = ui->spin_Sy->value();
    Cx     = ui->spin_Cx->value();
    Cy     = ui->spin_Cy->value();
    Width  = ui->spin_Width->value();
    Height = ui->spin_Height->value();

}

HandeyeCalib::~HandeyeCalib()
{
    delete ui;
}

void HandeyeCalib::on_pushButton_clicked()
{
   QMessageBox::warning(this,"dfwfwef","sdfefwe");
}

void HandeyeCalib::disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
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
void HandeyeCalib::set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
    HTuple hv_Slant)
{
  // Local control variables
  HTuple  hv_OS, hv_BufferWindowHandle, hv_Ascent;
  HTuple  hv_Descent, hv_Width, hv_Height, hv_Scale, hv_Exception;
  HTuple  hv_SubFamily, hv_Fonts, hv_SystemFonts, hv_Guess;
  HTuple  hv_I, hv_Index, hv_AllowedFontSizes, hv_Distances;
  HTuple  hv_Indices, hv_FontSelRegexp, hv_FontsCourier;
  GetSystem("operating_system", &hv_OS);
  if (0 != (HTuple(hv_Size==HTuple()).TupleOr(hv_Size==-1)))
  {
    hv_Size = 16;
  }
  if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Win")))
  {
    //Set font on Windows systems
    try
    {
      //Check, if font scaling is switched on
      OpenWindow(0, 0, 256, 256, 0, "buffer", "", &hv_BufferWindowHandle);
      SetFont(hv_BufferWindowHandle, "-Consolas-16-*-0-*-*-1-");
      GetStringExtents(hv_BufferWindowHandle, "test_string", &hv_Ascent, &hv_Descent,
          &hv_Width, &hv_Height);
      //Expected width is 110
      hv_Scale = 110.0/hv_Width;
      hv_Size = (hv_Size*hv_Scale).TupleInt();
      CloseWindow(hv_BufferWindowHandle);
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
    if (0 != (HTuple(hv_Font==HTuple("Courier")).TupleOr(hv_Font==HTuple("courier"))))
    {
      hv_Font = "Courier New";
    }
    else if (0 != (hv_Font==HTuple("mono")))
    {
      hv_Font = "Consolas";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Font = "Arial";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Font = "Times New Roman";
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_Bold = 1;
    }
    else if (0 != (hv_Bold==HTuple("false")))
    {
      hv_Bold = 0;
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Slant==HTuple("true")))
    {
      hv_Slant = 1;
    }
    else if (0 != (hv_Slant==HTuple("false")))
    {
      hv_Slant = 0;
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    try
    {
      SetFont(hv_WindowHandle, ((((((("-"+hv_Font)+"-")+hv_Size)+"-*-")+hv_Slant)+"-*-*-")+hv_Bold)+"-");
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
  }
  else if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Dar")))
  {
    //Set font on Mac OS X systems. Since OS X does not have a strict naming
    //scheme for font attributes, we use tables to determine the correct font
    //name.
    hv_SubFamily = 0;
    if (0 != (hv_Slant==HTuple("true")))
    {
      hv_SubFamily = hv_SubFamily|1;
    }
    else if (0 != (hv_Slant!=HTuple("false")))
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_SubFamily = hv_SubFamily|2;
    }
    else if (0 != (hv_Bold!=HTuple("false")))
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Font==HTuple("mono")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "Menlo-Regular";
      hv_Fonts[1] = "Menlo-Italic";
      hv_Fonts[2] = "Menlo-Bold";
      hv_Fonts[3] = "Menlo-BoldItalic";
    }
    else if (0 != (HTuple(hv_Font==HTuple("Courier")).TupleOr(hv_Font==HTuple("courier"))))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "CourierNewPSMT";
      hv_Fonts[1] = "CourierNewPS-ItalicMT";
      hv_Fonts[2] = "CourierNewPS-BoldMT";
      hv_Fonts[3] = "CourierNewPS-BoldItalicMT";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "ArialMT";
      hv_Fonts[1] = "Arial-ItalicMT";
      hv_Fonts[2] = "Arial-BoldMT";
      hv_Fonts[3] = "Arial-BoldItalicMT";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "TimesNewRomanPSMT";
      hv_Fonts[1] = "TimesNewRomanPS-ItalicMT";
      hv_Fonts[2] = "TimesNewRomanPS-BoldMT";
      hv_Fonts[3] = "TimesNewRomanPS-BoldItalicMT";
    }
    else
    {
      //Attempt to figure out which of the fonts installed on the system
      //the user could have meant.
      QueryFont(hv_WindowHandle, &hv_SystemFonts);
      hv_Fonts.Clear();
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font);
      hv_Guess.Append(hv_Font+"-Regular");
      hv_Guess.Append(hv_Font+"MT");
      {
      HTuple end_val100 = (hv_Guess.TupleLength())-1;
      HTuple step_val100 = 1;
      for (hv_I=0; hv_I.Continue(end_val100, step_val100); hv_I += step_val100)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[0] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of slanted font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-Italic");
      hv_Guess.Append(hv_Font+"-ItalicMT");
      hv_Guess.Append(hv_Font+"-Oblique");
      {
      HTuple end_val109 = (hv_Guess.TupleLength())-1;
      HTuple step_val109 = 1;
      for (hv_I=0; hv_I.Continue(end_val109, step_val109); hv_I += step_val109)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[1] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of bold font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-Bold");
      hv_Guess.Append(hv_Font+"-BoldMT");
      {
      HTuple end_val118 = (hv_Guess.TupleLength())-1;
      HTuple step_val118 = 1;
      for (hv_I=0; hv_I.Continue(end_val118, step_val118); hv_I += step_val118)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[2] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of bold slanted font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-BoldItalic");
      hv_Guess.Append(hv_Font+"-BoldItalicMT");
      hv_Guess.Append(hv_Font+"-BoldOblique");
      {
      HTuple end_val127 = (hv_Guess.TupleLength())-1;
      HTuple step_val127 = 1;
      for (hv_I=0; hv_I.Continue(end_val127, step_val127); hv_I += step_val127)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[3] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
    }
    hv_Font = ((const HTuple&)hv_Fonts)[hv_SubFamily];
    try
    {
      SetFont(hv_WindowHandle, (hv_Font+"-")+hv_Size);
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
  }
  else
  {
    //Set font for UNIX systems
    hv_Size = hv_Size*1.25;
    hv_AllowedFontSizes.Clear();
    hv_AllowedFontSizes[0] = 11;
    hv_AllowedFontSizes[1] = 14;
    hv_AllowedFontSizes[2] = 17;
    hv_AllowedFontSizes[3] = 20;
    hv_AllowedFontSizes[4] = 25;
    hv_AllowedFontSizes[5] = 34;
    if (0 != ((hv_AllowedFontSizes.TupleFind(hv_Size))==-1))
    {
      hv_Distances = (hv_AllowedFontSizes-hv_Size).TupleAbs();
      TupleSortIndex(hv_Distances, &hv_Indices);
      hv_Size = ((const HTuple&)hv_AllowedFontSizes)[HTuple(hv_Indices[0])];
    }
    if (0 != (HTuple(hv_Font==HTuple("mono")).TupleOr(hv_Font==HTuple("Courier"))))
    {
      hv_Font = "courier";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Font = "helvetica";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Font = "times";
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_Bold = "bold";
    }
    else if (0 != (hv_Bold==HTuple("false")))
    {
      hv_Bold = "medium";
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Slant==HTuple("true")))
    {
      if (0 != (hv_Font==HTuple("times")))
      {
        hv_Slant = "i";
      }
      else
      {
        hv_Slant = "o";
      }
    }
    else if (0 != (hv_Slant==HTuple("false")))
    {
      hv_Slant = "r";
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    try
    {
      SetFont(hv_WindowHandle, ((((((("-adobe-"+hv_Font)+"-")+hv_Bold)+"-")+hv_Slant)+"-normal-*-")+hv_Size)+"-*-*-*-*-*-*-*");
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      if (0 != (HTuple((hv_OS.TupleSubstr(0,4))==HTuple("Linux")).TupleAnd(hv_Font==HTuple("courier"))))
      {
        QueryFont(hv_WindowHandle, &hv_Fonts);
        hv_FontSelRegexp = (("^-[^-]*-[^-]*[Cc]ourier[^-]*-"+hv_Bold)+"-")+hv_Slant;
        hv_FontsCourier = (hv_Fonts.TupleRegexpSelect(hv_FontSelRegexp)).TupleRegexpMatch(hv_FontSelRegexp);
        if (0 != ((hv_FontsCourier.TupleLength())==0))
        {
          hv_Exception = "Wrong font name";
          //throw (Exception)
        }
        else
        {
          try
          {
            SetFont(hv_WindowHandle, ((HTuple(hv_FontsCourier[0])+"-normal-*-")+hv_Size)+"-*-*-*-*-*-*-*");
          }
          // catch (Exception)
          catch (HalconCpp::HException &HDevExpDefaultException)
          {
            HDevExpDefaultException.ToHTuple(&hv_Exception);
            //throw (Exception)
          }
        }
      }
      //throw (Exception)
    }
  }
  // dev_set_preferences(...); only in hdevelop
  return;
}

void HandeyeCalib::on_btnCalibInternal_clicked()
{
//    // Local iconic variables
    HObject  ho_Image, ho_Caltab;

    // Local control variables
    // ImgPath,CaltabName,ParamePath,FirstImgPath,
    HTuple hv_WindowHandle, hv_OpSystem,Width, Height;
    HTuple  hv_StartCamPar, hv_CalibDataID, hv_NumImages, hv_I;

    HTuple  hv_Error, hv_CamParam, hv_Message;
    ReadImage(&ho_ModelImage, FirstImgPath);
    GetImageSize(ho_ModelImage, &Width, &Height);
    SetWindowAttr("background_color","black");
   // OpenWindow(0,0,Width,Height,winID,"","",&hv_WindowHandle);
    OpenWindow(0,0,650*1280/1024,650,winID,"","",&hv_WindowHandle);
    HDevWindowStack::Push(hv_WindowHandle);
  //  dev_update_off();
    if (HDevWindowStack::IsOpen())
      SetDraw(HDevWindowStack::GetActive(),"margin");
    if (HDevWindowStack::IsOpen())
      SetLineWidth(HDevWindowStack::GetActive(),3);
    hv_OpSystem = HTuple("OS").TupleEnvironment();

  //  set_display_font(hv_WindowHandle, 14, "mono", "true", "false");
    //Calibrate the camera.

    hv_StartCamPar.Clear();
    hv_StartCamPar[0] = 0.0184898;
    hv_StartCamPar[1] = -548.002;
    hv_StartCamPar[2] = 8.33409e-006;
    hv_StartCamPar[3] = 8.3e-006;
    hv_StartCamPar[4] = 643;
    hv_StartCamPar[5] = 510;
    hv_StartCamPar[6] = 1280;
    hv_StartCamPar[7] = 1024;
    CreateCalibData("calibration_object", 1, 1, &hv_CalibDataID);
    SetCalibDataCamParam(hv_CalibDataID, 0, "area_scan_division", hv_StartCamPar);
    SetCalibDataCalibObject(hv_CalibDataID, 0, CaltabName);
    hv_NumImages = 10;
    //Note, we do not use the image from which the pose of the measurement plane can be derived
    {
    HTuple end_val17 = hv_NumImages;
    HTuple step_val17 = 1;
    for (hv_I=1; hv_I.Continue(end_val17, step_val17); hv_I += step_val17)
    {
      ReadImage(&ho_Image, (ImgPath+"calib_")+(hv_I.TupleString("02d")));
      if (HDevWindowStack::IsOpen())
        DispObj(ho_Image, HDevWindowStack::GetActive());
      FindCalibObject(ho_Image, hv_CalibDataID, 0, 0, hv_I, HTuple(), HTuple());
      GetCalibDataObservContours(&ho_Caltab, hv_CalibDataID, "caltab", 0, 0, hv_I);
      if (HDevWindowStack::IsOpen())
        SetColor(HDevWindowStack::GetActive(),"green");
      if (HDevWindowStack::IsOpen())
        DispObj(ho_Caltab, HDevWindowStack::GetActive());
    }
    }
    CalibrateCameras(hv_CalibDataID, &hv_Error);
    GetCalibData(hv_CalibDataID, "camera", 0, "params", &hv_CamParam);
    //Write the internal camera parameters to a file
    WriteCamPar(hv_CamParam, ParamePath);
    hv_Message = "Interior camera parameters have";
    hv_Message[1] = "been written to file";
    disp_message(hv_WindowHandle, hv_Message, "window", 12, 12, "red", "false");
    ClearCalibData(hv_CalibDataID);
}

void HandeyeCalib::on_pushSetCalibParam_clicked()
{
    CaltabName   =  HTuple(ui->edit_LCaltabName->text().toLatin1().data());
    FirstImgPath =  HTuple(ui->edit_LFirstImgPath->text().toLatin1().data());
    ImgPath      =  HTuple(ui->edit_LImgPath->text().toLatin1().data());
    ParamePath   =  HTuple(ui->edit_LParamePath->text().toLatin1().data());

    foucus = ui->spin_Focus->value();
    Kappa  = ui->spin_Kappa->value();
    Sx     = ui->spin_Sx->value();
    Sy     = ui->spin_Sy->value();
    Cx     = ui->spin_Cx->value();
    Cy     = ui->spin_Cy->value();
    Width  = ui->spin_Width->value();
    Height = ui->spin_Height->value();

}

void HandeyeCalib::on_pushButtonClean_clicked()
{

        if (HDevWindowStack::IsOpen())
          ClearWindow(HDevWindowStack::GetActive());
        if (HDevWindowStack::IsOpen())
             CloseWindow(HDevWindowStack::Pop());

}
