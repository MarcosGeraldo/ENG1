#include "sistemaImpl.h"


SistemaImpl::SistemaImpl(){}

SistemaImpl::~SistemaImpl(){}

SistemaImpl::SistemaImpl(string nomeEntrada,double conteudo){
  nome = nomeEntrada;
  setConteudo(conteudo);
}

string SistemaImpl::getNome(){
  return nome;
}

void SistemaImpl::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

double SistemaImpl::getConteudo(){
  return conteudo;
}

void SistemaImpl::setConteudo(double conteudoEntrada){
  conteudo=conteudoEntrada;
}

void SistemaImpl::incrementaConteudo(double incremento){
  conteudo+=incremento;
}

void SistemaImpl::decrementaConteudo(double decremento){
  conteudo-=decremento;
}
