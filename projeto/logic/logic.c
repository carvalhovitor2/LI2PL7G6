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
int jogar(ESTADO *e, COORDENADA coord){
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


void posInicial(ESTADO *e){
    COORDENADA coord_variavel, inicial = {3,4}, std = {8,8};

    for(int k = 0; k != 8; k ++)
        for(int l = 0; l != 8; l ++){
            coord_variavel.linha = l; coord_variavel.coluna = k;
            changePiece(e, coord_variavel, VAZIO);
        }

    for(int t = 0; t != 32; t ++){
        coloca_jogada(e, t, std, 1); coloca_jogada(e, t, std, 2);
    }

    changePiece(e,inicial,BRANCA);
    changeJogada(e,0);

    if (obter_jogador_atual(e) == 2) 
        changePlayer(e); 
}

void posDireto(ESTADO *e, int i_New, int posJogada){
    COORDENADA player1, player2, std = {8,8};

    changeJogada(e,posJogada);

    while (i_New + 1 != posJogada){ 
        player1.linha = obter_coord_deJogada(e, i_New, 1, 1, 1); player1.coluna = obter_coord_deJogada(e, i_New, 1, 0, 1);
        player2.linha = obter_coord_deJogada(e, i_New, 2, 1, 1); player2.coluna = obter_coord_deJogada(e, i_New, 2, 0, 1);

        changePiece(e, player1, VAZIO); 
        changePiece(e, player2, VAZIO);

        coloca_jogada(e, i_New, std, 1); 
        coloca_jogada(e, i_New, std, 2);

        i_New --;

        if (obter_jogador_atual(e) == 2) 
            changePlayer(e);
    }
}


void posInBetween(ESTADO *e, int i_New, int posJogada){
    COORDENADA player1, player2;

    changeJogada(e,posJogada);

    if (obter_jogador_atual(e) == 2) 
        changePlayer(e);
    
    coloca_preta(e);

    while(i_New != posJogada){

        player1.linha = obter_coord_deJogada(e, i_New, 1, 1, 0); player1.coluna = obter_coord_deJogada(e, i_New, 1, 0, 0);
        player2.linha = obter_coord_deJogada(e, i_New, 2, 1, 0); player2.coluna = obter_coord_deJogada(e, i_New, 2, 0, 0);

        changePiece(e, player1, obter_estado_casa(e, player1, 0, 0)); 
        changePiece(e, player2, obter_estado_casa(e, player2, 0, 0));

        coloca_jogada(e, i_New, player1, 1); 
        coloca_jogada(e, i_New, player2, 2);

        i_New ++;
    }  
}

void pos(ESTADO *e, int posJogada){
    int i_OLD = obter_numero_de_jogadas(e, 0), i_New = obter_numero_de_jogadas(e, 1);

    if (posJogada == 0)
        posInicial(e); 
    else{
        if (posJogada <= i_OLD){
            if (i_New < posJogada) posInBetween(e, i_New, posJogada);
            else                   posDireto(e, i_New, posJogada);

            COORDENADA novaBranca = {getLastPiece(e,0), getLastPiece(e,1)};
            changePiece(e,novaBranca,BRANCA);
        }
        else
            printf("Comando inválido. %d é um número maior que a jogada atual.\n", posJogada);
    }
}
