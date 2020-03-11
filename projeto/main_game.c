#include <stdio.h>
#include <stdlib.h>
#include "interface/interface.h"

int main(){
	ESTADO *e=inicializar_estado();
	mostrar_tabuleiro(e);	
	return 0;
}
