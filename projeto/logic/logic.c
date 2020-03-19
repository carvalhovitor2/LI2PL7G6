//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

void coloca_preta (ESTADO *e){
    COORDENADA c = {3,4}; //Posição inicial no tabuleiro.
    if (obter_jogador_atual(e) == 1 && obter_numero_de_jogadas(e) == 0) //caso seja a primeira jogada vai colocar a peça preta na posição 4,4
        changePiece (e,c,PRETA);
    else if (obter_jogador_atual(e) == 1 && obter_numero_de_jogadas(e) > 0)
        changePiece (e,e->jogadas[obter_numero_de_jogadas(e)-1].jogador2,PRETA);
    else changePiece (e,e->jogadas[obter_numero_de_jogadas(e)].jogador1,PRETA);
}


COORDENADA findPreta(ESTADO *e){
    int i = 0, j = 0, bool = 1;
    COORDENADA preta;
    while(i != 8 && bool){
        while(j != 8 && bool){
            if (e-> tab[i][j] == PRETA){
                preta.linha = i;
                preta.coluna = j;
                bool = 0;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    return preta;
}


int aroundPreta(ESTADO *e){
    COORDENADA preta = findPreta(e);
    int l = preta.linha;
    int c = preta.coluna;
    if (e-> tab[l-1][c-1] == BRANCA && e-> tab[l-1][c] == BRANCA && e-> tab[l-1][c+1] == BRANCA &&
        e-> tab[l][c-1] == BRANCA && e-> tab[l][c+1] == BRANCA && 
        e-> tab[l+1][c-1] == BRANCA && e-> tab[l+1][c] == BRANCA && e-> tab[l+1][c+1] == BRANCA)
        return 1;
    return 0;
}


int gameOver(ESTADO *e){
    if (e-> tab[0][7] == BRANCA || e-> tab[7][0] == BRANCA)
        return 1;
    if (aroundPreta(e))
        return 1;
    return 0;
}

//Receives a coordinate and makes a move. (e.g changes the position of a player and leaves a black piece in its current position)
int jogar(ESTADO *e, COORDENADA c) {
    if (jogadaValida(e, c)){
	    changePiece(e, c, BRANCA);
            coloca_preta(e);
            if (obter_jogador_atual(e) == 1) {
                coloca_jogada(e,obter_numero_de_jogadas(e),c,1);
                changePlayer(e);
            }
            else
            {
                coloca_jogada(e,obter_numero_de_jogadas(e),c,2);
                changePlayer(e);
                incrJogada(e);
            }
            printf("jogar %d %d\n", c.linha+1, c.coluna+1);
            return 1;
    }
    else printf("Jogada invalida\n");
    return 0;
}


//Validates a move
int jogadaValida(ESTADO *e, COORDENADA c){
	//Declaring used variables
	int num_jogadas; JOGADA jogada; COORDENADA current = {3,4};

	//Assigning values to declared variables
	num_jogadas = (e->num_jogadas); jogada = e->jogadas[num_jogadas-1];

	//Verifiy if its the first move. If it is, assume the gamer position is the first position. If not, use last move.
	if (num_jogadas != 0 && obter_jogador_atual(e) == 1 ) current = jogada.jogador1;
	if (num_jogadas != 0 && obter_jogador_atual(e) == 2 ) current = jogada.jogador2;

	//Here goes the actual function purpose
	//Ensures move is in a maximum of 8x8 range
	if ( c.linha > 7 || c.linha < 0 || c.coluna > 7 || c.coluna < 0){
		return 0;
	}

	//Ensures player is going to a piece that is a valid distance (only 1 piece distance)
	if( (abs(c.linha - current.linha) > 1) || (abs(c.coluna - current.coluna) > 1)){
	       	return 0;
	}

	//Ensures going piece is not BLACK
	c.linha++;
	c.coluna++;
	if ( obter_estado_casa(e, c) == PRETA ){
	       	return 0;
	}

	return 1;
}
