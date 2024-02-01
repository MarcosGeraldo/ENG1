#include "teste_Unit_Sistema.h"


class MeuFluxo1 : public FluxoImpl{

public:
	MeuFluxo1(string nome, SistemaImpl *origem, SistemaImpl *destino) : FluxoImpl(nome, origem, destino){}

	~MeuFluxo1(){}

	double equacao(){
		return origem->getConteudo() * 2;
	}
};

void testeUnitarioSistema()
{
	SistemaImpl* s1 = new SistemaImpl("sistema1", 3.0);
	MeuFluxo1* f1 = new MeuFluxo1("fluxo1", NULL, NULL);

	assert(s1->getNome() == "sistema1");
	assert(s1->getConteudo() == 3.0);

	f1->setOrigem(s1);

	s1->setNome("sistema2");
	s1->setConteudo(9.5);

	s1->incrementaConteudo(f1->equacao());

	assert(s1->getConteudo() == 28.5);
	assert(s1->getNome() == "sistema2");

	delete s1;
	delete f1;
}
