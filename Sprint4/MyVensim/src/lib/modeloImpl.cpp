#include "modeloImpl.h"



ModeloImpl::ModeloImpl(){
  fluxos.clear();
  nome="";
}

ModeloImpl::~ModeloImpl(){
  for (Fluxo* flu : fluxos)
    if (flu!=NULL)
      delete flu;
  fluxos.clear();
}

ModeloImpl::ModeloImpl(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada, Fluxo* fluxoEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
  adicionaFluxo(fluxoEntrada);
}

ModeloImpl::ModeloImpl(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
}

ModeloImpl::ModeloImpl(string nomeEntrada){
  nome = nomeEntrada;
}

string ModeloImpl::getNome(){
  return nome;
}

void ModeloImpl::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

int ModeloImpl::getCiclos(){
  return ciclos;
}

int ModeloImpl::getCiclosAtuais(){
  return cicloAtual;
}

void ModeloImpl::setCiclos(int cicloEntrada){
  ciclos=cicloEntrada;
}

void ModeloImpl::setCiclosAtuais(int cicloAtualEntrada){
  cicloAtual=cicloAtualEntrada;
}

void ModeloImpl::incrementaCiclo(){
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

void ModeloImpl::adicionaFluxo(Fluxo *fluxo){
  fluxos.push_back(fluxo);
}

void ModeloImpl::removeFluxo(Fluxo *fluxoRemover){
  int tamanho = fluxos.size();
  for (int i = 0; i < tamanho; i++){
		if (fluxos[i]->getNome() == fluxoRemover->getNome())
			fluxos.erase(fluxos.begin() + i);
	}
}

ModeloImpl& ModeloImpl::operator= (const ModeloImpl& modelo){
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

bool ModeloImpl::operator== (const ModeloImpl& modelo){
	if (this == &modelo)
		return true;

	if (fluxos.size() != modelo.fluxos.size())
		return false;

	for (int i = 0, tamanho = modelo.fluxos.size(); i < tamanho; i++)
		if (!(fluxos[i] == modelo.fluxos[i]))
			return false;

	return true;
}
