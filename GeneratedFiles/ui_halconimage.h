/********************************************************************************
** Form generated from reading UI file 'halconimage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALCONIMAGE_H
#define UI_HALCONIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HalconImage
{
public:

    void setupUi(QWidget *HalconImage)
    {
        if (HalconImage->objectName().isEmpty())
            HalconImage->setObjectName(QStringLiteral("HalconImage"));
        HalconImage->resize(332, 432);

        retranslateUi(HalconImage);

        QMetaObject::connectSlotsByName(HalconImage);
    } // setupUi

    void retranslateUi(QWidget *HalconImage)
    {
        HalconImage->setWindowTitle(QApplication::translate("HalconImage", "HalconImage", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HalconImage: public Ui_HalconImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALCONIMAGE_H
