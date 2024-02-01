#include "rentHB.h"


RentBody::RentBody(){}

RentBody::RentBody(User*){}

RentBody::~RentBody(){}

Vehicle* RentBody::getVehicle(){
  return vehicle;
}

void RentBody::setVehicle(Vehicle* vehicleImput){
  vehicle=vehicleImput;
}

User* RentBody::getLessee(){
  return lessee;
}

void RentBody::setLessee(User* lesseeImput){
  lessee=lesseeImput;
}

User* RentBody::getLocator(){
  return locator;
}

void RentBody::setLocator(User* locatorImput){
  locator=locatorImput;
}

double RentBody::getCost(){
  return cost;
}

void RentBody::setCost(double costImput){
  cost=costImput;
}

int RentBody::getStatus(){
  return status;
}

void RentBody::setStatus(int statusImput){
  status=statusImput;
}

int RentBody::getDuration(){
  return duration;
}

void RentBody::setDuration(int durationImput){
  duration=durationImput;
}
