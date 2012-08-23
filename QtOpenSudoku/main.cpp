#include <QtGui/QApplication>
#include "gamemainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMainWindow w;
    w.show();
    
    return a.exec();
}
