#include <QCoreApplication>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Hello World" << endl;
    return a.exec();
}
