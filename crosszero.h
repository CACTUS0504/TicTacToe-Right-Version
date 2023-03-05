#ifndef CROSSZERO_H
#define CROSSZERO_H

#include <QWidget>
#include <QtWidgets>

class CrossZero : public QWidget
{
    Q_OBJECT
private:
    int cnt;
    QGridLayout* fieldLayout;
    QPushButton* buttons[3][3];
public:
    explicit CrossZero(QWidget *parent = nullptr);
    QString end();

public slots:
    void slotButtonClicked();
};

#endif
