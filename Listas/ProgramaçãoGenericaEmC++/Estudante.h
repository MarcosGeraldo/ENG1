#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>
#include <string>


class Estudante{

	int matricula;
	int idade;
	double cpf;
	char* nome;

public:

	Estudante(int,int,double,char*);
	~Estudante();
	char* getNome(void);
	int* getIdade(void);
	double GetCpf(void);
	int getMatricula(void);
	void setNome(char* entradaNome);
	void setIdade(int entradaIdade);
	void setCpf(double entradaCpf);
	void setMatricula(int entradaMatricula);
}

#endif
