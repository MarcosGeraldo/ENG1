#ifndef USER_H
#define USER_H

#include<string>

using namespace std;

/**
*@brief A Interface User Ã© a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class User{

public:
  /**
  *@brief Este destrutor Ã© um destrutor virtual da Classe
  */
  virtual ~User(){};
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getName()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setName(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getPassword()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setPassword(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getEmail()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setEmail(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getPhone()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setPhone(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getCpf()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setCpf(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getAddress()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setAddress(string)=0;
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  virtual string getCnh()=0;
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  virtual void setCnh(string)=0;
};



#endif
