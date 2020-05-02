#include <stdio.h>
#include "bot.h"

int main(int argc, char *argv[]){
	ESTADO *e = inicializar_estado();
	if(argc == 3){
		ler(argv[1], e, 1);
		jog2(e);
		gr(argv[2], e, 1);
	}
	return 0;
}