#include "mainWidget.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    mainWidget w;
    w.setWindowTitle("Vc-Camera");
    w.setWindowIcon(QIcon(":/images/vc.png"));

    w.show();

   return a.exec();

}
