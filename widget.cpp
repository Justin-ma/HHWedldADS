#include "widget.h"
//#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPainter painter(this);
        lastPoint.setX(0);
        lastPoint.setY(0);
        endPoint.setX(0);
        endPoint.setY(0);// 初始化位置，这里不初始化也行，不过初始化是个好习惯.
//        path.moveTo(50,50);
//        path.lineTo(100,200);
//        path.addEllipse(100,200,50,50);     // 向path 中添加图形
        painter.setPen(Qt:: red);
        painter.setBrush(Qt::transparent);
        painter.drawPath(path);   // 绘制前面创建的path
        painter.drawRect(0,0,0,0);




}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
           lastPoint = event->pos();
       }

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
           endPoint = event->pos();
           update();//拖动时有痕迹

       }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
       endPoint = event->pos();
       update();
       }

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
      painter.setPen(Qt:: red);
      painter.setBrush(Qt::transparent);
        qDebug()<<lastPoint;//移动前的位置
        path.translate(endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());//移动(可理解为向量移动)
        qDebug()<<endPoint;//移动后的位置
        painter.drawPath(path);//画出移动后的图形
        painter.drawRect(lastPoint.rx(),lastPoint.ry(),endPoint.rx()-lastPoint.rx(),endPoint.ry()-lastPoint.ry());
        //lastPoint = endPoint;
}
