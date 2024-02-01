#ifndef VEHICLE_HB_H
#define VEHICLE_HB_H

#include <cstdlib>
#include <iostream>
#include "vehicle.h"
#include "handleBodySemDebug.h"

using namespace std;


/**
*@brief A classe SistemaImpl é a classe que aramazena os valores, é a classe "conteiner"
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class VehicleBody : public Body{
protected:
  string brand="";/* *<Esta variavel armazena */
  double price=0;/* *< Esta variavel armazena */
  string description="";/* *<Esta variavel armazena */
  string model="";/* *< Esta variavel armazena a */
  int year=0;/* *< Esta variavel armazena  */
public:

  VehicleBody();

  ~VehicleBody();

  VehicleBody(string);

  string getBrand(void);

  void setBrand(string);

  double getPrice();

  void setPrice(double);

  string getDescription(void);

  void setDescription(string);

  string getModel(void);

  void setModel(string);

  int getYear(void);

  void setYear(int);
};

class VehicleHandle : public Vehicle, public Handle<VehicleBody>{
public:
  VehicleHandle(string name){
    pImpl_->setModel(name);
  }

  VehicleHandle(){}

  ~VehicleHandle(){}

  virtual string getBrand(void){return pImpl_->getBrand();};

  virtual void setBrand(string brand){pImpl_->setBrand(brand);};

  virtual double getPrice(){return pImpl_->getPrice();};

  virtual void setPrice(double price){pImpl_->setPrice(price);};

  virtual string getDescription(void){return pImpl_->getDescription();};

  virtual void setDescription(string descrip){pImpl_->setDescription(descrip);};

  virtual string getModel(void){return pImpl_->getModel();};

  virtual void setModel(string model){pImpl_->setModel(model);};

  virtual int getYear(void){return pImpl_->getYear();};

  virtual void setYear(int year){pImpl_->setYear(year);};

};


#endif
