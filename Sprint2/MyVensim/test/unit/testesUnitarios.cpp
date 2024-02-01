#include "testesUnitarios.h"
#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>

using namespace std;

#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"


class MeuFluxo1 : public Fluxo{

public:
	MeuFluxo1(string nome, Sistema *origem, Sistema *destino) : Fluxo(nome, origem, destino){}

	~MeuFluxo1(){}

	double equacao(){
		return origem->getConteudo() * 2;
	}
};

void testeDoFluxo(){
	Sistema* s1 = new Sistema("Sistema1",3);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1",NULL,NULL);


	assert(f1->getNome() == "fluxo1");
	assert(f1->getOrigem() == NULL);
	assert(f1->getDestino() == NULL);

	f1->setDestino(s1);

	assert(f1->getOrigem() == NULL);
	assert(f1->getDestino() != NULL);
	assert(f1->equacao() == 6);

	f1->setOrigem(s1);

	assert(f1->getOrigem() != NULL);
	assert(f1->getDestino() != NULL);

	delete s1;
	delete f1;
}



void testeDoSistema()
{
	Sistema* s1 = new Sistema("sistema1", 3.0);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1", NULL, NULL);

	assert(s1->getNome() == "system1");
	assert(s1->getConteudo() == 3.0);

	f1->setDestino(s1);

	s1->setNome("sistema2");
	s1->setConteudo(9.5);

	s1->incrementaConteudo(f1->equacao());

	assert(s1->getConteudo() == 28.5);
	assert(s1->getNome() == "system2");

	delete s1;
	delete f1;

}

void testeDoModelo(){
	Modelo* m1 = new Modelo("modelo1");
	Sistema* s1 = new Sistema("sistema1", 3.0);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1", NULL, s1);


	assert(m1->getNome() == "modelo1");

	m1->setNome("modelo2");

	assert(m1->getNome() == "modelo2");

	m1->adicionaFluxo(f1);
  m1->setCiclos(1);
  m1->setCiclosAtuais(0);
	m1->incrementaCiclo();

	assert(s1->getConteudo() == 9.0);

	m1->removeFluxo(f1);

	m1->incrementaCiclo();
  m1->setCiclos(1);
  m1->setCiclosAtuais(0);

	assert(s1->getConteudo() == 9.0);

	delete s1;
	delete f1;
	delete m1;
}
