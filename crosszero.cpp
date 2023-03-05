#include "crosszero.h"

CrossZero::CrossZero(QWidget *parent): QWidget{parent}
{
    fieldLayout = new QGridLayout;
    fieldLayout->setContentsMargins(5, 5, 5, 5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QPushButton* button = new QPushButton(this);
            button->setMinimumSize(120, 120);
            connect(button, SIGNAL(clicked()), SLOT(slotButtonClicked()));
            fieldLayout->addWidget(button, i, j);
            buttons[i][j] = button;
        }
    }
    this->setLayout(fieldLayout);
    setMaximumSize(380, 380);
    cnt = 0;
}

void CrossZero::slotButtonClicked()
{
    qDebug() << "click";
    QPushButton* senderPtr = static_cast<QPushButton*>(sender());
    if (senderPtr->text().size() == 0)
    {
        if (!(cnt % 2)) senderPtr->setText("X");
        else senderPtr->setText("O");
        cnt++;
    }
    if (end() != "")
    {
        qDebug() << end() << " wins";
        QLabel* endGame = new QLabel(end() + " wins") ;
        fieldLayout->addWidget(endGame);
        QApplication::exit();
    }
}

QString CrossZero::end()
{
    for (int i = 0; i < 3; i++)
    {
        if ((buttons[i][0]->text() == buttons[i][1]->text()) && (buttons[i][2]->text() == buttons[i][1]->text()) && (buttons[i][0]->text() != "")) return buttons[i][0]->text();
        else if ((buttons[0][i]->text() == buttons[1][i]->text()) && (buttons[2][i]->text() == buttons[1][i]->text()) && (buttons[0][i]->text() != "")) return buttons[0][i]->text();
    }
    if ((buttons[0][0]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][2]->text()) | (buttons[0][2]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][0]->text())  && (buttons[1][1]->text() != "")) return buttons[1][1]->text();
    return "";
}
