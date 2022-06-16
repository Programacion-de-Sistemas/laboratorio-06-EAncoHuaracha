#include "chess.h"
#include "figures.h"

void display(){
	char** sImp = reverse(knight);

	interpreter(sImp);

	libMemoria(sImp);
}
