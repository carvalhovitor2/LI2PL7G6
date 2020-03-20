/**
@file data.h
Definição do estado e das funções que o manipulam
*/

#ifndef HEADER_FILE
#define HEADER_FILE

typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
	int linha;
	int coluna;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
	COORDENADA jogador1;
	COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
	CASA tab[8][8];
    /** As jogadas */
	JOGADAS jogadas;
    /** O número das jogadas*/
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
} ESTADO;

/**
\brief incrementa o valor do número de jogadas
@param e Apontador para o estado
*/
void incrJogada(ESTADO *e);
/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
*/
void coloca_preta (ESTADO *e);
/**
\brief Cria o estado inicial do jogo
*/
ESTADO *inicializar_estado();
/**
\brief Devolve o jogador atual a jogar
@param e Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);
/**
\brief Devolve o número de jogadas do estado
@param e Apontador para o estado
*/
int obter_numero_de_jogadas(ESTADO *estado);
/**
\brief Obtém o estado atual da casa
@param e Apontador para o estado
@param c A coordenada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/**
\brief coloca na posição num_jogadas do array JOGADAS no determinado jogador a coordenada c
@param e Apontador para o estado
@param num_jogadas para o num de jogadas no estado
@param c A coordenada
@param num_player Jogador atual
*/
void coloca_jogada (ESTADO *e,int num_jogadas,COORDENADA c,int num_player);
/**
\brief Alter o jogador atual
@param e Apontador para o estado
*/
void changePlayer(ESTADO *e);
/**
\brief Altera a peça da casa
@param e Apontador para o estado
@param c A coordenada
@param piece A casa que vamos trocar pela que está naquela coordenada
*/
void changePiece(ESTADO *e, COORDENADA c, CASA piece);
void gr(char *fileName, ESTADO *e);
#endif
