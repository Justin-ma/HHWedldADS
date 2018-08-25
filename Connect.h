#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>
#include "ImageThread.h"

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = 0);
    ~Connect();

    bool isColorImg;
    senddata dt;

private:
    Ui::Connect *ui;

    ImageThread *imagethread;


signals:
    void sConnectServer(QString strIP,int port,ImageThread *imgt);
    void sDisConnect();
    void sStop();
    void sStopData();
    void sWriteData(QString str);//sWriteParameter


private slots:
    void on_buttonstart_clicked();
    void on_buttonstop_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_btExposure_clicked();
    void on_btGain_clicked();
   // void on_spinx0_valueChanged(int arg1);
    void on_spinx0_valueChanged(int arg1);
    void on_spindx_valueChanged(int arg1);
    void on_spiny0_valueChanged(int arg1);
    void on_spindy_valueChanged(int arg1);
    void on_comboBox_2_currentIndexChanged(int index);
};

#endif // CONNECT_H
