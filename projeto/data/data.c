//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>



//Gets current player
int getCurrentPiece(ESTADO *e, COORDENADA *c){
	return e->tab[c->linha-1][c->coluna-1];
}

//Gets current player
int getCurrentPlayer(ESTADO *e){
	return e->jogador_atual;	
}


//Gets current number of moves
int getNumberOfMoves(ESTADO *e){
	return e->num_jogadas;	
}

void changePlayer(ESTADO *e){
	if ( e->jogador_atual == 1) e->jogador_atual = 2;
	else e->jogador_atual = 1;
}


//Initializes the state
ESTADO *inicializar_estado(){
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e->jogador_atual=1;
	e->num_jogadas=0;
	//Iterates through lines
	for(int linha = 0; linha < 8; linha++){
		//Iterates through columns
		for(int coluna = 0; coluna < 8; coluna++){
			//Initializes boardPiece;
			e->tab[linha][coluna] = VAZIO;
		}
	}
	return e;
}
