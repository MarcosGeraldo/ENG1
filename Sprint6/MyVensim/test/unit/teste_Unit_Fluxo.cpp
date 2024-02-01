#include "teste_Unit_Fluxo.h"



class MeuFluxo1 : public FluxHandle{

public:
	MeuFluxo1(string nome, Sistema *origem, Sistema *destino) : FluxHandle(nome, origem, destino){}



	double equacao(){
		return (this->getOrigem())->getConteudo() * 2;
	}
};


void testeUnitarioFluxo(){
	Sistema* s1 = new SystemHandle("Sistema1",3);
	Fluxo* f1 = new MeuFluxo1("fluxo1",NULL,NULL);


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
