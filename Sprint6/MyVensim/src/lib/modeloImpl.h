#ifndef MODELO_IMP_H
#define MODELO_IMP_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "modelo.h"
#include "sistemaImpl.h"
#include "handleBodySemDebug.h"

using namespace std;

/**
*@brief Esta classe armazena o tempo da simulacao e um vector contendo todos os fluxos deste modelo
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class ModelBody : public Body{

protected:
  string nome="";/* *< Esta variavel aramazena o nome de um modelo */
  int ciclos=0;/* *< Esta variavel aramazena o volume total de ciclos a serrem percorridos*/
  int cicloAtual=0;/* *< Esta variavel aramazena o ciclo atual */
  vector<Fluxo*> fluxos;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para fluxo*/
  vector<Sistema*> sistemas;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para fluxo*/
  static vector<ModelBody*> modelos;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para Modelo*/

public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  */
  ModelBody();
  /**
  *@brief Este é o destrutor da classe
  */
  virtual ~ModelBody();
  /**
  *@brief Este construtor adiciona, nome, numero de ciclos, o ciclo atual e um fluxo ao Modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome, dois inteiros representando numero total de ciclos e o ciclo atual e uma variavel do tipo Fluxo
  */
  ModelBody(string, int, int, Fluxo*);
  /**
  *@brief Este construtor adiciona, nome, numero de ciclos e o ciclo atual a um modelo ao Modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome e dois inteiros representando numero total de ciclos e o ciclo atual
  */
  ModelBody(string, int, int);
  /**
  *@brief Este construtor recebe e adiciona o nome a um modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome
  */
  ModelBody(string);
  /**
  *@brief Este metodo retorna o nome de um modelo
  *
  *@retval É retornado um string contendo o nome
  */
  string getNome();
  /**
  *@brief Este metodo atribui um nome a um modelo
  *
  *@param Deve ser passada uma string contendo o nome
  */
  void setNome(string);
  /**
  *@brief Este metodo retorna quantos ciclos serão efetuados um uma simulação
  *
  *@retval É retornado um inteiro representando o numero total de ciclos a ser executados
  */
  int getCiclos();
  /**
  *@brief Este metodo retorna em qual ciclo a simulacao esta
  *
  *@retval É retornado um inteiro de qual é o ciclo atual
  */
  int getCiclosAtuais();
  /**
  *@brief Este metodo atribui um valor ao valor do numero de ciclos a serem executados
  *
  *@param Deve ser passado um inteiro
  */
  void setCiclos(int);
  /**
  *@brief Este metodo atribui um valor ao ciclo atual
  *
  *@param deve ser passado um inteiro que representa o ciclo atual
  */
  void setCiclosAtuais(int);
  /**
  *@brief Este metodo executa um ciclo, fazendo todas as execucoes necessarias em um ciclo do simulador
  */
  void incrementaCiclo();
  /**
  *@brief Este metodo adiciona um fluxo ao vector de Fluxos
  *
  *@param Deve ser passado um ponteiro de Fluxo a ser adicionado
  */
  void adiciona(Fluxo*);
  /**
  *@brief Este metodo remove um Fluxo do vector de Fluxos
  *
  *@param Deve ser passado o fluxo a ser removido
  */
  void remove(Fluxo*);
  /**
  *@brief Este metodo adiciona um sistema ao vector de Sistemas
  *
  *@param Deve ser passado um ponteiro de Sistema a ser adicionado
  */
  void adiciona(Sistema*);
  /**
  *@brief Este metodo remove um Sistema do vector de Sistema
  *
  *@param Deve ser passado o Sistema a ser removido
  */
  void remove(Sistema*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	Sistema* criarSistema(string, double = 0.0);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void sistemaSetContedo(Sistema*, double);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void sistemaSetNome(Sistema*, string);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	float sistemaGetConteudo(Sistema*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	string sistemaGetNome(Sistema*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void sistemaIncrementa(Sistema*,double);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void sistemaDecrementa(Sistema*, double);




  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	Fluxo* criarFluxo(Fluxo*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void fluxoSetNome(Fluxo*, string);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	string fluxoGetNome(Fluxo*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void fluxoSetOrigem(Fluxo*, Sistema*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	void fluxoSetDestino(Fluxo*, Sistema*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	Sistema* fluxoGetOrigem(Fluxo*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	Sistema* fluxoGetDestino(Fluxo*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	double equacao(Fluxo*);
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
  static ModelBody* criarModelo(string nome = "");
  /**
  *@brief
  *
  *@param
  *
  *retval
  */
	static void deletaModelo(string);
private:
  /**
  *@brief Este metodo é a sobrecarga do operador '=', fazendo a "clonagem" de um Modelo para o outro
  *
  *@param Deve ser passada o Modelo a ser clonado
  *
  *@retval É retornado um modelo que é clone do que foi passado para o metodo, que foi o modelo que chamou esta função, o modelo a esquerda do '='
  */
  ModelBody& operator= (const ModelBody&);
  /**
  *@brief Este metodo é a sobre carga do operador '==' comparando um modelo com o modelo que chamou esta funcao
  *
  *@param É passado o modelo a ser comparado com o modelo que chamou o metodo
  *
  *@retval False quando os modelos passados são diferentes
  *
  *@retval True quando os modelos passados são iguais
  */
  bool operator== (const ModelBody&);
};

class ModelHandle : public Modelo, public Handle<ModelBody>{
public:
  ModelHandle(string name, int start, int end,Fluxo* flux){
    pImpl_->setNome(name);
    pImpl_->setCiclos(end);
    pImpl_->setCiclosAtuais(start);
    pImpl_->adiciona(flux);
  }
  ModelHandle(string name, int start, int end){
    pImpl_->setNome(name);
    pImpl_->setCiclos(end);
    pImpl_->setCiclosAtuais(start);
  }
  ModelHandle(string name){
    pImpl_->setNome(name);
  }
  ModelHandle(ModelBody* pImpl_1){
    pImpl_=pImpl_1;
  }

  ModelHandle(){}

  ~ModelHandle(){
    pImpl_->detach();
  }

  virtual string getNome(){return pImpl_->getNome();}

  virtual void setNome(string name){pImpl_->setNome(name);}

  virtual int getCiclos(){return pImpl_->getCiclos();}

  virtual int getCiclosAtuais(){pImpl_->getCiclosAtuais();}

  virtual void setCiclos(int cicle){pImpl_->setCiclos(cicle);}

  virtual void setCiclosAtuais(int cicleA){pImpl_->setCiclosAtuais(cicleA);}

  virtual void incrementaCiclo(){pImpl_->incrementaCiclo();}

  virtual void adiciona(Fluxo* flux){pImpl_->adiciona(flux);}

  virtual void remove(Fluxo* flux){pImpl_->remove(flux);}

  virtual void adiciona(Sistema* sistema){pImpl_->adiciona(sistema);}

  virtual void remove(Sistema* sistema){pImpl_->remove(sistema);}


  virtual Sistema* criarSistema(string nome, double conteudo=0){return pImpl_->criarSistema(nome, conteudo);}

  virtual void sistemaSetContedo(Sistema* sis, double cont){pImpl_->sistemaSetContedo(sis,cont);}

  virtual void sistemaSetNome(Sistema* sis, string nome){pImpl_->sistemaSetNome(sis,nome);}

  virtual double sistemaGetConteudo(Sistema* sis){return pImpl_->sistemaGetConteudo(sis);}

  virtual string sistemaGetNome(Sistema* sis){return pImpl_->sistemaGetNome(sis);}

  virtual void sistemaIncrementa(Sistema* sis,double incre){pImpl_->sistemaIncrementa(sis,incre);}

  virtual void sistemaDecrementa(Sistema* sis, double decre){pImpl_->sistemaDecrementa(sis,decre);}






  virtual Fluxo* criarFluxo(Fluxo* flux){pImpl_->criarFluxo(flux);}

  virtual void fluxoSetNome(Fluxo* flux, string nome){pImpl_->fluxoSetNome(flux,nome);}

  virtual string fluxoGetNome(Fluxo* flux){return pImpl_->fluxoGetNome(flux);}

  virtual void fluxoSetOrigem(Fluxo* flux, Sistema* sis){pImpl_->fluxoSetOrigem(flux,sis);}

  virtual void fluxoSetDestino(Fluxo* flux, Sistema* sis){pImpl_->fluxoSetDestino(flux,sis);}

  virtual Sistema* fluxoGetOrigem(Fluxo* flux){return pImpl_->fluxoGetOrigem(flux);}

  virtual Sistema* fluxoGetDestino(Fluxo* flux){return pImpl_->fluxoGetDestino(flux);}

  virtual double equacao(Fluxo* flux){return pImpl_->equacao(flux);}


  static ModelHandle* criarModelo(string nome = ""){
    ModelHandle* a = new ModelHandle(ModelBody::criarModelo(nome));
    return a;}

  static void deletaModelo(string nome){ModelBody::deletaModelo(nome);}
};


#endif
