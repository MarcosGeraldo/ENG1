#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>

using namespace std;


/**
*@brief A Interface Sistema é a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Sistema{


public:
  /**
  *@brief Este é o destrutor da classe
  */
  virtual~Sistema(){};
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno é uma string que contem o nome do sistema
  */
  virtual string getNome(void)=0;
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  virtual void setNome(string)=0;
  /**
  *@brief Este metodo retorna o conteudo de um sistema
  *
  *@retval É retornado um double contendo o conteudo de um sistema
  */
  virtual double getConteudo()=0;
  /**
  *@brief Este metodo atribui um valor ao conteudo de um sistema
  *
  *@param Deve ser passado para esse metodo um double a ser atribuido
  */
  virtual void setConteudo(double)=0;
  /**
  *@brief Este metodo incrementa um valor passado ao conteudo atual do sistema
  *
  *@param Deve ser passado um valor a ser incrementado
  */
  virtual void incrementaConteudo(double)=0;
  /**
  *@brief Este metodo decrementa um valor passado ao conteudo atual do sistema
  *
  *@param Deve ser passado um valor a ser decrementado
  */
  virtual void decrementaConteudo(double)=0;
};



#endif
