Aplicação
//////////////////////////////////////////////// -- API
// classe puramente abstrata
class InterfaceOutraClasse { // Interface
    virtual int metodo1(...) = 0;
    virtual bool metodo2(...) = 0;
}

//////////////////////////////////////////////// -- IMPLENTAÇAO API
// Classe concreta
class OutraClasse: public InterfaceOutraClasse{
	protected:
		int variavel 
	public:
		
		OutraClasse(){...}
		virtual ~OutraClasse(){...}
		
		int metodo1(...);
		bool metodo2(...);
		
	public:
		OutraClasse ( const OutraClasse &o) {...}
		OutraClasse operator=( const OutraClasse &o) {...}
}
MinhaClasse obj; // não
OutraClasse obj; // sim

obj.metodo1();
////////////////////////////////////////////////


