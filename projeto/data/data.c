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


void coloca_jogada (ESTADO *e,int num_jogadas,COORDENADA c,int num_player){
    if (num_player==1) e->jogadas[num_jogadas].jogador1 = c;
    else  e->jogadas[num_jogadas].jogador2 = c;
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

	for(int i = 0; i<30 ;i ++){
		e -> jogadas[i].jogador1 = c;
		e -> jogadas[i].jogador2 = c; 
	}
}


//Initializes the state
ESTADO *inicializar_estado(){
	COORDENADA coordenadaInicial = {3,4};
	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	e->jogador_atual=1;
	e->num_jogadas=0;
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

//Writes in a file
void gr(char *fileName, ESTADO *e){
	//Removes \n from string
	fileName[strlen(fileName)-1] = 0;

	//Opens the file
	FILE *file = fopen(fileName, "w+");

	//Writes the board in the file instead of stdout
	mostrar_tabuleiro(file, e);
	movs(file,e);
}


void ler(char *fileName, ESTADO *e){
	//Removes \n from string
	fileName[strlen(fileName)-1] = 0;

	//Opens the file
	FILE *file = fopen(fileName, "r");

	//Auxiliar char to translate chars to integers
	char *c, *b;

	//Iterates through lines
	for(int linha = 0; linha < 8; linha++){

		//Please note that scanf functions read something and moves the reading pointer to the next thing to be read.
		//That is why you can iterate it like this
		//Discarding column with letters (a, b, c ...)
		fscanf(file, "%c ", c);

		//Iterates through columns
		for(int coluna = 0; coluna < 8; coluna++){

			//Reads a piece and stores it in game state
			fscanf(file, "%c ", c);
			if( *c == '.') e->tab[linha][coluna] = VAZIO;
			if( *c == '#') e->tab[linha][coluna] = PRETA;
			if( *c == '*') e->tab[linha][coluna] = BRANCA;
		}
	}
	
	//Discarding number line of the board (1, 2, 3 ...)
	fscanf(file, "1 2 3 4 5 6 7 8 ");
	char jogada, p1Linha, p1Coluna, p2Linha, p2Coluna;
//	while(fscanf(file, "%c", c) == 1 )printf("%c", *c);
	for(int buffer = 0, linha = 0;linha < 90 && (fscanf(file, "%c", c) == 1); buffer++, linha++, buffer %=9){
		switch(buffer){
			case 1: jogada = *c;
				break;
			case 4: p1Linha = *c;
				break;
			case 5: p1Coluna = *c;
				break;
			case 7: p2Linha = *c;
				break;
			case 8: p2Coluna = *c;
				break;
			default:
				break;
		
		}
		if (buffer == 8){
			printf("jogada = %c -- p1 = %c%c p2 = %c%c\n", jogada, p1Linha, p1Coluna, p2Linha, p2Coluna);
		//	j1.linha = (int)(p1Linha);
//			j1.linha = p1Linha;
			
//			e->jogadas[jogada-1].jogador1 = j1;
//			e->jogadas[jogada-1].jogador2 = j2;
			//Discards newline
			fscanf(file, " ");
//		
		}
	}
}

int pos(ESTADO *e, int x){
	int i = obter_numero_de_jogadas(e);

	if (x <= i){
		int l1, l2, c1, c2;
		l1 = e -> jogadas[i].jogador1.linha;
		l2 = e -> jogadas[i].jogador1.coluna;
		c1 = e -> jogadas[i].jogador1.coluna;
		c2 = e -> jogadas[i].jogador2.coluna;

		changeJogada(e,x);

		for(i; i == x; i --){
			e -> tab[l1][c1] = VAZIO;
			e -> tab[l2][c2] = VAZIO;
			e -> jogadas[i].jogador1.linha = 8;
			e -> jogadas[i].jogador1.coluna = 8;
		    e -> jogadas[i].jogador1.coluna = 8;
			e -> jogadas[i].jogador2.coluna = 8;
		}

	}

	else
		return 1;

	return 0;
}