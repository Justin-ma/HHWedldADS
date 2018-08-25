#include "Simulate.h"
#include <QHBoxLayout>


Simulate::Simulate(QWidget *parent) : QWidget(parent)
{
   //timer = new QTimer(this);

   //界面////////////////////////////////////////////////////////////////////
   groupclient = new QGroupBox("Client");
   groupserver = new QGroupBox("Server");
   textclient  = new QTextBrowser;
   textserver  = new QTextBrowser;
   buttonclear = new QPushButton("Clear");
   buttonsimulate = new QPushButton("Start the Simulate");
   lay = new QGridLayout(this);

   QHBoxLayout *lay1 = new QHBoxLayout;
   lay1->addWidget(textclient);
   QHBoxLayout *lay2 = new QHBoxLayout;
   lay2->addWidget(textserver);
   groupclient->setLayout(lay1);
   groupserver->setLayout(lay2);

   edit = new QLineEdit;
   editx = new QLineEdit;
   edity = new QLineEdit;
   labelx = new QLabel("        X:");
   labely = new QLabel("        Y:");

   lay->addWidget(groupserver,0,0,1,3);
   lay->addWidget(groupclient,1,0,1,3);
   lay->addWidget(labelx,2,0);
   lay->addWidget(labely,3,0);
   lay->addWidget(editx,2,1,1,2);
   lay->addWidget(edity,3,1,1,2);
   lay->addWidget(buttonclear,4,0);
   lay->addWidget(buttonsimulate,4,1);
   lay->addWidget(edit,4,2);
   lay->setRowStretch(3,1);
   // ///////////////////////////////////////////////////////////////////////////

   connect(buttonclear,SIGNAL(clicked()),this,SLOT(slotClear()));
   connect(buttonsimulate,&QPushButton::clicked,[&]()
   {
       //timer->start(5000);
       //connect(timer,SIGNAL(timeout()),this,SLOT(slotSimulateSend()));
       if(editx->text() == "" || edity->text() == ""){
           editx->setText("1.1234");
           edity->setText("3.4567");
       }

       textclient->append("Send: X:" + editx->text() + ",Y:" + edity->text());
       emit sSimulateSend(edit->text()+ "&" + editx->text() + "&" + edity->text()+ "&");
   });

}


void Simulate::slotClear()
{
    textclient->clear();
    textserver->clear();
}

void Simulate::TextAppend(double *xp,double *yp,double *a,int *attr)
{
    // textserver->append(QString::number(xp));
}
void Simulate::analy(char* str,double *xp,double *yp,double *a,int *attr)
{
   // strncpy(str,buf,5);
    short i=0;
    int num=0;
    short l=0;

    while(str[i] != '&'){
        if(str[i] == '.'){
            l = i;
            i++;
            continue;
        }
        num = num*10 + str[i]-'0';
        i++;
    }
    l = i-2;
    *xp = (double)num;
   while(l){*xp /= 10.0; l--;}


   l=i;
   i++;
   num=0;
   while(str[i] != '&'){
        if(str[i] == '.'){
            l = i;
            i++;
            continue;
        }
        num = num*10 + str[i]-'0';
        i++;
    }
    l = i-l-1;
    *yp = (double)num;
   while(l){*yp /= 10.0; l--;}


   l=i;
   i++;
   num=0;
   while(str[i] != '&'){
        if(str[i] == '.'){
            l = i;
            i++;
            continue;
        }
        num = num*10 + str[i]-'0';
        i++;
    }
    l = i-l-1;
    *a = (double)num;
   while(l){*a /= 10.0; l--;}


   i++;
   while(str[i] != '\0'){
       *attr = *attr*10 + str[i]-'0';
       i++;
   }
}
void Simulate::TextAppend(QString str)
{
    textserver->append(str);
}
/*
void Simulate::slotSimulateSend()
{
      textclient->append("Send: X:1.1234,Y:3.4567");

      emit sSimulateSend();
}*/
