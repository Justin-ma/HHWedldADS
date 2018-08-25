#include "mainWidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include <QFileInfo>
#include "ChooseDialog.h"

#include <QDebug>
#include <string.h>



mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    //界面//////////////////////////////////////////////////////////////////
    //单独的窗口
    scene = new widgetscens;
    view = new widgetView;
    view->setScene(scene);
    fpixmap = new QGraphicsPixmapItem(QPixmap(":/philo1.png"));
    scene->addItem(fpixmap);

    calibration = new Calibration;
    handeyecalib= new HandeyeCalib(view);
    models      = new Models;
    matching    = new Matching;
    connection  = new Connect;
    simulate    = new Simulate;
    imageshow   = new ImageShow(view);
    halconImage   = new HalconImage;

    buttonsave = new QPushButton("Save");
    buttonopen = new QPushButton("Open");

    tabwidget = new QTabWidget;
    tabwidget->setTabPosition(QTabWidget::East);
    //tabwidget->setStyleSheet("background-color:#FFFAFA;");
    tabwidget->addTab(handeyecalib,"畸变");
    tabwidget->addTab(calibration,"手眼标定");//添加个畸变矫正，类似于imageshow；
    tabwidget->addTab(models,"模板设置");
    tabwidget->addTab(matching,"功能");
    tabwidget->addTab(connection,"连接");
    tabwidget->addTab(simulate,"触发");
    tabwidget->addTab(imageshow,"两圆定位");
   // tabwidget->addTab(halconImage,"halcon图像");

    labeltitle = new QLabel(QObject::trUtf8("<b><font size='20' color='red'>HUAHENG</font><br>"
                            "<font size='30' color='black'>华恒</font></b><br>"
                            "<font> Welding CO., Ltd</font>" ));
    labeltitle->setAlignment(Qt::AlignCenter);

    hlay = new QHBoxLayout;
    hlay->addWidget(buttonsave);
    hlay->addWidget(buttonopen);

    vlay = new QVBoxLayout;
    vlay->addWidget(labeltitle);
    vlay->addWidget(tabwidget);
    vlay->addLayout(hlay);

    lay = new QGridLayout(this);
    lay->addWidget(view,0,0);
    lay->addLayout(vlay,0,1);
    // ////////////////////////////////////////////////////////////////////////////

    namei = 1;
    //isStart  = true;
    //isgetimg = false;
    viewmodel = true;

    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.3.15",3000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadbuf()));
    connect(buttonsave,SIGNAL(clicked()),this,SLOT(slotSvaeImage()));
    connect(buttonopen,SIGNAL(clicked()),this,SLOT(slotOpenImage()));

    connect(scene,&widgetscens::sGetMousepos,[=](QPointF p){
        calibration->TextAppend("mouse pos:("+QString::number(p.x())+","+QString::number(p.y())+")");
    });


    connect(models,&Models::sSaveModel,this,&mainWidget::MOslotSaveMode);
    connect(models,&Models::sUpLoadModel,this,&mainWidget::MOslotUploadMode);
    connect(models,&Models::sSendName,this,&mainWidget::MOslotSendName);
    connect(models,&Models::sChooceModels,this,&mainWidget::MOslotChooceModels);
    connect(models,&Models::sChangeModelR,[=](){ view->setDragMode(QGraphicsView::RubberBandDrag);
                                                 viewmodel = true;
                                               });
    connect(models,&Models::sChangeModelS,[=](){ view->setDragMode(QGraphicsView::ScrollHandDrag);
                                                 viewmodel = false;
                                               });

    connect(simulate,&Simulate::sSimulateSend,this,&mainWidget::SISimulateSend);

    connect(matching,&Matching::sSendStartMatch,this,&mainWidget::MAslotSendStartMatch);
    connect(matching,&Matching::sSendSetDeviate,this,&mainWidget::MAslotSendSetDeviate);
    connect(matching,&Matching::sSendOneMatch,this,&mainWidget::MAslotSendgOneMatch);
    connect(matching,&Matching::sSendManyMatch,this,&mainWidget::MAslotSendManyMatch);


    connect(calibration,&Calibration::sSendCoordinate,this,&mainWidget::CAslotSend);//发送8个坐标
    connect(calibration,&Calibration::sGetIamge,[=](){
        if(!pixmap.isNull()){
        pixmap.save("./_img_.jpg");
        calibration->CalculationXYR();}
        });

    connect(connection,&Connect::sConnectServer,this,&mainWidget::COslotConnect);//连接服务器,接收图像
    connect(connection,&Connect::sWriteData,[=](QString str){
        qDebug() << str;
        socket->write(str.toLatin1().data());
    });

    connect(imageshow,&ImageShow::sWriteParameter,[=](QString str){
        qDebug() << str;
        socket->write(str.toLatin1().data());
    });

    connect(connection,&Connect::sStop,[=](){

        });
    connect(connection,&Connect::sStopData,[=](){
        socket->write("2");//2发送启动关闭接收图像指令
        socket->disconnectFromHost();
        socket->close();
        });
    connect(connection,&Connect::sDisConnect,this,[=](){
        socket->disconnectFromHost();
        socket->close();
        });

    connect(imageshow,SIGNAL(sProcessPictures()),this,SLOT(IAslotProcessImage()));
    connect(imageshow,SIGNAL(sProcessPictures3()),this,SLOT(IAslotProcessImage3()));
    connect(imageshow,SIGNAL(sSendParam()),this,SLOT(IAslotSendParam()));
    connect(imageshow,SIGNAL(sSendParam2()),this,SLOT(IAslotSendParam2()));
    connect(imageshow,&ImageShow::sChooseImage,this,&mainWidget::IAslotChooseImage);

    connect(imageshow,&ImageShow::writeData,[=](QString str){
        qDebug() << str;
        socket->write(str.toLatin1().data());

    });
}



