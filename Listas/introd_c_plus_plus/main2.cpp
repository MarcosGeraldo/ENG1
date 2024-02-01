#include <cstdlib>
#include <iostream>

using namespace std;

// QUEST�O 1: O c�digo desse exerc�cio � id�ntico ao do exerc�cio anterior.
//          Por�m o operador "<<" foi sobrecarregado para permitir que
//          programador implemente de maneira mais f�cil a sa�da do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1;
//
//          a) Explique porque o m�todo que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa?
                //1)A) O método foi declarado como friend para ter acesso
                //aos membros privados e protegidos, no caso a variável orc, que foi utilizada.

//          b) Explique o funcionamento do novo operador "<<".
                //B) O funcionamento do novo operador é o seguinte, para este novo operador
                //é passado um “objeto” da classe ostream, s, e um objeto de Casa, c, a ser
                //impresso, o conteúdo da variável orc de c é passado com o operador << para a
                //variável s e o s é retornado.

class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUEST�O 2: Explique o c�digo abaixo e cada uma das linhas de texto que
// formam sua sa�da.
      //2)A primeira linha a ser impressa é “C1: “seguido do valor orc de c1, 7,
      //e “, C2: “seguido do valor orc de c1 também 7, na linha de baixo o valor
      //de orc de c1 é alterado para 3 por meio da variável referencia c2, e é
      //impresso utilizando-se da sobrecarga de operadores “C1: “valor de orc de c1, 3,
      //e “, C2: “o valor de c1 também 3 por meio da variável referência c2.
int main(int argc, char *argv[])
{
    Casa c1(7), &c2 = c1;

    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;
    c2.setOrc(3);
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
