#include <stdio.h>
#include <stdlib.h>

//devuelve el simbolo contrario 
char negative(char c){
	switch(c){
		case '.': 
			return '@';
		case '@': 
			return '.';
		case '_': 
			return '=';
		case '=': 
			return '_';
		default: 
			return c;
	}
}
