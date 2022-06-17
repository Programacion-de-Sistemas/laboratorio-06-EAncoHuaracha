#include "chess.h"
#include "figures.h"

void display(){

	// se carga el tablero
	char** blackSquare = reverse(whiteSquare);
	char** unionSquare = join(blackSquare, whiteSquare);
	char** repeatSquare = repeatH(unionSquare,4);
	char** upSquare = up(repeatSquare, reverse(repeatSquare));
	char** tablero = (repeatV(upSquare,2));

	//se cargan las fichas
	char** c1 = join(rook, knight);
	char** c2 = join(c1, bishop);
	char** c3 = join(c2, king);
	char** c4 = join(c3, queen);
	char** c5 = join(c4, bishop);
	char** c6 = join(c5, knight);
	char** c7 = join(c6, rook);
	char** c8 = up(c7,repeatH(pawn,8));
	char** c9 = up(repeatH(pawn,8), c7);

	//superposicion
	char** fichasWhite = superImpose(c8, upSquare);
	char** fichasBlack = superImpose(reverse(c9), upSquare);
	//Union
	
	char** tmp = up(fichasWhite,up(tablero,fichasBlack));

	interpreter(tmp);

	libMemoria(tmp);

}
