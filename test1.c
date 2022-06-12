#include "chess.h"
#include "figures.h"

void display(){
	char** sImp = superImpose(rook, whiteSquare);

	interpreter(sImp);

	libMemoria(sImp);
}
