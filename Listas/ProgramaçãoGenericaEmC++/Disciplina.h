#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>



class Disciplina
{
	char* codigo;
	int horas;
	char* professor;

public:

  Disciplina(char*,int,char*);
  ~Disciplina();

	char* getCodigo(void);
	int getHoras(void);
	char* getProfessor(void);
	void setCodigo(int entradaCodigo);
	void setHoras(int entradaHoras);
	void setProfessor(char* entradaProfessor);

}

#endif
