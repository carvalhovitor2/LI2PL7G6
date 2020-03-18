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


int jogar(ESTADO *e, COORDENADA c) {
    changePiece(e, c, BRANCA);
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
