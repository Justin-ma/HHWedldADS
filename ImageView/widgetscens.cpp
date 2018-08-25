#include "widgetscens.h"
#include <qDebug>

widgetscens::widgetscens(QGraphicsScene *parent) : QGraphicsScene(parent)
{
   rectitem = NULL;
}

void widgetscens::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sGetMousepos(event->scenePos());
    deleteRect();
    firstpos = event->scenePos();
}

void widgetscens::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    sGetMousepos(event->scenePos());
    lastpos = event->scenePos();
    setRect();
}

void widgetscens::deleteRect()
{
    if(rectitem != NULL)
        delete [] rectitem;

    rectitem = new QGraphicsRectItem(QRectF(firstpos,lastpos));
    rectitem->setPen(QPen(QBrush(Qt::transparent),1,Qt::DashLine));

    this->addItem(rectitem);
    update();
}

void widgetscens::setRect()
{
    if(rectitem != NULL)
        delete [] rectitem;

    rectitem = new QGraphicsRectItem(QRectF(firstpos,lastpos));
    rectitem->setPen(QPen(QBrush(QColor(42,126,212)),1,Qt::DashLine));

    this->addItem(rectitem);
    update();
}


double widgetscens::xt()
{
    return firstpos.x();
}

double widgetscens::yt()
{
    return firstpos.y();
}

double widgetscens::xb()
{
    return lastpos.x();
}

double widgetscens::yb()
{
    return lastpos.y();
}
