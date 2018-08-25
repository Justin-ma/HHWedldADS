#include "Matching.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>

Matching::Matching(QWidget *parent) : QWidget(parent)
{
    buttonNormal = new QRadioButton("模板  ");
    buttonSpecial = new QRadioButton("特殊  ");

    labelThreld= new QLabel("ThreShold");
    labelScore = new QLabel("Score ");
    labelX = new QLabel("MinRadius");
    labelY = new QLabel("MaxRadius");
    labelmode = new QLabel("Mode");
    labelRX1 = new QLabel("CamRotX");
    labelRY1 = new QLabel("CamRotY");

    editValue = new QLineEdit;
    editScore = new QLineEdit;   
    editX = new QLineEdit;
    editY = new QLineEdit;
    editmode = new QLineEdit;
    editRX1 = new QLineEdit;
    editRY1 = new QLineEdit;

    text = new QTextBrowser;
    buttonBeforecalib = new QPushButton("Original Image");
    buttoDeviate  = new QPushButton("After Calibration");
    buttonAftercalib = new QPushButton("Rotate Image");
    buttonSetting = new QPushButton("OCR");


    QHBoxLayout *layModel = new QHBoxLayout;
    layModel->addWidget(buttonNormal);
    layModel->addWidget(buttonSpecial);

    QGridLayout *layValue = new QGridLayout;
    layValue->addWidget(labelThreld,0,0);
    layValue->addWidget(labelScore,0,2);
    layValue->addWidget(labelX,1,0);
    layValue->addWidget(labelY,1,2);
    layValue->addWidget(labelmode,2,0);

    layValue->addWidget(labelRX1,3,0);
    layValue->addWidget(labelRY1,3,2);
    layValue->addWidget(editScore,0,1);
    layValue->addWidget(editValue,0,3);
    layValue->addWidget(editX,1,1);
    layValue->addWidget(editY,1,3);
    layValue->addWidget(editmode,2,1);
    layValue->addWidget(editRX1,3,1);
    layValue->addWidget(editRY1,3,3);

    QGridLayout *layAlternately = new QGridLayout;
    layAlternately->addWidget(text,0,0,2,2);
    layAlternately->addWidget(buttonBeforecalib,2,0);
    layAlternately->addWidget(buttoDeviate,2,1);
    layAlternately->addWidget(buttonAftercalib,3,0);
    layAlternately->addWidget(buttonSetting,3,1);

    groupModel = new QGroupBox("匹配模式");
    groupModel->setLayout(layModel);
    groupValue = new QGroupBox("匹配设置");
    groupValue->setLayout(layValue);
    groupAlternately = new QGroupBox("相机交互");
    groupAlternately->setLayout(layAlternately);

    QGridLayout *layWed = new QGridLayout;
  //  layWed->addWidget();

    groupWelding = new QGroupBox("wwwdsfc");


    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget(groupModel);
    lay->addWidget(groupValue);
    lay->addWidget(groupAlternately);
    lay->addStretch(1);



    connect(buttonAftercalib,&QPushButton::clicked,[=](){
        if( editValue->text() == "" )
             editValue->setText("99.1");
         text->append("set score:" + editValue->text() + "&");        
        emit sSendOneMatch(editValue->text() + "&");
         //qDebug() << QString::number(editValue->text().toDouble());
    });

    connect(buttoDeviate,&QPushButton::clicked,[=](){
        text->append("show after calibration image");
        emit sSendSetDeviate(editValue->text()+ "&");
    });


   connect(buttonBeforecalib,&QPushButton::clicked,[=](){   
       text->append("Real-Time Image for Calibration" );
       emit sSendStartMatch( "");//采图-畸变之前 发送 开头0
   });

   connect(buttonSetting,&QPushButton::clicked,[=](){

     editmode->setText("0");
     text->append("开启字符识别模式:");

//     if(editmode->text() == "0" )
//      {
//       editmode->setText("0");
//       text->append("脱机模式:" + editmode->text()+ "&");
//     }
//     if(editmode->text() == "1" )
//      {
//       editmode->setText("1");
//       text->append("发图模式:" + editmode->text()+ "&");
//     }
     emit sSendManyMatch(QString::number(editmode->text().toDouble())+"&");
//     text->append("Threshold:" + editScore->text() + "&"+editX->text()+ "&"+editY->text()+ "&"+editmode->text());
//     emit sSendManyMatch(editScore->text()+ "&" +QString::number(editX->text().toDouble())+
//                         "&" +QString::number(editY->text().toDouble())+"&" +QString::number(editmode->text().toDouble()));
 });
}

void Matching::TextAppend(QString str)
{
    text->append(str);
   // textserver->append(str);
}
