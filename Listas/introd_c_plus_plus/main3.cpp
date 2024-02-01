// Sistema: Gerenciamento de Concessionaria de Automoveis - AutoMananger
// Modulo: Principal
// Autor: Tiago Garcia de Senna Carneiro
// Ultima alteracao:15/12/2006
// Responsavel: Tiago G. S. Carneiro
//
// Descri��o: Este eh o modulo principal do sistema para gerenciamento
// de uma agencia de automoveis: motos, caminhoes e ve�culos de passeio. Ele
// mantem o cadastro de automoveis a venda, a lista de cliente com os quais a
// concessionaria se relaciona, e a lista de funcionarios da empresa, e uma
// lista de carros que est�o na oficina com o nome do funcin�rio que repons�vel
// pelo conserto. Motos nunca sao enviadas para oficina, pois os mecanicos s�
// consertam carros. Uma nova funcionalidade foi implementada para o
// departamento de marketing, os veiculos na concessionaria sao classificados
// automaticamente classificados em veiculos de duas ou quatro rodas.
//
// Servi�os (API):
//           - Gerencia cadastro de veiculos e funcionarios (RUIM: Realiza a entrada e sa�da de dados)
//           - Calcula o reajuste de salarial para todos os funcionarios.
//           - Imprime a lista de carros com o nome do funcionario
//           responsavel pelo conserto.
//           - Lista de veiculos classificados pelo numero de rodas.
//
// Requisitos:
//           - Nenhuma informa��o deve ser persistida.
//           - Fornecer a qualquer momento o numero de automoveis carregados
//           na memoria.

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#include "veiculo.h"
#include "cliente.h"
#include "funcionario.h"

// QUESTAO 1: A funcao abaixo cria nomes com base em um prefixo escolhido pelo
// pelo programador. Por exemplo, para o parametro "Cliente" ela cria os nomes:
// Cliente0, Cliente1, Cliente2,...
// Responda:
//          (a) Por que a variavel "cont" foi declarada static?
                    //1)A) A variável cont foi definida como static para que o contador
                    //não se reiniciasse toda vez, o contador se torna estável, a variável
                    //é criada não com o inicio da função, ms com o início do programa,
                    //desta forma o valor atual não é perdido.

//          (b) Por que "sufixo" nao foi declarado como "char*" ao invez de
//              "char[15]"? Tente fazer essa altera��o, recompliar e executar
//              o codigo para entender o porque.
                    //B) Ele foi declarado como char [15] porque esta variável é
                    //utilizada como um buffer para a função itoa.

//          (c) Por que e somado 1(uma) unidade ao tamanho do nome?
                  //C) É somado 1 pois a função strcat coloca um caractere nulo no fim da string.

//          (d) Qual a vantagem obtida ao se declarar a variavel "cont" local
  //            a rotina "criaNome" ao invez de declara-la global ao modulo?
                    //D) Segurança, declarando-a localmente a chance de alguma alteração
                    // incorreta ser feita nela é muito pequena.

//          (e) Porque � necess�rio alocar memoria para variavel
//              "str" atrav�s do operador "new"? Altere codigo para "char *str",
//              e deixe de alocar memoria. Ent�o, execute o programa e veja o
//              que acontece.
                  //E) É necessário alocar memória pois é uma informação
                  // a ser utilizada posteriormente e caso isso não seja feito haveria uma perda de dados.

char* criaNome( const char *prefixo )
{
      static unsigned int cont = 0;

      // converte inteiro (int) para string (array) utilizando a base 10
      // e cria o sufixo do nome
      char sufixo[15];
      itoa(cont, sufixo, 10);

      // calcula o tamanho do novo nome a partir dos tamanhos do prefixo e do
      // sufixo
      int size = strlen(prefixo) + strlen(sufixo) + 1;

      // incrementa gerador de sulfixo
      cont++;

      // char* str;
      char* str = new char[size];
      strcpy( str , prefixo ); // copia a segunda string para a primeira
      strcat( str , sufixo );  // anexa a segunda sring a primeira
      return  str;

}

#define MAIN_2
#if defined(  MAIN_1 )

