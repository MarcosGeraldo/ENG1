#ifndef TESTE_FUNCIONAL_H
#define TESTE_FUNCIONAL_H

#include <string>
#include <assert.h>
#include <math.h>

using namespace std;


#include "../../src/lib/modeloImpl.h"
#include "../../src/lib/sistemaImpl.h"
#include "../../src/lib/fluxoImpl.h"

/**
*@brief Esta funcao executa o teste funcial exponencial
*/
void testeExponencialFuncional();
/**
*@brief Esta funcao executa o teste logistico
*/
void testeLogisticaFuncional();
/**
*@brief Esta funcao executa o teste "complexo", que possui varios sistemas e fluxos
*/
void testeComplexoFuncional();


#endif
