#include "Models.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QDebug>
/*
    QRadioButton *buttonRubberband;
    QRadioButton *buttonScrollhand;
    QPushButton *buttonSave;
    QPushButton *buttonUpload;
    QPushButton *buttonSend;

    QGroupBox *groupModel;
    QGroupBox *groupMaketemplate;
    QGroupBox *groupSelecttemplate;

    ，拖拽模式，模板设置，制作模板，选定模板，保存模板 上传模板 发送
 * */

Models::Models(QWidget *parent) : QWidget(parent)
{
   //GUI/////////////////////////////////////////////////////
   buttonRubberband = new QRadioButton("框选ROI");
   buttonRubberband->setChecked(true);
   buttonScrollhand = new QRadioButton("拖拽模式");

   buttonSave = new QPushButton("保存模板");
   buttonUpload = new QPushButton("上传模板");
   buttonChooce = new QPushButton("选定模板");

   edit = new QLineEdit;
   buttonSendname = new QPushButton("send");
   text = new QTextBrowser;

   QHBoxLayout *layModels = new QHBoxLayout;
   layModels->addWidget(buttonRubberband);
   layModels->addWidget(buttonScrollhand);

   QHBoxLayout *layMake = new QHBoxLayout;
   layMake->addWidget(buttonSave);
   layMake->addWidget(buttonUpload);

   QGridLayout *laySelect = new QGridLayout;
   laySelect->addWidget(edit,0,0);
   laySelect->addWidget(buttonChooce,0,1);
   laySelect->addWidget(buttonSendname,1,0,2,1);

   groupModel = new QGroupBox("模板设置");
   groupModel->setLayout(layModels);
   groupMaketemplate = new QGroupBox("制作模板");
   groupMaketemplate->setLayout(layMake);
   groupSelecttemplate = new QGroupBox("选定模板");
   groupSelecttemplate->setLayout(laySelect);

   QVBoxLayout *lay = new QVBoxLayout(this);
   lay->addWidget(text);
   lay->addWidget(groupModel);
   lay->addWidget(groupMaketemplate);
   lay->addWidget(groupSelecttemplate);
   lay->addStretch(1);
   // ///////////////////////////////////////////////////

   connect(buttonRubberband,SIGNAL(clicked()),this,SLOT(slotChangeModelR()));
   connect(buttonScrollhand,SIGNAL(clicked()),this,SLOT(slotChangeModelS()));

   connect(buttonChooce,SIGNAL(clicked()),this,SLOT(slotChooceModels()));
   connect(buttonSave,&QPushButton::clicked,[=](){ emit sSaveModel();});
   connect(buttonUpload,&QPushButton::clicked,[=](){ emit sUpLoadModel(); });
   connect(buttonSendname,&QPushButton::clicked,[=](){ emit sSendName(edit->text()); });

}

void Models::slotChangeModelR()
{
    emit sChangeModelR();
}

void Models::slotChangeModelS()
{
    emit sChangeModelS();
}

void Models::textAppend(QString str)
{
    text->append(str);
}

void Models::slotChooceModels()
{
    emit sChooceModels();
}