// QUESTAO 2:  Antes de executar o codigo abaixo, pressione "ctrl+alt+del" e
// ative o painel "desempenho" do gerenciador de tarefas do Windows. Execute o
// o codigo e observe o consumo de mem�ria registrado pelo sistema operacional.
// Explique porque a demanda por mem�ria aumenta sempre que seu programa �
// executado. Altere a classe "Cliente" para corrigir essa falha na
// sua implementacao.
// Obs: N�o se esque�a de recompilar todo o c�digo para que sua corre��o tenha
// efeito.
      //2)Ocorre um grande uso de memoria pois estamos apenas alocando mais e mais memoria para
      //suprir as chamadas feitas dentro do criaNome, mas tal memória não está sendo liberada
      //de forma alguma durante a execução do programa
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{
    char* const PREFIXO = "Dr. Fulano";
    cout << "espere..." << endl;
    for( unsigned int i = 0; i < 10000; i++ ){
         for( unsigned int j = 0; j < 10000; j++ ){
              //Para sanar o problema a implementação de um destrutor seria satisfatoria
              // e tambem a criação de um try catch para destruir os cliantes antes de realocar novamente
              try{
                delete[] cli1;
                delete[] cli2;
                delete[] cli3;
              }
              Cliente cli1("Dra. Beltrana"), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
         }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_2 )
// QUESTAO 3: Para resolver esta questao, antes, vc devera resolver a QUESTAO 2.
// Antes de executar o codigo abaixo, pressione "ctrl+alt+del" e ative o painel
// "desempenho" do gerenciador de tarefas do Windows. Ent�o, execute o codigo e
// observe que o erro de consumo indevido de memoria retournou. Entretanto,
// sua causa agora � outra. Ou ent�o aconteceu o pior, seu programa est�
// abortando e n�o funciona mais devio ao erro gerado pela linha "cli1 = cli2".
// Comente esta linha e ent�o observe o resultado do progrma. Explique a
// sa�da do programa e a causa do erro? Sobrecarregue o opeador "=" da classe
// "Cliente" e corrija o problema.
// Garanta que sua corre��o passe sem problemas pelo codigo: "cli1 = cli1", onde
// um objeto "Cliente" � atribuido a ele mesmo.
unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{
    char* const PREFIXO = "Dr. Fulano";

    cout << "espere..." << endl;
    for( unsigned int i = 0; i < 100000; i++ ){
         for( unsigned int j = 0; j < 100; j++ ){
            try{
              delete[] cli1;
              delete[] cli2;
              delete[] cli3;
            }
              Cliente cli1(criaNome(PREFIXO)), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
              cli1 = cli2;   // linha que esta gerando erro
        }
    }
    system("PAUSE");

    Cliente cli1("Dra. Beltrana"), cli2(criaNome(PREFIXO)), cli3(criaNome(PREFIXO));
    cout << "Antes  -- Clientes: " << cli1.getNome() <<", "<< cli2.getNome();
    cout << ", "  << cli3.getNome() << endl;
    cout << "Antes  -- Clientes: " << (void*)cli1.getNome() <<", "<< (void*)cli2.getNome();
    cout << ", "  << (void*)cli3.getNome() << endl;
    cout << endl << endl;
    cli2 = cli1;
    cout << "Depois -- Clientes: " << cli1.getNome() <<", "<< cli2.getNome();
    cout << ", "  << cli3.getNome() << endl;
    cout << "Depois -- Clientes: " << (void*)cli1.getNome() <<", "<< (void*)cli2.getNome();
    cout << ", "  << (void*)cli3.getNome() << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_3 )

// QUESTAO 4: Ao invez de declararmos uma vari�vel global para mantermos a
// contagem do numero de objetos da classe "Veiculo" carregados na mem�ria,
// decidimos declarar a var��vel "cont" na pr�pria classe "Veiculo". Qual �
// a vantagem dessa abordagem? Por que essa variavel precisa ser declarada como
// "static" para que nosso codigo funcione? Experimente tirar o qualificador
// "static" e executar a nova vers�o do codigo para entender, por completo,
// seu funcionamento. Ao retirar o qualificador "static" da variavel, vc
// percebera que os metodos que fazem acesso a variavel "cont" tambem precisarao
// deixar de ser "static".
        //4)A vantagem de declarar a variável cont de forma local na classe veículo
        //é que nos temos maior segurança, se esta variável não for declarada como
        //static, a cada chamada para a classe o valor será reiniciado.

// QUESTAO 5: Por que o metodo "getCont()" pode ser invocado por meio do nome
// da classe, "Veiculo::getCont()", e n�o � preciso um objeto para invoca-lo?
      // 5)Isso pode ser feito pois uma variável static é de certa forma compartilhada
      // para todos os objetos, e existe de forma independente de um objeto em especifico,
      // logo é possível invocá-la por meio da classe.

unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Carro car1(10.0f), &car2 = car1;
    Caminhao cam1(100);

    cout << "Antes - Numero de ve�culos na memoria: " << car1.getCont() << endl;
    Carro car3(100);
    cout << "Depois - Numero de ve�culos na memoria: " << Veiculo::getCont() << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_4)

