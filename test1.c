#include "chess.h"
#include "figures.h"

void display(){
	char** joinKR = join(knight, rook);

	interpreter(joinKR);

	libMemoria(joinKR);

	
}
