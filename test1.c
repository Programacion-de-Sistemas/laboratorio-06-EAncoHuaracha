#include "chess.h"
#include "figures.h"

void display(){
	char** reverseKnight = reverse(knight);
	interpreter(reverseKnight);
	libMemoria(reverseKnight);
}
