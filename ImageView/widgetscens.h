#ifndef WIDGETSCENS_H
#define WIDGETSCENS_H

#include <QPoint>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class widgetscens : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit widgetscens(QGraphicsScene *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setRect();
    void deleteRect();

    double xt();
    double yt();
    double xb();
    double yb();

private:
    QGraphicsRectItem *rectitem;
    QPointF firstpos;
    QPointF lastpos;


signals:
    void sGetMousepos(QPointF p);

public slots:
};

#endif // WIDGETSCENS_H
