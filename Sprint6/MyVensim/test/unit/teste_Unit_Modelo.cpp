#include "teste_Unit_Modelo.h"



class MeuFluxo1 : public FluxHandle{

public:
	MeuFluxo1(string nome, Sistema *origem, Sistema *destino) : FluxHandle(nome, origem, destino){}


	double equacao(){
		return (this->getOrigem())->getConteudo() * 2;
	}
};


void testeUnitarioModelo(){
	Modelo *m1=Modelo::criarModelo();
	m1->setNome("modelo1");
	Sistema *sOri=m1->criarSistema("sistema1", 3.0), *sDes=m1->criarSistema("sistema2", 0);
	m1->criarFluxo<MeuFluxo1>("fluxo1", sOri, sDes);

	assert(m1->getNome() == "modelo1");

	m1->setNome("modelo2");

	assert(m1->getNome() == "modelo2");

  m1->setCiclos(1);
  m1->setCiclosAtuais(0);
	m1->incrementaCiclo();
	assert(sOri->getConteudo() == -3.0);
	assert(sDes->getConteudo() == 6.0);

	m1->incrementaCiclo();
  m1->setCiclos(1);
  m1->setCiclosAtuais(0);
	Modelo::deletaModelo("modelo2");
	delete m1;
}
