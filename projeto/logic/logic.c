//This file is supposed to store the definitions of the logic functions of our project
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int jogar(ESTADO *e, COORDENADA c){
    int column = c.coluna;
    int line = c.linha;
    //Checks if it's a valid move. Returns false if it's not a valid move.
  
    changePiece(e, c, BRANCA);
    if (obter_jogador_atual(e) == 1) {
        e-> jogadas[e-> num_jogadas].jogador1 = c;
        changePlayer(e);
    }
    else
    {
        e-> jogadas[e-> num_jogadas].jogador2 = c;
        changePlayer(e);
        e-> num_jogadas++;
    }
    return 1;
}

