#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "ConjOrdenado.h"
#include "Estudante.h"
#include "Disciplina.h"

template <typename Temp>

ConjOrdenado<Temp>::ConjOrdenado(){}

template <typename Temp>
ConjOrdenado<Temp> :: ~ConjOrdenado(){
    for (auto item : lista){
        delete item;
    }
}


template <typename Temp>
void ConjOrdenado<Temp> ::inserir(Temp item)
{
    auto aux;
    for (aux = lista.begin();aux != lista.end();aux++){
        if ((*item) > (aux)){
            lista.insert(aux, item);
            return;
        }
    }
    lista.insert(aux,item);
}


template <typename Temp>
typename list<Temp>::iterator ConjOrdenado<Temp>::begin(){
    return lista.begin();
}


template <typename Temp>
typename list<Temp>::iterator ConjOrdenado<Temp>::end(){
    return lista.end();
}
