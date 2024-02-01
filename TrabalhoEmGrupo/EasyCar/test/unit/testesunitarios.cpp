#include "testesunitarios.h"

void testeVehicle(){
    System *system= System::criateSystem("EasyCar");

    Vehicle* ford=system->criateVehicle("Fusion");

    assert(ford->getModel()=="Fusion");

    ford->setBrand("Ford");
    ford->setDescription("V6 Engine, RWD");
    ford->setPrice(350);
    ford->setYear(2010);
    ford->setModel("ford escort");

    assert(ford->getModel()=="ford escort");
    assert(ford->getDescription()=="V6 Engine, RWD");
    assert(ford->getPrice()==350);
    assert(ford->getYear()==2010);
    assert(ford->getBrand()=="Ford");

}
void testeUser(){
    System *system= System::criateSystem("EasyCar");

    User* user = system->criateUser("Renato");

    assert(user->getName()=="Renato");

    user->setCpf("13592269666");
    user->setAddress("Rua quitandinha 102");
    user->setCnh("MG 22 154 145");
    user->setEmail("xaolimatadordeporco@gmail.com");
    user->setPassword("123456789");
    user->setPhone("40028922");
    user->setName("Rodrigo");

    assert(user->getName()=="Rodrigo");
    assert(user->getAddress()=="Rua quitandinha 102");
    assert(user->getCnh()=="MG 22 154 145");
    assert(user->getEmail()=="xaolimatadordeporco@gmail.com");
    assert(user->getPassword()=="123456789");
    assert(user->getPhone()=="40028922");

}
void testeRent(){
    System *system= System::criateSystem("EasyCar");
    User* user = system->criateUser("Renato");
    User* user1 = system->criateUser("Rodrigo");

    Rent* rent=system->criateRent(user);
    assert(user->getName()==(rent->getLocator())->getName());

    rent->setLessee(user1);
    assert(user1->getName()==(rent->getLessee())->getName());

    Vehicle* ford=system->criateVehicle("Ford");
    rent->setVehicle(ford);
    assert(ford->getModel()==(rent->getVehicle())->getModel());

    rent->setStatus(1);
    rent->setCost(500);
    rent->setDuration(10);
    assert(rent->getStatus()==1);
    assert(rent->getCost()==500);
    assert(rent->getDuration()==10);

}

void testeSystem(){
    System *system= System::criateSystem("EasyCar");
    vector<Rent*> aux;

    User* user = system->criateUser("Renato");

    user->setName("Rodrigo");

    User* user1=system->getUser("Rodrigo");

    assert(user1->getName()=="Rodrigo");

    Rent *rent=system->criateRent(user);

    Vehicle* car=system->criateVehicle("Fusion");

    rent->setVehicle(car);

    aux=system->getRent(car);

    assert((aux[0]->getVehicle())->getModel()==car->getModel());
}
