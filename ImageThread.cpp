#include "ImageThread.h"

#include <QDebug>
ImageThread::ImageThread(senddata *dt_,bool *isColorImg_,QObject *parent) : QThread(parent)
{
   socket = new QTcpSocket(this);

   dt = dt_;
   img_x = dt->dx;
   img_y = dt->dy;
   imgSize = img_x*img_y*3;

   isColorImg = isColorImg_;
}


void ImageThread::run()
{
    qDebug() << "run";
    socket->write((char*)dt,sizeof(*dt));
    socket->flush();

    connect(socket,&QTcpSocket::readyRead,[=](){

            buf += socket->readAll();

              if(buf.length() == imgSize+28){

                  QByteArray buff = buf.remove(0,28);

                  if(*isColorImg){
                       QByteArray buff2;
                      for(int j = 0;j<img_y*img_x;j++)
                      {
                          buff2.append(buff[0*img_x*img_y+j]);
                          buff2.append(buff[1*img_x*img_y+j]);
                          buff2.append(buff[2*img_x*img_y+j]);
                      }
                      QImage im((uchar *)buff2.data(),img_x,img_y,QImage::Format_RGB888);
                      pixmap = QPixmap::fromImage(im);
                      emit sReadImage(&pixmap);

                  }else{

                      QImage im((uchar *)buff.data(),img_x,img_y,QImage::Format_Grayscale8);
                      pixmap = QPixmap::fromImage(im);
                      emit sReadImage(&pixmap);

                  }


                 buf.clear();
                 socket->write((char*)dt,sizeof(*dt));
                 //重置参数
                 img_x = dt->dx;
                 img_y = dt->dy;
                 imgSize = img_x*img_y*3;
             }
    });


   exec();
}

void ImageThread::connectHost(QString ip, int port)
{
    socket->connectToHost(ip,port);
    socket->waitForConnected();
}

void ImageThread::disConnect()
{
    socket->disconnect();
    socket->close();
}
