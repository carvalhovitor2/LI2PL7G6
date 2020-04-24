//This file is designed to store the definition of the functions used in main_game.c
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../logic/logic.h"
#include "../interface/interface.h"
#include "../listas_ligadas/listas_ligadas.h"

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

int nr_coord_around(COORDENADA c, ESTADO *e){
	int r = 0,
		j = -1,
		border = 1;

	if (c.coluna == 7)
		border = 0;

	while(c.linha != 0 && j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha - 1][c.coluna + j] == VAZIO)
				r ++;
		}
		j ++;
	}

	j = -1;

	while(j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha][c.coluna + j] == VAZIO)
				r ++;
		}
		j ++;
	}

	j = -1;

	while(c.linha != 7 && j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha + 1][c.coluna + j] == VAZIO)
				r ++;
		}
		j ++;
	}

	return r;
}

void array_coord_around(COORDENADA c, COORDENADA *A, ESTADO *e){
	int r = 0,
		j = -1,
		border = 1;
	COORDENADA fake;

	if (c.coluna == 7)
		border = 0;

	while(c.linha != 0 && j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha - 1][c.coluna + j] == VAZIO){
				fake.linha = c.linha - 1;
				fake.coluna = c.coluna + j;
				A[r] = fake;
				r ++;
			}
		}
		j ++;
	}

	j = -1;

	while(j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha][c.coluna + j] == VAZIO){
				fake.linha = c.linha;
				fake.coluna = c.coluna + j;
				A[r] = fake;
				r ++;
			}
		}
		j ++;
	}

	j = -1;

	while(c.linha != 7 && j <= border){
		if (c.coluna + j != -1){
			if(e-> tab[c.linha + 1][c.coluna + j] == VAZIO){
				fake.linha = c.linha + 1;
				fake.coluna = c.coluna + j;
				A[r] = fake;
				r ++;
			}
		}
		j ++;
	}	
}


//LISTA lista_de_coord(COORDENADA *A, int N, LISTA L){
//	int i = 0;
//
//	while(i < N){
//		L = insere_cabeca(L,A + i);
//		i ++;
//	}
//
//	return L;
//}

int calcula_dist_dest(COORDENADA C, ESTADO *e){
	int dist;
	int player = obter_jogador_atual(e);
	int x = C.linha,
		y = C.coluna;

	if (player == 1)
		dist = sqrt(pow(7 - x, 2) + pow(0 - y, 2));
	else
		dist = sqrt(pow(0 - x, 2) + pow(7 - y, 2));

	return dist;
}

float calcula_dist_destF(COORDENADA C, ESTADO *e){
	float dist;
	int player = obter_jogador_atual(e);
	int x = C.linha,
		y = C.coluna;

	if (player == 1)
		dist = sqrt(pow(7 - x, 2) + pow(0 - y, 2));
	else
		dist = sqrt(pow(0 - x, 2) + pow(7 - y, 2));

	return dist;
}


float calcula_dist_dest2(int x){
	float dist;

	dist = (powf(7 - x, 2.0) + powf(0 - x, 2.0));
	//printf("%f\n", dist);

	return dist;
}

int indice_menorDist(LISTA L){
	int r = 0, i = 1;
	LISTA fake = L;
	int *x;
	x = devolve_cabeca(L);
	int *y; 

	if (fake && fake-> proximo){
		fake = fake-> proximo;
		y = devolve_cabeca(fake);
	}

	while(fake){
		if (x > y){
			r = i;
			x = y;
		}
		fake = fake-> proximo;
		if (fake)
			y = devolve_cabeca(fake);
		i ++;
	}

	return r;
}

//LISTA atualiza_LISTAS(ESTADO *e){
//	LISTA L;
//	L = e-> lista_jogadas_possiveis;
//	void *yo = devolve_cabeca(L);
//	ESTADO *yos = (ESTADO *)yo;
//}
