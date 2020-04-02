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
	int jogada = obter_numero_de_jogadasOLD(e);
	if (x<10)
		printf("# 0%d PL%d (%d)> ", x, gamer, jogada + 1);
	else 
		printf("# %d PL%d (%d)> ", x, gamer, jogada + 1);
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



	while((strlen(linha) > 2)                                  &&
		 ((sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2)       ||
		  (!strcmp(linha, addStr("ler ",remStr(4,linha))))     ||
	      (!strcmp(linha,"movs\n"))                            ||
	      (!strcmp(linha, addStr("pos ",remStr(4,linha)))))){
		
		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
			COORDENADA coord = {*lin - 'a', *col - '1'};
			jogar(e, coord);
			replicaEstado(e);
		}

		if (strlen(linha) == 5 && !strcmp(linha,"movs\n"))
			movs(stdout,e);

		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("ler ",remStr(4,linha))))){
				char* filename = remStr(4,linha);
				ler(filename,e);
		}

		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("pos ",remStr(4,linha))))){
			char* newLinha;

			newLinha = remStr(4,linha);
			newLinha[strlen(newLinha)-1] = 0;
			
			int posJogada = atoi(newLinha) - 1;

			pos(e,posJogada);

			//if (pos(e,posJogada))
			//	if (posJogada == obter_numero_de_jogadas(e))
			//		printf("Comando inválido. %d já é a jogada atual.\n", posJogada);
			//	else
			//		printf("Comando inválido. %d é um número maior que a jogada atual.\n", posJogada);
		}

		x ++;
		mostrar_tabuleiro(stdout, e);
		prompt(e,x);
		fgets(linha, BUF_SIZE, stdin);
	}

	if ((strlen(linha) > 3) && (!strcmp(linha, addStr("gr ",remStr(3,linha))))){
		char* fileName = remStr(3,linha);
		gr(fileName,e);
	}

	//Quits game
	if (!strcmp(linha, "Q\n"))
		return 0;

	return 1;
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
    COORDENADA *coord = malloc(sizeof(int)*2);
    COORDENADA *coord1 = malloc(sizeof(int)*2);
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
            	coord->linha = p1Linha - 'a';
            	coord->coluna = p1Coluna - '1';
            	coord1->linha = p2Linha - 'a';
            	coord1->coluna = p2Coluna - '1';
		e->jogadas[jogada-'1'].jogador1 = *coord;
		e->jogadas[jogada-'1'].jogador2 = *coord1;
		incrJogada(e);
            //Discards newline
            fscanf(file, " ");
//
        }
    }
}

void pos(ESTADO *e, int x){
    int i = obter_numero_de_jogadasOLD(e);
    int j = obter_numero_de_jogadas(e);

    int l1, l2, c1, c2;
    COORDENADA std, pl1, pl2;
    std.linha = 8;
    std.coluna = 8;


    if (j < x && x <= i){
    	pl1.linha = e -> jogadasOLD[i].jogador1.linha;
        pl2.linha = e -> jogadasOLD[i].jogador2.linha;
        pl1.coluna = e -> jogadasOLD[i].jogador1.coluna;
        pl2.coluna = e -> jogadasOLD[i].jogador2.coluna;

        changePiece(e, pl1, e -> tabOLD[pl1.linha][pl1.coluna]);
        changePiece(e, pl2, e -> tabOLD[pl2.linha][pl2.coluna]);
    }

    else if (x <= i){

        changeJogada(e,x + 1);

		if (obter_jogador_atual(e) == 2)
			changePlayer(e);

        while (i != x){
            pl1.linha = e -> jogadas[i].jogador1.linha;
            pl2.linha = e -> jogadas[i].jogador2.linha;
            pl1.coluna = e -> jogadas[i].jogador1.coluna;
            pl2.coluna = e -> jogadas[i].jogador2.coluna;

            changePiece(e, pl1, VAZIO);
            changePiece(e, pl2, VAZIO);

            coloca_jogada(e, i, std, 1);
            coloca_jogada(e, i, std, 2);

            i --;
        }

        printf("%d %d \n",i,j);
        //changePiece(e,e->jogadas[x]);
    }

}
