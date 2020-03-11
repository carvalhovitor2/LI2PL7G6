//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c){
    int column = c.coluna;
    int line = c.linha;
    e-> num_jogadas++;
    e-> tab[line][column] = BRANCA;
    e-> jogador_atual = (e -> jogador_atual == 1) ? 2 : 1;
    printf("jogar %d %d\n", line, column);
    return 1;
}

int interpretador(ESTADO *e){

}

