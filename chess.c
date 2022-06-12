#include <stdio.h>
#include <stdlib.h>

//devuelve el simbolo contrario 
char negative(char c){
	switch(c){
		case '.': 
			return '@';
		case '@': 
			return '.';
		case '_': 
			return '=';
		case '=': 
			return '_';
		default: 
			return c;
	}
}

// Calcular el tamaño de la figura recibidA
char** reverse(char** figura){
  char** tmp = figura;
  int cant = 0;
  while(*tmp){cant++; tmp++; }
  printf("tamaño:%d\n",cant);

  return tmp;
}
