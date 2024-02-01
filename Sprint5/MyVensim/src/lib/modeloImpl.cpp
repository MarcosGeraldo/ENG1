#include "modeloImpl.h"

vector<Modelo*> ModeloImpl:: modelos;

ModeloImpl::ModeloImpl(){
  fluxos.clear();
  nome="";
}

ModeloImpl::~ModeloImpl(){
  for (Sistema* sis : sistemas)
    if (sis!=NULL)
      delete sis;
  sistemas.clear();
  for (Fluxo* flu : fluxos)
    if (flu!=NULL)
      delete flu;
  fluxos.clear();
}

ModeloImpl::ModeloImpl(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada, Fluxo* fluxoEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
  adiciona(fluxoEntrada);
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

void ModeloImpl::adiciona(Fluxo *fluxo){
  fluxos.push_back(fluxo);
  adiciona(fluxo->getOrigem());
  adiciona(fluxo->getDestino());
}

void ModeloImpl::remove(Fluxo *fluxoRemover){
  int tamanho = fluxos.size();
  remove(fluxoRemover->getOrigem());
  remove(fluxoRemover->getDestino());
  for (int i = 0; i < tamanho; i++){
		if (fluxos[i]->getNome() == fluxoRemover->getNome())
			fluxos.erase(fluxos.begin() + i);
	}
}
void ModeloImpl::adiciona(Sistema *sistema){
  sistemas.push_back(sistema);
}

void ModeloImpl::remove(Sistema *sistemaRemover){
  int tamanho = sistemas.size();
  for (int i = 0; i < tamanho; i++){
		if (sistemas[i]->getNome() == sistemaRemover->getNome())
			sistemas.erase(sistemas.begin() + i);
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


Modelo* ModeloImpl::criarModelo(string nome){
  ModeloImpl* modelo = new ModeloImpl(nome);
  ModeloImpl::modelos.push_back(modelo);
	return modelo;
}

Modelo* Modelo::criarModelo(string nome){
	return ModeloImpl::criarModelo(nome);
}

void ModeloImpl:: deletaModelo(string nome){
	int tam = ModeloImpl::modelos.size();

	for (int i = 0; i < tam; i++){
		if (ModeloImpl::modelos[i]->getNome() == nome){

      ModeloImpl* aux = (ModeloImpl*)ModeloImpl::modelos[i];
      /*for(Sistema* sis : aux->sistemas)
        delete sis;
      aux->sistemas.clear();

      for(Fluxo* flu : aux->fluxos)
        delete flu;
      aux->fluxos.clear();*/

      ModeloImpl::modelos.erase(ModeloImpl::modelos.begin());
      break;
		}
	}
}

Sistema* ModeloImpl::criarSistema(string nome, double conteudo){
  Sistema* sistema = new SistemaImpl(nome, conteudo);
  adiciona(sistema);
  return sistema;
}

void ModeloImpl::sistemaSetContedo(Sistema* sistema, double conteudo){
  sistema->setConteudo(conteudo);
}

void ModeloImpl::sistemaSetNome(Sistema* sistema, string nome){
  sistema->setNome(nome);
}

double ModeloImpl::sistemaGetConteudo(Sistema* sistema){
  return sistema->getConteudo();
}
string ModeloImpl::sistemaGetNome(Sistema* sistema){
  return sistema->getNome();
}

void ModeloImpl::sistemaIncrementa(Sistema* sistema,double incremento){
  sistema->incrementaConteudo(incremento);
}

void ModeloImpl::sistemaDecrementa(Sistema* sistema, double decremento){
  sistema->decrementaConteudo(decremento);
}






Fluxo* ModeloImpl::criarFluxo(Fluxo* fluxo){
  adiciona(fluxo);
  return fluxo;
}

void ModeloImpl::fluxoSetNome(Fluxo* fluxo, string nome){
  fluxo->setNome(nome);
}

string ModeloImpl::fluxoGetNome(Fluxo* fluxo){
  return fluxo->getNome();
}

void ModeloImpl::fluxoSetOrigem(Fluxo* fluxo, Sistema* sistema){
  fluxo->setOrigem(sistema);
}

void ModeloImpl::fluxoSetDestino(Fluxo* fluxo, Sistema* sistema){
  fluxo->setDestino(sistema);
}

Sistema* ModeloImpl::fluxoGetOrigem(Fluxo* fluxo){
  return fluxo->getOrigem();
}

Sistema* ModeloImpl::fluxoGetDestino(Fluxo* fluxo){
  return fluxo->getDestino();
}

double ModeloImpl::equacao(Fluxo* fluxo){
  return fluxo->equacao();
}
