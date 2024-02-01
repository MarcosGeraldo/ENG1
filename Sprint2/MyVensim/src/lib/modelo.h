#ifndef MODELO_H
#define MODELO_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "fluxo.h"
//#include "sistema.h"

using namespace std;


class Modelo{

protected:
  string nome;
  int ciclos;
  int cicloAtual;
  vector<Fluxo*> fluxos;

public:
  Modelo();
  ~Modelo();
  Modelo(string, int, int, Fluxo*);
  Modelo(string, int, int);
  Modelo(string);
  string getNome();
  void setNome(string);
  int getCiclos();
  int getCiclosAtuais();
  void setCiclos(int);
  void setCiclosAtuais(int);
  void incrementaCiclo();
  void adicionaFluxo(Fluxo*);
  void removeFluxo(Fluxo*);
private:
  Modelo& operator= (const Modelo&);
  bool operator== (const Modelo&);
};


#endif
