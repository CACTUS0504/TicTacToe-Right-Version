#include "crosszero.h"

CrossZero::CrossZero(QWidget *parent): QWidget{parent}
{
    resizeMapButtons();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QString button = "";
            buttons[i][j] = button;
        }
    }
    cnt = 0;
}

void CrossZero::resizeMapButtons()
{
    buttons.resize(3);
    for (int i = 0; i < 3; i++)
    {
        buttons[i].resize(3);
    }
}

QString CrossZero::end()
{
    for (int i = 0; i < 3; i++)
    {
        if ((buttons[i][0] == buttons[i][1]) && (buttons[i][2] == buttons[i][1]) && (buttons[i][0] != "")) return buttons[i][0];
        else if ((buttons[0][i] == buttons[1][i]) && (buttons[2][i] == buttons[1][i]) && (buttons[0][i] != "")) return buttons[0][i];
    }
    if ((buttons[0][0] == buttons[1][1] && buttons[1][1] == buttons[2][2]) | (buttons[0][2] == buttons[1][1] && buttons[1][1] == buttons[2][0])  && (buttons[1][1] != "")) return buttons[1][1];
    return "";
}

void CrossZero::setButton(int i, int j, QString text)
{
    buttons[i][j] = text;
}

QVector<QVector<QString>> CrossZero::getButtons()
{
    return buttons;
}

int CrossZero::getCnt() {return cnt;}

void CrossZero::setCnt(int cnt) {this->cnt = cnt;}

void CrossZero::resetButtons()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QString button = "";
            buttons[i][j] = button;
        }
    }
    cnt = 0;
}
