//This file is designed to store the definition of the interface functions
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

//Print the game board
void mostrar_tabuleiro(FILE *whereToPrint, ESTADO *e){
	int boardPiece = 0;
    for(int linha = 0; linha < 8; linha++){
    	char a = 'a' + linha;
    	fprintf(whereToPrint, "%c", a);
    	fprintf(whereToPrint, " ");
        for(int coluna = 0; coluna < 8; coluna++){
		//Translate enum to chars
                    boardPiece = e->tab[linha][coluna];
			if(linha == 7 && coluna == 0) boardPiece = 3;
			if(linha == 0 && coluna == 7) boardPiece = 4;
			switch (boardPiece){
				case 0: fprintf(whereToPrint, ". ");
					break;
				case 1: fprintf(whereToPrint, "* ");
					break;
				case 2: fprintf(whereToPrint, "# ");
					break;
				case 3: fprintf(whereToPrint, "1 ");
					break;
				case 4: fprintf(whereToPrint, "2 ");
					break;
				default: break;	

			}
                }
		fprintf(whereToPrint, "\n");
        } 

    fprintf(whereToPrint, "  1 2 3 4 5 6 7 8\n");
}


int prompt(ESTADO *e, int x){
	int gamer = obter_jogador_atual(e);
	int jogada = obter_numero_de_jogadas(e);
	if (x<10)
		printf("# 0%d PL%d (%d)> ", x, gamer, jogada);
	else 
		printf("# %d PL%d (%d)> ", x, gamer, jogada);
	return 1;
}

int interpretador(ESTADO *e){
	char linha[BUF_SIZE];
	char col[2], lin[2];
	int x = 1;

	prompt(e,x);
	if(fgets(linha, BUF_SIZE, stdin) == NULL)
		return 0;


	while(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
		COORDENADA coord = {*lin - 'a', *col - '1'};
		jogar(e, coord);
		mostrar_tabuleiro(stdout, e);
		prompt(e,x);
		x ++;
		fgets(linha, BUF_SIZE, stdin);
	}

	//Quits game
	if(strlen(linha) == 2 && sscanf(linha, "Q"))
		return 0;

	return 1;
}

