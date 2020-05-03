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
void gr(char *fileName, ESTADO *e);


/**
\brief Le um ficheiro e carrega as informacoes do ficheiro no estado do jogo
@param e Apontador para o estado
@param fileName o nome do ficheiro onde gravar o estado
*/
void ler(char *fileName, ESTADO *e);

/**
\brief Função responsável por escrever as jogadas realizadas num jogo. Pode-se escolher o local de impressão das jogadas. (Ex: stdout ou um ficheiro)
@param e Apontador para o estado.
*/
void movs(FILE *whereToPrint,ESTADO *e);