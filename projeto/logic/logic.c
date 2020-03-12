//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c) {
    changePiece(e, c, BRANCA);
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}
