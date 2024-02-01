#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "ConjNOrdenado.h"
#include "Estudante.h"
#include "Disciplina.h"


template <typename Temp>
ConjNOrdenado<Temp>::ConjNOrdenado(){}

template <typename Temp>
ConjNOrdenado<Temp>::~ConjNOrdenado(){
    for (auto item : lista){
        delete item;
    }
}

template <typename Temp>
void ConjNOrdenado<Temp>::inserir(Temp item){
    lista.push_back(item);
}

template <typename Temp>
typename list<Temp>::iterator ConjNOrdenado<Temp>::begin(){
    return lista.begin();
}

template <typename Temp>
typename list<Temp>::iterator ConjNOrdenadod<Temp>::end(){
    return lista.end();
}
