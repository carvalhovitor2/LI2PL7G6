#include <stdio.h>
#include <stdlib.h>
#include "interface/interface.h"

int main(){
	COORDENADA c = {2,5};
	ESTADO *e=inicializar_estado();
	mostrar_tabuleiro(stdout, e);
	interpretador(e);
	return 0;
}
