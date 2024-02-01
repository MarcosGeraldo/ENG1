#include "sistemaImpl.h"


//SystemBody::SystemBody(){}

SystemBody::~SystemBody(){}
/*
SystemBody::SystemBody(string nomeEntrada,double conteudo){
  nome = nomeEntrada;
  setConteudo(conteudo);
}*/

string SystemBody::getNome(){
  return nome;
}

void SystemBody::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

double SystemBody::getConteudo(){
  return conteudo;
}

void SystemBody::setConteudo(double conteudoEntrada){
  conteudo=conteudoEntrada;
}

void SystemBody::incrementaConteudo(double incremento){
  conteudo+=incremento;
}

void SystemBody::decrementaConteudo(double decremento){
  conteudo-=decremento;
}
Sistema& SystemBody::retornaSistema(string nome, double conteudo){
  Sistema* sistema = new SystemHandle(nome, conteudo);
  return *sistema;
}
