#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using namespace std;


/**
*@brief A Interface Vehicle ÃƒÂ© a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class Vehicle{


public:
  /**
  *@brief Este ÃƒÂ© o destrutor da classe
  */
  virtual~Vehicle(){};
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno ÃƒÂ© uma string que contem o nome do sistema
  */
  virtual string getBrand(void)=0;
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  virtual void setBrand(string)=0;
  /**
  *@brief Este metodo retorna o conteudo de um sistema
  *
  *@retval Ãƒâ€° retornado um double contendo o conteudo de um sistema
  */
  virtual double getPrice()=0;
  /**
  *@brief Este metodo atribui um valor ao conteudo de um sistema
  *
  *@param Deve ser passado para esse metodo um double a ser atribuido
  */
  virtual void setPrice(double)=0;
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno ÃƒÂ© uma string que contem o nome do sistema
  */
  virtual string getDescription(void)=0;
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  virtual void setDescription(string)=0;
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno ÃƒÂ© uma string que contem o nome do sistema
  */
  virtual string getModel(void)=0;
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  virtual void setModel(string)=0;
  /**
  *@brief Este metodo retorna o nome de um sistema
  *
  *@retval O retorno ÃƒÂ© uma string que contem o nome do sistema
  */
  virtual int getYear(void)=0;
  /**
  *@brief Este metodo atribui um nome a um sistema
  *
  *@param Uma string armazenando o nome que se deseja atribuir a um sistema
  */
  virtual void setYear(int)=0;
};



#endif
