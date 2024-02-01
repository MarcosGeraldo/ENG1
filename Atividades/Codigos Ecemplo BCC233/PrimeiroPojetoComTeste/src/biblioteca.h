
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

long unsigned int fat(int n ) {
 
  long unsigned int result = 1;
  
  for (int i = 1; i <= n; i++) {
	  result = result * i;
  }

  return result;
}

#endif