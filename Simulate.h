#ifndef SIMULATE_H
#define SIMULATE_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QTextBrowser>
#include <QLineEdit>
#include <QGridLayout>
#include <QTimer>
#include <QLabel>
#include <QDebug>
class Simulate : public QWidget
{
    Q_OBJECT
public:
    explicit Simulate(QWidget *parent = 0);
    void TextAppend(QString str);
    void analy(char* buf,double *xp,double *yp,double *a,int *attr);
    void TextAppend(double *xp,double *yp,double *a,int *attr);
private:
    QGroupBox *groupclient;
    QGroupBox *groupserver;
    QTextBrowser *textclient;//
    QTextBrowser *textserver;
    QPushButton *buttonsimulate;
    QPushButton *buttonclear;

    QLineEdit *editx;
    QLineEdit *edity;
    QLineEdit *edit;
    QLabel *labelx;
    QLabel *labely;

    QGridLayout *lay;
   // QTimer *timer;

signals:
    void sSimulateSend(QString str);

public slots:
    void slotClear();
    //void slotSimulateSend();
};

#endif // SIMULATE_H
