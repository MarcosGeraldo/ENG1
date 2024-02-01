#ifndef SYSTEM_HB_H
#define SYSTEM_HB_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "system.h"
#include "userHB.h"
#include "rentHB.h"
#include "vehicleHB.h"

using namespace std;

/**
*@brief Esta classe armazena o tempo da simulacao e um vector contendo todos os fluxos deste modelo
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class SystemBody : public Body{

protected:
  string name="";/* *< Esta variavel aramazena o nome de um modelo */
  vector<User*> users;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para fluxo*/
  vector<Rent*> rents;/* *< Esta variavel armazena um vector de variaves do tipo ponteiro para fluxo*/
  static System* system;
public:

  SystemBody();

  virtual ~SystemBody();

  SystemBody(string);

  string getName();

  void setName(string);

  void add(User*);

  void remove(User*);

  void add(Rent*);

  void remove(Rent*);

  static System* criateSystem(string name);

  User* criateUser(string);

  Rent* criateRent(User*);

  Vehicle* criateVehicle(string);

  User* getUser(string);

  vector<Rent*> getRent(Vehicle*);

  static void add(System*);

private:

  SystemBody& operator= (const SystemBody&);

  bool operator== (const SystemBody&);
};

class SystemHandle : public System, public Handle<SystemBody>{
public:
  SystemHandle(string name){
    pImpl_->setName(name);
  }

  SystemHandle(){}

  ~SystemHandle(){}

  virtual string getName(){return pImpl_->getName();}

  virtual void setName(string name){pImpl_->setName(name);}

  virtual void add(User*){}

  virtual void remove(User*){}

  virtual void add(Rent*){}

  virtual void remove(Rent*){}

  virtual User* criateUser(string name){return pImpl_->criateUser(name);}

  virtual Rent* criateRent(User* user){return pImpl_->criateRent(user);}

  virtual Vehicle* criateVehicle(string model){return pImpl_->criateVehicle(model);}

  virtual User* getUser(string name){return pImpl_->getUser(name);}

  virtual vector<Rent*> getRent(Vehicle* car){return pImpl_->getRent(car);}
};


#endif
