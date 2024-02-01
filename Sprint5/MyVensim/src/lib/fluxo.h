#ifndef FLUXO_H
#define FLUXO_H

#include "sistema.h"

using namespace std;

/**
*@brief A Interface Fluxo é a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Fluxo{

public:
  /**
  *@brief Este destrutor é um destrutor virtual da Classe
  */
  virtual ~Fluxo(){};
  /**
  *@brief Este metodo retorna o nome de um fluxo
  *
  *@retval É retornado uma string contendo o nome
  */
  virtual string getNome()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setNome(string)=0;
  /**
  *@brief Este metodo retorno o Sistema de destino de um Fluxo
  *
  *@retval É retornado um ponteiro de Sistema
  */
  virtual Sistema* getDestino()=0;
  /**
  *@brief Este metodo atribui um destino ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  virtual void setDestino(Sistema*)=0;
  /**
  *@brief Este metodo retorno o Sistema de origem  de um Fluxo
  *
  *@retval É retornado um ponteiro de Sistema da origem
  */
  virtual Sistema* getOrigem()=0;
  /**
  *@brief Este metodo atribui uma origem ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  virtual void setOrigem(Sistema*)=0;
  /**
  *@brief Este metodo retorna o valor armazenado dentro do Fluxo
  *
  *@retval É retornado um double contendo o valor que esta armazenado no fluxo
  */
  virtual double getFluxo()=0;
  /**
  *@brief Este metodo atribui um valor ao fluxo
  *
  *@param Deve ser passado um double contendo o valor para o metedo
  */
  virtual void setFluxo(double)=0;
  /**
  *@brief Este metodo virtual é o metodo que deve ser implementado, atribuindo uma equacao a este metodo
  *
  *@retval O retorno foi definido como double para manter a propiedade de um Fluxo, que deve apenas "transportar" valores
  */
  virtual double equacao()=0;
  /**
  *@brief Este metodo conecta dois sistemas entre si, tendo como conector o Fluxo que chamou este metodo
  *
  *@param Deve ser passados dois ponteiros de Sistema para a funcao
  */
  virtual void conecta(Sistema*,Sistema*)=0;
};



#endif
