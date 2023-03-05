#include "crosszero.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrossZero* crossZero = new CrossZero();
    crossZero->resize(400, 400);
    crossZero->show();
    return a.exec();
}
