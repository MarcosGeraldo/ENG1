#ifndef FLUXO_H
#define FLUXO_H


#include <cstdlib>
#include <iostream>
#include <string>
#include "sistema.h"

using namespace std;

/**
*@brief Esta classe Fluxo conecta dois sistemas e por meio da equacao nele inserida trafere valores de um sistema ao outro
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Fluxo{

protected:
  string nome;/* *< Esta variavel armazena o nome de um determinado fluxo */
  Sistema* destino;/* *< Esta variavel armazena  o sistema de destino deste fluxo */
  Sistema* origem;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  double fluxo;/* *<  Esta variavel armazena o valor a ser inserido no sistema de destino apos todos os calculos terem sido feitos  */

public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  */
  Fluxo();
  /**
  *@brief Este contrutor atribui nome, origem e destino a um fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome e dois Sistemas, o destino e a origem
  */
  Fluxo(string,Sistema*,Sistema*);
  /**
  *@brief Este construtor atribui nome, origem, destino, e um valor a ser armazenado dentro do fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome, dois Sistemas, o destino e a origem, e um double de conteudo
  */
  Fluxo(string,Sistema*,Sistema*,double);
  /**
  *@brief Este destrutor é um destrutor virtual da Classe
  */
  virtual ~Fluxo();
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
  virtual double equacao()=0;
  /**
  *@brief Este metodo conecta dois sistemas entre si, tendo como conector o Fluxo que chamou este metodo
  *
  *@param Deve ser passados dois ponteiros de Sistema para a funcao
  */
  void conecta(Sistema*,Sistema*);
};



#endif
