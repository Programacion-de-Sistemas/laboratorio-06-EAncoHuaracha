#include<stdio.h>
#include<stdlib.h>

//definimos nuestra node
typedef struct node
{
	int number;
	struct node *next;
}
node;

int main(){
	node *list=NULL;

	int n,num;


	//pedimos ingresar la cantidad de n numeros para la lista
	printf("ingrese la cantidad de numeros: ");
	scanf("%d", &n);
	
	//Bucle para preguntar las n veces
	for(int i=0; i<n; i++){

		//pedir numero
		printf("Ingrese el numero: ");
		scanf("%d", &num);
		printf("%d\n", num);

	}


	// imprimir los elementos de la lista
	for (node *tmp = list;tmp!=NULL;tmp=tmp->next)
	{
		printf("%i\n",tmp->number);


	}

	// función (free) BUENA PR´ACTICA EN PROGRAMACI´ON EN "C"
	while(list!=NULL){
		node *tmp=list->next;
		free(list);
		list=tmp;
	}

	return 0;

}
