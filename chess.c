#include <stdio.h>
#include <stdlib.h>


//funcion para liberar memoria
void libMemoria(char** figura){
	char** tmp = figura;

	while(*tmp){
		free(*tmp);
		tmp++;
	}

	free(figura);
}


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

char** flipV(char** );

char** flipH(char**);

char** rotateL(char**);

char** rotateR(char**);

char** superImpose(char** sobre, char** abajo){

	//calculamos altura y ancho
	int l = altura(sobre);
	int a = ancho(sobre);

	//se define la memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l + 1));
	char** tmp2 = tmp;

	char* alm1 = *tmp;
	char* alm2 = *sobre;
	char* alm3 = *abajo;

	while(*sobre){
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp;
		alm2 = *sobre;
		alm3 = *abajo;

		while(*alm2){
			if(*alm2 == ' ')
				*alm1 = *alm3;
			else
				*alm1 = *alm2;

			alm1++;
			alm2++;
			alm3++;
		}
		*alm1 = 0;

		tmp++;
		sobre++;
		abajo++;
	}
	*tmp = 0;
	return tmp2;
}
char** join(char**, char**);

char** up(char**, char**);

char** repeatH(char**, int);

char** repeatV(char**, int);

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


