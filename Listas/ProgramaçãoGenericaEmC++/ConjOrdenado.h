#ifndef CONJORD_H
#define CONJORD_H

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "Estudante.h"
#include "Disciplina.h"


template<typename Temp>
class ConjOrdenado{
public:
    list<Temp> lista;
    ConjOrd();
    ~ConjOrd();
    typename list<Temp>::iterator begin();
    typename list<Temp>::iterator end();
    void inserir(Temp item);
};



template <typename Temp>
ConjOrdenado<Temp>::ConjOrdenado(){}

template <typename Temp>
ConjOrdenado<Temp>::~ConjOrdenado(){}

template <typename Temp>
void ConjOrdenado<Temp>::inserir(Temp item){
    auto aux = lista.begin();
    for (aux = lista.begin(); aux != lista.end(); aux++){
        if ((item) < (*aux)){
            lista.insert(aux, item);
            return;
        }
    }
    lista.insert(aux, item);
}

template <typename Temp>
typename list<Temp>::iterator ConjOrdenado<Temp>::begin(){
    return lista.begin();
}

template <typename Temp>
typename list<Temp>::iterator ConjOrdenado<Temp>::end(){
    return lista.end();
}

#endif
