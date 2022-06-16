#include "chess.h"
#include "figures.h"

void display(){
	char** fVknight = flipV(knight);

	interpreter(fVknight);

	libMemoria(fVknight);
}
