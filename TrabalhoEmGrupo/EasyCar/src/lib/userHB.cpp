#include "userHB.h"


UserBody::UserBody(){}

UserBody::UserBody(string nameImput){
  name=nameImput;
}

UserBody::UserBody(string nameImput,string emailImput,string passwordImput){
  name=nameImput;
  email=emailImput;
  password=passwordImput;
}

UserBody::~UserBody(){

}

string UserBody::getName(){
 return name;
}

void UserBody::setName(string nameImput){
 name=nameImput;
}

string UserBody::getPassword(){
  return password;
}

void UserBody::setPassword(string passwordImput){
 password=passwordImput;
}

string UserBody::getEmail(){
 return email;
}

void UserBody::setEmail(string emailImput){
  email=emailImput;
}

string UserBody::getPhone(){
 return phone;
}

void UserBody::setPhone(string phoneImput){
  phone=phoneImput;
}

string UserBody::getCpf(){
 return cpf;
}

void UserBody::setCpf(string cpfImput){
  cpf=cpfImput;
}

string UserBody::getAddress(){
 return address;
}

void UserBody::setAddress(string addressImput){
  address=addressImput;
}

string UserBody::getCnh(){
 return cnh;
}

void UserBody::setCnh(string cnhImput){
  cnh=cnhImput;
}
