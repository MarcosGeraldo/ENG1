#ifndef FLUXO_H
#define FLUXO_H


#include <cstdlib>
#include <iostream>
#include <string>
#include "sistema.h"

using namespace std;


class Fluxo{

protected:
  string nome;
  Sistema* destino;
  Sistema* origem;
  double fluxo;

public:
  Fluxo();
  Fluxo(string,Sistema*,Sistema*);
  Fluxo(string,Sistema*,Sistema*,double);
  virtual ~Fluxo();
  string getNome();
  void setNome(string);
  Sistema* getDestino();
  void setDestino(Sistema*);
  Sistema* getOrigem();
  void setOrigem(Sistema*);
  double getFluxo();
  void setFluxo(double);
  virtual double equacao()=0;
  void conecta(Sistema*,Sistema*);
};



#endif
