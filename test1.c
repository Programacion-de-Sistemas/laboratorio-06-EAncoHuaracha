#include "chess.h"
#include "figures.h"

void display(){

	char** tmp = up(rook,rook);

	char** tmp2 = up(tmp,queen);

	interpreter(tmp2);

	libMemoria(tmp2);

	
}
