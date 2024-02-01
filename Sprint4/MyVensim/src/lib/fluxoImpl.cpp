#include "fluxoImpl.h"


FluxoImpl::FluxoImpl(){
  origem=NULL;
  destino=NULL;
  nome[0]= '\0';
}

FluxoImpl::~FluxoImpl(){}

FluxoImpl::FluxoImpl(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada,double conteudo){
  string nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
  fluxo=conteudo;
}

FluxoImpl::FluxoImpl(string nomeEntrada,Sistema* origemEntrada,Sistema* destinoEntrada){
  nome = nomeEntrada;
  origem=origemEntrada;
  destino=destinoEntrada;
}

string FluxoImpl::getNome(){
  return nome;
}

void FluxoImpl::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

Sistema* FluxoImpl::getDestino(){
  return destino;
}

void FluxoImpl::setDestino(Sistema *destinoEntrada){
  destino=destinoEntrada;
}

Sistema* FluxoImpl::getOrigem(){
  return origem;
}

void FluxoImpl::setOrigem(Sistema *origemEntrada){
  origem=origemEntrada;
}

double FluxoImpl::getFluxo(){
  return fluxo;
}

void FluxoImpl::setFluxo(double conteudoEntrada){
  fluxo=conteudoEntrada;
}

void FluxoImpl::conecta(Sistema *origemEntrada,Sistema *destinoEntrada){
  origem=origemEntrada;
  destino=destinoEntrada;
}
