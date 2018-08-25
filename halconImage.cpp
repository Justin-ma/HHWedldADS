#include "halconImage.h"
#include "ui_halconimage.h"

HalconImage::HalconImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HalconImage)
{
    ui->setupUi(this);
}

HalconImage::~HalconImage()
{
    delete ui;
}
