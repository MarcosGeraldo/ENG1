#include <iostream>
#include <algorithm>
#include <assert.h>
#include "Estudante.h"
#include "Disciplina.h"
#include "ConjNOrdenado.h"
#include "ConjOrdenado.h"


int Sum(ConjOrdenado<Disciplina*>& conjunto){
    int resultado = 0;
    for (auto item : conjunto){
        resultado += item->getCargaHoraria();
    }
    return soma;
}

double Average(ConjOrdenado<Disciplina*>& conjunto){
    int resultado = 0;
    int quantidade = 0;
    for (auto item : conjunto){
        resultado += itemm->getCargaHoraria();
        quantidade++;
    }
    return resultado/quantidade;
}


int main()
{
    Estudante estudante1("Aluno1", 1234567);
    Estudante estudante2("Aluno2", 1234567);

    Disciplina disciplina1("Disciplina1", 120);
    Disciplina disciplina2("Disciplina2", 60);

    ConjNOrdenado <Estudante*> conjunto1;
    ConjOrdenado <Disciplina*> conjunto2;

    conjunto1.inserir(&estudante1);
    conjunto1.inserir(&estudante2);
    conjunto1.inserir(&estudante1);

    conjunto2.inserir(&disciplina2);
    conjunto2.inserir(&disciplina2);
    conjunto2.inserir(&disciplina1);

    assert(count(conjunto1.begin(),conjunto1.end(),&estudante1)== 2);

    assert(count(conjunto2.begin(), conjunto2.end(),&disciplina1) == 1);

    assert(Sum(conjunto2) == 140);
    assert(Average(conjunto2) == 140/3);

    return 0;
}
