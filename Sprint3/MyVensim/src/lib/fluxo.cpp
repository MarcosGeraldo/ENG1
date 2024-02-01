#include "fluxo.h"




Fluxo::Fluxo(){
  origem=NULL;
  destino=NULL;
  nome[0]= '\0';
}

Fluxo::~Fluxo(){}

Fluxo::Fluxo(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada,double conteudo){
  string nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
  fluxo=conteudo;
}

Fluxo::Fluxo(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada){
  nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
}

string Fluxo::getNome(){
  return nome;
}

void Fluxo::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

Sistema* Fluxo::getDestino(){
  return destino;
}

void Fluxo::setDestino(Sistema *destinoEntrada){
  destino=destinoEntrada;
}

Sistema* Fluxo::getOrigem(){
  return origem;
}

void Fluxo::setOrigem(Sistema *origemEntrada){
  origem=origemEntrada;
}

double Fluxo::getFluxo(){
  return fluxo;
}

void Fluxo::setFluxo(double conteudoEntrada){
  fluxo=conteudoEntrada;
}

void Fluxo::conecta(Sistema *origemEntrada,Sistema *destinoEntrada){
  origem=origemEntrada;
  destino=destinoEntrada;
}
