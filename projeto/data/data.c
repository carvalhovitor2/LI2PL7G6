//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>



//Gets current piece
CASA obter_estado_casa(ESTADO *e, COORDENADA c){
	int line = c.linha - 1;
	int column = c.coluna - 1;
	return ((*e).tab[line][column]);
}


//Gets current player
int obter_jogador_atual(ESTADO *estado){
	return ((*estado).jogador_atual);
}


//Gets current number of moves
int obter_numero_de_jogadas(ESTADO *estado){
	return ((*estado).num_jogadas);
}


//Alternates current player
void changePlayer(ESTADO *e){
	if ( e->jogador_atual == 1) e->jogador_atual = 2;
	else e->jogador_atual = 1;
}


//Changes a board piece
void changePiece(ESTADO *e, COORDENADA c, CASA piece){
	e->tab[c.linha-1][c.coluna-1] = piece;
}


//Incrementa o nº de jogadas
void incrJogada(ESTADO *e){
	(e-> num_jogadas) ++;
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

//Verifies a move
//int validate(ESTADO *e, COORDENADA c){
//	if ( line < 1 || line > 8 || column < 1 || column > 8 || getCurrentPiece(e, &c) == BRANCA || getCurrentPiece(e, &c) == PRETA ) return 0;
//	return 1;
//}
