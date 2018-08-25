/********************************************************************************
** Form generated from reading UI file '2dimageshow1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2DIMAGESHOW1_H
#define UI_2DIMAGESHOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *Image1;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLineEdit *ModelFileName;
    QLabel *label_8;
    QLineEdit *ImageFile;
    QLabel *label_9;
    QLineEdit *Numlevels;
    QLabel *label_33;
    QLabel *label_10;
    QLineEdit *InspectContrast;
    QLabel *label_34;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QLabel *label_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_Rectangleborder;
    QLabel *label_15;
    QLabel *label_3;
    QPushButton *pushButton_modelcenter;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_17;
    QLabel *label_23;
    QLineEdit *Contrast;
    QLabel *label_18;
    QLabel *label_11;
    QLabel *label_14;
    QTextBrowser *textmoudle;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushSetParam;
    QPushButton *pushcreatROI;
    QPushButton *pushButtonClean;
    QPushButton *pushSendRectangle;
    QPushButton *showclear;
    QPushButton *pushButton_13;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_6;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinRoiColumn;
    QDoubleSpinBox *doubleSpinRoiRow;
    QDoubleSpinBox *doubleSpinRoiLength1;
    QDoubleSpinBox *doubleSpinRoiLength2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_12;
    QPushButton *pushButtonFetchmodeSet;
    QLabel *label_16;
    QPushButton *pushButtonStandardmodeSet;
    QSpinBox *spinStandardmode;
    QSpacerItem *verticalSpacer;
    QSpinBox *spinBoxFetchmode;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QPushButton *pushButtonAngleQ;
    QPushButton *pushButtonCamRotY;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QDoubleSpinBox *spinTX2;
    QPushButton *pushButton_2;
    QDoubleSpinBox *spinMaxTY2;
    QDoubleSpinBox *doubleSpinTX1;
    QDoubleSpinBox *doubleSpinTY1;
    QPushButton *pushButtonCamRotZ;
    QDoubleSpinBox *doubleSpinAngleQ;
    QDoubleSpinBox *doubleSpinCamRotY;
    QDoubleSpinBox *doubleSpinCamRotZ;
    QPushButton *pushButtonPixDistance;
    QDoubleSpinBox *doubleSpinPixDistance;
    QWidget *tab_plc;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout;
    QPushButton *btnRR;
    QPushButton *btnStart;
    QPushButton *btnAnL;
    QPushButton *btnRL;
    QPushButton *btnWeldMode;
    QPushButton *btnLevelL;
    QPushButton *btnbbV;
    QPushButton *btnAnR;
    QPushButton *btnbbL;
    QPushButton *btnStop;
    QPushButton *btnZAxisR;
    QPushButton *btnbbAng;
    QPushButton *btnReset;
    QPushButton *btnZAxisL;
    QPushButton *btnRaR;
    QPushButton *btnRaL;
    QPushButton *btnWR;
    QPushButton *btnPause;
    QPushButton *btnLevelR;
    QPushButton *btnbbRad;
    QPushButton *btnWL;
    QPushButton *btnVerticalL;
    QPushButton *btnVerticalR;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(375, 583);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(9, 15, 449, 599));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setToolTipDuration(1);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Rounded);
        Image1 = new QWidget();
        Image1->setObjectName(QStringLiteral("Image1"));
        gridLayout_4 = new QGridLayout(Image1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(Image1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        ModelFileName = new QLineEdit(groupBox);
        ModelFileName->setObjectName(QStringLiteral("ModelFileName"));

        gridLayout_3->addWidget(ModelFileName, 0, 1, 1, 2);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        ImageFile = new QLineEdit(groupBox);
        ImageFile->setObjectName(QStringLiteral("ImageFile"));

        gridLayout_3->addWidget(ImageFile, 1, 1, 1, 2);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        Numlevels = new QLineEdit(groupBox);
        Numlevels->setObjectName(QStringLiteral("Numlevels"));

        gridLayout_3->addWidget(Numlevels, 2, 1, 1, 1);

        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_3->addWidget(label_33, 2, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        InspectContrast = new QLineEdit(groupBox);
        InspectContrast->setObjectName(QStringLiteral("InspectContrast"));

        gridLayout_3->addWidget(InspectContrast, 3, 1, 1, 1);

        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_3->addWidget(label_34, 3, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_4 = new QGroupBox(Image1);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 0, 2, 1, 1);

        pushButton_Rectangleborder = new QPushButton(groupBox_4);
        pushButton_Rectangleborder->setObjectName(QStringLiteral("pushButton_Rectangleborder"));

        gridLayout_2->addWidget(pushButton_Rectangleborder, 2, 2, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 2, 0, 1, 2);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        pushButton_modelcenter = new QPushButton(groupBox_4);
        pushButton_modelcenter->setObjectName(QStringLiteral("pushButton_modelcenter"));

        gridLayout_2->addWidget(pushButton_modelcenter, 1, 2, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 3, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 1, 1, 1, 1);

        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 5, 3, 1, 1);

        Contrast = new QLineEdit(groupBox_4);
        Contrast->setObjectName(QStringLiteral("Contrast"));

        gridLayout_2->addWidget(Contrast, 5, 2, 1, 1);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 5, 0, 1, 2);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 3, 1, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 3, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 1, 0, 1, 2);

        textmoudle = new QTextBrowser(Image1);
        textmoudle->setObjectName(QStringLiteral("textmoudle"));

        gridLayout_4->addWidget(textmoudle, 2, 0, 1, 1);

        groupBox_6 = new QGroupBox(Image1);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        pushSetParam = new QPushButton(groupBox_6);
        pushSetParam->setObjectName(QStringLiteral("pushSetParam"));

        verticalLayout_8->addWidget(pushSetParam);

        pushcreatROI = new QPushButton(groupBox_6);
        pushcreatROI->setObjectName(QStringLiteral("pushcreatROI"));

        verticalLayout_8->addWidget(pushcreatROI);

        pushButtonClean = new QPushButton(groupBox_6);
        pushButtonClean->setObjectName(QStringLiteral("pushButtonClean"));

        verticalLayout_8->addWidget(pushButtonClean);

        pushSendRectangle = new QPushButton(groupBox_6);
        pushSendRectangle->setObjectName(QStringLiteral("pushSendRectangle"));

        verticalLayout_8->addWidget(pushSendRectangle);

        showclear = new QPushButton(groupBox_6);
        showclear->setObjectName(QStringLiteral("showclear"));

        verticalLayout_8->addWidget(showclear);

        pushButton_13 = new QPushButton(groupBox_6);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        verticalLayout_8->addWidget(pushButton_13);


        gridLayout_4->addWidget(groupBox_6, 2, 1, 1, 1);

        tabWidget->addTab(Image1, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout->addWidget(label_13);

        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        doubleSpinRoiColumn = new QDoubleSpinBox(groupBox_5);
        doubleSpinRoiColumn->setObjectName(QStringLiteral("doubleSpinRoiColumn"));
        doubleSpinRoiColumn->setMaximum(1600);
        doubleSpinRoiColumn->setValue(800);

        verticalLayout_2->addWidget(doubleSpinRoiColumn);

        doubleSpinRoiRow = new QDoubleSpinBox(groupBox_5);
        doubleSpinRoiRow->setObjectName(QStringLiteral("doubleSpinRoiRow"));
        doubleSpinRoiRow->setMaximum(1024);
        doubleSpinRoiRow->setValue(600);

        verticalLayout_2->addWidget(doubleSpinRoiRow);

        doubleSpinRoiLength1 = new QDoubleSpinBox(groupBox_5);
        doubleSpinRoiLength1->setObjectName(QStringLiteral("doubleSpinRoiLength1"));
        doubleSpinRoiLength1->setMaximum(1280);
        doubleSpinRoiLength1->setValue(500);

        verticalLayout_2->addWidget(doubleSpinRoiLength1);

        doubleSpinRoiLength2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinRoiLength2->setObjectName(QStringLiteral("doubleSpinRoiLength2"));
        doubleSpinRoiLength2->setMaximum(1024);
        doubleSpinRoiLength2->setValue(500);

        verticalLayout_2->addWidget(doubleSpinRoiLength2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_12 = new QPushButton(groupBox_5);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_3->addWidget(pushButton_12);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout_7->addWidget(groupBox_5, 4, 0, 1, 2);

        pushButtonFetchmodeSet = new QPushButton(groupBox_3);
        pushButtonFetchmodeSet->setObjectName(QStringLiteral("pushButtonFetchmodeSet"));

        gridLayout_7->addWidget(pushButtonFetchmodeSet, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_7->addWidget(label_16, 3, 0, 1, 2);

        pushButtonStandardmodeSet = new QPushButton(groupBox_3);
        pushButtonStandardmodeSet->setObjectName(QStringLiteral("pushButtonStandardmodeSet"));

        gridLayout_7->addWidget(pushButtonStandardmodeSet, 0, 0, 1, 1);

        spinStandardmode = new QSpinBox(groupBox_3);
        spinStandardmode->setObjectName(QStringLiteral("spinStandardmode"));
        spinStandardmode->setMinimum(1);
        spinStandardmode->setMaximum(1);

        gridLayout_7->addWidget(spinStandardmode, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 5, 0, 1, 1);

        spinBoxFetchmode = new QSpinBox(groupBox_3);
        spinBoxFetchmode->setObjectName(QStringLiteral("spinBoxFetchmode"));
        spinBoxFetchmode->setMaximum(0);

        gridLayout_7->addWidget(spinBoxFetchmode, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButtonAngleQ = new QPushButton(groupBox_2);
        pushButtonAngleQ->setObjectName(QStringLiteral("pushButtonAngleQ"));

        gridLayout_5->addWidget(pushButtonAngleQ, 4, 0, 1, 1);

        pushButtonCamRotY = new QPushButton(groupBox_2);
        pushButtonCamRotY->setObjectName(QStringLiteral("pushButtonCamRotY"));

        gridLayout_5->addWidget(pushButtonCamRotY, 5, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_5->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_5->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);

        spinTX2 = new QDoubleSpinBox(groupBox_2);
        spinTX2->setObjectName(QStringLiteral("spinTX2"));
        spinTX2->setDecimals(3);
        spinTX2->setMinimum(0);
        spinTX2->setMaximum(10000);
        spinTX2->setSingleStep(0.001);
        spinTX2->setValue(5);

        gridLayout_5->addWidget(spinTX2, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 1, 0, 1, 1);

        spinMaxTY2 = new QDoubleSpinBox(groupBox_2);
        spinMaxTY2->setObjectName(QStringLiteral("spinMaxTY2"));
        spinMaxTY2->setDecimals(3);
        spinMaxTY2->setMinimum(0);
        spinMaxTY2->setMaximum(10000);
        spinMaxTY2->setSingleStep(0.1);
        spinMaxTY2->setValue(70);

        gridLayout_5->addWidget(spinMaxTY2, 3, 1, 1, 1);

        doubleSpinTX1 = new QDoubleSpinBox(groupBox_2);
        doubleSpinTX1->setObjectName(QStringLiteral("doubleSpinTX1"));
        doubleSpinTX1->setDecimals(3);
        doubleSpinTX1->setMaximum(50000);
        doubleSpinTX1->setSingleStep(0.01);
        doubleSpinTX1->setValue(140);

        gridLayout_5->addWidget(doubleSpinTX1, 0, 1, 1, 1);

        doubleSpinTY1 = new QDoubleSpinBox(groupBox_2);
        doubleSpinTY1->setObjectName(QStringLiteral("doubleSpinTY1"));
        doubleSpinTY1->setDecimals(3);
        doubleSpinTY1->setMaximum(99999);
        doubleSpinTY1->setSingleStep(0.01);
        doubleSpinTY1->setValue(220);

        gridLayout_5->addWidget(doubleSpinTY1, 1, 1, 1, 1);

        pushButtonCamRotZ = new QPushButton(groupBox_2);
        pushButtonCamRotZ->setObjectName(QStringLiteral("pushButtonCamRotZ"));

        gridLayout_5->addWidget(pushButtonCamRotZ, 6, 0, 1, 1);

        doubleSpinAngleQ = new QDoubleSpinBox(groupBox_2);
        doubleSpinAngleQ->setObjectName(QStringLiteral("doubleSpinAngleQ"));
        doubleSpinAngleQ->setDecimals(4);
        doubleSpinAngleQ->setMinimum(-399.9);
        doubleSpinAngleQ->setMaximum(399.99);
        doubleSpinAngleQ->setValue(0);

        gridLayout_5->addWidget(doubleSpinAngleQ, 4, 1, 1, 1);

        doubleSpinCamRotY = new QDoubleSpinBox(groupBox_2);
        doubleSpinCamRotY->setObjectName(QStringLiteral("doubleSpinCamRotY"));
        doubleSpinCamRotY->setDecimals(4);
        doubleSpinCamRotY->setMinimum(-999);
        doubleSpinCamRotY->setMaximum(999);
        doubleSpinCamRotY->setValue(0);

        gridLayout_5->addWidget(doubleSpinCamRotY, 5, 1, 1, 1);

        doubleSpinCamRotZ = new QDoubleSpinBox(groupBox_2);
        doubleSpinCamRotZ->setObjectName(QStringLiteral("doubleSpinCamRotZ"));
        doubleSpinCamRotZ->setMinimum(-999);
        doubleSpinCamRotZ->setMaximum(999.99);
        doubleSpinCamRotZ->setValue(0);

        gridLayout_5->addWidget(doubleSpinCamRotZ, 6, 1, 1, 1);

        pushButtonPixDistance = new QPushButton(groupBox_2);
        pushButtonPixDistance->setObjectName(QStringLiteral("pushButtonPixDistance"));

        gridLayout_5->addWidget(pushButtonPixDistance, 7, 0, 1, 1);

        doubleSpinPixDistance = new QDoubleSpinBox(groupBox_2);
        doubleSpinPixDistance->setObjectName(QStringLiteral("doubleSpinPixDistance"));
        doubleSpinPixDistance->setDecimals(4);
        doubleSpinPixDistance->setValue(9.18);

        gridLayout_5->addWidget(doubleSpinPixDistance, 7, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_plc = new QWidget();
        tab_plc->setObjectName(QStringLiteral("tab_plc"));
        groupBox_7 = new QGroupBox(tab_plc);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 330, 351, 201));
        groupBox_7->setLayoutDirection(Qt::LeftToRight);
        groupBox_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        gridLayout = new QGridLayout(groupBox_7);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnRR = new QPushButton(groupBox_7);
        btnRR->setObjectName(QStringLiteral("btnRR"));
        sizePolicy.setHeightForWidth(btnRR->sizePolicy().hasHeightForWidth());
        btnRR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnRR, 1, 5, 1, 1);

        btnStart = new QPushButton(groupBox_7);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        sizePolicy.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnStart->setFont(font);
        btnStart->setStyleSheet(QStringLiteral("color: rgb(0, 255, 0);"));
        btnStart->setCheckable(false);
        btnStart->setChecked(false);

        gridLayout->addWidget(btnStart, 4, 0, 1, 2);

        btnAnL = new QPushButton(groupBox_7);
        btnAnL->setObjectName(QStringLiteral("btnAnL"));
        sizePolicy.setHeightForWidth(btnAnL->sizePolicy().hasHeightForWidth());
        btnAnL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnAnL, 3, 2, 1, 1);

        btnRL = new QPushButton(groupBox_7);
        btnRL->setObjectName(QStringLiteral("btnRL"));
        sizePolicy.setHeightForWidth(btnRL->sizePolicy().hasHeightForWidth());
        btnRL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnRL, 1, 3, 1, 2);

        btnWeldMode = new QPushButton(groupBox_7);
        btnWeldMode->setObjectName(QStringLiteral("btnWeldMode"));
        sizePolicy.setHeightForWidth(btnWeldMode->sizePolicy().hasHeightForWidth());
        btnWeldMode->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        btnWeldMode->setFont(font1);

        gridLayout->addWidget(btnWeldMode, 3, 3, 1, 2);

        btnLevelL = new QPushButton(groupBox_7);
        btnLevelL->setObjectName(QStringLiteral("btnLevelL"));
        sizePolicy.setHeightForWidth(btnLevelL->sizePolicy().hasHeightForWidth());
        btnLevelL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnLevelL, 1, 2, 1, 1);

        btnbbV = new QPushButton(groupBox_7);
        btnbbV->setObjectName(QStringLiteral("btnbbV"));
        sizePolicy.setHeightForWidth(btnbbV->sizePolicy().hasHeightForWidth());
        btnbbV->setSizePolicy(sizePolicy);
        btnbbV->setStyleSheet(QStringLiteral(""));
        btnbbV->setCheckable(false);
        btnbbV->setChecked(false);

        gridLayout->addWidget(btnbbV, 0, 0, 1, 1);

        btnAnR = new QPushButton(groupBox_7);
        btnAnR->setObjectName(QStringLiteral("btnAnR"));
        sizePolicy.setHeightForWidth(btnAnR->sizePolicy().hasHeightForWidth());
        btnAnR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnAnR, 3, 1, 1, 1);

        btnbbL = new QPushButton(groupBox_7);
        btnbbL->setObjectName(QStringLiteral("btnbbL"));
        sizePolicy.setHeightForWidth(btnbbL->sizePolicy().hasHeightForWidth());
        btnbbL->setSizePolicy(sizePolicy);
        btnbbL->setCheckable(false);
        btnbbL->setChecked(false);

        gridLayout->addWidget(btnbbL, 1, 0, 1, 1);

        btnStop = new QPushButton(groupBox_7);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        sizePolicy.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy);
        btnStop->setFont(font);
        btnStop->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
""));
        btnStop->setCheckable(false);
        btnStop->setChecked(false);

        gridLayout->addWidget(btnStop, 4, 4, 1, 2);

        btnZAxisR = new QPushButton(groupBox_7);
        btnZAxisR->setObjectName(QStringLiteral("btnZAxisR"));
        sizePolicy.setHeightForWidth(btnZAxisR->sizePolicy().hasHeightForWidth());
        btnZAxisR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnZAxisR, 0, 5, 1, 1);

        btnbbAng = new QPushButton(groupBox_7);
        btnbbAng->setObjectName(QStringLiteral("btnbbAng"));
        sizePolicy.setHeightForWidth(btnbbAng->sizePolicy().hasHeightForWidth());
        btnbbAng->setSizePolicy(sizePolicy);
        btnbbAng->setCheckable(false);
        btnbbAng->setChecked(false);

        gridLayout->addWidget(btnbbAng, 3, 0, 1, 1);

        btnReset = new QPushButton(groupBox_7);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        sizePolicy.setHeightForWidth(btnReset->sizePolicy().hasHeightForWidth());
        btnReset->setSizePolicy(sizePolicy);
        btnReset->setFont(font);
        btnReset->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        btnReset->setCheckable(false);
        btnReset->setChecked(false);

        gridLayout->addWidget(btnReset, 4, 2, 1, 2);

        btnZAxisL = new QPushButton(groupBox_7);
        btnZAxisL->setObjectName(QStringLiteral("btnZAxisL"));
        sizePolicy.setHeightForWidth(btnZAxisL->sizePolicy().hasHeightForWidth());
        btnZAxisL->setSizePolicy(sizePolicy);
        btnZAxisL->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(btnZAxisL, 0, 3, 1, 2);

        btnRaR = new QPushButton(groupBox_7);
        btnRaR->setObjectName(QStringLiteral("btnRaR"));
        sizePolicy.setHeightForWidth(btnRaR->sizePolicy().hasHeightForWidth());
        btnRaR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnRaR, 2, 1, 1, 1);

        btnRaL = new QPushButton(groupBox_7);
        btnRaL->setObjectName(QStringLiteral("btnRaL"));
        sizePolicy.setHeightForWidth(btnRaL->sizePolicy().hasHeightForWidth());
        btnRaL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnRaL, 2, 2, 1, 1);

        btnWR = new QPushButton(groupBox_7);
        btnWR->setObjectName(QStringLiteral("btnWR"));
        sizePolicy.setHeightForWidth(btnWR->sizePolicy().hasHeightForWidth());
        btnWR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnWR, 2, 3, 1, 2);

        btnPause = new QPushButton(groupBox_7);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        sizePolicy.setHeightForWidth(btnPause->sizePolicy().hasHeightForWidth());
        btnPause->setSizePolicy(sizePolicy);
        btnPause->setFont(font1);

        gridLayout->addWidget(btnPause, 3, 5, 1, 1);

        btnLevelR = new QPushButton(groupBox_7);
        btnLevelR->setObjectName(QStringLiteral("btnLevelR"));
        sizePolicy.setHeightForWidth(btnLevelR->sizePolicy().hasHeightForWidth());
        btnLevelR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnLevelR, 1, 1, 1, 1);

        btnbbRad = new QPushButton(groupBox_7);
        btnbbRad->setObjectName(QStringLiteral("btnbbRad"));
        sizePolicy.setHeightForWidth(btnbbRad->sizePolicy().hasHeightForWidth());
        btnbbRad->setSizePolicy(sizePolicy);
        btnbbRad->setCheckable(false);
        btnbbRad->setChecked(false);

        gridLayout->addWidget(btnbbRad, 2, 0, 1, 1);

        btnWL = new QPushButton(groupBox_7);
        btnWL->setObjectName(QStringLiteral("btnWL"));
        sizePolicy.setHeightForWidth(btnWL->sizePolicy().hasHeightForWidth());
        btnWL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnWL, 2, 5, 1, 1);

        btnVerticalL = new QPushButton(groupBox_7);
        btnVerticalL->setObjectName(QStringLiteral("btnVerticalL"));
        sizePolicy.setHeightForWidth(btnVerticalL->sizePolicy().hasHeightForWidth());
        btnVerticalL->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnVerticalL, 0, 1, 1, 1);

        btnVerticalR = new QPushButton(groupBox_7);
        btnVerticalR->setObjectName(QStringLiteral("btnVerticalR"));
        sizePolicy.setHeightForWidth(btnVerticalR->sizePolicy().hasHeightForWidth());
        btnVerticalR->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnVerticalR, 0, 2, 1, 1);

        tabWidget->addTab(tab_plc, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "Inspect_shape_model", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\345\234\260\345\235\200", Q_NULLPTR));
        ModelFileName->setText(QApplication::translate("Widget", "model1.shm", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\345\233\276\347\211\207\345\234\260\345\235\200", Q_NULLPTR));
        ImageFile->setText(QApplication::translate("Widget", "Model.png", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\351\207\221\345\255\227\345\241\224\347\272\247\346\225\260", Q_NULLPTR));
        Numlevels->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        label_33->setText(QApplication::translate("Widget", "01-10", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        InspectContrast->setText(QApplication::translate("Widget", "120", Q_NULLPTR));
        label_34->setText(QApplication::translate("Widget", "10-160", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Widget", "Creat_shape_model", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Widget", "\345\214\271\351\205\215\345\214\272\345\237\237ROI", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", " 0", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Widget", "\345\275\242\347\212\266\344\270\255\345\277\203", Q_NULLPTR));
        pushButton_Rectangleborder->setText(QApplication::translate("Widget", "\346\265\213\350\257\225\347\237\251\345\275\242\350\276\271\346\241\206", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "\346\265\213\350\257\225\347\252\227\345\217\243\351\232\217\347\211\251\344\275\223\347\247\273\345\212\250\345\222\214\346\227\213\350\275\254", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", " 1", Q_NULLPTR));
        pushButton_modelcenter->setText(QApplication::translate("Widget", "\346\250\241\346\235\277\347\237\251\345\275\242\350\276\271\346\241\206", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\250\241\346\235\277\345\214\271\351\205\215\357\274\210\345\237\272\344\272\216\345\275\242\347\212\266\357\274\211", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", " 2", Q_NULLPTR));
        label_17->setText(QApplication::translate("Widget", "\345\275\242\347\212\266\345\214\271\351\205\215\347\232\204\346\250\241\346\235\277", Q_NULLPTR));
        label_23->setText(QApplication::translate("Widget", "01-40", Q_NULLPTR));
        Contrast->setText(QApplication::translate("Widget", "20", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "                \345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\345\214\271\351\205\215\345\214\272\345\237\237ROI\345\217\202\346\225\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", " 3", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        pushSetParam->setText(QApplication::translate("Widget", "\347\241\256\350\256\244\345\217\202\346\225\260", Q_NULLPTR));
        pushcreatROI->setText(QApplication::translate("Widget", "\345\210\233\345\273\272\346\250\241\346\235\277/ROI", Q_NULLPTR));
        pushButtonClean->setText(QApplication::translate("Widget", "\346\270\205\351\231\244UI", Q_NULLPTR));
        pushSendRectangle->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\250\241\346\235\277\345\217\202\346\225\260", Q_NULLPTR));
        showclear->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\346\241\206\346\270\205\351\231\244", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\214\271\351\205\215ROI\345\217\202\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Image1), QApplication::translate("Widget", "\347\273\230\345\207\272\346\250\241\346\235\277", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\345\217\202\346\225\260\350\256\276\347\275\2562", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Widget", "\346\204\237\345\205\264\350\266\243\345\214\272\345\237\237\347\237\251\345\275\242ROI", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\344\270\255\345\277\203\347\202\271X\345\235\220\346\240\207", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "\344\270\255\345\277\203\347\202\271Y\345\235\220\346\240\207", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\347\237\251\345\275\242\351\225\277\345\272\246", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "\347\237\251\345\275\242\345\256\275\345\272\246", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Widget", "ROI\350\256\276\347\275\256", Q_NULLPTR));
        pushButtonFetchmodeSet->setText(QApplication::translate("Widget", "\350\277\220\350\241\214\346\250\241\345\274\217", Q_NULLPTR));
        label_16->setText(QString());
        pushButtonStandardmodeSet->setText(QApplication::translate("Widget", "\350\260\203\350\257\225\346\250\241\345\274\217", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\217\202\346\225\260\350\256\276\347\275\2561", Q_NULLPTR));
        pushButtonAngleQ->setText(QApplication::translate("Widget", "\345\256\211\350\243\205\350\247\222\345\272\246", Q_NULLPTR));
        pushButtonCamRotY->setText(QApplication::translate("Widget", "Tcp\345\210\260\347\233\270\346\234\272CamRotX", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "\350\276\271\347\274\230\346\243\200\346\265\213\344\275\216\351\230\210\345\200\274", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\350\276\271\347\274\230\346\243\200\346\265\213\351\253\230\351\230\210\345\200\274", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\345\206\205\345\234\206\345\215\212\345\276\204\357\274\210\345\215\212\345\276\204\344\270\213\351\231\220\357\274\211", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\345\244\226\345\234\206\345\215\212\345\276\204\357\274\210\345\215\212\345\276\204\344\270\212\351\231\220\357\274\211", Q_NULLPTR));
        pushButtonCamRotZ->setText(QApplication::translate("Widget", "Tcp\345\210\260\347\233\270\346\234\272CamRotY", Q_NULLPTR));
        pushButtonPixDistance->setText(QApplication::translate("Widget", "1mm\345\257\271\345\272\224\345\203\217\347\264\240\345\200\274", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\344\270\244\345\234\206\345\256\232\344\275\215", Q_NULLPTR));
        groupBox_7->setTitle(QString());
        btnRR->setText(QApplication::translate("Widget", "\345\217\215\350\275\254", Q_NULLPTR));
        btnStart->setText(QApplication::translate("Widget", "\347\204\212\346\216\245\345\220\257\345\212\250", Q_NULLPTR));
        btnAnL->setText(QApplication::translate("Widget", "\350\247\222\345\272\246\344\270\213", Q_NULLPTR));
        btnRL->setText(QApplication::translate("Widget", "\346\255\243\350\275\254", Q_NULLPTR));
        btnWeldMode->setText(QApplication::translate("Widget", "\346\211\213\345\212\250\347\204\212\346\216\245", Q_NULLPTR));
        btnLevelL->setText(QApplication::translate("Widget", "\345\220\216\347\247\273", Q_NULLPTR));
        btnbbV->setText(QApplication::translate("Widget", "\345\236\202\347\233\264", Q_NULLPTR));
        btnAnR->setText(QApplication::translate("Widget", "\350\247\222\345\272\246\344\270\212", Q_NULLPTR));
        btnbbL->setText(QApplication::translate("Widget", "\346\260\264\345\271\263", Q_NULLPTR));
        btnStop->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", Q_NULLPTR));
        btnZAxisR->setText(QApplication::translate("Widget", "Z\345\220\216\351\200\200", Q_NULLPTR));
        btnbbAng->setText(QApplication::translate("Widget", "\350\247\222\345\272\246", Q_NULLPTR));
        btnReset->setText(QApplication::translate("Widget", "\345\244\215\344\275\215", Q_NULLPTR));
        btnZAxisL->setText(QApplication::translate("Widget", "Z\345\211\215\350\277\233", Q_NULLPTR));
        btnRaR->setText(QApplication::translate("Widget", "\345\215\212\345\276\204\344\270\212", Q_NULLPTR));
        btnRaL->setText(QApplication::translate("Widget", "\345\215\212\345\276\204\344\270\213", Q_NULLPTR));
        btnWR->setText(QApplication::translate("Widget", "\351\200\201\344\270\235", Q_NULLPTR));
        btnPause->setText(QApplication::translate("Widget", "\346\232\202\345\201\234\344\272\214\345\220\257", Q_NULLPTR));
        btnLevelR->setText(QApplication::translate("Widget", "\345\211\215\347\247\273", Q_NULLPTR));
        btnbbRad->setText(QApplication::translate("Widget", "\345\215\212\345\276\204", Q_NULLPTR));
        btnWL->setText(QApplication::translate("Widget", "\346\212\275\344\270\235", Q_NULLPTR));
        btnVerticalL->setText(QApplication::translate("Widget", "\345\211\215\345\200\276", Q_NULLPTR));
        btnVerticalR->setText(QApplication::translate("Widget", "\345\220\216\344\273\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_plc), QApplication::translate("Widget", "PLC\346\216\247\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2DIMAGESHOW1_H
