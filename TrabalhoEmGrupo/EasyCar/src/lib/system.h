#ifndef SYSTEM_H
#define SYSTEM_H

#include "rent.h"
#include <vector>

/**
*@brief A Interface Modelo Ã© a Interface que define os metodos a serem implemetados
*
*@author Marcos Geraldo Braga Emiliano 1914012
*/
class System{

public:
	/**
	*@brief Este é o destrutor da classe
	*/
    virtual ~System(){};
	/**
	*@brief Este construtor adiciona, nome, numero de ciclos, o ciclo atual e um fluxo ao Modelo que esta sendo criado
	*
	*@param Deve ser passado uma string contendo o nome, dois inteiros representando numero total de ciclos e o ciclo atual e uma variavel do tipo Fluxo
	*/
	virtual string getName()=0;
	/**
	*@brief Este construtor adiciona, nome, numero de ciclos, o ciclo atual e um fluxo ao Modelo que esta sendo criado
	*
	*@param Deve ser passado uma string contendo o nome, dois inteiros representando numero total de ciclos e o ciclo atual e uma variavel do tipo Fluxo
	*/
	virtual User* getUser(string)=0;
	/**
	*@brief Este metodo atribui um nome a um modelo
	*
	*@param Deve ser passada uma string contendo o nome
	*/
    virtual vector<Rent*> getRent(Vehicle*)=0;
    /**
    *@brief Este metodo atribui um nome a um modelo
    *
    *@param Deve ser passada uma string contendo o nome
    */
	virtual void setName(string)=0;
	/**
	*@brief Este metodo retorna quantos ciclos serão efetuados um uma simulação
	*
	*@retval É retornado um inteiro representando o numero total de ciclos a ser executados
	*/
	virtual void add(User*)=0;
	/**
	*@brief Este metodo remove um Fluxo do vector de Fluxos
	*
	*@param Deve ser passado o fluxo a ser removido
	*/
	virtual void remove(User*)=0;
	/**
	*@brief Este metodo adiciona um sistema ao vector de Sistemas
	*
	*@param Deve ser passado um ponteiro de Sistema a ser adicionado
	*/
	virtual void add(Rent*)=0;
	/**
	*@brief Este metodo remove um Sistema do vector de Sistema
	*
	*@param Deve ser passado o Sistema a ser removido
	*/
	virtual void remove(Rent*)=0;
	/**
	*@brief
	*
	*@param
	*
	*retval
	*/
	virtual User* criateUser(string)=0;
	/**
	*@brief
	*
	*@param
	*
	*retval
	*/
	virtual Rent* criateRent(User*)=0;
	/**
	*@brief
	*
	*@param
	*
	*retval
	*/
    virtual Vehicle* criateVehicle(string model)=0;
    /**
    *@brief
    *
    *@param
    *
    *retval
    */
    static System* criateSystem(string name);
};



#endif
