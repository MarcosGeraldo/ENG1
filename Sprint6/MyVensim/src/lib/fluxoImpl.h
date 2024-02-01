#ifndef FLUXO_IMP_H
#define FLUXO_IMP_H


#include <cstdlib>
#include <iostream>
#include "fluxo.h"
#include "handleBodySemDebug.h"


using namespace std;

/**
*@brief Esta classe Fluxo conecta dois sistemas e por meio da equacao nele inserida trafere valores de um sistema ao outro
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class FluxBody : public Body {

protected:
  string nome;/* *< Esta variavel armazena o nome de um determinado fluxo */
  Sistema* destino;/* *< Esta variavel armazena  o sistema de destino deste fluxo */
  Sistema* origem;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  double fluxo;/* *<  Esta variavel armazena o valor a ser inserido no sistema de destino apos todos os calculos terem sido feitos  */

public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  */
  //FluxBody();
  /**
  *@brief Este contrutor atribui nome, origem e destino a um fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome e dois Sistemas, o destino e a origem
  */
  //FluxBody(string,Sistema*,Sistema*);
  /**
  *@brief Este construtor atribui nome, origem, destino, e um valor a ser armazenado dentro do fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome, dois Sistemas, o destino e a origem, e um double de conteudo
  */
  //FluxBody(string,Sistema*,Sistema*,double);
  /**
  *@brief Este destrutor é um destrutor virtual da Classe
  */
  //virtual ~FluxBody();
  /**
  *@brief Este metodo retorna o nome de um fluxo
  *
  *@retval É retornado uma string contendo o nome
  */
  string getNome();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setNome(string);
  /**
  *@brief Este metodo retorno o Sistema de destino de um Fluxo
  *
  *@retval É retornado um ponteiro de Sistema
  */
  Sistema* getDestino();
  /**
  *@brief Este metodo atribui um destino ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  void setDestino(Sistema*);
  /**
  *@brief Este metodo retorno o Sistema de origem  de um Fluxo
  *
  *@retval É retornado um ponteiro de Sistema da origem
  */
  Sistema* getOrigem();
  /**
  *@brief Este metodo atribui uma origem ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  void setOrigem(Sistema*);
  /**
  *@brief Este metodo retorna o valor armazenado dentro do Fluxo
  *
  *@retval É retornado um double contendo o valor que esta armazenado no fluxo
  */
  double getFluxo();
  /**
  *@brief Este metodo atribui um valor ao fluxo
  *
  *@param Deve ser passado um double contendo o valor para o metedo
  */
  void setFluxo(double);
  /**
  *@brief Este metodo virtual é o metodo que deve ser implementado, atribuindo uma equacao a este metodo
  *
  *@retval O retorno foi definido como double para manter a propiedade de um Fluxo, que deve apenas "transportar" valores
  */
  //virtual double equacao();
  /**
  *@brief Este metodo conecta dois sistemas entre si, tendo como conector o Fluxo que chamou este metodo
  *
  *@param Deve ser passados dois ponteiros de Sistema para a funcao
  */
  void conecta(Sistema*,Sistema*);
};


class FluxHandle : public Fluxo, public Handle<FluxBody>{
public:
  FluxHandle(string name,Sistema* source,Sistema* target){
    pImpl_->setNome(name);
    pImpl_->setOrigem(source);
    pImpl_->setDestino(target);
  }

  FluxHandle(){}

  ~FluxHandle(){
  }

  virtual string getNome(){return pImpl_->getNome();}

  virtual void setNome(string name){pImpl_->setNome(name);}

  virtual Sistema* getDestino(){return pImpl_->getDestino();}

  virtual void setDestino(Sistema* s){pImpl_->setDestino(s);}

  virtual Sistema* getOrigem(){return pImpl_->getOrigem();}

  virtual void setOrigem(Sistema* s){pImpl_->setOrigem(s);}

  virtual double getFluxo(){return pImpl_->getFluxo();}

  virtual void setFluxo(double value){pImpl_->setFluxo(value);}

  virtual double equacao()=0;

  virtual void conecta(Sistema* source,Sistema* target){pImpl_->conecta(source,target);}
};
#endif
