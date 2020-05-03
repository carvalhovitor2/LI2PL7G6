//This file is designed to store the definition of the interface functions
#include "interface.h"
#include "listas_ligadas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

//Print the game board
void mostrar_tabuleiro(FILE *whereToPrint, ESTADO *e){
	int boardPiece = 0;
    for(int linha = 0; linha < 8; linha++){
    	char letra_linha = 'a' + linha;
	if ( whereToPrint == stdout ){
		fprintf(whereToPrint, "%c", letra_linha);
		fprintf(whereToPrint, " ");
	}
        for(int coluna = 0; coluna < 8; coluna++){
		//Translate enum to chars
		COORDENADA coord = {linha+1, coluna+1};
                boardPiece = obter_estado_casa(e, coord, 1, 1);
			if(linha == 7 && coluna == 0) boardPiece = 3;
			if(linha == 0 && coluna == 7) boardPiece = 4;
			switch (boardPiece){
				case 0: fprintf(whereToPrint, ".");
				        if(whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 1: fprintf(whereToPrint, "*");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 2: fprintf(whereToPrint, "#");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 3: fprintf(whereToPrint, "1");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				case 4: fprintf(whereToPrint, "2");
				        if( whereToPrint == stdout) fprintf(whereToPrint, " ");
					break;
				default: break;
			}
                }
		fprintf(whereToPrint, "\n");
        } 

	if (whereToPrint == stdout) fprintf(whereToPrint, "  1 2 3 4 5 6 7 8\n");
}


void prompt(ESTADO *e, int nr_comandos, int new_or_old){
	int player = obter_jogador_atual(e);
	int jogada;

	jogada = obter_numero_de_jogadas(e, new_or_old);

	if (nr_comandos < 10)
		printf("# 0%d PL%d (%d)> ", nr_comandos, player, jogada + 1);
	else 
		printf("# %d PL%d (%d)> ", nr_comandos, player, jogada + 1);
}

void movs(FILE *whereToPrint,ESTADO *e){
	int count = 0, nr_jogadas = obter_numero_de_jogadas(e, 1);
	char l1, l2;
	int col1, col2;
	COORDENADA c1, c2;

	if (obter_coord_deJogada(e, nr_jogadas, 1, 1, 1) == 8)
		nr_jogadas --;

	while (count <= nr_jogadas){
		c1.linha = obter_coord_deJogada(e, count, 1, 1, 1), c1.coluna =  obter_coord_deJogada(e, count, 1, 0, 1);
		c2.linha = obter_coord_deJogada(e, count, 2, 1, 1), c2.coluna =  obter_coord_deJogada(e, count, 2, 0, 1);
		
		l1 = 'a' + c1.linha;  l2 = 'a' + c2.linha;
		col1 = c1.coluna + 1; col2 = c2.coluna + 1;

		if (obter_coord_deJogada(e, count, 2, 0, 1) < 8){
			if (count < 9)
				fprintf(whereToPrint, "0%d: %c%d %c%d\n", count + 1, l1, col1, l2, col2);
			else
				fprintf(whereToPrint, "%d: %c%d %c%d\n", count + 1, l1, col1, l2, col2);
		}

		else{
			if (count < 9)
				fprintf(whereToPrint, "0%d: %c%d \n", count + 1, l1, col1);
			else
				fprintf(whereToPrint, "%d: %c%d \n", count + 1, l1, col1);
		}

		count ++;
	}
}

char* remStr(int nr_para_remover, char* original){
	char* ret = malloc(strlen(original) - nr_para_remover);
	int count = nr_para_remover;

	while(original[count]){
		ret[count - nr_para_remover] = original[count];
		count ++;
	}

	ret[count] = '\0';

	return ret;
}


char* addStr(char* str1, char* str2){
	char* ret = malloc(strlen(str1) + strlen(str2));
	int count_ret, count_str2 = 0;

	for(count_ret = 0; str1[count_ret]; count_ret ++)
		ret[count_ret] = str1[count_ret];

	while(str2[count_str2]){
		ret[count_ret] = str2[count_str2];
		count_str2 ++;
		count_ret ++;
	}
	ret[count_ret] = '\0';

	return ret;
}


int interpretador(ESTADO *e){
	char linha[BUF_SIZE], col[2], lin[2];
	int nr_comandos = 1, new_or_old = 1;
	prompt(e, nr_comandos, 1);

	if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
	while((strlen(linha) > 2)                                  &&
		 ((sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2)       || (!strcmp(linha,"jog\n"))  || (!strcmp(linha,"jog2\n"))  || 
		  (!strcmp(linha, addStr("ler ",remStr(4,linha))))     || (!strcmp(linha,"movs\n")) || (!strcmp(linha, addStr("pos ",remStr(4,linha)))))){
		
		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
			COORDENADA coord = {*lin - 'a', *col - '1'};
			jogar(e, coord);
			replicaEstado(e); new_or_old = 1;
		}
		if (strlen(linha) == 4 && !strcmp(linha,"jog\n")){
			jog(e);
			replicaEstado(e); new_or_old = 1;
		}
		if (strlen(linha) == 5 && !strcmp(linha,"jog2\n")){
			COORDENADA C_escolhida = {jog2(e, 1), jog2(e, 0)};
			jogar(e, C_escolhida);
			replicaEstado(e); new_or_old = 1;
		}
		if (strlen(linha) == 5 && !strcmp(linha,"movs\n"))	movs(stdout,e);
		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("ler ",remStr(4,linha))))){
			char* filename = remStr(4,linha);
			ler(filename, e);
		}
		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("pos ",remStr(4,linha))))){
			char* newLinha = remStr(4,linha);
			newLinha[strlen(newLinha)-1] = 0;
			int posJogada = atoi(newLinha);
			pos(e, posJogada);
			new_or_old = 0;
		}
		mostrar_tabuleiro(stdout, e);
		prompt(e, ++nr_comandos, new_or_old);
		char *result = fgets(linha, BUF_SIZE, stdin);
		if (!result) printf("couldn't read line\n");
	}
	if ((strlen(linha) > 3) && (!strcmp(linha, addStr("gr ",remStr(3,linha))))){
		char* fileName = remStr(3,linha);
		gr(fileName, e);
	}
	if (!strcmp(linha, "Q\n")) return 0;
	return 1;
}

