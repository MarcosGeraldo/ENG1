#ifndef MODELO_H
#define MODELO_H
#include "fluxo.h"

/**
*@brief A Interface Modelo é a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Modelo{

public:
  /**
  *@brief Este é o destrutor da classe
  */
  virtual ~Modelo(){};
  /**
  *@brief Este metodo retorna o nome de um modelo
  *
  *@retval É retornado um string contendo o nome
  */
  virtual string getNome()=0;
  /**
  *@brief Este metodo atribui um nome a um modelo
  *
  *@param Deve ser passada uma string contendo o nome
  */
  virtual void setNome(string)=0;
  /**
  *@brief Este metodo retorna quantos ciclos serão efetuados um uma simulação
  *
  *@retval É retornado um inteiro representando o numero total de ciclos a ser executados
  */
  virtual int getCiclos()=0;
  /**
  *@brief Este metodo retorna em qual ciclo a simulacao esta
  *
  *@retval É retornado um inteiro de qual é o ciclo atual
  */
  virtual int getCiclosAtuais()=0;
  /**
  *@brief Este metodo atribui um valor ao valor do numero de ciclos a serem executados
  *
  *@param Deve ser passado um inteiro
  */
  virtual void setCiclos(int)=0;
  /**
  *@brief Este metodo atribui um valor ao ciclo atual
  *
  *@param deve ser passado um inteiro que representa o ciclo atual
  */
  virtual void setCiclosAtuais(int)=0;
  /**
  *@brief Este metodo executa um ciclo, fazendo todas as execucoes necessarias em um ciclo do simulador
  */
  virtual void incrementaCiclo()=0;
  /**
  *@brief Este metodo adiciona um fluxo ao vector de Fluxos
  *
  *@param Deve ser passado um ponteiro de Fluxo a ser adicionado
  */
  virtual void adicionaFluxo(Fluxo*)=0;
  /**
  *@brief Este metodo remove um Fluxo do vector de Fluxos
  *
  *@param Deve ser passado o fluxo a ser removido
  */
  virtual void removeFluxo(Fluxo*)=0;
};



#endif
