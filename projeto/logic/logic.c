//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"


COORDENADA findBranca(ESTADO *e){
    int i = 0, j = 0, bool = 1;
    COORDENADA branca;
    while(i != 8 && bool){
        branca.linha = i;
        while(j != 8 && bool){
            branca.coluna = j; 
            if (obter_estado_casa(e, branca, 0, 1) == BRANCA){
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
	COORDENADA teste = {branca.linha-1, branca.coluna-1};

	for(int i = 0, max = 0; max < 8; max++, i = max % 3){
		if(max != 0 && i%3 == 0){
		       	teste.linha++;
			teste.coluna = branca.coluna;
		}
		if (jogadaValida(e, teste)) return 0;
		teste.coluna++;
	}
	return 1;
}

int gameOver(ESTADO *e){
    COORDENADA win1 = {7,0}, win2 = {0,7};
    if (obter_estado_casa(e, win1, 0, 1) != VAZIO || obter_estado_casa(e, win2, 0, 1) != VAZIO)
        return 1;
    if (aroundBranca(e))
        return 1;
    return 0;
}

int winner(ESTADO *e){
    COORDENADA win1 = {7,0}, win2 = {0,7};

    if (obter_estado_casa(e, win2, 1, 1) == BRANCA)
        return 2;
    else if (obter_estado_casa(e, win1, 1, 1) == BRANCA)
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
            coloca_jogada(e,obter_numero_de_jogadas(e, 1), c, 1);
            changePlayer(e);
            if (gameOver(e)){
                x = winner(e);
                printf("Game Over. Parábens jogador %d!\n",x);
                return 0;
            }
        }
        else{
            coloca_jogada(e,obter_numero_de_jogadas(e, 1),c,2);
            changePlayer(e);
            incrJogada(e);
            if (gameOver(e)){
                x = winner(e);
                printf("Game Over. Parábens jogador %d!\n",x);
                return 0;
            }
        }
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
	if (obter_estado_casa(e, going, 1, 1) == PRETA || obter_estado_casa(e, going, 1, 1) == BRANCA){
	       	return 0;
	}

	return 1;
}

//Conta a quantidade de coordenadas vazias no entorno de um jogador
int nr_coord_around(COORDENADA c, ESTADO *e){
    int r = 0, j = -1, border = 1;
    COORDENADA copycat;

    if (c.coluna == 7) border = 0;
    copycat.linha = c.linha - 1;
    while(c.linha != 0 && j <= border){
        copycat.coluna = c.coluna + j;
        if (c.coluna + j != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                r ++;
        }
        j ++;
    }
    j = -1; copycat.linha ++;
    while(j <= border){
        copycat.coluna = c.coluna + j;
        if (c.coluna + j != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                r ++;
        }
        j ++;
    }
    j = -1; copycat.linha ++;
    while(c.linha != 7 && j <= border){
        copycat.coluna = c.coluna + j;
        if (c.coluna + j != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                r ++;
        }
        j ++;
    }

    return r;
}

//Coloca as coordenadas ao redor de um player num array
void array_coord_around(COORDENADA c, COORDENADA *A, ESTADO *e){
    int r = 0, j = -1, border = 1;
    COORDENADA fake;
    if (c.coluna == 7) border = 0;

    fake.linha = c.linha - 1;
    while(c.linha != 0 && j <= border){
        if (c.coluna + j != -1){
            fake.coluna = c.coluna + j;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                A[r++] = fake;
            }
        }
        j ++;
    }
    j = -1; fake.linha ++;
    while(j <= border){
        if (c.coluna + j != -1){
            fake.coluna = c.coluna + j;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                A[r++] = fake;
            }
        }
        j ++;
    }
    j = -1; fake.linha ++;
    while(c.linha != 7 && j <= border){
        if (c.coluna + j != -1){
            fake.coluna = c.coluna + j;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                A[r++] = fake;
            }
        }
        j ++;
    }   
}