#include <iostream>
#include "teste_Unit_Modelo.h"
#include "teste_Unit_Fluxo.h"
#include "teste_Unit_Sistema.h"

using namespace std;


int main(){

  cout << "\nInicio dos testes unitarios!!!";
  testeUnitarioFluxo();
	testeUnitarioSistema();
	testeUnitarioModelo();

  cout << "\nInicio dos testes unitarios!!!\n";

  return 0;
}
