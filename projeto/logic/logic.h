/**
@file logic.h
This file is supposed to store the declarations of the logic functions used in our project
*/

#include "../data/data.h"

/**
\brief Função que faz a jogada e atualiza o estado com ajuda das funções dos dados
@param e Apontador para o estado
@param c A coordenada
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que dado a coordenada vê se a jogada é válida e se não for avisa o jogador
@param e Apontador para o estado
@param c A coordenada
*/
int jogadaValida(ESTADO *e, COORDENADA c);
