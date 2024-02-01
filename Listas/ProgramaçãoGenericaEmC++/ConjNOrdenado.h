#ifndef CONJNORD_H
#define CONJNORD_H

#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "Estudante.h"
#include "Disciplina.h"

template<typename Temp>
class ConjNOrdenado{
public:
    list<Temp> lista;

    ConjNOrdenado();
    ~ConjNOrdenado();
    typename list<Temp>::iterator begin();
    typename list<Temp>::iterator end();
    void inserir(Temp elemento);
};


template <typename Temp>
ConjNOrdenado<Temp>::ConjNOrdenado(){}

template <typename Temp>
ConjNOrdenado<Temp>:: ~ConjNOrdenado(){}

template <typename Temp>
void ConjNOrdenado<Temp>::inserir(Temp item){
    lista.push_back(item);
}

template <typename Temp>
typename list<Temp>::iterator ConjNOrdenado<Temp>::begin(){
    return lista.begin();
}

template <typename Temp>
typename list<Temp>::iterator ConjNOrdenado<Temp>::end(){
    return lista.end();
}

#endif
