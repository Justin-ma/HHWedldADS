#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QListWidget>
#include <QVector>

class ChooseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseDialog(QDialog *parent = 0);
    ChooseDialog(const QVector<int> &v);

private:
    QPushButton *buttonOK;
    QPushButton *buttonCancel;
    QListWidget *listwidget;

signals:
    void sClickOk(QString str);

public slots:
    void slotClickOK();
};

#endif // CHOOSEDIALOG_H
