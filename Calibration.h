#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QSpinBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QGridLayout>
class Calibration : public QWidget
{
    Q_OBJECT
public:
    explicit Calibration(QWidget *parent = 0);

    void TextAppend(QString str);
    void CalculationXYR();

private:
    //camera栏的物件
    QLineEdit *editcamerax1;
    QLineEdit *editcamerax2;
    QLineEdit *editcamerax3;
    QLineEdit *editcamerax4;
    QLineEdit *editcameray1;
    QLineEdit *editcameray2;
    QLineEdit *editcameray3;
    QLineEdit *editcameray4;

    //robot栏的物件
    QLineEdit *editrobotx1;
    QLineEdit *editrobotx2;
    QLineEdit *editrobotx3;
    QLineEdit *editrobotx4;
    QLineEdit *editroboty1;
    QLineEdit *editroboty2;
    QLineEdit *editroboty3;
    QLineEdit *editroboty4;

    QTextBrowser *text;

    //Action栏的物件
    QSpinBox *spinbox;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;


    //分类栏
    QGroupBox *groupcamera;
    QGroupBox *grouprobot;
    QGroupBox *groupaction;
    QGroupBox *groupbutton;

    //布局
    QGridLayout *laycamera;
    QGridLayout *layrobot;
    QGridLayout *layaction;
    QGridLayout *laybutton;
     QVBoxLayout *vlay;
     QPixmap pixmap;

signals:
     void sSendCoordinate(double *co);
     void sGetIamge();

public slots:
     void slotSend();
     void slotGetxy();
};

#endif // CALIBRATION_H
