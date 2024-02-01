#include "testesfuncionais.h"
#include "../unit/testesunitarios.h"

using namespace std;

int main(){

    cout << "Inicio dos testes funcionais\n";
    testesFuncionais();
    cout << "Fim dos testes funcionais\n";

    cout << "Inicio dos testes unitarios de Vehicle\n";
    testeVehicle();
    cout << "Fim dos testes unitarios de Vehicle\n";

    cout << "Inicio dos testes unitarios de User\n";
    testeUser();
    cout << "Fim dos testes unitarios de User\n";

    cout << "Inicio dos testes unitarios de Rent\n";
    testeRent();
    cout << "Fim dos testes unitarios de Rent\n";

    cout << "Inicio dos testes unitarios de System\n";
    testeSystem();
    cout << "Fim dos testes unitarios de System\n";
    return 0;
}
