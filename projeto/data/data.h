
/**
@file data.h
Definição do estado e das funções que o manipulam
*/
#ifndef HEADER_FILE
#define HEADER_FILE
#include <math.h>

typedef struct nodo *LISTA;

/** 
\brief Tipo de dados para diferenciar coordenadas no tabuleiro
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/** 
\brief Tipo de dados para as coordenadas
*/
typedef struct {
	int linha;
	int coluna;
} COORDENADA;

/**
\brief Tipo de dados para uma jogada
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
	/** Tabuleiro alternativo para auxiliar o comando pos */
	CASA tabOLD[8][8];
    /** As jogadas */
	JOGADAS jogadas;
    /** Réplica do array de jogadas para auxiliar o comando pos*/
    JOGADAS jogadasOLD;
    /** O número das jogadas*/
    int num_jogadas;
    /** Número de jogadas alternativo para auxiliar o comando pos */
	int num_jogadasOLD;
    /** O jogador atual */
    int jogador_atual;
    ///** Lista de estados com  */
    //int floodTab[8][8];
    //LISTA lista_jogadas_possiveis;
    ///** Distância à casa de destino do jogador atual */
    //int dist_destino;

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


/**
\brief Obtem o numero de jogadas ocorridos num estado anterior
@param Apontador para o estado
*/
int obter_numero_de_jogadasOLD(ESTADO *estado);

/**
\brief Passa o numero de jogadas antigo para o numero de jogadas atual
@param Apontador para o estado
*/
void replicaEstado(ESTADO *e);

/**
\brief Modifica uma jogada
@param Apontador para o estado
*/
void changeJogada(ESTADO *e, int x);

/**
\brief Busca a ultima peca do tabuleiro
@param Apontador para o estado
@param Um inteiro que verifica o estado do ESTADO
*/
int getLastPiece(ESTADO *e, int bool);

/**
\brief Monta um array com as coordenadas que estao no entorno de um player
@param A coordenada onde esta o player
@param Um array de coordenadas
@param Apontador para o estado do jogo
*/
void array_coord_around(COORDENADA c, COORDENADA *A, ESTADO *e);

/**
\brief Retorna o numero de coordenadas vazias no entorno de um jogador
@param A coordenada onde esta o jogador
@param Apotador para o estado do jogo
*/
int nr_coord_around(COORDENADA c, ESTADO *e);


int obter_coord_deJogada(ESTADO *e, int jogada, int player, int decider);
#endif
