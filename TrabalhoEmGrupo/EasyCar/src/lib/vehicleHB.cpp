#include "vehicleHB.h"


VehicleBody::VehicleBody(){}

VehicleBody::~VehicleBody(){}

VehicleBody::VehicleBody(string nameImput){
  model = nameImput;
}


string VehicleBody::getBrand(void){
  return brand;
}

void VehicleBody::setBrand(string brandInput){
  brand=brandInput;
}

double VehicleBody::getPrice(){
  return price;
}

void VehicleBody::setPrice(double priceImput){
  price=priceImput;
}

string VehicleBody::getDescription(void){
  return description;
}

void VehicleBody::setDescription(string descriptionImput){
  description=descriptionImput;
}

string VehicleBody::getModel(void){
  return model;
}

void VehicleBody::setModel(string modelImput){
 model=modelImput;
}

int VehicleBody::getYear(void){
  return year;
}

void VehicleBody::setYear(int yearImput){
  year=yearImput;
}
