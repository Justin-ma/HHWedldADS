#include "Connect.h"
#include "ui_connect.h"

Connect::Connect(QWidget *parent) :QWidget(parent),ui(new Ui::Connect),
    isColorImg(true)
{
    ui->setupUi(this);

    dt.x0 = ui->spinx0->value();
    dt.y0 = ui->spiny0->value();
    dt.dx = ui->spindx->value();
    dt.dy = ui->spindy->value();
    dt.incrx = ui->spinix->value();
    dt.incry = ui->spiniy->value();

    imagethread = new ImageThread(&dt,&isColorImg,this);

}

Connect::~Connect()
{
    delete ui;
}


void Connect::on_buttonstart_clicked()
{
    QString strIP   = ui->editIP->text();
    QString imgPort = ui->editImg->text();
    QString dataPort = ui->editData->text();
    if(strIP == "" || imgPort == "" || dataPort == ""){
        return;
    }

    if(imagethread == NULL){
        imagethread = new ImageThread(&dt,&isColorImg,this);
    }

    dt.x0 = ui->spinx0->value();
    dt.y0 = ui->spiny0->value();
    dt.dx = ui->spindx->value();
    dt.dy = ui->spindy->value();
    dt.incrx = ui->spinix->value();
    dt.incry = ui->spiniy->value();

    sWriteData("b&" + QString::number(dt.x0) + "&"
                    + QString::number(dt.y0) + "&"
                    + QString::number(dt.dx) + "&"
                    + QString::number(dt.dy) + "&");
   // QThread::msleep(100);
    imagethread->connectHost(strIP,imgPort.toInt());
    emit sConnectServer(strIP,dataPort.toInt(),imagethread);
}

void Connect::on_buttonstop_clicked()
{
    //emit sStop();
    imagethread->disConnect();
    imagethread->exit();
    imagethread->deleteLater();
    imagethread = NULL;
}

void Connect::on_pushButton_clicked()
{
    emit sStopData();
}


void Connect::on_btExposure_clicked()
{
    emit sWriteData("d&" + QString::number(ui->spinExposure->value()) + "&");
}

void Connect::on_btGain_clicked()
{
    emit sWriteData("e&" + QString::number(ui->spinGain->value()) + "&");
}
void Connect::on_pushButton_2_clicked()
{
    emit sWriteData("f&" + QString::number(ui->comboBox->currentIndex()) + "&");
}

void Connect::on_spinx0_valueChanged(int arg1)
{
    int value = ui->spinx0->value() + ui->spindx->value();
    if(value > 1280){
      ui->spindx->setValue(1280-(ui->spinx0->value()));
    }
}

void Connect::on_spindx_valueChanged(int arg1)
{
    int value = ui->spinx0->value() + ui->spindx->value();
    if(value > 1280){
        ui->spindx->setValue(1280-(ui->spinx0->value()));
    }
}

void Connect::on_spiny0_valueChanged(int arg1)
{
    int value = ui->spiny0->value() + ui->spindy->value();
    if(value > 1024){
        ui->spindy->setValue(1024-(ui->spiny0->value()));
    }
}

void Connect::on_spindy_valueChanged(int arg1)
{
    int value = ui->spiny0->value() + ui->spindy->value();
    if(value > 1024){
        ui->spindy->setValue(1024-(ui->spiny0->value()));
    }
}

void Connect::on_comboBox_2_currentIndexChanged(int index)
{
    isColorImg = !index;

}
