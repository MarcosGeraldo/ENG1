#include "modelo.h"



Modelo::Modelo(){}

Modelo::~Modelo(){
  fluxos.clear();
}

Modelo::Modelo(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada, Fluxo* fluxoEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
  adicionaFluxo(fluxoEntrada);
}

Modelo::Modelo(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
}

Modelo::Modelo(string nomeEntrada){
  nome = nomeEntrada;
}

string Modelo::getNome(){
  return nome;
}

void Modelo::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

int Modelo::getCiclos(){
  return ciclos;
}

int Modelo::getCiclosAtuais(){
  return cicloAtual;
}

void Modelo::setCiclos(int cicloEntrada){
  ciclos=cicloEntrada;
}

void Modelo::setCiclosAtuais(int cicloAtualEntrada){
  cicloAtual=cicloAtualEntrada;
}

void Modelo::incrementaCiclo(){
  int tamanho = fluxos.size();
  double* valoresFluxos = new double[tamanho];

  for (int i = cicloAtual; i < ciclos; i++){

    for (int j = 0; j < tamanho; j++)
      valoresFluxos[j]=fluxos[j]->equacao();

    for (int k = 0; k < tamanho;k++){

      if (fluxos[k]->getDestino() != NULL)
        fluxos[k]->getDestino()->incrementaConteudo(valoresFluxos[k]);

      if (fluxos[k]->getOrigem() != NULL)
        fluxos[k]->getOrigem()->decrementaConteudo(valoresFluxos[k]);
    }
    cicloAtual++;
  }
}

void Modelo::adicionaFluxo(Fluxo *fluxoEntrada){
  fluxos.push_back(fluxoEntrada);
}

void Modelo::removeFluxo(Fluxo *fluxoRemover){
  int tamanho = fluxos.size();
  for (int i = 0; i < tamanho; i++){
		if (fluxos[i]->getNome() == fluxoRemover->getNome())
			fluxos.erase(fluxos.begin() + i);
	}
}

Modelo& Modelo::operator= (const Modelo& modelo){
	if (this == &modelo)
		return *this;


	for (vector<Fluxo*>::iterator it = fluxos.begin(); it != this->fluxos.end(); it++)
		delete* it;

	fluxos.clear();

	for (int i = 0, tamanho = modelo.fluxos.size(); i < tamanho; i++){
    fluxos.push_back(modelo.fluxos[i]);
	}

	return *this;
}

bool Modelo::operator== (const Modelo& modelo){
	if (this == &modelo)
		return true;

	if (fluxos.size() != modelo.fluxos.size())
		return false;

	for (int i = 0, tamanho = modelo.fluxos.size(); i < tamanho; i++)
		if (!(fluxos[i] == modelo.fluxos[i]))
			return false;

	return true;
}
