#include "widgetview.h"
#include <QScrollArea>
#include <QDebug>


widgetView::widgetView(QGraphicsView *parent) : QGraphicsView(parent)
{
   this->setDragMode(QGraphicsView::RubberBandDrag);
   zoom = value = 50;
}

void widgetView::wheelEvent(QWheelEvent * event)
{
    qreal s;
    if(event->delta() > 0){
        value += 1;
        if(value >= 300) value=300;
        s=pow(1.01,(value-zoom));
    }
    else{
        value -= 1;
        if(value <= -50) value=-50;
        s=pow(1/1.01,(zoom-value));
    }
    //qDebug() << s;
    scale(s,s);
    zoom = value;

}


