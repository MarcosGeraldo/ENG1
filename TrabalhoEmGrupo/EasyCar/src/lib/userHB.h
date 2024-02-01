#ifndef USER_HB_H
#define USER_HB_H


#include <cstdlib>
#include <vector>
#include <iostream>
#include "user.h"
#include "rent.h"
#include "handleBodySemDebug.h"


using namespace std;

/**
*@brief Esta classe Fluxo conecta dois sistemas e por meio da equacao nele inserida trafere valores de um sistema ao outro
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class UserBody : public Body {

protected:
  string name;/* *< Esta variavel armazena o nome de um determinado fluxo */
  string password;/* *< Esta variavel armazena  o sistema de destino deste fluxo */
  string email;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  string phone;/* *< Esta variavel armazena o nome de um determinado fluxo */
  string cpf;/* *< Esta variavel armazena o nome de um determinado fluxo */
  string address;/* *< Esta variavel armazena  o sistema de destino deste fluxo */
  string cnh;/* *< Esta variavel armazena o sistema de origem de um fluxo */
public:
  /**
  *@brief Este construtor é o construtor vazio da classe
  */
  UserBody();
  /**
  *@brief Este contrutor atribui nome, origem e destino a um fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome e dois Sistemas, o destino e a origem
  */
  UserBody(string);
  /**
  *@brief Este construtor atribui nome, origem, destino, e um valor a ser armazenado dentro do fluxo
  *
  *@param Deve ser passado para o construtor uma string contendo o nome, dois Sistemas, o destino e a origem, e um double de conteudo
  */
  UserBody(string,string,string);
  /**
  *@brief Este destrutor é um destrutor virtual da Classe
  */
  virtual ~UserBody();
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getName();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setName(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getPassword();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setPassword(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getEmail();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setEmail(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getPhone();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setPhone(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getCpf();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setCpf(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getAddress();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setAddress(string);
  /**
  *@brief Este metodo retorna o nome de um User
  *
  *@retval Ã‰ retornado uma string contendo o nome
  */
  string getCnh();
  /**
  *@brief Este metodo atribui o nome a uma string
  *
  *@param Deve ser passado um string para o metodo
  */
  void setCnh(string);
};


class UserHandle : public User, public Handle<UserBody>{
public:
  UserHandle(string name){
    pImpl_->setName(name);
  }
  UserHandle(string name,string email,string password){
    pImpl_->setName(name);
    pImpl_->setEmail(email);
    pImpl_->setPassword(password);
  }
  UserHandle(){}

  ~UserHandle(){
  }


  virtual string getName(){return pImpl_->getName();}

  virtual void setName(string name){pImpl_->setName(name);}

  virtual string getPassword(){return pImpl_->getPassword();}

  virtual void setPassword(string password){pImpl_->setPassword(password);}

  virtual string getEmail(){return pImpl_->getEmail();}

  virtual void setEmail(string email){pImpl_->setEmail(email);}

  virtual string getPhone(){return pImpl_->getPhone();}

  virtual void setPhone(string phone){pImpl_->setPhone(phone);}

  virtual string getCpf(){return pImpl_->getCpf();}

  virtual void setCpf(string cpf){pImpl_->setCpf(cpf);}

  virtual string getAddress(){return pImpl_->getAddress();}

  virtual void setAddress(string address){pImpl_->setAddress(address);}

  virtual string getCnh(){return pImpl_->getCnh();}

  virtual void setCnh(string cnh){pImpl_->setCnh(cnh);}
};
#endif
