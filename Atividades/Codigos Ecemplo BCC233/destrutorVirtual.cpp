#include <iostream>
using namespace std;

class MinhaClasse { 
	protected: 
		char c;
	public:
		 MinhaClasse( ) { c = ' ';  }
		 virtual ~MinhaClasse( ) { cout << "End"; }
			
};

//////////////////////////////////////////////// -- IMPLENTAÇAO API
// Classe concreta
class OutraClasse: public MinhaClasse{
	private:
		int* p;
		int variavel;
	public:
		OutraClasse( ) { p = new int; }
		virtual ~OutraClasse() { delete p;  cout << "The" << c; }
};

int main( void ){
	MinhaClasse *obj = new OutraClasse(); 

	delete obj;
}
////////////////////////////////////////////////