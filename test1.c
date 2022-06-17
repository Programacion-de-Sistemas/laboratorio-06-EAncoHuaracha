#include "chess.h"
#include "figures.h"

void display(){

	char** tmp = repeatV(rook,4);

	interpreter(tmp);

	libMemoria(tmp);

	
}
