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


void prompt(ESTADO *e, int x){
	int gamer = obter_jogador_atual(e);
	int jogada = obter_numero_de_jogadas(e);
	if (x<10)
		printf("# 0%d PL%d (%d)> ", x, gamer, jogada);
	else 
		printf("# %d PL%d (%d)> ", x, gamer, jogada);
}

void movs(FILE *whereToPrint,ESTADO *e){
	int i = 0, x;
	char l1, l2;
	int col1, col2;
	COORDENADA c1, c2;

	x = obter_numero_de_jogadas(e);

	if (e -> jogadas[x].jogador1.linha == 8)
		x --;

	while (i <= x){
		c1 = e-> jogadas[i].jogador1;
		c2 = e-> jogadas[i].jogador2;
		l1 = 'a' + c1.linha;
		l2 = 'a' + c2.linha;
		col1 = c1.coluna + 1;
		col2 = c2.coluna + 1;

		if (e -> jogadas[i].jogador2.coluna < 8){
			if (i < 9)
				fprintf(whereToPrint, "0%d: %c%d %c%d\n", i + 1, l1, col1, l2, col2);
			else
				fprintf(whereToPrint, "%d: %c%d %c%d\n", i + 1, l1, col1, l2, col2);
		}

		else{
			if (i < 9)
				fprintf(whereToPrint, "0%d: %c%d \n", i + 1, l1, col1);
			else
				fprintf(whereToPrint, "%d: %c%d \n", i + 1, l1, col1);
		}

		i ++;
	}

	
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



	while((strlen(linha) > 2)                                                  
		  &&
		  ((strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2) ||
		  (!strcmp(linha, addStr("ler ",remStr(4,linha))))                     ||
		  (!strcmp(linha,"movs\n")))){
		
		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
			COORDENADA coord = {*lin - 'a', *col - '1'};
			jogar(e, coord);
			mostrar_tabuleiro(stdout, e);
		}

		if (strlen(linha) == 5 && !strcmp(linha,"movs\n"))
			movs(stdout,e);

		if (strlen(linha) > 4){

			 if (!strcmp(linha, addStr("ler ",remStr(4,linha)))){
				char* filename = remStr(4,linha);
				ler(filename,e);
				mostrar_tabuleiro(stdout, e);
			}
		}

		x ++;
		prompt(e,x);
		fgets(linha, BUF_SIZE, stdin);
	}

	if (strlen(linha) > 3 && !strcmp(linha, addStr("gr ",remStr(3,linha)))){
		char* fileName = remStr(3,linha);
		gr(fileName,e);
	}

	//Quits game
	if (!strcmp(linha, "Q\n"))
		return 0;

	return 1;
}

