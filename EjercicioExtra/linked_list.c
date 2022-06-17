#include<stdio.h>
#include<stdlib.h>

//definimos nuestra node
typedef struct node
{
	int number;
	struct node *next;
}
node;

//declaramos la funcion agregar
node *agregar(node *l, int num);

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
		//se llama a la funcion agregar
		list = agregar(list, num);

	}


	// imprimir los elementos de la lista
	for (node *tmp = list;tmp!=NULL;tmp=tmp->next)
	{
		printf("%i\n",tmp->number);


	}

	// función (free) BUENA PRÁCTICA EN PROGRAMACIÓN EN "C"
	while(list!=NULL){
		node *tmp=list->next;
		free(list);
		list=tmp;
	}

	return 0;

}

node *agregar(node *l, int num){
	//asiganmos memoria para node
	node *new = malloc(sizeof(node));
	node *aux;
	if(new!=NULL){
		// se da el valor del num ingresado
		new->number=num;
		new->next=NULL;

		if(l==NULL)
			l=new;
		else{
			aux = l;
			while(aux->next!=NULL)

				aux = aux->next;
			aux->next=new;
		}
	}
	return l;
}

