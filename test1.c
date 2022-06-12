#include "chess.h"
#include "figures.h"

void display(){
	char** bSquare = reverse(whiteSquare);
	interpreter(bSquare);
}
