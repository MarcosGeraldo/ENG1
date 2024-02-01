include <iostream>
#include <string>


#include "Disciplina.h"




Disciplina::Disciplina(char* entradaCodigo,int entradaHoras,char* entradaProfessor){
  strcpy(codigo,entradaCodigo);
  strcpy(professor,entradaProfessor);
  horas=entradaHoras;
}
Disciplina::~Disciplina(){
  try{
    delete[] codigo;
    delete[] professor;
  }
}

Disciplina:: getCodigo(void){
  return codigo;
}
Disciplina:: getHoras(void){
  return horas;
}
char* getProfessor(void){
  return prpfessor;
}
Disciplina:: setCodigo(int entradaCodigo){
  strcpy(codigo,entradaCodigo);
}
Disciplina:: setHoras(int entradaHoras){
  horas=entradaHoras;
}
Disciplina:: setProfessor(char* entradaProfessor){
  strcpy(professor,entradaProfessor);
}
