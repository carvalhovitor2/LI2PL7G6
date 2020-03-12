//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

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
