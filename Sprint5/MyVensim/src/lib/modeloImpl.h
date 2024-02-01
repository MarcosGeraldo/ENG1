#ifndef MODELO_IMP_H
#define MODELO_IMP_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "modelo.h"
#include "sistemaImpl.h"

using namespace std;

/**
*@brief Esta classe armazena o tempo da simulacao e um vector contendo todos os fluxos deste modelo
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class ModeloImpl : public Modelo{

protected:
  string nome;/* *< Esta variavel aramazena o nome de um modelo */
  int ciclos;/* *< Esta variavel aramazena o volume total de ciclos a serrem percorridos*/
  int cicloAtual;/* *< Esta variavel aramazena o ciclo atual */
  vector<Fluxo*> fluxos;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para fluxo*/
  vector<Sistema*> sistemas;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para sistema*/
  static vector<Modelo*> modelos;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para Modelo*/

public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  */
  ModeloImpl();
  /**
  *@brief Este é o destrutor da classe
  */
  virtual ~ModeloImpl();
  /**
  *@brief Este construtor adiciona, nome, numero de ciclos, o ciclo atual e um fluxo ao Modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome, dois inteiros representando numero total de ciclos e o ciclo atual e uma variavel do tipo Fluxo
  */
  ModeloImpl(string, int, int, Fluxo*);
  /**
  *@brief Este construtor adiciona, nome, numero de ciclos e o ciclo atual a um modelo ao Modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome e dois inteiros representando numero total de ciclos e o ciclo atual
  */
  ModeloImpl(string, int, int);
  /**
  *@brief Este construtor recebe e adiciona o nome a um modelo que esta sendo criado
  *
  *@param Deve ser passado uma string contendo o nome
  */
  ModeloImpl(string);
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
  *@brief Este metodo adiciona um sistema ao vector de sistemas
  *
  *@param Deve ser passado um ponteiro de Sistema a ser adicionado
  */
  void adiciona(Sistema*);
  /**
  *@brief Este metodo remove um sistema do vector de sistemas
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
	double sistemaGetConteudo(Sistema*);
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
  static Modelo* criarModelo(string nome = "");
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
  ModeloImpl& operator= (const ModeloImpl&);
  /**
  *@brief Este metodo é a sobre carga do operador '==' comparando um modelo com o modelo que chamou esta funcao
  *
  *@param É passado o modelo a ser comparado com o modelo que chamou o metodo
  *
  *@retval False quando os modelos passados são diferentes
  *
  *@retval True quando os modelos passados são iguais
  */
  bool operator== (const ModeloImpl&);
};


#endif
