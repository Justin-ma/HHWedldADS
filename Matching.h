#ifndef MATCHING_H
#define MATCHING_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QTextBrowser>
#include <QGroupBox>
#include <QSpinBox>
#include <QSlider>

class Matching : public QWidget
{
    Q_OBJECT
public:
    explicit Matching(QWidget *parent = 0);
    void TextAppend(QString str);

private:
    QRadioButton *buttonNormal;
    QRadioButton *buttonSpecial;

    QLabel *labelScore;
    QLabel *labelThreld;
    QLabel *labelX;
    QLabel *labelY;
    QLabel * labelmode;
    QLabel *labelRX1;
    QLabel *labelRY1;
    QLineEdit *editScore;
    QLineEdit *editValue;
    QLineEdit *editX;
    QLineEdit *editY;
    QLineEdit *editmode;
    QLineEdit *editRX1;
    QLineEdit *editRY1;

    QTextBrowser *text;
    QPushButton *buttonBeforecalib;
    QPushButton *buttoDeviate;
    QPushButton *buttonAftercalib;
    QPushButton *buttonSetting;

    QGroupBox *groupModel;
    QGroupBox *groupValue;
    QGroupBox *groupAlternately;
    QGroupBox *groupWelding;


    QSlider *s1;

signals:
    void sSendStartMatch(QString str);
    void sSendSetDeviate(QString str);
    void sSendOneMatch(QString str);
    void sSendManyMatch(QString str);


public slots:
};

#endif // MATCHING_H
