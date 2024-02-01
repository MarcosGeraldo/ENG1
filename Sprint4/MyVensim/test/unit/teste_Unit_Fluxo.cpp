#include "teste_Unit_Fluxo.h"



class MeuFluxo1 : public FluxoImpl{

public:
	MeuFluxo1(string nome, SistemaImpl *origem, SistemaImpl *destino) : FluxoImpl(nome, origem, destino){}

	~MeuFluxo1(){}

	double equacao(){
		return origem->getConteudo() * 2;
	}
};


void testeUnitarioFluxo(){
	SistemaImpl* s1 = new SistemaImpl("Sistema1",3);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1",NULL,NULL);


	assert(f1->getNome() == "fluxo1");
	assert(f1->getOrigem() == NULL);
	assert(f1->getDestino() == NULL);

	f1->setOrigem(s1);

	assert(f1->getOrigem() != NULL);
	assert(f1->getDestino() == NULL);
	assert(f1->equacao() == 6);

	f1->setDestino(s1);

	assert(f1->getOrigem() != NULL);
	assert(f1->getDestino() != NULL);

	delete s1;
	delete f1;
}
