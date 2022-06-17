#include "chess.h"
#include "figures.h"

void display(){

	char** tmp = up(rook,queen);


	interpreter(tmp);

	libMemoria(tmp);

	
}
