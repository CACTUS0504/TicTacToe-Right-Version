#include "qmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    buttons.resize(3);
    for (int i = 0; i < 3; i++)
    {
        buttons[i].resize(3);
    }

    this->game = new CrossZero();
    fieldLayout = new QGridLayout;
    fieldLayout->setContentsMargins(5, 5, 5, 5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Cell* button = new Cell("", static_cast<QWidget*>(this), i, j, game);
            button->setMinimumSize(120, 120);
            connect(button, SIGNAL(clicked()), SLOT(slotButtonClicked()));
            buttons[i][j] = button;
            fieldLayout->addWidget(buttons[i][j], i, j);
        }
    }
    this->setLayout(fieldLayout);
    setMaximumSize(380, 380);

    // Окно для рестарта, по умолчанию скрыто
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            delete buttons[i][j];
        }
    }
    delete fieldLayout;
    delete game;
}

void MainWindow::slotButtonClicked()
{

    Cell* pushedButton = static_cast<Cell*>(sender());
    if (pushedButton->isAvailable())
    {
        pushedButton->SetUnAvailable();
        qDebug() << "click";

        // Обновление окна
        if (!(this->game->getCnt() % 2))
        {
            pushedButton->setText("X");
        }
        else
        {
            pushedButton->setText("O");
        }

        // Обновление состояния игры
        this->game->setCnt(this->game->getCnt() + 1);
        this->game->setButton(pushedButton->getCoords()[0],pushedButton->getCoords()[1], pushedButton->text());

        // Проверка на конец игры
        if (this->game->end() != "")
        {
            // Рисуем окно для рестарта
            restartWindow = new QWidget(static_cast<QWidget*>(this));
            restartWindow->resize(300, 200);
            restartWindow->move((this->width() - restartWindow->width()) / 2, (this->height() - restartWindow->height()) / 2);
            QPalette pall;
            pall.setColor(restartWindow->backgroundRole(), Qt::white);
            restartWindow->setPalette(pall);
            restartWindow->setAutoFillBackground(true);
            QVBoxLayout* restartLayout = new QVBoxLayout(restartWindow);
            if (this->game->end() == "X") restartLayout->addWidget(new QLabel("Крестики выиграли"));
            else restartLayout->addWidget(new QLabel("Нолики выиграли"));
            QPushButton* restart = new QPushButton("Начать заново");
            connect(restart, SIGNAL(clicked()), this, SLOT(restart()));
            restartLayout->addWidget(restart);
            QPushButton* quit = new QPushButton("Выйти");
            connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
            restartLayout->addWidget(quit);
            restartWindow->show();
            qDebug() << this->game->end() << " wins";
        }
    }
}

void MainWindow::restart()
{
    game->resetButtons();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            buttons[i][j]->SetAvailable();
            buttons[i][j]->setText("");
        }
    }
    delete restartWindow;
}
