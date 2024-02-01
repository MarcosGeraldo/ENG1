#ifndef SISTEMA_IMP_H
#define SISTEMA_IMP_H

#include <cstdlib>
#include <iostream>
#include "sistema.h"
#include "handleBodySemDebug.h"

using namespace std;


/**
*@brief A classe SistemaImpl é a classe que aramazena os valores, é a classe "conteiner"
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class SystemBody : public Body {
protected:
  string nome;/* *<Esta variavel armazena o nome de um sistema */
  double conteudo;/* *< Esta variavel armazena o conteudo de um sistema */
public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  **/
//  SystemBody();
  /**
  *@brief Este é o destrutor da classe
  */
  ~SystemBody();
  /**
  *@brief Este construtor é o construtor se passando o nome e o valor do conteudo
  *
  *@param
  */
//  SystemBody(string,double);
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno é uma string que contem o nome do sistema
  */
  string getNome(void);
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  void setNome(string);
  /**
  *@brief Este metodo retorna o conteudo de um sistema
  *
  *@retval É retornado um double contendo o conteudo de um sistema
  */
  double getConteudo();
  /**
  *@brief Este metodo atribui um valor ao conteudo de um sistema
  *
  *@param Deve ser passado para esse metodo um double a ser atribuido
  */
  void setConteudo(double);
  /**
  *@brief Este metodo incrementa um valor passado ao conteudo atual do sistema
  *
  *@param Deve ser passado um valor a ser incrementado
  */
  void incrementaConteudo(double);
  /**
  *@brief Este metodo decrementa um valor passado ao conteudo atual do sistema
  *
  *@param Deve ser passado um valor a ser decrementado
  */
  void decrementaConteudo(double);
  /**
  *@brief Este metodo decrementa um valor passado ao conteudo atual do sistema
  *
  *@param Deve ser passado um valor a ser decrementado
  */
  Sistema& retornaSistema(string,double);
};

class SystemHandle : public Sistema, public Handle<SystemBody>{
public:
  SystemHandle(string name, double content){
    pImpl_->setNome(name);
    pImpl_->setConteudo(content);
  }

  SystemHandle(){}

  ~SystemHandle(){}

  virtual double getConteudo(){return pImpl_->getConteudo();}

  virtual string getNome(){return pImpl_->getNome();}

  virtual void setConteudo(double content){ pImpl_->setConteudo(content);}

  virtual void setNome(string name){pImpl_->setNome(name);}

  virtual void incrementaConteudo(double value){pImpl_->incrementaConteudo(value);}

  virtual void decrementaConteudo(double value){pImpl_->decrementaConteudo(value);}

};


#endif
