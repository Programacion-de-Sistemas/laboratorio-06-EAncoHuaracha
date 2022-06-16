#include "chess.h"
#include "figures.h"

void display(){
	char** fHknight = flipH(knight);

	interpreter(fHknight);

	libMemoria(fHknight);

	
}
