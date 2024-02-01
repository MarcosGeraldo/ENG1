#include "teste_Unit_Modelo.h"



class MeuFluxo1 : public FluxoImpl{

public:
	MeuFluxo1(string nome, SistemaImpl *origem, SistemaImpl *destino) : FluxoImpl(nome, origem, destino){}

	~MeuFluxo1(){}

	double equacao(){
		return origem->getConteudo() * 2;
	}
};


void testeUnitarioModelo(){
	ModeloImpl* m1 = new ModeloImpl("modelo1");
	SistemaImpl* s1 = new SistemaImpl("sistema1", 3.0);
	SistemaImpl* s2 = new SistemaImpl("sistema1", 0);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1", s1, s2);


	assert(m1->getNome() == "modelo1");

	m1->setNome("modelo2");

	assert(m1->getNome() == "modelo2");

	m1->adicionaFluxo(f1);
  m1->setCiclos(1);
  m1->setCiclosAtuais(0);
	m1->incrementaCiclo();

	assert(s2->getConteudo() == 6.0);

	m1->removeFluxo(f1);

  m1->setCiclos(1);
  m1->setCiclosAtuais(0);
	m1->incrementaCiclo();

	assert(s2->getConteudo() == 6.0);

	delete s1;
	delete s2;
	delete m1;
}