void jog(ESTADO *e){
	srandom(time(NULL));

	int nrCoord = nr_coord_around(findBranca(e), e),
		rnd = random() % nrCoord;
	COORDENADA C[nrCoord]; 
	array_coord_around(findBranca(e), C, e);

	LISTA lista_Jog;
	lista_Jog = criar_lista();

	for(int count = nrCoord; count >= 0; count --)
		lista_Jog = insere_cabeca(lista_Jog, C + count);

	while(lista_Jog && rnd > 0){
		lista_Jog = remove_cabeca(lista_Jog);
		rnd --;
	}
			
	COORDENADA *aleatoria;
	aleatoria = devolve_cabeca(lista_Jog);

	jogar(e, *aleatoria);
	free(lista_Jog);
}

int jog2(ESTADO *e, int lin_or_col){
	int nrCoord = nr_coord_around(findBranca(e), e);
	COORDENADA COORDS[nrCoord]; 
	array_coord_around(findBranca(e), COORDS, e);
	float DISTS[nrCoord];

	for(int ind_dists = 0; ind_dists < nrCoord; ind_dists ++){
		if (obter_jogador_atual(e) == 1)
			DISTS[ind_dists] = sqrt(pow(7 - COORDS[ind_dists].linha, 2) + pow(0 - COORDS[ind_dists].coluna, 2));
		else
			DISTS[ind_dists] = sqrt(pow(0 - COORDS[ind_dists].linha, 2) + pow(7 - COORDS[ind_dists].coluna, 2));
	}

	LISTA lista_Coord, lista_Dist;
	lista_Coord = criar_lista();
	lista_Dist = criar_lista();
	for(int count_listas = nrCoord - 1; count_listas >= 0; count_listas--){
		lista_Dist = insere_cabeca(lista_Dist, DISTS + count_listas);
		lista_Coord = insere_cabeca(lista_Coord, COORDS + count_listas);
	}
			
	int indice = menorDist(lista_Dist);
	for(; lista_Coord && indice > 0; indice --){
		lista_Coord = remove_cabeca(lista_Coord);
	}

	COORDENADA *menor;
	menor = devolve_cabeca(lista_Coord);

	free(lista_Dist);
	free(lista_Coord);

	if (lin_or_col)
		return (menor-> linha);
	else
		return (menor-> coluna);
}

//Writes in a file
void gr(char *fileName, ESTADO *e){
    //Removes \n from string
    fileName[strlen(fileName)-1] = 0;
    //Opens the file
    FILE *file = fopen(fileName, "w+");

    //Writes the board in the file instead of stdout
    mostrar_tabuleiro(file, e);
    fputc('\n', file);
    movs(file, e);
}


void ler(char *fileName, ESTADO *e){
    //Removes \n from string
    fileName[strlen(fileName)-1] = 0;
    COORDENADA *coord = malloc(sizeof(int)*2);
    COORDENADA *coord1 = malloc(sizeof(int)*2);
    COORDENADA peca;
    //Opens the file
    FILE *file = fopen(fileName, "r");

    //Auxiliar char to translate chars to integers
    char *c=malloc(sizeof(char));

    //Iterates trough board lines
    for(int linha = 0; linha < 8; linha++){
	peca.linha = linha;
        //Iterates through board columns
        for(int coluna = 0; coluna < 8; coluna++){
	    peca.coluna = coluna;
            //Reads a piece and stores it in game state
            int try = fscanf(file, "%c ", c);
	    if(try != 1)printf("could read char\n");
            if( *c == '.') changePiece(e, peca, VAZIO);
            if( *c == '#') changePiece(e, peca, PRETA);
            if( *c == '*') changePiece(e, peca, BRANCA);
        }
    }

    char jogada='a', p1Linha='a', p1Coluna='a', p2Linha='a', p2Coluna='a';

    //Reads movs
    for(int buffer = 0, byte = 0;byte < 281 && (fscanf(file, "%c", c) == 1); buffer++, byte++, buffer %=9){
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
        if (buffer == 6){
            	coord->linha = p1Linha - 'a';
		changePlayer(e);
            	coord->coluna = p1Coluna - '1';
	        if(byte > 81)
			coloca_jogada(e, jogada-'1'+10, *coord, 1);
		else
			coloca_jogada(e, jogada-'1', *coord, 1);
        }
	if (buffer == 8){
                coord1->linha = p2Linha - 'a';
		changePlayer(e);
                coord1->coluna = p2Coluna - '1';
	        if(byte > 81)
			coloca_jogada(e, jogada-'1'+10, *coord, 2);
		else
			coloca_jogada(e, jogada-'1', *coord, 2);
		incrJogada(e);
		//Discards newline
                int try = fscanf(file, " ");
		if (try != 1 && try != 0)printf("Couldnt read char");
	}
    }
}
