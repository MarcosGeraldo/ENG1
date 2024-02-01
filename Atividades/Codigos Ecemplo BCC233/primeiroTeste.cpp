#include <assert.h>
#include <iostream>

// TDD - Test Driven Development



using namespace std;

long unsigned int fat(int n ) {
 
  long unsigned int result = 1;
  
  for (int i = 1; i <= n; i++) {
	  result = result * i;
  }

  return result;
}


bool testFat( void ) {

    ///cout << fat(3);
    assert ( fat(0) == 1); 
	assert ( fat(1) == 1); 
	assert ( fat(2) == 2);
	assert ( fat(3) == 6); 
	assert ( fat(32) == (unsigned long int) 2147483648L);
	
}


int func( void ){
	
	return true;
}


int main(void){

	cout << "inicio..." << endl;
	
	assert( func() == true);

	testFat();

    cout <<"usuário novo:" << fat(32) << endl;	
	
	cout << "fim!";

}