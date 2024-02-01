#include "modeloImpl.h"

vector<ModelBody*> ModelBody::modelos;

ModelBody::ModelBody(){
  fluxos.clear();
  nome="";
}

ModelBody::~ModelBody(){
  for (Sistema* sis : sistemas)
    if (sis!=NULL)
      delete sis;
  sistemas.clear();
  for (Fluxo* flu : fluxos)
    if (flu!=NULL)
      delete flu;
  fluxos.clear();
}

ModelBody::ModelBody(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada, Fluxo* fluxoEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
  adiciona(fluxoEntrada);
}

ModelBody::ModelBody(string nomeEntrada, int cicloAtualEntrada, int cicloEntrada){
  nome = nomeEntrada;
  ciclos=cicloEntrada;
  cicloAtual=cicloAtualEntrada;
}

ModelBody::ModelBody(string nomeEntrada){
  nome = nomeEntrada;
}

string ModelBody::getNome(){
  return nome;
}

void ModelBody::setNome(string nomeEntrada){
  nome=nomeEntrada;
}

int ModelBody::getCiclos(){
  return ciclos;
}

int ModelBody::getCiclosAtuais(){
  return cicloAtual;
}

void ModelBody::setCiclos(int cicloEntrada){
  ciclos=cicloEntrada;
}

void ModelBody::setCiclosAtuais(int cicloAtualEntrada){
  cicloAtual=cicloAtualEntrada;
}

void ModelBody::incrementaCiclo(){
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
  delete valoresFluxos;
}

void ModelBody::adiciona(Fluxo *fluxo){
  fluxos.push_back(fluxo);
  adiciona(fluxo->getOrigem());
  adiciona(fluxo->getDestino());
}

void ModelBody::remove(Fluxo *fluxoRemover){
  int tamanho = fluxos.size();
  remove(fluxoRemover->getOrigem());
  remove(fluxoRemover->getDestino());
  for (int i = 0; i < tamanho; i++){
		if (fluxos[i]->getNome() == fluxoRemover->getNome())
			fluxos.erase(fluxos.begin() + i);
	}
}

void ModelBody::adiciona(Sistema *sistema){
  sistemas.push_back(sistema);
}

void ModelBody::remove(Sistema *sistemaRemover){
  int tamanho = sistemas.size();
  for (int i = 0; i < tamanho; i++){
		if (sistemas[i]->getNome() == sistemaRemover->getNome())
			sistemas.erase(sistemas.begin() + i);
	}
}

ModelBody& ModelBody::operator= (const ModelBody& model){
	if (this == &model)
		return *this;


	for (vector<Fluxo*>::iterator it = fluxos.begin(); it != this->fluxos.end(); it++)
		delete* it;

	fluxos.clear();

	for (int i = 0, tamanho = model.fluxos.size(); i < tamanho; i++){
    fluxos.push_back(model.fluxos[i]);
	}

	return *this;
}

bool ModelBody::operator== (const ModelBody& model){
	if (this == &model)
		return true;

	if (fluxos.size() != model.fluxos.size())
		return false;

	for (int i = 0, tamanho = model.fluxos.size(); i < tamanho; i++)
		if (!(fluxos[i] == model.fluxos[i]))
			return false;

	return true;
}

ModelBody* ModelBody::criarModelo(string nome){
  ModelBody* modelo = new ModelBody(nome);
  ModelBody::modelos.push_back(modelo);
	return modelo;
}

Modelo* Modelo::criarModelo(string nome){
  return ModelHandle::criarModelo(nome);
}

void Modelo::deletaModelo(string nome){
  ModelHandle::deletaModelo(nome);
}

void ModelBody:: deletaModelo(string nome){
	int tam = ModelBody::modelos.size();

	for (int i = 0; i < tam; i++){
		if (ModelBody::modelos[i]->getNome() == nome){

      ModelBody* aux = (ModelBody*)ModelBody::modelos[i];
      /*for(Sistema* sis : aux->sistemas)
        delete sis;
      aux->sistemas.clear();

      for(Fluxo* flu : aux->fluxos)
        delete flu;
      aux->fluxos.clear();*/

      ModelBody::modelos.erase(ModelBody::modelos.begin());
      break;
		}
	}
}



Sistema* ModelBody::criarSistema(string nome, double conteudo){
  Sistema* sistema = new SystemHandle(nome, conteudo);
  adiciona(sistema);
  return sistema;
}

void ModelBody::sistemaSetContedo(Sistema* sistema, double conteudo){
  sistema->setConteudo(conteudo);
}

void ModelBody::sistemaSetNome(Sistema* sistema, string nome){
  sistema->setNome(nome);
}

float ModelBody::sistemaGetConteudo(Sistema* sistema){
  return sistema->getConteudo();
}
string ModelBody::sistemaGetNome(Sistema* sistema){
  return sistema->getNome();
}

void ModelBody::sistemaIncrementa(Sistema* sistema,double incremento){
  sistema->incrementaConteudo(incremento);
}

void ModelBody::sistemaDecrementa(Sistema* sistema, double decremento){
  sistema->decrementaConteudo(decremento);
}






Fluxo* ModelBody::criarFluxo(Fluxo* fluxo){
  adiciona(fluxo);
  return fluxo;
}

void ModelBody::fluxoSetNome(Fluxo* fluxo, string nome){
  fluxo->setNome(nome);
}

string ModelBody::fluxoGetNome(Fluxo* fluxo){
  return fluxo->getNome();
}

void ModelBody::fluxoSetOrigem(Fluxo*fluxo, Sistema* sistema){
  fluxo->setOrigem(sistema);
}

void ModelBody::fluxoSetDestino(Fluxo* fluxo, Sistema* sistema){
  fluxo->setDestino(sistema);
}

Sistema* ModelBody::fluxoGetOrigem(Fluxo* fluxo){
  return fluxo->getOrigem();
}

Sistema* ModelBody::fluxoGetDestino(Fluxo* fluxo){
  return fluxo->getDestino();
}

double ModelBody::equacao(Fluxo* fluxo){
  return fluxo->equacao();
}
