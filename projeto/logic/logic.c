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


int aroundBranca(ESTADO *e){
    COORDENADA branca = findBranca(e);
    int l = branca.linha;
    int c = branca.coluna;

    if (!l || l == 7){
        switch(l){
            case 0:
            if (e-> tab[l][c-1] == PRETA && e-> tab[l][c+1] == PRETA && 
                e-> tab[l+1][c-1] == PRETA && e-> tab[l+1][c] == PRETA && e-> tab[l+1][c+1] == PRETA)
                return 1;
            break;

            case 7:
            if (e-> tab[l-1][c-1] == PRETA && e-> tab[l-1][c] == PRETA && e-> tab[l-1][c+1] == PRETA &&
                e-> tab[l][c-1] == PRETA && e-> tab[l][c+1] == PRETA)
                return 1;
            break;
        }
    }

    if (!c || c == 7){
        switch(c){
            case 0:
            if (e-> tab[l-1][c] == PRETA && e-> tab[l-1][c+1] == PRETA &&
                e-> tab[l][c+1] == PRETA && 
                e-> tab[l+1][c] == PRETA && e-> tab[l+1][c+1] == PRETA)
                return 1;
            break;

            case 7:
            if (e-> tab[l-1][c-1] == PRETA && e-> tab[l-1][c] == PRETA &&
                e-> tab[l][c-1] == PRETA &&
                e-> tab[l+1][c-1] == PRETA && e-> tab[l+1][c] == PRETA)
                return 1;
            break;
        }

    }

    if (e-> tab[l-1][c-1] == PRETA && e-> tab[l-1][c] == PRETA && e-> tab[l-1][c+1] == PRETA &&
        e-> tab[l][c-1] == PRETA && e-> tab[l][c+1] == PRETA && 
        e-> tab[l+1][c-1] == PRETA && e-> tab[l+1][c] == PRETA && e-> tab[l+1][c+1] == PRETA)
        return 1;

    return 0;
}


int gameOver(ESTADO *e){
    if (e-> tab[0][7] != VAZIO || e-> tab[7][0] != VAZIO)
        return 1;
    if (aroundBranca(e))
        return 1;
    if ((e-> tab[0][0] == BRANCA && e-> tab[0][1] == PRETA && e-> tab[1][1] == PRETA && e-> tab[1][0] == PRETA) ||
        (e-> tab[7][7] == BRANCA && e-> tab[6][7] == PRETA && e-> tab[6][6] == PRETA && e-> tab[7][6] == PRETA))
        return 1;
    return 0;
}

int winner(ESTADO *e){

    if (e-> tab[0][7] == BRANCA)
        return 2;
    else if (e-> tab[7][0] == BRANCA)
            return 1;

    if (obter_jogador_atual(e) == 1)
        return 2;
    else
        return 1;
}

//Receives a coordinate and makes a move. (e.g changes the position of a player and leaves a black piece in its current position)
int jogar(ESTADO *e, COORDENADA c) {
    int x;
    if (jogadaValida(e, c) && !gameOver(e)){
	    coloca_preta(e);
	    changePiece(e, c, BRANCA);
        if (obter_jogador_atual(e) == 1) {
            coloca_jogada(e,obter_numero_de_jogadas(e),c,1);
            changePlayer(e);
            if (gameOver(e)){
                x = winner(e);
                printf("Game Over. Parábens jogador %d!\n",x);
                return 0;
            }
        }
        else{
            coloca_jogada(e,obter_numero_de_jogadas(e),c,2);
            changePlayer(e);
            incrJogada(e);
            if (gameOver(e)){
                x = winner(e);
                printf("Game Over. Parábens jogador %d!\n",x);
                return 0;
            }
        }
        printf("jogar %d %d\n", c.linha+1, c.coluna+1);
        return 1;
    }
    else{
        if (gameOver(e))
            printf("Jogada inválida. O jogo já acabou.\n");
        else 
            printf("Jogada inválida.\n");
    }
    return 0;
}


//Validates a move
int jogadaValida(ESTADO *e, COORDENADA going){
	//Declaring used variables
	COORDENADA current = {3,4};

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
