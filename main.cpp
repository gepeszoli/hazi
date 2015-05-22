#include "mainwindow.h"
#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(images);
    QApplication a(argc, argv);
    GameWindow w;
    w.show();

    return a.exec();
}
