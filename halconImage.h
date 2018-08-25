#ifndef HALCONIMAGE_H
#define HALCONIMAGE_H

#include <QWidget>

namespace Ui {
class HalconImage;
}

class HalconImage : public QWidget
{
    Q_OBJECT

public:
    explicit HalconImage(QWidget *parent = 0);
    ~HalconImage();

private:
    Ui::HalconImage *ui;
};

#endif // HALCONIMAGE_H
