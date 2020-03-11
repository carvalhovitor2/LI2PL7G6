//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>


//Inicializa o estado do tabuleiro
ESTADO *inicializar_estado(){
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e->jogador_atual=1;
	e->num_jogadas=0;
	//Percorre linhas
	for(int linha = 0; linha < 8; linha++){
		//Percorre colunas
		for(int coluna = 0; coluna < 8; coluna++){
			//Inicializa o elemento da matriz
			e->tab[linha][coluna] = VAZIO;
		}
	}
	return e;
}
