/********************************************************************************
** Form generated from reading UI file 'handeyecalib.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDEYECALIB_H
#define UI_HANDEYECALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandeyeCalib
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *edit_LImgPath;
    QLineEdit *edit_LParamePath;
    QLineEdit *edit_LCaltabName;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *edit_LFirstImgPath;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QDoubleSpinBox *spin_Focus;
    QDoubleSpinBox *spin_Kappa;
    QLabel *label_5;
    QDoubleSpinBox *spin_Sx;
    QDoubleSpinBox *spin_Sy;
    QLabel *label_6;
    QDoubleSpinBox *spin_Cx;
    QDoubleSpinBox *spin_Cy;
    QLabel *label_7;
    QDoubleSpinBox *spin_Width;
    QDoubleSpinBox *spin_Height;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushSetCalibParam;
    QPushButton *btnCalibInternal;
    QPushButton *pushButtonClean;
    QPushButton *pushSendCalibparam;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *HandeyeCalib)
    {
        if (HandeyeCalib->objectName().isEmpty())
            HandeyeCalib->setObjectName(QStringLiteral("HandeyeCalib"));
        HandeyeCalib->resize(400, 520);
        gridLayout_4 = new QGridLayout(HandeyeCalib);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(HandeyeCalib);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        edit_LImgPath = new QLineEdit(groupBox_2);
        edit_LImgPath->setObjectName(QStringLiteral("edit_LImgPath"));

        gridLayout_2->addWidget(edit_LImgPath, 2, 1, 1, 1);

        edit_LParamePath = new QLineEdit(groupBox_2);
        edit_LParamePath->setObjectName(QStringLiteral("edit_LParamePath"));

        gridLayout_2->addWidget(edit_LParamePath, 3, 1, 1, 1);

        edit_LCaltabName = new QLineEdit(groupBox_2);
        edit_LCaltabName->setObjectName(QStringLiteral("edit_LCaltabName"));

        gridLayout_2->addWidget(edit_LCaltabName, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        edit_LFirstImgPath = new QLineEdit(groupBox_2);
        edit_LFirstImgPath->setObjectName(QStringLiteral("edit_LFirstImgPath"));

        gridLayout_2->addWidget(edit_LFirstImgPath, 1, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(HandeyeCalib);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        spin_Focus = new QDoubleSpinBox(groupBox);
        spin_Focus->setObjectName(QStringLiteral("spin_Focus"));
        spin_Focus->setDecimals(3);
        spin_Focus->setMaximum(1);
        spin_Focus->setSingleStep(0.0001);
        spin_Focus->setValue(0.016);

        gridLayout->addWidget(spin_Focus, 0, 1, 1, 1);

        spin_Kappa = new QDoubleSpinBox(groupBox);
        spin_Kappa->setObjectName(QStringLiteral("spin_Kappa"));
        spin_Kappa->setDecimals(1);
        spin_Kappa->setMinimum(-1000);
        spin_Kappa->setMaximum(1000);
        spin_Kappa->setSingleStep(0.1);

        gridLayout->addWidget(spin_Kappa, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        spin_Sx = new QDoubleSpinBox(groupBox);
        spin_Sx->setObjectName(QStringLiteral("spin_Sx"));
        spin_Sx->setDecimals(2);
        spin_Sx->setMaximum(100);
        spin_Sx->setSingleStep(0.1);
        spin_Sx->setValue(4.5);

        gridLayout->addWidget(spin_Sx, 1, 1, 1, 1);

        spin_Sy = new QDoubleSpinBox(groupBox);
        spin_Sy->setObjectName(QStringLiteral("spin_Sy"));
        spin_Sy->setMaximum(100);
        spin_Sy->setSingleStep(0.1);
        spin_Sy->setValue(4.5);

        gridLayout->addWidget(spin_Sy, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        spin_Cx = new QDoubleSpinBox(groupBox);
        spin_Cx->setObjectName(QStringLiteral("spin_Cx"));
        spin_Cx->setDecimals(0);
        spin_Cx->setMaximum(1000);
        spin_Cx->setValue(400);

        gridLayout->addWidget(spin_Cx, 2, 1, 1, 1);

        spin_Cy = new QDoubleSpinBox(groupBox);
        spin_Cy->setObjectName(QStringLiteral("spin_Cy"));
        spin_Cy->setDecimals(0);
        spin_Cy->setMaximum(1000);
        spin_Cy->setValue(400);

        gridLayout->addWidget(spin_Cy, 2, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        spin_Width = new QDoubleSpinBox(groupBox);
        spin_Width->setObjectName(QStringLiteral("spin_Width"));
        spin_Width->setDecimals(0);
        spin_Width->setMaximum(1400);
        spin_Width->setValue(800);

        gridLayout->addWidget(spin_Width, 3, 1, 1, 1);

        spin_Height = new QDoubleSpinBox(groupBox);
        spin_Height->setObjectName(QStringLiteral("spin_Height"));
        spin_Height->setDecimals(0);
        spin_Height->setMaximum(1400);
        spin_Height->setValue(800);

        gridLayout->addWidget(spin_Height, 3, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(HandeyeCalib);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushSetCalibParam = new QPushButton(groupBox_3);
        pushSetCalibParam->setObjectName(QStringLiteral("pushSetCalibParam"));

        gridLayout_3->addWidget(pushSetCalibParam, 0, 0, 1, 1);

        btnCalibInternal = new QPushButton(groupBox_3);
        btnCalibInternal->setObjectName(QStringLiteral("btnCalibInternal"));

        gridLayout_3->addWidget(btnCalibInternal, 0, 1, 1, 1);

        pushButtonClean = new QPushButton(groupBox_3);
        pushButtonClean->setObjectName(QStringLiteral("pushButtonClean"));

        gridLayout_3->addWidget(pushButtonClean, 1, 0, 1, 1);

        pushSendCalibparam = new QPushButton(groupBox_3);
        pushSendCalibparam->setObjectName(QStringLiteral("pushSendCalibparam"));

        gridLayout_3->addWidget(pushSendCalibparam, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 163, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(HandeyeCalib);

        QMetaObject::connectSlotsByName(HandeyeCalib);
    } // setupUi

    void retranslateUi(QWidget *HandeyeCalib)
    {
        HandeyeCalib->setWindowTitle(QApplication::translate("HandeyeCalib", "HandeyeCalib", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("HandeyeCalib", "\345\217\202\346\225\2601", Q_NULLPTR));
        edit_LImgPath->setText(QApplication::translate("HandeyeCalib", "calib/", Q_NULLPTR));
        edit_LParamePath->setText(QApplication::translate("HandeyeCalib", "calib/camera_parameters.dat", Q_NULLPTR));
        edit_LCaltabName->setText(QApplication::translate("HandeyeCalib", "calib/caltab_30mm.descr", Q_NULLPTR));
        label_3->setText(QApplication::translate("HandeyeCalib", "\345\206\231\345\205\245\345\217\202\346\225\260\345\234\260\345\235\200", Q_NULLPTR));
        label_8->setText(QApplication::translate("HandeyeCalib", "\351\246\226\345\274\240\345\233\276\347\211\207\345\234\260\345\235\200", Q_NULLPTR));
        edit_LFirstImgPath->setText(QApplication::translate("HandeyeCalib", "calib/calib_001.png", Q_NULLPTR));
        label->setText(QApplication::translate("HandeyeCalib", "\345\233\276\347\211\207\345\234\260\345\235\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("HandeyeCalib", "\346\240\207\345\256\232\346\235\277\345\234\260\345\235\200", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("HandeyeCalib", "\345\217\202\346\225\2602", Q_NULLPTR));
        label_4->setText(QApplication::translate("HandeyeCalib", "Focus\357\274\214Kappa", Q_NULLPTR));
        label_5->setText(QApplication::translate("HandeyeCalib", "Sx,Sy", Q_NULLPTR));
        label_6->setText(QApplication::translate("HandeyeCalib", "Cx,Cy", Q_NULLPTR));
        label_7->setText(QApplication::translate("HandeyeCalib", "Width,Height", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("HandeyeCalib", "GroupBox", Q_NULLPTR));
        pushSetCalibParam->setText(QApplication::translate("HandeyeCalib", "\347\241\256\350\256\244\345\217\202\346\225\260", Q_NULLPTR));
        btnCalibInternal->setText(QApplication::translate("HandeyeCalib", "\346\240\207\345\256\232\345\206\205\345\217\202", Q_NULLPTR));
        pushButtonClean->setText(QApplication::translate("HandeyeCalib", "\346\270\205\351\231\244UI", Q_NULLPTR));
        pushSendCalibparam->setText(QApplication::translate("HandeyeCalib", "\345\217\221\351\200\201\345\217\202\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HandeyeCalib: public Ui_HandeyeCalib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDEYECALIB_H
