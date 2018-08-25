#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QFile>
#include <QBuffer>
#include <QTcpSocket>
#include <QVector>

#include "Calibration.h"
#include "HandeyeCalib.h"
#include "Models.h"
#include "Matching.h"
#include "Connect.h"
#include "Simulate.h"
#include "ImageShow.h"
#include "halconImage.h"

#include "ImageView/widgetscens.h"
#include "ImageView/widgetview.h"

#include "ImageThread.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();

    void RecvImage(QPixmap *pixmap);
    void analy(char *buf,double *i1,double *i2,double *i3,int *i_);

    void SendPixmapModel(QFile *file,qint64 size);

private:  
    Calibration *calibration;
    HandeyeCalib *handeyecalib;
    Models *models;
    Matching *matching;
    Connect *connection;
    Simulate *simulate;
    ImageShow *imageshow;
    HalconImage *halconImage;

    QTabWidget *tabwidget;
    QLabel *labeltitle;
    QPushButton *buttonsave;
    QPushButton *buttonopen;

    widgetView *view;
    widgetscens *scene;
    QGraphicsPixmapItem *fpixmap;

    QGridLayout *lay;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;
    QTcpSocket *socket;

    int namei;
    bool viewmodel;
    QPixmap pixmap;
    QString path;
    QString filename_;
    QString filesize_;
    double xp,yp,a;
    int attr;
    QString cvpath;

signals:

public slots:
    void slotReadbuf();
    void slotSvaeImage();
    void slotOpenImage();
    void CAslotSend(double *co);
    void COslotConnect(QString strIP,int port,ImageThread *imgt);
    void SISimulateSend(QString str);
    void MAslotSendgOneMatch(QString str);
    void MAslotSendSetDeviate(QString str);
    void MAslotSendStartMatch(QString str);
    void MAslotSendManyMatch(QString str);
    void MOslotSaveMode();
    void MOslotUploadMode();
    void MOslotSendName(QString str);
    void MOslotChooceModels();
    void  IExposureAslotValueChange(int value,int type);//曝光值
    void IAslotSendParam();
    void IAslotSendParam2();
    void IAslotChooseImage(int type);


};

#endif // MAINWIDGET_H
