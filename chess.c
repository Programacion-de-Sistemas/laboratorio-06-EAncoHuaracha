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

//Calcula la ancho de la figura
int ancho(char** figura){
	char* tmp = *figura;
	int cont = 0;

	while(*tmp){ cont++; tmp++;}

	return cont;
}

char** flipV(char** figura){

	//calculamos altura y ancho
	int l = altura(figura);
	int a = ancho(figura);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l +1));
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** tmp3 = figura;
	char* alm1;
	char* alm2;

	// se crea un contador para recorrer
	int cont = 0;

	int contR;

	while(*tmp3){
		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp;
		alm2 = *tmp3;

		//cuenta para atras
		contR = a - 1;

		//se ejecuta este bucle hasta que llegue a 0 el recorrido
		while(contR >= 0){
			*alm1 = alm2[contR];
			alm1++;
			contR--;
		}
		*alm1 = 0;
		tmp++;
		tmp3++;
	}
	*tmp = 0;
	return tmp2;

}

char** flipH(char** figura){
	//calculamos altura y ancho
	int l = altura(figura);
	int a = ancho(figura);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l +1));
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** tmp3 = figura;
	char* alm1;
	char* alm2;

	int contR = l - 1;

	//se ejecuta este bucle hasta que llegue a 0 el recorrido
	while(contR >= 0){

		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp;
		alm2 = &tmp3[contR][0];

		while(*alm2){
			*alm1 = *alm2;
			alm1++;
			alm2++;
		}
		contR--;
		*alm1 = 0;
		tmp++;
	}
	*tmp = 0;
	return tmp2;
}

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
char** join(char** izq, char** der){
	//calculamos altura y ancho de la figura a la izquierda
	int l = altura(izq);
	int aIzq = ancho(izq);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l +1));
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;
	char** tmp3Izq = izq;


	char* alm1;
	char* alm2;


	//Calculamos el ancho de la figura de la derecha
	//No se calcula la altura ya que es la misma
	int aDer = ancho(der);
	int a = aIzq + aDer;
	char** tmp3Der = der;

	//se ejecuta este bucle hasta que llegue a 0 el recorrido
	while(*tmp3Izq){

		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp3Izq;
		alm2 = *tmp;

		while(*alm1){
			*alm2 = *alm1;
			alm1++;
			alm2++;
		}

		alm1 = *tmp3Der;
		while(*alm1){
			*alm2 = *alm1;
			alm1++;
			alm2++;
		}

		*alm2 = 0;
		tmp++;
		tmp3Izq++;
		tmp3Der++;
	}
	*tmp = 0;
	return tmp2;
}

char** up(char**, char**);

char** repeatH(char**, int);

char** repeatV(char**, int);

char** reverse(char** figura){
	//calculamos altura y ancho
	int l = altura(figura);
	int a = ancho(figura);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * l);
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** figP = figura;
	char* alm1;
	char* alm2;

	// se crea un contador para recorrer
	int cont = 0;
	while(*figP){
		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * a);
		alm1 = *tmp;
		alm2 = *figP;

		while(*alm2){
			// se realiza el intercambio por su negativo llamando a la funcion negative.
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


