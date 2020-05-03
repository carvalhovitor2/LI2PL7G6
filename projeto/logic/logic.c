//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"


COORDENADA findBranca(ESTADO *e){
    int line = 0, 
        column = 0, 
        foundBranca = 0;
    COORDENADA branca;

    while(line != 8 && !foundBranca){
        branca.linha = line;
        while(column != 8 && !foundBranca){   
            branca.coluna = column;
            if (obter_estado_casa(e, branca, 0, 1) == BRANCA){
                foundBranca = 1;
            }
            column ++;
        }
        line ++;
        column = 0;
    }

    return branca;
}

int aroundBranca(ESTADO *e){
    COORDENADA branca = findBranca(e);
    if(nr_coord_around(branca, e) != 0) return 0;
    else return 1;
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

    if (obter_estado_casa(e, win2, 0, 1) == BRANCA)
        return 2;
    else if (obter_estado_casa(e, win1, 0, 1) == BRANCA)
            return 1;

    if (obter_jogador_atual(e) == 1)
        return 2;
    else
        return 1;
}

//Receives a coordinate and makes a move. (e.g changes the position of a player and leaves a black piece in its current position)
int jogar(ESTADO *e, COORDENADA coord) {
    int vencedor;
    if (jogadaValida(e, coord) && !gameOver(e)){
	    coloca_preta(e);
	    changePiece(e, coord, BRANCA);
        if (obter_jogador_atual(e) == 1) {
            coloca_jogada(e,obter_numero_de_jogadas(e, 1), coord, 1);
            changePlayer(e);
            if (gameOver(e)){
                vencedor = winner(e);
                printf("Game Over. Parábens jogador %d!\n", vencedor);
                return 0;
            }
        }
        else{
            coloca_jogada(e,obter_numero_de_jogadas(e, 1), coord, 2);
            changePlayer(e);
            incrJogada(e);
            if (gameOver(e)){
                vencedor = winner(e);
                printf("Game Over. Parábens jogador %d!\n", vencedor);
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
	if (going.linha > 7 || going.linha < 0 || going.coluna > 7 || going.coluna < 0){
		return 0;
	}

	//Ensures player is going to a piece that is a valid distance (only 1 piece distance)
	if((abs(going.linha - current.linha) > 1) || (abs(going.coluna - current.coluna) > 1)){
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
int nr_coord_around(COORDENADA coord, ESTADO *e){
    int ret = 0, count = -1, border = 1;
    COORDENADA copycat;

    if (coord.coluna == 7) border = 0;
    copycat.linha = coord.linha - 1;
    while(coord.linha != 0 && count <= border){
        copycat.coluna = coord.coluna + count;
        if (coord.coluna + count != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                ret ++;
        }
        count ++;
    }
    count = -1; copycat.linha ++;
    while(count <= border){
        copycat.coluna = coord.coluna + count;
        if (coord.coluna + count != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                ret ++;
        }
        count ++;
    }
    count = -1; copycat.linha ++;
    while(coord.linha != 7 && count <= border){
        copycat.coluna = coord.coluna + count;
        if (coord.coluna + count != -1){
            if(obter_estado_casa(e, copycat, 0, 1) == VAZIO)
                ret ++;
        }
        count ++;
    }

    return ret;
}

//Coloca as coordenadas ao redor de um player num array
void array_coord_around(COORDENADA coord, COORDENADA *ARRAY, ESTADO *e){
    int ret = 0, count = -1, border = 1;
    COORDENADA fake;
    if (coord.coluna == 7) border = 0;

    fake.linha = coord.linha - 1;
    while(coord.linha != 0 && count <= border){
        if (coord.coluna + count != -1){
            fake.coluna = coord.coluna + count;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                ARRAY[ret++] = fake;
            }
        }
        count ++;
    }
    count = -1; fake.linha ++;
    while(count <= border){
        if (coord.coluna + count != -1){
            fake.coluna = coord.coluna + count;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                ARRAY[ret++] = fake;
            }
        }
        count ++;
    }
    count = -1; fake.linha ++;
    while(coord.linha != 7 && count <= border){
        if (coord.coluna + count != -1){
            fake.coluna = coord.coluna + count;
            if(obter_estado_casa(e, fake, 0, 1) == VAZIO){
                ARRAY[ret++] = fake;
            }
        }
        count ++;
    }   
}