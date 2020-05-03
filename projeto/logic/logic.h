/**
@file logic.h
This file is supposed to store the declarations of the logic functions used in our project
*/

#include "../data/data.h"

/**
\brief Função que dado o estado devolve a coordenada onde se encontra a peça branca.
@param e Apontador para o estado do jogo.
*/
COORDENADA findBranca(ESTADO *e);

/**
\brief Conta o número de casas vazias à volta de uma certa coordenada.
@param coord A coordenada em questão.
@param e Apontador para o estado do jogo.
*/
int nr_coord_around(COORDENADA coord, ESTADO *e);


/**
\brief É responsável por verificar se uma peça está cercada. Caso esteja, o jogo é terminado. Esta função é uma dependência da função gameOver.
@param e Apontador para o estado do jogo.
*/
int aroundBranca(ESTADO *e);

/**
\brief Retorna o numero de coordenadas vazias no entorno de um jogador
@param A coordenada onde esta o jogador
@param Apotador para o estado do jogo
*/
int nr_coord_around(COORDENADA c, ESTADO *e);

/**
\brief Monta um array com as coordenadas que estao no entorno de um player
@param A coordenada onde esta o player
@param Um array de coordenadas
@param Apontador para o estado do jogo
*/
void array_coord_around(COORDENADA c, COORDENADA *A, ESTADO *e);

/**
\brief Função responsável por verificar se o jogo acabou.
@param e Apontador para o estado do jogo.
*/
int gameOver(ESTADO *e);


/**
\brief Tem o propósito de perceber qual o vencedor da partida.
@param e Apontador para o estado do jogo.
*/
int winner(ESTADO *e);


/**
\brief Faz a jogada e atualiza o estado com ajuda das funções dos dados
@param e Apontador para o estado
@param c A coordenada para onde jogar
*/
int jogar(ESTADO *e, COORDENADA coord);

/**
\brief Função que dado a coordenada vê se a jogada é válida e se não for avisa o jogador
@param e Apontador para o estado
@param c A coordenada escolhida para a jogada que vai ser testada
*/
int jogadaValida(ESTADO *e, COORDENADA going);

/**
\brief Modifica um array de coordenadas, depositando nele as casas vazias à volta de uma certa coordenada
@param coord A coordenada em questão
@param ARRAY O array que vai ser modificado
@param e Apontador para o estado
*/
void array_coord_around(COORDENADA coord, COORDENADA *ARRAY, ESTADO *e);

/**
\brief Auxiliar à função e comando pos, que executa o comando pos quando o jogador pretende voltar ao início do jogo
@param e Apontador para o estado
*/
void posInicial(ESTADO *e);

/**
\brief Auxiliar à função e comando pos, que executa o comando pos quando o jogador pretende voltar atrás mas não ao início
@param e Apontador para o estado
@param i_New A número de jogadas que estavam efetuados até então
@param posJogada A jogada que o utilizador quer reaver
*/
void posDireto(ESTADO *e, int i_New, int posJogada);

/**
\brief Auxiliar à função e comando pos, que executa o comando pos quando o jogador já o executou anteriormente e quer passar para uma jogada à frente
@param e Apontador para o estado
@param i_New A jogada que o utilizador estaria a ver nesse momento
@param posJogada A jogada que o utilizador quer reaver
*/
void posInBetween(ESTADO *e, int i_New, int posJogada);

/**
\brief Função que executa o comando pos
@param e Apontador para o estado
@param posJogada A jogada que o utilizador quer reaver
*/
void pos(ESTADO *e, int posJogada);