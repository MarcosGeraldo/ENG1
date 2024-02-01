#ifndef RENT_HB_H
#define RENT_HB_H


#include <cstdlib>
#include <iostream>
#include "handleBodySemDebug.h"
#include "rent.h"

using namespace std;

/**
*@brief Esta classe Fluxo conecta dois sistemas e por meio da equacao nele inserida trafere valores de um sistema ao outro
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class RentBody : public Body {

protected:
  User* lessee;/* *< Esta variavel armazena  o sistema de destino deste fluxo */
  User* locator;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  Vehicle *vehicle;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  int status;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  double cost;/* *< Esta variavel armazena o sistema de origem de um fluxo */
  int duration;/* *< Esta variavel armazena o sistema de origem de um fluxo */

public:

  RentBody();

  RentBody(User*);

  virtual ~RentBody();

  Vehicle* getVehicle();

  void setVehicle(Vehicle*);

  User* getLessee();

  void setLessee(User*);

  User* getLocator();

  void setLocator(User*);

  double getCost();

  void setCost(double);

  int getStatus();

  void setStatus(int);

  int getDuration();

  void setDuration(int);

};


class RentHandle : public Rent, public Handle<RentBody>{
public:
  RentHandle(User* locator){
    pImpl_->setLocator(locator);
  }

  RentHandle(){}

  ~RentHandle(){}

  virtual Vehicle* getVehicle(){return pImpl_->getVehicle();}

  virtual void setVehicle(Vehicle* vehicle){pImpl_->setVehicle(vehicle);}

  virtual User* getLessee(){return pImpl_->getLessee();}

  virtual void setLessee(User* lessee){pImpl_->setLessee(lessee);}

  virtual User* getLocator(){return pImpl_->getLocator();}

  virtual void setLocator(User* locator){pImpl_->setLocator(locator);}

  virtual double getCost(){return pImpl_->getCost();}

  virtual void setCost(double cost){pImpl_->setCost(cost);}

  virtual int getStatus(){return pImpl_->getStatus();}

  virtual void setStatus(int status){pImpl_->setStatus(status);}

  virtual int getDuration(){return pImpl_->getDuration();}

  virtual void setDuration(int duration){pImpl_->setDuration(duration);}

  //virtual void setLessee(User*){}

  //virtual void setLocator(User*){}

};
#endif
