#include "cell.h"

Cell::Cell(QString text, QWidget* parent, int x, int y, CrossZero* game) : QPushButton(text, parent)
{
    this->x = x;
    this->y = y;
    this->available = true;
    this->game = game;
}

bool Cell::isAvailable()
{
    return available;
}

void Cell::SetUnAvailable()
{
    available = false;
}

void Cell::SetAvailable()
{
    available = true;
}

QVector<int> Cell::getCoords()
{
    QVector<int> coords = {x, y};
    return coords;
}
