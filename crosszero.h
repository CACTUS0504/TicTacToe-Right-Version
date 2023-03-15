#ifndef CROSSZERO_H
#define CROSSZERO_H

#include <QWidget>
#include <QtWidgets>

class CrossZero : public QWidget
{
    Q_OBJECT
private:
    int cnt;
    QVector<QVector<QString>> buttons;
public:
    explicit CrossZero(QWidget *parent = nullptr);
    QString end();
    void setButton(int i, int j, QString text);
    QVector<QVector<QString>> getButtons();
    void resizeMapButtons();
    int getCnt();
    void setCnt(int val);
    void resetButtons();
};

#endif
