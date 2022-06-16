#include "chess.h"
#include "figures.h"

void display(){

	char** tmp = repeatH(rook,4);

	interpreter(tmp);

	libMemoria(tmp);

	
}