// QUESTAO 6: Na classe "Funcionario" o metodo "reajustaSalario" foi declarado
// como um metodo "virtual". Observe o codigo abaixo e explique o por que. Para
// entender melhor o funcionamento desse codigo, retire o qualificador "virtual"
// do metodo "reajustaSalario", execute o programa novamente e observe sua
// sa�da.
    //6) O método “reajustaSalario” e declarado como Virtual pois este método é posteriormente
    //reimplementado pelas classes, Gerente, GerenteGeral e Mecânico, e seus valores são
    //diferentes entre si.

unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Funcionario* funcs[5];
    String r = "Ciclano";

    // alloca memoria para o cadastro de funcionarios, perceba que cada item
    // do cadastro � um tipo diferente de funcionario
    funcs[0] = new Mecanico(10.0f, r );
    funcs[1] = new Mecanico(10.0f, r );
    funcs[2] = new GerenteGeral(10.0f, r);
    funcs[3] = new Gerente(10.0f, r);
    funcs[4] = new Gerente(10.0f, r);

    for(int i = 0; i < 5; i++ ) {
            cout << "Funcionario[" << i << "]: " << funcs[i]->getSalario() << endl;
    }
    cout << endl << endl;
    for(int i = 0; i < 5; i++ ) {
            funcs[i]->reajustaSalario();
    }
    cout << endl << endl;
    for(int i = 0; i < 5; i++ ) {
            cout << "Funcionario[" << i << "]: " << funcs[i]->getSalario() << endl;
    }

    // libera a memoria ocupada pelo cadastro de funcionarios
    delete [] funcs;

    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_5)
// QUESTAO 7: O codigo a seguir faz a listagem dos carros da concessionaria
// classificando-os como "biciclo" ou "quadriciclo". Repare que a constante
// "classe" que armazena a classificacao do veiculo, n�o foi declarada na classe
// "Veiculo", pois nao se sabe a essa altura se o objeto a ser instanciado tera
// 2(duas) ou 4(quatro) rodas. Desta maneira, somente a classe "Moto" e
// "Automovel" possuiem a constante "classe" para a classificacao automatica do
// veiculo instaciado. Entretanto, e desejavel que se possa invocar o metodo
// "getClasse()" a partir de objetos do tipo "Veiculo". Por esse motivo, a
// classe "Veiculo" tambem possui esse m�todo na  sua interface. Responda os
// seguintes itens:
// (a) Tente declarar um objeto da classe "Veiculo" e explique por que nao
//     foi possivel.
      //A) Não é possível declarar um objeto da classe Veiculo pois veiculo
      //e uma classe abstrata, lembrando que basta um membro virtual para tornar uma classe abstrata.

// (b) O metodo "Veiculo::getClasse()" foi declarado como um metodo "puramente
//     virtual". Por que?
      //B) Ele foi declarado como um método virtual pois o veículo em si não possui
      // classe, mas as classes que herdam de veículo, no caso Automóvel e Moto, possuem.

// (c) O valor de retorno do metodo "Veiculo::getClasse()" foi declarado duas
//     vezes como constante. Por que?
      //C) O valor foi declarado como const em ambas declarações pois do contrario haveria
      //o risco de uma declaração interferir na outra, no caso a de Veiculo e a de Moto ou a de Automóvel.

unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Veiculo* veiculos[5];


    // alloca memoria para o cadastro de funcionarios, perceba que cada item
    // do cadastro � um tipo diferente de funcionario
    veiculos[0] = new Moto(10.0f);
    veiculos[1] = new Moto(10.0f);
    veiculos[2] = new Caminhao(10.0f);
    veiculos[3] = new Carro(10.0f);
    veiculos[4] = new Moto(10.0f);

    for(int i = 0; i < 5; i++ ) {
            cout << "Veiculos[" << i << "]: " << veiculos[i]->getClasse() << endl;
    }

    // libera a memoria ocupada pelo cadastro de funcionarios
    delete [] veiculos;

    system("PAUSE");
    return EXIT_SUCCESS;
}

#elif defined( MAIN_6)
// QUESTAO 8: No codigo a seguir, a constante "MOTO" possui o tipo "Moto", assim
// como a variavel "moto".
// Explique por que � possivel invocar o metodo "getClasse()" por meio
// variavel e n�o e possivel invoca-lo atraves da constante. Corrija a definicao
// do metodo "getClasse()" para que seja possivel invoca-lo tanto por meio de
// uma variavel quanto de uma constante.
    //8)Quando declaramos um objeto como const, só é possível chamar os membros const,
    //assegurando que o objeto nunca será modificado, mas não achei o motivo para o não
    //funcionamento de tal sentença.

unsigned int Veiculo::cont = 0;
int main(int argc, char *argv[])
{

    Moto moto(10);
    const Moto MOTO(10);

    cout << "Classe da moto: " << moto.getClasse() << endl;

    // Retire o comentario da linha a seguir para testar seu fucionamento
    cout << "Classe da MOTO: " << MOTO.getClasse() << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
#endif
