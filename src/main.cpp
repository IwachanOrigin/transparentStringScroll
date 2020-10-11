#include "transparentimage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TransparentImage w;
    w.show();
    return a.exec();
}
