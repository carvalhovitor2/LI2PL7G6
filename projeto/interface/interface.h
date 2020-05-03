/**
@file interface.h
Declare the functions that are defined in interface.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../logic/logic.h"

/**
\brief Função que imprime o tabuleiro.
@param e Apontador para o estado.
@param whereToPrint Apontador para onde o tabuleiro vai ser imprimido.
*/
void mostrar_tabuleiro(FILE *whereToPrint, ESTADO *e);

/**
\brief Imprime o prompt de comandos.
@param e Apontador para o estado do jogo.
@param nr_comandos O numero de comandos efetuados até então.
@param new_or_old Variável booleana para decidir se o numero de comandos efetuados traduz-se no array de jogadas novo ou antigo.
*/
void prompt(ESTADO *e, int nr_comandos, int new_or_old);

/**
\brief Função responsável por escrever as jogadas realizadas num jogo. Pode-se escolher o local de impressão das jogadas. (Ex: stdout ou um ficheiro).
@param e Apontador para o estado.
@param whereToPrint Apontador para o local de impressão. Pode ser stdout ou um ficheiro.
*/
void movs(FILE *whereToPrint, ESTADO *e);

/**
\brief Remove um pedaço de uma string.
@param nr_para_remover O numero de chars para remover de uma string.
@param original Apontador para a string original.
*/
char* remStr(int nr_para_remover, char* original);

/**
\brief Junta duas strings.
@param str1 Apontador para a primeira string.
@param str2 Apontador para a segunda string.
*/
char* addStr(char* str1, char* str2);

/**
\brief Função que lê e executa o comando dado.
@param e Apontador para o estado.
*/
int interpretador(ESTADO *e);

/**
\brief Função que executa o comando jog.
@param e Apontador para o estado.
*/
void jog(ESTADO *e);

/**
\brief Função que executa o comando jog2.
@param e Apontador para o estado.
@param line_or_col Variável booleana para servir de escolha dos eixos de uma coordenada.
*/
int jog2(ESTADO *e, int line_or_col);

/**
\brief Grava o estado de jogo num ficheiro.
@param e Apontador para o estado.
@param fileName O nome do ficheiro onde gravar o estado.
*/
void gr(char *fileName, ESTADO *e);

/**
\brief Lê um ficheiro e carrega as informações do ficheiro no estado do jogo.
@param e Apontador para o estado.
@param fileName O nome do ficheiro onde gravar o estado.
*/
void ler(char *fileName, ESTADO *e);