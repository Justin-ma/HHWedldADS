/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *editIP;
    QLabel *label_2;
    QLineEdit *editImg;
    QLabel *label_5;
    QLineEdit *editData;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QSpinBox *spinx0;
    QSpinBox *spiny0;
    QLabel *label_7;
    QSpinBox *spindx;
    QSpinBox *spindy;
    QLabel *label_8;
    QSpinBox *spinix;
    QSpinBox *spiniy;
    QPushButton *buttonstart;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *btExposure;
    QSpinBox *spinExposure;
    QSpinBox *spinGain;
    QPushButton *btGain;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *buttonstop;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName(QStringLiteral("Connect"));
        Connect->resize(355, 492);
        gridLayout_3 = new QGridLayout(Connect);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(Connect);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        editIP = new QLineEdit(Connect);
        editIP->setObjectName(QStringLiteral("editIP"));

        gridLayout_3->addWidget(editIP, 0, 1, 1, 2);

        label_2 = new QLabel(Connect);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        editImg = new QLineEdit(Connect);
        editImg->setObjectName(QStringLiteral("editImg"));

        gridLayout_3->addWidget(editImg, 1, 1, 1, 2);

        label_5 = new QLabel(Connect);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        editData = new QLineEdit(Connect);
        editData->setObjectName(QStringLiteral("editData"));

        gridLayout_3->addWidget(editData, 2, 1, 1, 2);

        groupBox_2 = new QGroupBox(Connect);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        spinx0 = new QSpinBox(groupBox_2);
        spinx0->setObjectName(QStringLiteral("spinx0"));
        spinx0->setMaximum(800);
        spinx0->setValue(0);

        gridLayout->addWidget(spinx0, 0, 1, 1, 1);

        spiny0 = new QSpinBox(groupBox_2);
        spiny0->setObjectName(QStringLiteral("spiny0"));
        spiny0->setMaximum(800);
        spiny0->setValue(0);

        gridLayout->addWidget(spiny0, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        spindx = new QSpinBox(groupBox_2);
        spindx->setObjectName(QStringLiteral("spindx"));
        spindx->setMaximum(1600);
        spindx->setValue(1600);

        gridLayout->addWidget(spindx, 1, 1, 1, 1);

        spindy = new QSpinBox(groupBox_2);
        spindy->setObjectName(QStringLiteral("spindy"));
        spindy->setMaximum(2000);
        spindy->setValue(1200);

        gridLayout->addWidget(spindy, 1, 2, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        spinix = new QSpinBox(groupBox_2);
        spinix->setObjectName(QStringLiteral("spinix"));
        spinix->setValue(1);

        gridLayout->addWidget(spinix, 2, 1, 1, 1);

        spiniy = new QSpinBox(groupBox_2);
        spiniy->setObjectName(QStringLiteral("spiniy"));
        spiniy->setValue(1);

        gridLayout->addWidget(spiniy, 2, 2, 1, 1);

        buttonstart = new QPushButton(groupBox_2);
        buttonstart->setObjectName(QStringLiteral("buttonstart"));

        gridLayout->addWidget(buttonstart, 4, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 3, 0, 1, 3);

        pushButton = new QPushButton(Connect);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 5, 0, 1, 1);

        groupBox = new QGroupBox(Connect);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btExposure = new QPushButton(groupBox);
        btExposure->setObjectName(QStringLiteral("btExposure"));

        gridLayout_2->addWidget(btExposure, 1, 0, 1, 1);

        spinExposure = new QSpinBox(groupBox);
        spinExposure->setObjectName(QStringLiteral("spinExposure"));
        spinExposure->setMaximum(30000);
        spinExposure->setValue(3000);

        gridLayout_2->addWidget(spinExposure, 1, 1, 1, 1);

        spinGain = new QSpinBox(groupBox);
        spinGain->setObjectName(QStringLiteral("spinGain"));
        spinGain->setMaximum(2000);
        spinGain->setValue(200);

        gridLayout_2->addWidget(spinGain, 2, 1, 1, 1);

        btGain = new QPushButton(groupBox);
        btGain->setObjectName(QStringLiteral("btGain"));

        gridLayout_2->addWidget(btGain, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 4, 0, 1, 3);

        buttonstop = new QPushButton(Connect);
        buttonstop->setObjectName(QStringLiteral("buttonstop"));

        gridLayout_3->addWidget(buttonstop, 5, 2, 1, 1);


        retranslateUi(Connect);

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QApplication::translate("Connect", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("Connect", "\346\234\215\345\212\241\345\231\250Ip", Q_NULLPTR));
        editIP->setText(QApplication::translate("Connect", "192.168.3.15", Q_NULLPTR));
        label_2->setText(QApplication::translate("Connect", "\345\233\276\347\211\207\347\253\257\345\217\243", Q_NULLPTR));
        editImg->setText(QApplication::translate("Connect", "2002", Q_NULLPTR));
        label_5->setText(QApplication::translate("Connect", "\346\225\260\346\215\256\347\253\257\345\217\243", Q_NULLPTR));
        editData->setText(QApplication::translate("Connect", "3000", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Connect", "\347\233\270\346\234\272\345\217\202\346\225\2601", Q_NULLPTR));
        label_6->setText(QApplication::translate("Connect", "[x0,y0]", Q_NULLPTR));
        label_7->setText(QApplication::translate("Connect", "[dx,dy]", Q_NULLPTR));
        label_8->setText(QApplication::translate("Connect", "[incrx,incry]", Q_NULLPTR));
        buttonstart->setText(QApplication::translate("Connect", "\345\274\200\345\247\213\347\233\270\346\234\272", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Connect", "\345\275\251\350\211\262\345\233\276\345\203\217", Q_NULLPTR)
         << QApplication::translate("Connect", "\347\201\260\350\211\262\345\233\276\345\203\217", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Connect", ".\345\201\234\346\255\242\346\225\260\346\215\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Connect", "\347\233\270\346\234\272\345\217\202\346\225\2602", Q_NULLPTR));
        btExposure->setText(QApplication::translate("Connect", "\346\233\235\345\205\211\345\200\274", Q_NULLPTR));
        btGain->setText(QApplication::translate("Connect", "\345\242\236\347\233\212", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Connect", "\350\247\246\345\217\221\346\250\241\345\274\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Connect", "TRGSRC_UNSET 0 ", Q_NULLPTR)
         << QApplication::translate("Connect", "TRGSRC_IMM    1", Q_NULLPTR)
         << QApplication::translate("Connect", "TRGSRC_EXT      2", Q_NULLPTR)
        );
        buttonstop->setText(QApplication::translate("Connect", "\345\244\215\344\275\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
