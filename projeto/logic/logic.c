//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"


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


COORDENADA findBranca(ESTADO *e){
    int i = 0, j = 0, bool = 1;
    COORDENADA branca;
    while(i != 8 && bool){
        while(j != 8 && bool){
            if (e-> tab[i][j] == BRANCA){
                branca.linha = i;
                branca.coluna = j;
                bool = 0;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    return branca;
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
int jogadaValida(ESTADO *e, COORDENADA going){
	//Declaring used variables
	int num_jogadas; JOGADA jogada; COORDENADA current = {3,4};

	//Assigning values to declared variables
	num_jogadas = (e->num_jogadas); jogada = e->jogadas[num_jogadas-1];

	//Verifiy if its the first move. If it is, assume the gamer position is the first position. If not, use last move.
	current = findBranca(e);

	//Here goes the actual function purpose
	//Ensures move is in a maximum of 8x8 range
	if ( going.linha > 7 || going.linha < 0 || going.coluna > 7 || going.coluna < 0){
		return 0;
	}

	//Ensures player is going to a piece that is a valid distance (only 1 piece distance)
	if( (abs(going.linha - current.linha) > 1) || (abs(going.coluna - current.coluna) > 1)){
	       	return 0;
	}

	//Ensures going piece is not BLACK or WHITE already
	going.linha++;
	going.coluna++;
	if ( obter_estado_casa(e, going) == PRETA || obter_estado_casa(e, going) == BRANCA){
	       	return 0;
	}

	return 1;
}
