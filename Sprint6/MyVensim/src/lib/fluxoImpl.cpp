#include "fluxoImpl.h"


/*FluxBody::FluxBody(){}

FluxBody::~FluxBody(){}

FluxBody::FluxBody(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada,double conteudo){
  string nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
  fluxo=conteudo;
}

FluxBody::FluxBody(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada){
  nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
}*/

string FluxBody::getNome(){
  return nome;
}

void FluxBody::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

Sistema* FluxBody::getDestino(){
  return destino;
}

void FluxBody::setDestino(Sistema *destinoEntrada){
  destino=destinoEntrada;
}

Sistema* FluxBody::getOrigem(){
  return origem;
}

void FluxBody::setOrigem(Sistema *origemEntrada){
  origem=origemEntrada;
}

double FluxBody::getFluxo(){
  return fluxo;
}

void FluxBody::setFluxo(double conteudoEntrada){
  fluxo=conteudoEntrada;
}

void FluxBody::conecta(Sistema *origemEntrada,Sistema *destinoEntrada){
  origem=origemEntrada;
  destino=destinoEntrada;
}
