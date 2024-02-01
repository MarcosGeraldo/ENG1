#ifndef SISTEMA_H
#define SISTEMA_H

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;
class Sistema{

protected:
  string nome;
  double conteudo;

public:
  Sistema();
  ~Sistema();
  Sistema(string,double);
  string getNome(void);
  void setNome(string);
  double getConteudo();
  void setConteudo(double);
  void incrementaConteudo(double);
  void decrementaConteudo(double);
};



#endif
