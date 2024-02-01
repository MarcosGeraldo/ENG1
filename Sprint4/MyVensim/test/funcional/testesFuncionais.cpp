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

	Sistema* pop1 = new SistemaImpl("pop1", 100), *pop2 = new SistemaImpl("pop2",0);
	Modelo* m1 = new ModeloImpl("ModeloExponencial",0,100);
	MeuFluxo2* exponencial = new MeuFluxo2("exponencial", pop1, pop2); ;

	m1->adicionaFluxo(exponencial);

	m1->incrementaCiclo();

	assert(fabs(pop1->getConteudo() - 36.6032) < 0.0001);
	assert(fabs(pop2->getConteudo() - 63.3968) < 0.0001);

	delete m1;
	delete pop1;
	delete pop2;
}

void testeLogisticaFuncional()
{
	//temos dois sistemas p1 e p1
	//Remove 0.01*(p1)*(1-p1/70) de p1 e insere em p2
	//P1 tem como valor inicial 100, e p2 comeca com 10

	Sistema *p1 = new SistemaImpl("p", 100), *p2 = new SistemaImpl("p2", 10);
	MeuFluxo1* logistica =  new MeuFluxo1("logistica", p1, p2);
	Modelo* m2 = new ModeloImpl("Logistica",0,100);
	m2->adicionaFluxo(logistica);
	m2->incrementaCiclo();

	assert(fabs(p1->getConteudo() - 88.2167) < 0.0001);
	assert(fabs(p2->getConteudo() - 21.7833) < 0.0001);

	delete m2;
	delete p1;
	delete p2;
}

void testeComplexoFuncional()
{
	// Sistema q1 inicializa com 100 , q2, q3, q4, q5, com 0
	//Equacao para todos os fluxos é 0.01*(conteudo do sistema de origem)
	//temos os fluxos:
	//q1 a q2, q1 a q3, q4 a q1, q3 a q4, q2 a q3, q2 a q5
	// Executado por 101 ciclos

	SistemaImpl *q1 = new SistemaImpl("Q1", 100), *q2 =  new SistemaImpl("Q2", 0), *q3 = new SistemaImpl("Q3", 100),
		*q4 = new SistemaImpl("Q4", 0), *q5 = new SistemaImpl("Q5", 0);

	MeuFluxo2 *f = new MeuFluxo2("f", q1, q2), *g = new MeuFluxo2("g", q1, q3),
		*v = new MeuFluxo2("v", q4, q1), *u = new MeuFluxo2("u", q3, q4),
		*t = new MeuFluxo2("t", q2, q3), *r = new MeuFluxo2("r", q2, q5);

	ModeloImpl* m3 = new ModeloImpl;
	//Nao constava no envio
	m3->setCiclosAtuais(0);
	m3->setCiclos(100);

	m3->adicionaFluxo(f);
	m3->adicionaFluxo(g);
	m3->adicionaFluxo(v);
	m3->adicionaFluxo(u);
	m3->adicionaFluxo(t);
	m3->adicionaFluxo(r);
	m3->incrementaCiclo();

	assert(fabs(q1->getConteudo() - 31.8513) < 0.0001);
	assert(fabs(q2->getConteudo() - 18.4003) < 0.0001);
	assert(fabs(q3->getConteudo() - 77.1143) < 0.0001);
	assert(fabs(q4->getConteudo() - 56.1728) < 0.0001);
	assert(fabs(q5->getConteudo() - 16.4612) < 0.0001);

	delete m3;
	delete q1;
	delete q2;
	delete q3;
	delete q4;
	delete q5;
}
