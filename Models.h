#ifndef MODELS_H
#define MODELS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QTextBrowser>
#include <QRadioButton>

class Models : public QWidget
{
    Q_OBJECT
public:
    explicit Models(QWidget *parent = 0);

    void textAppend(QString str);

private:
    QRadioButton *buttonRubberband;
    QRadioButton *buttonScrollhand;
    QLineEdit *edit;
    QTextBrowser *text;
    QPushButton *buttonChooce;
    QPushButton *buttonSave;
    QPushButton *buttonUpload;
    QPushButton *buttonSendname;

    QGroupBox *groupModel;
    QGroupBox *groupMaketemplate;
    QGroupBox *groupSelecttemplate;

signals:
    void sChangeModelR();
    void sChangeModelS();
    void sSaveModel();
    void sUpLoadModel();
    void sSendName(QString str);
    void sChooceModels();

public slots:
    void slotChangeModelR();
    void slotChangeModelS();
    void slotChooceModels();

};

#endif // MODELS_H
