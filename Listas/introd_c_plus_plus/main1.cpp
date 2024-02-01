#define EXERC1

#include <cstdlib>
#include <iostream>
#include "Casa.h"

using namespace std;

#if defined(EXERC1)
// QUEST�O 1: Critique o c�digo abaixo e aponte seus problemas com rela��o:
//          a) � flexibilidade da implementa��o: altera��es em pequenos trechos
//             do c�digo n�o deveriam exigir recodifica��o de outras partes
                  //1)A) A flexibilidade de código na implementação desta classe está
                  //feita de uma forma bem ruim, de modo que os métodos, estão juntos
                  //com os atributos, que estão juntos com o main, de forma que qualquer
                  //alteração necessita necessariamente da re compilação do código.

//          b) � legibilidade do c�digo: lendo o c�digo � f�cil entrender os
//             objetos e processos que ele representa. Qual � seu objetivo?
                  //B) O código está escrito de forma bem compactada, de modo que as
                  //linhas de código não ficam organizadas em blocos ou secções, na
                  //classe as variáveis possuem nomes não significativos, código por
                  //si próprio não tem comentário algum explicando o que está sendo feito.

class Casa {

      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na quest�o 1.
class Casa {
      // Coloque suas corre��es aqui...
      // A primeira correção já foi feita, criar uma biblioteca para armazenar a classe
      // Ea definição dentro de "Casa.h", seria->
    private:
      float nomeSignificativo; //como não sei o que essa variavel representaria
      int nomeSignificativo1;
    public:
      Casa() {}
      Casa(float nomeSignCons ) : setNomeSig(nomeSigCons)
      Casa(float nomeSignCons, int nomeSignCons1) : setNomeSig(nomeSigCons),setNomeSig1(nomeSignCons1)
          {}
      void setNomeSig( float dado ) {
          nomeSignificativo = dado;
      }
      float getNomeSig( void ) {
          return nomeSignificativo;
      }
      void setNomeSig1( int dado1 ) {
          nomeSignificativo1 = dado1;
      }
      int getOrc( void ) {
          return nomeSignificativo1;
      }
};
// ...e aqui se necess�rio.
#endif

// QUESTAO 3: Explique o c�digo abaixo e cada uma das linhas de texto que
// formam sua sa�da.
      //3)A primeira linha de sua saída imprime o valor contido em c1, no caso 7,
      //logo em seguida é impresso o conteúdo de C2, mas como C2 e um ponteiro que
      //aponta para C1 é impresso 3, valor atribuído na linha 62, na próxima linha e
      //impresso C3, que é uma variável referencia a C1, logo a valor impresso é 3 e
      //na ultima linha o valor de C2 e C3 são impressos, ambos valendo 3.

int main(int argc, char *argv[])
{
    Casa c1(7), *c2 = &c1, &c3 = c1;

    cout << "C1: " << c1.getOrc() << endl;
    c1.setOrc(3);
    cout << "C2: " << c2->getOrc() << ", ";
    cout << "C3: " << c3.getOrc() << endl;
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?
      //)O construtor da classe foi invocado uma vez, tendo em vista que a
      //única variável que realmente o invocou foi C1, pois C2 é um ponteiro
      //e C3 é uma variável de referência a C1.
