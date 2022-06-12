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

//Calcula la altura de la figura
int altura(char** figura){
	char** tmpA = figura;
	int cont = 0;

	while(*tmpA){ cont++; tmpA++;}

	return cont;
}

//Calcula la altura de la figura
int ancho(char** figura){
	char** tmp = figura;
	int cont = 0;

	while(*tmp){ cont++; tmp++;}

	return cont;
}

// Calcular el tamaño de la figura recibidA
char** reverse(char** figura){
	char** tmp = (char**) malloc(sizeof(char*) * 58);
	char** tmp2 = tmp;
	char** figP = figura;
	char* alm1;
	char* alm2;
	int cont = 0;
	while(*figP){
		*tmp = (char*) malloc(sizeof(char) * 58);
		alm1 = *tmp;
		alm2 = *figP;

		while(*alm2){
			*alm1 = negative(*alm2);
			alm1++;
			alm2++;
			cont++;
		}
		*alm1 = 0;
		tmp++;
		figP++;
	}
	*tmp = 0;
	return tmp2;
}


