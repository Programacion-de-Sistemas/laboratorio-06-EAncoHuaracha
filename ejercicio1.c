#include "chess.h"
#include "figures.h"

void display(){

	char** blackSquare = reverse(whiteSquare);


	char** unionSquare = join(whiteSquare,blackSquare);


	char** repeatSquare = repeatH(unionSquare,4);

	interpreter(repeatSquare);

	libMemoria(repeatSquare);

}
