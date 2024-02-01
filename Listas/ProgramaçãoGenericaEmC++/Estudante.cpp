#include <iostream>
#include <string>


#include "Estudante.h"


Estudante::Estudante(int entradamatricula,int entradaIdade,double entradaCpf,char* entradaNome){
  matricula=entradaMatricula;
  idade=entradaIdade;
  cpf=entradaCpf;
  strcpy(nome,entradaNome);
}
Estudante::~Estudante(){
  try{
    delete[] nome;
  }
}
Estudante:: getNome(void){
  return nome;
}
Estudante:: getIdade(void){
  return idade;
}
Estudante:: GetCpf(void){
  return cpf;
}
Estudante:: getMatricula(void){
  return matricula;
}
Estudante:: setNome(char* entradaNome){
  strcpy(nome,entradaNome);
}
Estudante:: setIdade(int entradaIdade){
  idade=entradaIdade;
}
Estudante:: setCpf(double entradaCpf){
  cpf=entradaCpf;
}
Estudante:: setMatricula(int entradaMatricula){
  matricula=entradaMatricula;
}
