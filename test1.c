#include "chess.h"
#include "figures.h"

void display(){
	char** joinKR = join(knight, rook);

	char** tmp = join(joinKR,rook);

	interpreter(tmp);

	libMemoria(tmp);

	
}