void mainWidget::MAslotSendStartMatch(QString str)
{
    socket->write("0");
  //  QThread::msleep(100);
   // socket->write(str.toLatin1().data());//00原图（畸变前工作
}
void mainWidget::MAslotSendgOneMatch(QString str)
{
    socket->write(("7" + str).toLatin1().data());
    qDebug() <<str;
}

void mainWidget::MAslotSendSetDeviate(QString str)
{
    qDebug() << str;
    socket->write("5");
    QThread::msleep(100);
    socket->write(str.toLatin1().data());//05模式选择
}
void mainWidget::MAslotSendManyMatch(QString str)
{

    socket->write("5");
    QThread::msleep(100);

}
//PIC1
void mainWidget::IAslotSendParam()
{
    socket->write("8");
    QThread::msleep(100);

}

//PIC3

void mainWidget::IAslotSendParam2()
{
    socket->write("9");
    QThread::msleep(100);

}



void mainWidget::slotReadbuf()
{

    QByteArray buf_ = socket->readAll();
    char *buf = (char *)buf_.data();
    char str[5];
    strncpy(str,buf,5);
    if(strncmp(str,"0x03:",5) == 0)
    {
        calibration->TextAppend("Cabliretion Ok");
    }
    else if(strncmp(str,"Image",5) ==0)
    {
      simulate->TextAppend(QString(buf));
    }
    else if(strncmp(str,"0x05:",5) ==0)
    {
        models->textAppend("success!");
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
        {
            models->textAppend("File Open error");
            return;
        }
        SendPixmapModel(&file,(qint64)filesize_.toInt());
        file.close();

    }
    else if(strncmp(str,"0x01:",5) ==0)
    {
        simulate->TextAppend(QString(buf));
         }
    else if(strncmp(str,"0x02:",5) ==0)
    {
        simulate->TextAppend(QString(buf));
         }
    else if(strncmp(str,"0x00:",5) ==0)
    {
            simulate->TextAppend(QString(buf ));
             }
    else if(strncmp(str,"0x09:",5) ==0)
    {
        matching->TextAppend(QString(buf + 5));
    }
}

void mainWidget::slotSvaeImage()
{
    QString path = QFileDialog::getSaveFileName(this,"存储路径","pixmap","文件选择(*.png)");

   if(pixmap.save(path))
       calibration->TextAppend("Picture saved successfully!");
   else
       calibration->TextAppend("<font color='red'>Picture saved failed!</font>");

   namei++;
}

void mainWidget::slotOpenImage()
{
    QString path = QFileDialog::getOpenFileName(this,"选择图片","","(*.png)");
    if(path == "") return;
    calibration->TextAppend("Picture path:"+path);

    cvpath = path;
    //cvpixmap.loadPixmap(path.toStdString());
//    image_copy = cvpixmap.houghCirclesForNearestCircle();
    pixmap.load(path);
    fpixmap->setPixmap(pixmap);
   view->update();
}

void mainWidget::COslotConnect(QString strIP,int port,ImageThread *imgt)
{
    socket->connectToHost(strIP,port);
    imgt->start();

    connect(imgt,&ImageThread::sReadImage,[&](QPixmap *pixmap_){
        RecvImage(pixmap_);
        pixmap = *pixmap_;
    });
}

void mainWidget::CAslotSend(double *co)
{

       bool b=true;
       QByteArray byte;
       for(int i=0;i<16;i++){
           if(b){
              byte.append(QString::number(co[i]) + "&");
              b=false; }
           else{
                   byte.append(QString::number(co[i]) + "&");
              b=true;

           }
       }

   calibration->TextAppend("Send:"+byte);
   qDebug() << byte;
   socket->write("3");//3发送标定数据
   QThread::msleep(100);
   socket->write(byte.data());
}

void mainWidget::SISimulateSend(QString str)
{
    socket->write(("4&"+str).toLatin1().data());//04模拟发送数据
}

void mainWidget::MOslotSendName(QString str)
{
   qint64 len = socket->write(("6" + str).toLatin1().data());
   if(len > 0){
       models->textAppend(str + " Send Success");
   }
   else{
       models->textAppend(str + " Send Fail");
   }
}

