//This file is designed to store the definition of the functions used in main_game.c
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

//Making a move
int jogar(ESTADO *e, COORDENADA *c){
}

void mostrar_tabuleiro(ESTADO *e){
}


ESTADO *inicializar_estado(){
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e->jogador_atual=1;
	e->num_jogadas=0;
	//Inicializa a matriz do tabuleiro
	for(int linha = 0; linha < 8; linha++){
		for(int coluna = 0; coluna < 8; coluna++){
			e->tab[linha][coluna] = 0;
		}
	}
}

int interpretador(ESTADO *e){
}
