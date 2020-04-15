//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../logic/logic.h"
#include "../interface/interface.h"
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


int obter_numero_de_jogadasOLD(ESTADO *estado){
	return ((*estado).num_jogadasOLD);
}


int getLastPiece(ESTADO *e, int bool){
	int r;
	int i = obter_numero_de_jogadas(e);

	int l1 = e -> jogadas[i].jogador1.linha;
	int l2 = e -> jogadas[i].jogador2.linha;
	int c1 = e -> jogadas[i].jogador1.coluna;
	int c2 = e -> jogadas[i].jogador2.coluna;

		if (l1 == 8 && l2 == 8 && c1 == 8 && c2 == 8)
			i --;

		l1 = e -> jogadas[i].jogador1.linha;
		l2 = e -> jogadas[i].jogador2.linha;
		c1 = e -> jogadas[i].jogador1.coluna;
		c2 = e -> jogadas[i].jogador2.coluna;

		if (l2 != 8 && c2 != 8){
			if (bool)
				r = c2;
			else
				r = l2;
		}

		else{
			if (bool)
				r = c1;
			else
				r = l1;
		}
	

	return r;
}


void coloca_jogada (ESTADO *e,int num_jogadas,COORDENADA c,int num_player){
    if (num_player==1) 
    	e->jogadas[num_jogadas].jogador1 = c;
    else  
    	e->jogadas[num_jogadas].jogador2 = c;
}


//Puts a black piece in a desired coordinate
void coloca_preta (ESTADO *e){
	changePiece(e, findBranca(e), PRETA);
}


//Alternates current player
void changePlayer(ESTADO *e){
	if (e->jogador_atual == 1) e->jogador_atual = 2;
	else e->jogador_atual = 1;
}


//Changes a board piece
void changePiece(ESTADO *e, COORDENADA c, CASA piece){
	e->tab[c.linha][c.coluna] = piece;
}

//Muda a jogada atual
void changeJogada(ESTADO *e, int x){
	(e-> num_jogadas) = x;
}


//Incrementa a jogada atual
void incrJogada(ESTADO *e){
	(e-> num_jogadas) ++;
}


//Diminui a jogada atual
void dimJogada(ESTADO *e){
	(e-> num_jogadas) --;
}


void arrayJogadas(ESTADO *e){
	COORDENADA c;
	c.linha = 8; 
	c.coluna = 8;

	for(int i = 0; i < 32 ;i ++){
		e -> jogadas[i].jogador1 = c;
		e -> jogadas[i].jogador2 = c; 
	}
}


//Initializes the state
ESTADO *inicializar_estado(){
	COORDENADA coordenadaInicial = {3,4};
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e->jogador_atual = 1;
	e->num_jogadas = 0;
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


LISTA criar_lista(){
	LISTA r = malloc(sizeof(LISTA));

	r = NULL;

	return r;
}

LISTA insere_cabeca(LISTA L, void *valor){
	LISTA r = malloc(sizeof(LISTA));
	
	r -> proximo = L;
	r -> valor = valor;

	return r;
}

void *devolve_cabeca(LISTA L){
	return (L -> valor);
}

LISTA proximo(LISTA L){
	return (L -> proximo);
}

LISTA remove_cabeca(LISTA L){
	LISTA r = malloc(sizeof(LISTA));

	r = L;
	L = L -> proximo;

	r -> proximo = NULL;
	free(r);

	return L;
}

int lista_esta_vazia(LISTA L){
	if (L == NULL)
		return 1;
	else
		return 0;
}