void mainWidget::MOslotUploadMode()
{
    path = QFileDialog::getOpenFileName(this,
                                                "选择图片",
                                                 "",
                                                 "jpg文件(*.jpg)");
    if(path.isNull())
        return;
    QFileInfo info(path);
    filename_ = info.fileName();
    filesize_ = QString::number(info.size());

    qint64 len = socket->write(("5"+filename_ + "&" + filesize_).toLatin1().data());// (char*)filename&filesize
    //qDebug() <<( "5"+filename_ + "&" + filesize_).toLatin1().data() << "len:  " << len;
    if(len < 0)
    {
        models->textAppend("head send error");
        return;
    }
    //QThread::msleep(2000);
    qDebug() << "int " << filesize_.toInt();
    qDebug()<< "long long " << filesize_;

}

void mainWidget::MOslotSaveMode()
{
    if(viewmodel == false){
        QMessageBox::warning(this,"提示","请选择框选模式！");
        return;
    }

    QString savepath = QFileDialog::getSaveFileName(this,
                                                    "保存图片",
                                                    "Model.png",
                                                    "文件类型(*.png)");
    if(savepath.isNull())
        return;
    QPixmap pm;
    if(scene->xt() < scene->xb() && scene->yt() < scene->yb())
        pm = pixmap.copy(QRect(QPoint(scene->xt(),scene->yt()),QPoint(scene->xb(),scene->yb())));
    else if(scene->xt() > scene->xb() && scene->yt() > scene->yb())
        pm = pixmap.copy(QRect(QPoint(scene->xb(),scene->yb()),QPoint(scene->xt(),scene->yt())));
    else if(scene->xt() > scene->xb() && scene->yt() < scene->yb())
        pm = pixmap.copy(QRect(QPoint(scene->xb(),scene->yt()),QPoint(scene->xt(),scene->yb())));
    else
        pm = pixmap.copy(QRect(QPoint(scene->xt(),scene->yb()),QPoint(scene->xb(),scene->yt())));
    pm.save(savepath);
}

void mainWidget::MOslotChooceModels()
{
    QVector<int> v;
    for(int i=0;i<20;i++)
        v.append(i+1);
    ChooseDialog dialog(v);
    dialog.setWindowTitle("模板选择");
    ChooseDialog::connect(&dialog,&ChooseDialog::sClickOk,[=](QString str){
        qDebug() << str;
        models->textAppend("send " + str+" successful");
        socket->write(("6"+str).toLatin1().data());
    });
    dialog.exec();
}

void mainWidget::RecvImage(QPixmap *pixmap)
{
           qDebug() << *pixmap;
           fpixmap->setPixmap(*pixmap);
           view->update();
}

void mainWidget::SendPixmapModel(QFile *file,qint64 size)
{
   qint64 sendlen = 0;
   qint64 len;
   do{
      len = 0;
      char buf[1024] = {0};
      len = file->read(buf,sizeof(buf));
      len = socket->write(buf,len);
      sendlen += len;
   }while(len>0);
   if(sendlen != size){
      models->textAppend("ERROR，The picture is not fully sent or the server is not open");
      return;
   }
}

void mainWidget::analy(char *buf,double *i1,double *i2,double *i3,int *i_)
{
    //*i_ = *(buf+2) - '0';
    buf=buf+5;
    //printf("%s",buf);

    short i=0;
    int num=0;
    short l=0;

    while(buf[i] != '&'){
        if(buf[i] == '.'){
            l = i;
            i++;
            continue;
        }
        //printf("%c",buf[i]);
        num = num*10 + buf[i]-'0';
        i++;
    }
    l = i-l-1;
    *i1 = (double)num;
   while(l){*i1 /= 10.0; l--;}


   l=i;
   i++;
   num=0;
   while(buf[i] != '&'){
        if(buf[i] == '.'){
            l = i;
            i++;
            continue;
        }
        num = num*10 + buf[i]-'0';
        i++;
    }
    l = i-l-1;
    *i2 = (double)num;
   while(l){*i2 /= 10.0; l--;}


   l=i;i++;
   short pd=0;
   if(buf[i] == '-') {
       i++;pd=1;
   }
   num=0;
   while(buf[i] != '&'){
        if(buf[i] == '.'){
            l = i;
            i++;
            continue;
        }
        num = num*10 + buf[i]-'0';
        i++;
    }
    l = i-l-1;
    *i3 = (double)num;
   while(l){*i3 /= 10.0; l--;}
   if(pd) {*i3=0-*i3;}

   *i_ = buf[i+1]-'0';

}



void mainWidget::IExposureAslotValueChange(int value,int type)
{
     double Exposure=value;
      QString str = QString::number(Exposure) + "&" ;
     socket->write(("b&"+str).toLatin1().data());//b设置曝光值

}

void mainWidget::IAslotChooseImage(int type)
{


    switch (type) {
    }

}

mainWidget::~mainWidget()
{
    socket->disconnectFromHost();
    socket->close();
}



