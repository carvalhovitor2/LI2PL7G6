//This file is designed to store the definition of the interface functions
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

//Print the game board
void mostrar_tabuleiro(ESTADO *e){
	int boardPiece = 0;
    for(int linha = 0; linha < 8; linha++){
    	char a = 'a' + linha;
    	putchar(a);
    	putchar(' ');
        for(int coluna = 0; coluna < 8; coluna++){
		//Translate enum to chars
                    boardPiece = e->tab[linha][coluna];
			if(linha == 7 && coluna == 0) boardPiece = 3;
			if(linha == 0 && coluna == 7) boardPiece = 4;
			switch (boardPiece){
				case 0: printf(". ");
					break;
				case 1: printf("# ");
					break;
				case 2: printf("* ");
					break;
				case 3: printf("1 ");
					break;
				case 4: printf("2 ");
					break;
				default: break;	

			}
                }
		printf("\n");
        } 

    printf("\r  1 2 3 4 5 6 7 8\n");
}

int interpretador(ESTADO *e){
	char linha[BUF_SIZE];
	char col[2], lin[2];

	if(fgets(linha, BUF_SIZE, stdin) == NULL)
		return 0;

	while(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
		COORDENADA coord = {*lin - 'a', *col - '1'};
		jogar(e, coord);
		mostrar_tabuleiro(e);
		fgets(linha, BUF_SIZE, stdin);
	}

	return 1;
}

