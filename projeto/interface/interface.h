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
void jog2(ESTADO *e);

/**
\brief Fucção que executa o comando jog
@param e Apontador para o estado
*/
void jog(ESTADO *e);