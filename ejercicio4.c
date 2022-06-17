#include "chess.h"
#include "figures.h"

void display(){

	// se carga el tablero
	char** blackSquare = reverse(whiteSquare);
	char** unionSquare = join(blackSquare, whiteSquare);
	char** repeatSquare = repeatH(unionSquare,4);
	
	//se cargan las fichas
	char** c1 = join(rook, knight);
	char** c2 = join(c1, bishop);
	char** c3 = join(c2, king);
	char** c4 = join(c3, queen);
	char** c5 = join(c4, bishop);
	char** c6 = join(c5, knight);
	char** c7 = join(c6, rook);

	//Superposicion
	char** tmp = superImpose(c7,repeatSquare);

	interpreter(tmp);

	libMemoria(tmp);

}
