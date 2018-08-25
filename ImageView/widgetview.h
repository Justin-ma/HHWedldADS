#ifndef WIDGETVIEW_H
#define WIDGETVIEW_H

#include <QGraphicsView>
#include <QPushButton>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QPixmap>


class widgetView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit widgetView(QGraphicsView *parent = 0);
    void wheelEvent(QWheelEvent *event);


private:
    int zoom;
    int value;  

signals:

public slots:
};

#endif // WIDGETVIEW_H
