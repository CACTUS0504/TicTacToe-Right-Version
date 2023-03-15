#include "crosszero.h"

#include <QApplication>
#include "qmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(400, 400);
    w.show();
    return a.exec();
}
