#include "ChooseDialog.h"
#include <QGridLayout>
#include <QListWidgetItem>
#include <QDebug>

ChooseDialog::ChooseDialog(QDialog *parent) : QDialog(parent)
{
   buttonOK = new QPushButton("确定");
   buttonCancel = new QPushButton("取消");
   listwidget = new QListWidget;

   QGridLayout *lay = new QGridLayout(this);
   lay->addWidget(listwidget,0,0,8,5);
   lay->addWidget(buttonOK,8,0,1,1);
   lay->addWidget(buttonCancel,8,4,1,1);

}

ChooseDialog::ChooseDialog(const QVector<int> &v)
{
    buttonOK = new QPushButton("确定");
    buttonCancel = new QPushButton("取消");
    listwidget = new QListWidget;

    QGridLayout *lay = new QGridLayout(this);
    lay->addWidget(listwidget,0,0,8,5);
    lay->addWidget(buttonOK,8,0,1,1);
    lay->addWidget(buttonCancel,8,4,1,1);

    for(int i=0;i<v.length();i++){
        QListWidgetItem *itme = new QListWidgetItem(QString::number(v.at(i)));
        itme->setCheckState(Qt::Unchecked);
        listwidget->addItem(itme);
    }

    connect(buttonOK,SIGNAL(clicked()),this,SLOT(slotClickOK()));
    connect(buttonCancel,SIGNAL(clicked()),this,SLOT(close()));

    setFixedSize(300,400);
}

void ChooseDialog::slotClickOK()
{
   int count = listwidget->count();
   QString str;

   for(int i=0;i<count;i++){
       if(listwidget->item(i)->checkState() == Qt::Checked)
           str += listwidget->item(i)->text() + "&";
   }

  str = str.left(str.length()-1);
  str += "#";

  emit sClickOk(str);
  close();
}
