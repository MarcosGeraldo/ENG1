#include "cadastrousuario.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CadastroUsuario w;
    w.show();
    return a.exec();
}
