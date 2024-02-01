#include "teladelogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelaDeLogin w;
    w.show();
    return a.exec();
}
