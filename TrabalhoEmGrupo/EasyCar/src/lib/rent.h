#ifndef RENT_H
#define RENT_H

#include "vehicle.h"
#include "user.h"


using namespace std;

/**
*@brief A Interface Fluxo Ã© a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Rent{
public:
  /**
  *@brief Este destrutor Ã© um destrutor virtual da Classe
  */
  virtual ~Rent(){};
  /**
  *@brief Este metodo retorna o nome de um fluxo
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual Vehicle* getVehicle()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setVehicle(Vehicle*)=0;
  /**
  *@brief Este metodo retorno o Sistema de destino de um Fluxo
  *
  *@retval Ã‰ retornado um ponteiro de Sistema
  */
  virtual User* getLessee()=0;
  /**
  *@brief Este metodo atribui um destino ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  virtual void setLessee(User*)=0;
  /**
  *@brief Este metodo retorno o Sistema de origem  de um Fluxo
  *
  *@retval Ã‰ retornado um ponteiro de Sistema da origem
  */
  virtual User* getLocator()=0;
  /**
  *@brief Este metodo atribui uma origem ao Fluxo
  *
  *@param Deve ser passado o ponteiro de Sistema a ser atribuido
  */
  virtual void setLocator(User*)=0;
  /**
  *@brief Este metodo retorna o valor armazenado dentro do Fluxo
  *
  *@retval Ã‰ retornado um double contendo o valor que esta armazenado no fluxo
  */
  virtual double getCost()=0;
  /**
  *@brief Este metodo atribui um valor ao fluxo
  *
  *@param Deve ser passado um double contendo o valor para o metedo
  */
  virtual void setCost(double)=0;
  /**
  *@brief Este metodo retorna o valor armazenado dentro do Fluxo
  *
  *@retval Ã‰ retornado um double contendo o valor que esta armazenado no fluxo
  */
  virtual int getStatus()=0;
  /**
  *@brief Este metodo atribui um valor ao fluxo
  *
  *@param Deve ser passado um double contendo o valor para o metedo
  */
  virtual void setStatus(int)=0;
  /**
  *@brief Este metodo retorna o valor armazenado dentro do Fluxo
  *
  *@retval Ã‰ retornado um double contendo o valor que esta armazenado no fluxo
  */
  virtual int getDuration()=0;
  /**
  *@brief Este metodo atribui um valor ao fluxo
  *
  *@param Deve ser passado um double contendo o valor para o metedo
  */
  virtual void setDuration(int)=0;
};



#endif
