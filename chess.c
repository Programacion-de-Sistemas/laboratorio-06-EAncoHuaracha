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
// crea una imagen que es un espejo vertical de la imagen original
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

	int contR;

	// se recorre la figura
	while(*tmp3){
		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp;
		alm2 = *tmp3;

		//cuenta para atras
		contR = a - 1;

		//se ejecuta este bucle hasta que llegue a 0 el recorrido
		while(contR >= 0){
			// se guarda el valor encontrado
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

// crea una imagen que es un espejo horizontal de la imagen original
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
		//se obtiene con & la direccion de memoria de tmp3 y luego se almacena
		alm2 = &tmp3[contR][0];

		// recorremos el puntero
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

// crea una imagen producto de poner una imagen sobre otra
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
	
	//se recorre la primera imagen
	while(*sobre){
		*tmp = (char*) malloc(sizeof(char) * (a + 1));

		//se dan los valores a alm1 alm2 alm3
		alm1 = *tmp;
		alm2 = *sobre;
		alm3 = *abajo;

		//recorre el puntero *alm2 viene a ser la segunda figura
		while(*alm2){
			// si el valor es espacio se ingresa el puntero
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

// crea una imagen producto de poner una imagen al lado de otra
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

	//se recorre todo la figura de la izquierda
	while(*tmp3Izq){

		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp3Izq;
		alm2 = *tmp;

		//recorremos el puntero *alm1 viene a ser la figura de la izquierda
		while(*alm1){
			// se dan los valores
			*alm2 = *alm1;
			// siguiente
			alm1++;
			alm2++;
		}

		// se carga el puntero en alm1
		alm1 = *tmp3Der;

		// se recorre *alm1
		while(*alm1){
			// se dan los valores
			*alm2 = *alm1;

			//siguiente
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

// crea una imagen producto de poner una imagen encima otra
char** up(char** arriba, char** abajo){
	//calculamos altura de ambas ya que va a variar la altura sumando estas.
	int lArriba = altura(arriba);
	int lAbajo = altura(abajo);
	int l = lArriba + lAbajo;

	//calculamos el ancho de la figura, se calcula una vez ya que es igual este.
	int a = ancho(arriba);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l +1));
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** tmp3Arriba = arriba;


	char* alm1;
	char* alm2;


	char** tmp3Abajo = abajo;

	//se recorre la figura de arriba
	while(*tmp3Arriba){

		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		
		// se carga alm1 alm2
		alm1 = *tmp;
		alm2 = *tmp3Arriba;

		while(*alm2){
			// se dan los valores
			*alm1 = *alm2;

			//siguiente
			alm1++;
			alm2++;
		}
		*alm1 = 0;
		tmp++;
		tmp3Arriba++;
	}

	// se establece la figura de abajo
	tmp3Arriba = tmp3Abajo;

	// se recorre la figura de abajo
	while(*tmp3Arriba){

		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a + 1));
		alm1 = *tmp;
		alm2 = *tmp3Arriba;

		while(*alm2){
			*alm1 = *alm2;
			alm1++;
			alm2++;
		}
		*alm1 = 0;
		tmp++;
		tmp3Arriba++;
	}

	*tmp = 0;
	return tmp2;
}

// se muestra la imagen original.
char** carga(char** figura){
	//calculamos altura y ancho
	int l = altura(figura);
	int a = ancho(figura);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * l);
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** tmp3 = figura;
	char* alm1;
	char* alm2;

	// se recorre la figura
	while(*tmp3){
		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * a);

		//se carga en los alm1 alm2
		alm1 = *tmp;
		alm2 = *tmp3;

		while(*alm2){
			// se dan los valores
			*alm1 = *alm2;
			alm1++;
			alm2++;
		}
		*alm1 = 0;
		tmp++;
		tmp3++;
	}
	*tmp = 0;
	return tmp2;

}

// crea una imagen producto de repetir horizontalmente n veces la imagen original
char** repeatH(char** figura, int n){
	// se carga la imagen
	char** repF = carga(figura);
	char** tmp;
	// recorre n veces
	while(n != 1){
		tmp = repF;
		// se llama a la funcion join para añadir la imagen
		repF = join(repF, figura);
		n--;
	}

	return repF;
}


char** repeatV(char** figura, int n){
	char** repF = carga(figura);
	char** tmp;
	while(n != 1){
		tmp = repF;
		repF = up(repF, figura);
		n--;
	}

	return repF;
}

// crea una imagen que representa un negativo de la imagen original
char** reverse(char** figura){
	//calculamos altura y ancho
	int l = altura(figura);
	int a = ancho(figura);

	//cargamos el bloque de memoria
	char** tmp = (char**) malloc(sizeof(char*) * (l+1));
	//respaldamos tmp en tmp2
	char** tmp2 = tmp;

	char** figP = figura;
	char* alm1;
	char* alm2;

	//se recorre la figura
	while(*figP){
		//cargamos el bloque de memoria con el ancho de la figura
		*tmp = (char*) malloc(sizeof(char) * (a+1));

		// se cargan los punteros
		alm1 = *tmp;
		alm2 = *figP;

		while(*alm2){
			// se realiza el intercambio por su negativo llamando a la funcion negative.
			*alm1 = negative(*alm2);
			//recorrido de punteros
			alm1++;
			alm2++;
		}
		*alm1 = 0;
		tmp++;
		figP++;
	}
	*tmp = 0;
	return tmp2;
}


