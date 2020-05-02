/**
@file interface.h
Declare the functions that are defined in interface.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../logic/logic.h"

/**
\brief Função que imprime o tabuleiro
@param e Apontador para o estado
@param whereToPrint Apontador para guardar o estado.
*/
void mostrar_tabuleiro(FILE *whereToPrint, ESTADO *e);

/**
\brief Função que lê e executa o comando dado
@param e Apontador para o estado
*/
int interpretador(ESTADO *e);

/**
\brief Fucção que executa o comando jog2
@param e Apontador para o estado
*/
int jog2(ESTADO *e, int decider);

/**
\brief Fucção que executa o comando jog
@param e Apontador para o estado
*/
void jog(ESTADO *e);

/**
\brief Grava o estado de jogo num ficheiro
@param e Apontador para o estado
@param fileName o nome do ficheiro onde gravar o estado
*/
void gr(char *fileName, ESTADO *e, int bool_bot);


/**
\brief Le um ficheiro e carrega as informacoes do ficheiro no estado do jogo
@param e Apontador para o estado
@param fileName o nome do ficheiro onde gravar o estado
*/
void ler(char *fileName, ESTADO *e, int bool_bot);

/**
\brief Executa o comando pos
@param e Apontador para o estado
@param x O numero da jogada
*/
void pos(ESTADO *e, int x);