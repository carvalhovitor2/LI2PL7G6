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

char* remStr(int x, char* s){
	char* ret = malloc(strlen(s) - x);
	int i = 3;

	while(s[i]){
		ret[i - x] = s[i];
		i ++;
	}

	ret[i] = '\0';

	return ret;
}


char* addStr(char* s, char* v){
	char* ret = malloc(strlen(s) + strlen(v));
	int i, j = 0;

	for(i = 0; s[i]; i ++)
		ret[i] = s[i];

	while(v[j]){
		ret[i] = v[j];
		j ++;
		i ++;
	}
	ret[i] = '\0';

	return ret;
}


int interpretador(ESTADO *e){
	char linha[BUF_SIZE];
	char col[2], lin[2];
	int x = 1;

	prompt(e,x);

	if(fgets(linha, BUF_SIZE, stdin) == NULL)
		return 0;


	while((strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2)
		  ){
		
		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
			COORDENADA coord = {*lin - 'a', *col - '1'};
			jogar(e, coord);
			mostrar_tabuleiro(stdout, e);
			prompt(e,x);
			x ++;
		}

		char* filename = linha;
		gr(filename,e);

		fgets(linha, BUF_SIZE, stdin);
	}

	if (!strcmp(linha, addStr("gr ",remStr(3,linha)))){
			char* filename = remStr(3,linha);
			gr(filename,e);
		}

	if (!strcmp(linha, addStr("ler ",remStr(4,linha)))){
			printf("COMPLETAR COM A FUNÇÃO LER\n");
		}


	//Quits game
	if (!strcmp(linha, "Q\n"))
		return 0;

	return 1;
}

