#ifndef QMAINWINDOW_H
#define QMAINWINDOW_H

#include <QWidget>
#include "crosszero.h"
#include "cell.h"
#include <QDialog>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QVector<QVector<Cell*>> buttons;
    CrossZero* game;
    QGridLayout* fieldLayout;
    QWidget* restartWindow;
public slots:
    void slotButtonClicked();
    void restart();
signals:

};

#endif // QMAINWINDOW_H
