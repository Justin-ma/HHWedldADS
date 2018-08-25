#include "Calibration.h"
#include <QDebug>

Calibration::Calibration(QWidget *parent) : QWidget(parent)
{
    //界面//////////////////////////////////////////////////////////////////////
    //camera栏的物件
    editcamerax1 = new QLineEdit;
    editcamerax2 = new QLineEdit;
    editcamerax3 = new QLineEdit;
    editcamerax4 = new QLineEdit;
    editcameray1 = new QLineEdit;
    editcameray2 = new QLineEdit;
    editcameray3 = new QLineEdit;
    editcameray4 = new QLineEdit;

    //robot栏的物件
    editrobotx1 = new QLineEdit;
    editrobotx2 = new QLineEdit;
    editrobotx3 = new QLineEdit;
    editrobotx4 = new QLineEdit;
    editroboty1 = new QLineEdit;
    editroboty2 = new QLineEdit;
    editroboty3 = new QLineEdit;
    editroboty4 = new QLineEdit;

    //Action update栏的物件
    text = new QTextBrowser;

    //Action栏的物件
    spinbox = new QSpinBox;
    button1 = new QPushButton("Calibration");
    button2 = new QPushButton("Display");
    button3 = new QPushButton("Transform");


   //布局
   laycamera = new QGridLayout;//1
   layrobot  = new QGridLayout;//2
   layaction = new QGridLayout;//3
   laybutton = new QGridLayout;//4

   //1
   laycamera->addWidget(editcamerax1,0,0);
   laycamera->addWidget(editcamerax2,1,0);
   laycamera->addWidget(editcamerax3,2,0);
   laycamera->addWidget(editcamerax4,3,0);
   laycamera->addWidget(editcameray1,0,1);
   laycamera->addWidget(editcameray2,1,1);
   laycamera->addWidget(editcameray3,2,1);
   laycamera->addWidget(editcameray4,3,1);

   //2
   layrobot->addWidget(editrobotx1,0,0);
   layrobot->addWidget(editrobotx2,1,0);
   layrobot->addWidget(editrobotx3,2,0);
   layrobot->addWidget(editrobotx4,3,0);
   layrobot->addWidget(editroboty1,0,1);
   layrobot->addWidget(editroboty2,1,1);
   layrobot->addWidget(editroboty3,2,1);
   layrobot->addWidget(editroboty4,3,1);

   //3
   layaction->addWidget(text);

   //4
   laybutton->addWidget(spinbox,0,0);
   laybutton->addWidget(button1,0,1);
   laybutton->addWidget(button2,1,0);
   laybutton->addWidget(button3,1,1);


   //分类框
   groupcamera = new QGroupBox("Camera Coordinates");
   grouprobot  = new QGroupBox("Robot Coordinates");
   groupaction = new QGroupBox("Acttion Update");
   groupbutton = new QGroupBox;

   //分类框中布局
   groupcamera->setLayout(laycamera);
   grouprobot->setLayout(layrobot);
   groupaction->setLayout(layaction);
   groupbutton->setLayout(laybutton);

   //整体布局
   vlay = new QVBoxLayout(this);
   vlay->addWidget(groupcamera);
   vlay->addWidget(grouprobot);
   vlay->addWidget(groupaction);
   vlay->addWidget(groupbutton);

   // ///////////////////////////////////////////////////////////////////////////////

 //  m_opencvthread = new opencvthread("../biaodingzhi.jpg");

   connect(button1,SIGNAL(clicked()),this,SLOT(slotGetxy()));
   connect(button3,SIGNAL(clicked()),this,SLOT(slotSend()));
}

void Calibration::slotSend()
{
    double co[16] = {0};
    co[0] = editcamerax1->text().toDouble();
    co[1] = editcameray1->text().toDouble();
    co[2] = editcamerax2->text().toDouble();
    co[3] = editcameray2->text().toDouble();
    co[4] = editcamerax3->text().toDouble();
    co[5] = editcameray3->text().toDouble();
    co[6] = editcamerax4->text().toDouble();
    co[7] = editcameray4->text().toDouble();

    co[8]  = editrobotx1->text().toDouble();
    co[9]  = editroboty1->text().toDouble();
    co[10] = editrobotx2->text().toDouble();
    co[11] = editroboty2->text().toDouble();
    co[12] = editrobotx3->text().toDouble();
    co[13] = editroboty3->text().toDouble();
    co[14] = editrobotx4->text().toDouble();
    co[15] = editroboty4->text().toDouble();

    emit sSendCoordinate(co);
}

void Calibration::TextAppend(QString str)
{
    text->append(str);
}

void Calibration::CalculationXYR()
{

}

void Calibration::slotGetxy()
{
    emit sGetIamge();
}
