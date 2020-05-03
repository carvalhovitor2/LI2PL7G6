//This file is designed to store the definition of the interface functions
#include "interface.h"
#include "../listas_ligadas/listas_ligadas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

//Print the game board
void mostrar_tabuleiro(FILE *whereToPrint, ESTADO *e){
	int boardPiece = 0;
    for(int linha = 0; linha < 8; linha++){
    	char a = 'a' + linha;
	if ( whereToPrint == stdout ){
		fprintf(whereToPrint, "%c", a);
		fprintf(whereToPrint, " ");
	}
        for(int coluna = 0; coluna < 8; coluna++){
		//Translate enum to chars
		COORDENADA coord={linha+1, coluna+1};
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


void prompt(ESTADO *e, int x, int decider){
	int gamer = obter_jogador_atual(e);
	int jogada;

	if (decider)
		jogada = obter_numero_de_jogadas(e, 1);
	else
		jogada = obter_numero_de_jogadas(e, 0);

	if (x < 10)
		printf("# 0%d PL%d (%d)> ", x, gamer, jogada + 1);
	else 
		printf("# %d PL%d (%d)> ", x, gamer, jogada + 1);
}

void movs(FILE *whereToPrint,ESTADO *e){
	int i = 0, nr_jogadas = obter_numero_de_jogadas(e, 1);
	char l1, l2;
	int col1, col2;
	COORDENADA c1, c2;

	if (obter_coord_deJogada(e, nr_jogadas, 1, 1, 1) == 8)
		nr_jogadas --;

	while (i <= nr_jogadas){
		c1.linha = obter_coord_deJogada(e, i, 1, 1, 1), c1.coluna =  obter_coord_deJogada(e, i, 1, 0, 1);
		c2.linha = obter_coord_deJogada(e, i, 2, 1, 1), c2.coluna =  obter_coord_deJogada(e, i, 2, 0, 1);
		l1 = 'a' + c1.linha;
		l2 = 'a' + c2.linha;
		col1 = c1.coluna + 1;
		col2 = c2.coluna + 1;

		if (obter_coord_deJogada(e, i, 2, 0, 1) < 8){
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
	char linha[BUF_SIZE], col[2], lin[2];
	int x = 1, boolPrompt = 1;
	prompt(e,x,1);

	if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;

	while((strlen(linha) > 2)                                  &&
		 ((sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2)       || (!strcmp(linha,"jog\n"))                             ||
		  (!strcmp(linha,"jog2\n"))                            || (!strcmp(linha, addStr("ler ",remStr(4,linha))))     ||
	      (!strcmp(linha,"movs\n"))                            || (!strcmp(linha, addStr("pos ",remStr(4,linha)))))){
		
		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", lin, col) == 2){
			COORDENADA coord = {*lin - 'a', *col - '1'};
			jogar(e, coord);
			replicaEstado(e);
			boolPrompt = 1;
		}

		if (strlen(linha) == 4 && !strcmp(linha,"jog\n")){
			jog(e);
			replicaEstado(e);
			boolPrompt = 1;
		}

		if (strlen(linha) == 5 && !strcmp(linha,"jog2\n")){
			COORDENADA C_escolhida;
			C_escolhida.linha = jog2(e, 1), C_escolhida.coluna = jog2(e, 0);
			jogar(e, C_escolhida);
			replicaEstado(e);
			boolPrompt = 1;
		}

		if (strlen(linha) == 5 && !strcmp(linha,"movs\n"))	movs(stdout,e);

		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("ler ",remStr(4,linha))))){
				char* filename = remStr(4,linha);
				ler(filename, e);
		}

		if ((strlen(linha) > 4) && (!strcmp(linha, addStr("pos ",remStr(4,linha))))){
			char* newLinha;
			newLinha = remStr(4,linha);
			newLinha[strlen(newLinha)-1] = 0;
			int posJogada = atoi(newLinha);
			if (posJogada > obter_numero_de_jogadas(e, 0))
				printf("Comando inválido. %d é um número maior que a jogada atual.\n", obter_numero_de_jogadas(e, 0));
			else{
				pos(e, posJogada);
				boolPrompt = 0;
			}
		}

		mostrar_tabuleiro(stdout, e);
		prompt(e, ++x, boolPrompt);
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

	int nrC = nr_coord_around(findBranca(e), e),
		rnd = random() % nrC;
	COORDENADA C[nrC]; 
	array_coord_around(findBranca(e), C, e);

	LISTA lJog;
	lJog = criar_lista();

	for(int count = nrC; count >= 0; count --)
		lJog = insere_cabeca(lJog, C + count);

	while(lJog && rnd > 0){
		lJog = remove_cabeca(lJog);
		rnd --;
	}
			
	COORDENADA *aleatoria;
	aleatoria = devolve_cabeca(lJog);

	jogar(e, *aleatoria);
	free(lJog);
}

int jog2(ESTADO *e, int decider){
	int nrC = nr_coord_around(findBranca(e), e);
	COORDENADA C[nrC]; 
	array_coord_around(findBranca(e), C, e);
	float F[nrC];

	for(int i = 0; i < nrC; i ++){
		if (obter_jogador_atual(e) == 1)
			F[i] = sqrt(pow(7 - C[i].linha, 2) + pow(0 - C[i].coluna, 2));
		else
			F[i] = sqrt(pow(0 - C[i].linha, 2) + pow(7 - C[i].coluna, 2));
	}

	LISTA lC, lF;
	lC = criar_lista();
	lF = criar_lista();
	for(int count = nrC - 1; count >= 0; count--){
		lF = insere_cabeca(lF, F + count);
		lC = insere_cabeca(lC, C + count);
	}
			
	int indice = menorDist(lF);
	for(; lC && indice > 0; indice --){
		lC = remove_cabeca(lC);
	}

	COORDENADA *menor;
	menor = devolve_cabeca(lC);

	free(lF);
	free(lC);

	if (decider)
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


void pos(ESTADO *e, int x){
    int i_OLD = obter_numero_de_jogadas(e, 0), i_New = obter_numero_de_jogadas(e, 1);
	COORDENADA pl1, pl2, std = {8,8};

    if (x == 0){
    	COORDENADA PL, inicial = {3,4};

    	for(int k = 0; k != 8; k ++)
    		for(int l = 0; l != 8; l ++){
    			PL.linha = l; PL.coluna = k;
				changePiece(e, PL, VAZIO);
    		}
    	for(int t = 0; t != 32; t ++){
    		coloca_jogada(e, t, std, 1);
        	coloca_jogada(e, t, std, 2);
        }
    	changePiece(e,inicial,BRANCA);
    	changeJogada(e,0);
    	if (e-> jogador_atual == 2) changePlayer(e);
     
    }
	else{

    	if (x <= i_OLD){

    		if (i_New < x){

        		changeJogada(e,x);

        		if (obter_jogador_atual(e) == 2)
    				changePlayer(e);

    			coloca_preta(e);

        		while(i_New != x){
       		    	//int obter_coord_deJogada(ESTADO *e, int jogada, int player, int decider, int new_or_old)
       		    	pl1.linha = obter_coord_deJogada(e, i_New, 1, 1, 0); pl1.coluna = obter_coord_deJogada(e, i_New, 1, 0, 0);
       				pl2.linha = obter_coord_deJogada(e, i_New, 2, 1, 0); pl2.coluna = obter_coord_deJogada(e, i_New, 2, 0, 0);

        			changePiece(e, pl1, e -> tabOLD[pl1.linha][pl1.coluna]);
        			changePiece(e, pl2, e -> tabOLD[pl2.linha][pl2.coluna]);

        			coloca_jogada(e, i_New, pl1, 1);
            		coloca_jogada(e, i_New, pl2, 2);
        	
        			i_New ++;
        			}  
    			}

    		else{

        		changeJogada(e,x);

        		while (i_New + 1 != x){

            		pl1.linha = e -> jogadas[i_New].jogador1.linha;
            		pl2.linha = e -> jogadas[i_New].jogador2.linha;
            		pl1.coluna = e -> jogadas[i_New].jogador1.coluna;
            		pl2.coluna = e -> jogadas[i_New].jogador2.coluna;

            		changePiece(e, pl1, VAZIO);
            		changePiece(e, pl2, VAZIO);

            		coloca_jogada(e, i_New, std, 1);
            		coloca_jogada(e, i_New, std, 2);

        			i_New --;

        			if (obter_jogador_atual(e) == 2)
						changePlayer(e);
        		}
			}

    COORDENADA novaBranca = {getLastPiece(e,0), getLastPiece(e,1)};
    changePiece(e,novaBranca,BRANCA);
	}
	}

}
