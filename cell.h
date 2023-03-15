#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QDebug>
#include "crosszero.h"

class Cell : public QPushButton
{
    int x;
    int y;
    bool available;

    CrossZero* game;
public:
    Cell(QString text, QWidget* parent, int x, int y, CrossZero* game);
    bool isAvailable();
    void SetUnAvailable();
    void SetAvailable();
    QVector<int> getCoords();
};

#endif // CELL_H
