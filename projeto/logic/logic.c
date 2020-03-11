//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c){
    int column = c.coluna;
    int line = c.linha;
    e-> tab[line-1][column-1] = BRANCA;
    if (e-> jogador_atual == 1) {
        e-> jogadas[e-> num_jogadas].jogador1 = c;
        e-> jogador_atual = 2;
    }
    else
    {
        e-> jogadas[e-> num_jogadas].jogador2 = c;
        e-> jogador_atual = 1;
        e-> num_jogadas++;
    }

    printf("jogar %d %d\n", line, column);
    return 1;
}

