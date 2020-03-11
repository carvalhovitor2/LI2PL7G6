//This file is designed to store the definition of the interface functions
#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

//Print the game board
void mostrar_tabuleiro(ESTADO *e){
        for(int linha = 0; linha < 8; linha++){
                for(int coluna = 0; coluna < 8; coluna++){
                        printf("%d ", e->tab[linha][coluna]);
                }
		printf("\n");
        } 
}

int interpretador(ESTADO *e){

}

