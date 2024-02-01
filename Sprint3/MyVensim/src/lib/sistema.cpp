#include "sistema.h"






Sistema::Sistema(){}

Sistema::~Sistema(){}

Sistema::Sistema(string nomeEntrada,double conteudo){
  nome = nomeEntrada;
  setConteudo(conteudo);
}

string Sistema::getNome(){
  return nome;
}

void Sistema::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

double Sistema::getConteudo(){
  return conteudo;
}

void Sistema::setConteudo(double conteudoEntrada){
  conteudo=conteudoEntrada;
}

void Sistema::incrementaConteudo(double incremento){
  conteudo+=incremento;
}

void Sistema::decrementaConteudo(double decremento){
  conteudo-=decremento;
}
