#include "systemHB.h"


SystemBody::SystemBody(){
  name="";
}

SystemBody::~SystemBody(){
  for (User* us : users)
    if (us!=NULL)
      delete us;
  users.clear();
  for (Rent* re : rents)
    if (re!=NULL)
      delete re;
  rents.clear();
}

SystemBody::SystemBody(string nameImput){
  name = nameImput;
}

string SystemBody::getName(){
  return name;
}

void SystemBody::setName(string nameImput){
  name=nameImput;
}

void SystemBody::add(User *userImput){
  users.push_back(userImput);
}

void SystemBody::remove(User *userImput){
  int size = users.size();
  for (int i = 0; i < size; i++){
		if (users[i]->getName() == userImput->getName())
			users.erase(users.begin() + i);
	}
}

void SystemBody::add(Rent *rentImput){
  rents.push_back(rentImput);
}

void SystemBody::remove(Rent *rentImput){
  int size = rents.size();
  for (int i = 0; i < size; i++){
        if (&rents[i] == (&rentImput))
			rents.erase(rents.begin() + i);
	}
}

SystemBody& SystemBody::operator= (const SystemBody& sys){
	if (this == &sys)
		return *this;


	for (vector<User*>::iterator it = users.begin(); it != this->users.end(); it++)
		delete* it;

	users.clear();

	for (int i = 0, size = sys.users.size(); i < size; i++){
    users.push_back(sys.users[i]);
	}

  for (vector<Rent*>::iterator it = rents.begin(); it != this->rents.end(); it++)
		delete* it;

	rents.clear();

	for (int i = 0, size = sys.rents.size(); i < size; i++){
    rents.push_back(sys.rents[i]);
	}

	return *this;
}

bool SystemBody::operator== (const SystemBody& sys){
	if (this == &sys)
		return true;

	if (users.size() != sys.users.size())
		return false;

	for (int i = 0, size = sys.users.size(); i < size; i++)
		if (!(users[i] == sys.users[i]))
			return false;

  if (rents.size() != sys.rents.size())
		return false;

	for (int i = 0, size = sys.rents.size(); i < size; i++)
        if (!(rents[i] == sys.rents[i]))
            return false;

	return true;
}

void SystemBody::add(System* sys){
  system=sys;
}

System* SystemBody::system;

System* System::criateSystem(string name){
  return SystemBody::criateSystem(name);
}
System* SystemBody::criateSystem(string name){
  System* a = new SystemHandle(name);
  SystemBody::add(a);
  return a;
}

//////////////////////////


User* SystemBody::criateUser(string name){
  UserHandle* a = new UserHandle(name);
  add(a);
  return a;
}

User* SystemBody::getUser(string name){
  int size = users.size();
  for (int i = 0; i < size; i++){
		if (users[i]->getName() == name)
			return users[i];
	}
  return NULL;
}
vector<Rent*> SystemBody::getRent(Vehicle* car){
  int size = rents.size();
  Vehicle* carAux;
  vector<Rent*> aux;
  for (int i = 0; i < size; i++){
      carAux=rents[i]->getVehicle();
        if (carAux->getBrand()==car->getBrand()||carAux->getModel()==car->getModel()||carAux->getDescription()==car->getDescription()||carAux->getYear()==car->getYear()||carAux->getPrice()==car->getPrice())
            aux.push_back(rents[i]);

    }
  return aux;
}

Rent* SystemBody::criateRent(User* ur){
  RentHandle* a = new RentHandle(ur);
  add(a);
  return a;
}

Vehicle* SystemBody::criateVehicle(string model){
  VehicleHandle* a = new VehicleHandle(model);
  return a;
}

////////////////////////////
