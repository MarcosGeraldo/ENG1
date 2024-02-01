#include "testesFuncionais.h"


class MeuFluxo1 : public FluxoImpl{
public:
	MeuFluxo1(string nome, Sistema* origem, Sistema* destino) : FluxoImpl(nome, origem, destino){}

  ~MeuFluxo1(){}

	double equacao(){
		return 0.01 * (destino->getConteudo()) * (1 - (destino->getConteudo()) / 70);
	}
};

class MeuFluxo2 : public FluxoImpl
{

public:

	MeuFluxo2(string nome, Sistema* origem, Sistema* destino) : FluxoImpl(nome, origem, destino){}

	~MeuFluxo2(){}

	double equacao(){
		return 0.01 * (origem->getConteudo());
	}
};


void testeExponencialFuncional()
{

	//Remove 0.01 da pop1 e insere na pop2
	//Pop1 tem valor inicial 100, e pop2 inicia com 0
	//Rodando 0 a 100 ciclos

	Modelo* m1 = Modelo::criarModelo();
	m1->setNome("ModeloExponencial");
	m1->setCiclos(100);
	m1->setCiclosAtuais(0);

	Sistema *pop1 = m1->criarSistema("pop1",100), *pop2 = m1->criarSistema("pop2",0);

	m1->criarFluxo<MeuFluxo2>("exponencial", pop1, pop2);

	m1->incrementaCiclo();

	assert(fabs(pop1->getConteudo() - 36.6032) < 0.0001);
	assert(fabs(pop2->getConteudo() - 63.3968) < 0.0001);
	ModeloImpl::deletaModelo("ModeloExponencial");
}

void testeLogisticaFuncional()
{
	//temos dois sistemas p1 e p1
	//Remove 0.01*(p1)*(1-p1/70) de p1 e insere em p2
	//P1 tem como valor inicial 100, e p2 comeca com 10
	Modelo* m2=Modelo::criarModelo();
	m2->setNome("Logistica");
	m2->setCiclos(100);
	m2->setCiclosAtuais(0);

	Sistema *p1=m2->criarSistema("p",100), *p2=m2->criarSistema("p2",10);
	m2->criarFluxo<MeuFluxo1>("logistica", p1, p2);

	m2->incrementaCiclo();

	assert(fabs(p1->getConteudo() - 88.2167) < 0.0001);
	assert(fabs(p2->getConteudo() - 21.7833) < 0.0001);

	ModeloImpl::deletaModelo("Logistica");
}

void testeComplexoFuncional()
{
	// Sistema q1 inicializa com 100 , q2, q3, q4, q5, com 0
	//Equacao para todos os fluxos é 0.01*(conteudo do sistema de origem)
	//temos os fluxos:
	//q1 a q2, q1 a q3, q4 a q1, q3 a q4, q2 a q3, q2 a q5
	// Executado por 101 ciclos
	Modelo *m3= Modelo::criarModelo();
	m3->setNome("Complexo");
	Sistema *q1=m3->criarSistema("Q1",100), *q2=m3->criarSistema("Q2",00), *q3=m3->criarSistema("Q3",100),
	*q4=m3->criarSistema("Q4",00), *q5=m3->criarSistema("Q5",00);


	m3->criarFluxo<MeuFluxo2>("f", q1, q2);
	m3->criarFluxo<MeuFluxo2>("g", q1, q3);
	m3->criarFluxo<MeuFluxo2>("v", q4, q1);
	m3->criarFluxo<MeuFluxo2>("u", q3, q4);
	m3->criarFluxo<MeuFluxo2>("t", q2, q3);
	m3->criarFluxo<MeuFluxo2>("r", q2, q5);


	m3->setCiclosAtuais(0);
	m3->setCiclos(100);

	m3->incrementaCiclo();

	assert(fabs(q1->getConteudo() - 31.8513) < 0.0001);
	assert(fabs(q2->getConteudo() - 18.4003) < 0.0001);
	assert(fabs(q3->getConteudo() - 77.1143) < 0.0001);
	assert(fabs(q4->getConteudo() - 56.1728) < 0.0001);
	assert(fabs(q5->getConteudo() - 16.4612) < 0.0001);

	ModeloImpl::deletaModelo("Complexo");
}
