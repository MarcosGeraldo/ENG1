#include <iostream>
#include <string>
#include <assert.h>
#include "testesFuncionais.h"

using namespace std;


#include "../../src/lib/modelo.h"
#include "../../src/lib/sistema.h"
#include "../../src/lib/fluxo.h"


class MeuFluxo1 : public Fluxo{
public:
	MeuFluxo1(string nome, Sistema* origem, Sistema* destino) : Fluxo(nome, origem, destino){}

  ~MeuFluxo1(){}

	double equacao(){
		return 0.01 * (destino->getConteudo()) * (1 - (destino->getConteudo()) / 70);
	}
};

class MeuFluxo2 : public Fluxo
{

public:

	MeuFluxo2(string nome, Sistema* origem, Sistema* destino) : Fluxo(nome, origem, destino){}

	~MeuFluxo2(){}

	double equacao(){
		return 0.01 * (origem->getConteudo());
	}
};


void testeExponencialFuncional(){

	//Remove 0.01 da pop1 e insere na pop2
	//Pop1 tem valor inicial 100, e pop2 inicia com 0
	//Rodando 0 a 100 ciclos

	Sistema* pop1 = new Sistema("pop1", 100), *pop2 = new Sistema("pop2",0);
	Modelo* m1 = new Modelo("ModeloExponencial",0,100);
	MeuFluxo2* exponencial = new MeuFluxo2("exponencial", pop1, pop2);

	m1->adicionaFluxo(exponencial);

	m1->incrementaCiclo();

	assert(pop1->getConteudo() < 37.3 && pop1->getConteudo() > 35.2);
	assert(pop2->getConteudo() < 64.8 && pop2->getConteudo() > 62.7);

	delete m1;
}

void testeLogisticaFuncional()
{
	//temos dois sistemas p1 e p1
	//Remove 0.01*(p1)*(1-p1/70) de p1 e insere em p2
	//P1 tem como valor inicial 100, e p2 comeca com 10

	Sistema *p1 = new Sistema("p", 100), *p2 = new Sistema("p2", 10);
	MeuFluxo1* logistica =  new MeuFluxo1("logistica", p1, p2);
	Modelo* m2 = new Modelo("Logistica",0,100);
	m2->adicionaFluxo(logistica);
	m2->incrementaCiclo();

	assert(p1->getConteudo() < 89.1 && p1->getConteudo() > 87);
	assert(p2->getConteudo() < 23 && p2->getConteudo() > 20.9);

	delete m2;
}

void testeComplexoFuncional()
{
	// Sistema q1 inicializa com 100 , q2, q3, q4, q5, com 0
	//Equacao para todos os fluxos é 0.01*(conteudo do sistema de origem)
	//temos os fluxos:
	//q1 a q2, q1 a q3, q4 a q1, q3 a q4, q2 a q3, q2 a q5
	// Executado por 101 ciclos

	Sistema *q1 = new Sistema("Q1", 100), *q2 =  new Sistema("Q2", 0), *q3 = new Sistema("Q3", 100),
		*q4 = new Sistema("Q4", 0), *q5 = new Sistema("Q5", 0);

	MeuFluxo2 *f = new MeuFluxo2("f", q1, q2), *g = new MeuFluxo2("g", q1, q3),
		*v = new MeuFluxo2("v", q4, q1), *u = new MeuFluxo2("u", q3, q4),
		*t = new MeuFluxo2("t", q2, q3), *r = new MeuFluxo2("r", q2, q5);

	Modelo* m3 = new Modelo;
	m3->adicionaFluxo(f);
	m3->adicionaFluxo(g);
	m3->adicionaFluxo(v);
	m3->adicionaFluxo(u);
	m3->adicionaFluxo(t);
	m3->adicionaFluxo(r);
	m3->incrementaCiclo();

	assert(q1->getConteudo() < 32.8 && q1->getConteudo() > 30.7);
	assert(q2->getConteudo() < 19.4 && q2->getConteudo() > 17.3);
	assert(q3->getConteudo() < 77.9 && q3->getConteudo() > 75.8);
	assert(q4->getConteudo() < 57.4 && q4->getConteudo() > 55.3);
	assert(q5->getConteudo() < 17.7 && q5->getConteudo() > 15.8);

	delete m3;
}
