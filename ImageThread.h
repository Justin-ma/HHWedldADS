#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QBuffer>
#include <QPixmap>
#include <QTime>

typedef struct {
int x0;
int y0;
int dx;
int dy;
int incrx;
int incry;
}senddata;

class ImageThread : public QThread
{
    Q_OBJECT
public:
    explicit ImageThread(senddata *dt_,bool *isColorImg_,QObject *parent = 0);
    void run();
    void connectHost(QString ip,int port);
    void disConnect();

    senddata *dt;
    int img_x;
    int img_y;
    int imgSize;
    bool *isColorImg;

private:
    QTcpSocket *socket;
    QByteArray buf;
    QByteArray head;
    QPixmap pixmap;
    int len;


signals:
    void sReadImage(QPixmap *pixmap);

public slots:
};

#endif // IMAGETHREAD_H
