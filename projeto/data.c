//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "logic.h"
#include "interface.h"
#include "listas_ligadas.h"

//Gets current piece
CASA obter_estado_casa(ESTADO *e, COORDENADA coord, int decider_efeito, int new_or_old){
	if (new_or_old){
		if (decider_efeito){
			if (coord.linha <= 0 || coord.linha > 8 || coord.coluna <= 0 || coord.coluna > 8) 
				return PRETA;
			int line = coord.linha - 1;
			int column = coord.coluna - 1;
			return (e-> tab[line][column]);
		}
		else
			return (e-> tab[coord.linha][coord.coluna]);
	}
	else{
		if (decider_efeito){
			if (coord.linha <= 0 || coord.linha > 8 || coord.coluna <= 0 || coord.coluna > 8) 
				return PRETA;
			int line = coord.linha - 1;
			int column = coord.coluna - 1;
			return (e-> tabOLD[line][column]);
		}
		else
			return (e-> tabOLD[coord.linha][coord.coluna]);
	}
}

//Gets current player
int obter_jogador_atual(ESTADO *estado){
	return (estado-> jogador_atual);
}

//Gets current number of moves
int obter_numero_de_jogadas(ESTADO *estado, int new_or_old){
	if (new_or_old)
		return (estado-> num_jogadas);
	else
		return (estado-> num_jogadasOLD);
}

int obter_coord_deJogada(ESTADO *e, int jogada, int player, int decider, int new_or_old){
	if (new_or_old){
		if (player == 1){
			if (decider)
				return (e-> jogadas[jogada].jogador1.linha);
			else
				return (e-> jogadas[jogada].jogador1.coluna);
		}
		else{
			if (decider)
				return (e-> jogadas[jogada].jogador2.linha);
			else
				return (e-> jogadas[jogada].jogador2.coluna);
		}
	}
	else{
		if (player == 1){
			if (decider)
				return (e-> jogadasOLD[jogada].jogador1.linha);
			else
				return (e-> jogadasOLD[jogada].jogador1.coluna);
		}
		else{
			if (decider)
				return (e-> jogadasOLD[jogada].jogador2.linha);
			else
				return (e-> jogadasOLD[jogada].jogador2.coluna);
		}
	}
}

int getLastPiece(ESTADO *e, int lin_or_col){
	int ret;
	int nr_jogadas = obter_numero_de_jogadas(e, 1);

	int l1 = e -> jogadas[nr_jogadas].jogador1.linha,   l2 = e -> jogadas[nr_jogadas].jogador2.linha;
	int c1 = e -> jogadas[nr_jogadas].jogador1.coluna,  c2 = e -> jogadas[nr_jogadas].jogador2.coluna;

	if (l1 == 8 && l2 == 8 && c1 == 8 && c2 == 8)
		nr_jogadas --;

	l1 = e -> jogadas[nr_jogadas].jogador1.linha;  l2 = e -> jogadas[nr_jogadas].jogador2.linha;
	c1 = e -> jogadas[nr_jogadas].jogador1.coluna; c2 = e -> jogadas[nr_jogadas].jogador2.coluna;

	if (l2 != 8 && c2 != 8){
		if (lin_or_col)
			ret = c2;
		else
			ret = l2;
	}

	else{
		if (lin_or_col)
			ret = c1;
		else
			ret = l1;
	}
	
	return ret;
}

void coloca_jogada(ESTADO *e, int num_jogadas, COORDENADA coord, int num_player){
    if (num_player == 1) 
    	e->jogadas[num_jogadas].jogador1 = coord;
    else  
    	e->jogadas[num_jogadas].jogador2 = coord;
}

//Coloca uma peca preta no rastro deixado por uma branca
void coloca_preta (ESTADO *e){
	changePiece(e, findBranca(e), PRETA);
}

//Altera o jogador atual
void changePlayer(ESTADO *e){
	if (e->jogador_atual == 1) 
		e-> jogador_atual = 2;
	else 
		e->jogador_atual = 1;
}

//Altera a peca de uma coordenada
void changePiece(ESTADO *e, COORDENADA coord, CASA piece){
	e->tab[coord.linha][coord.coluna] = piece;
}

//Muda o numero de jogadas
void changeJogada(ESTADO *e, int new_num_jogada){
	(e-> num_jogadas) = new_num_jogada;
}

//Incrementa a jogada atual
void incrJogada(ESTADO *e){
	(e-> num_jogadas) ++;
}

void arrayJogadas(ESTADO *e){
	COORDENADA c = {8,8};

	for(int i = 0; i < 32; i ++){
		e -> jogadas[i].jogador1 = c;
		e -> jogadas[i].jogador2 = c; 
	}
}

//Initializes the state
ESTADO* inicializar_estado(){
	COORDENADA coordenadaInicial = {3,4};
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e-> jogador_atual = 1;
	e-> num_jogadas = 0;
	arrayJogadas(e);
	//Iterates through lines
	for(int linha = 0; linha < 8; linha++){
		//Iterates through columns
		for(int coluna = 0; coluna < 8; coluna++){
			//Initializes boardPiece;
			e->tab[linha][coluna] = VAZIO;
		}
	}
	changePiece(e, coordenadaInicial, BRANCA); 
	return e;
}

//Faz a replica de um estado
void replicaEstado(ESTADO *e){
	int k = 0, n = 0;

	for(int i = 0; i != 32; i ++)
		e -> jogadasOLD[i] = e -> jogadas[i];

	while(k != 8){
		while(n != 8){
			e -> tabOLD[k][n] = e -> tab[k][n];
			n ++;
		}
		n = 0;
		k ++;
	}

	e -> num_jogadasOLD = e -> num_jogadas;
}
