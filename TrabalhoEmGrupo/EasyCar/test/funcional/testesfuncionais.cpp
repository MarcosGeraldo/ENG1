#include "testesfuncionais.h"

void testesFuncionais(){
    System *system= System::criateSystem("EasyCar");
    User* user = system->criateUser("Renato");
    Rent* rent=system->criateRent(user);
    Rent* rent1=system->criateRent(user);
    Rent* rent2=system->criateRent(user);
    Vehicle* ford=system->criateVehicle("Fusion");
    Vehicle* vw=system->criateVehicle("Gol");
    Vehicle* chevy=system->criateVehicle("Corsa");

    rent->setVehicle(ford);
    rent1->setVehicle(vw);
    rent2->setVehicle(chevy);


    ford->setBrand("Ford");
    ford->setDescription("Black,V6,Petrol,RWD");
    ford->setPrice(250);
    ford->setYear(2015);
    vw->setBrand("Vw");
    vw->setDescription("Silver,I4,Petrol,FWD");
    vw->setPrice(100);
    vw->setYear(2018);
    chevy->setBrand("Chevy");
    chevy->setDescription("White,I6,Petrol,FWD");
    chevy->setPrice(100);
    chevy->setYear(2015);

    Vehicle *search=system->criateVehicle("");
    vector<Rent*> ret;

    search->setYear(2015);

    ret=system->getRent(search);


    assert((ret[0]->getVehicle())->getModel()=="Fusion");
    assert((ret[1]->getVehicle())->getModel()=="Corsa");

    ret.clear();

    search->setYear(0);
    search->setPrice(100);
    ret=system->getRent(search);

    assert((ret[0]->getVehicle())->getModel()=="Gol");
    assert((ret[1]->getVehicle())->getModel()=="Corsa");

}
