
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

} ESTADO;
/**
\brief Incrementa o valor do número de jogadas.
@param e Apontador para o estado do jogo.
*/
void incrJogada(ESTADO *e);


/**
\brief Inicializa o array de jogadas.
@param e Apontador para o estado do jogo.
*/
void arrayJogadas(ESTADO *e);


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
@param new_or_old Variavel booleana que decide opta por ver a quantidade de jogadas no array de jogadas actual ou o antigo.
*/
int obter_numero_de_jogadas(ESTADO *estado, int new_or_old);

/**
\brief Obtém o estado atual da casa
@param e Apontador para o estado
@param c A coordenada
@param decider_efeito Variavel utilizada para parametrizar a chamada de coordenadas quando necessario
@param new_or_old A coordenada Variavel utilizada para modularizar a funcao obter_estado_casa. Isto pois pode-se escolher se queremos o estado de uma peca do array de casas velhos ou novos.
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c, int decider_efeito, int new_or_old);

/**
\brief coloca na posição num_jogadas do array JOGADAS no determinado jogador a coordenada c
@param e Apontador para o estado
@param num_jogadas para o num de jogadas no estado
@param c A coordenada
@param num_player Jogador atual
*/
void coloca_jogada (ESTADO *e, int num_jogadas,COORDENADA c, int num_player);

/**
\brief Alter o jogador atual
@param e Apontador para o estado
*/
void changePlayer(ESTADO *e);

/**
\brief Altera a peça da casa
@param e Apontador para o estado
@param c A coordenada
@param piece A casa que vamos trocar pela que está naquela coordenada.
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
\brief Modifica o numero de jogadas
@param Apontador para o estado
@param new_num_jogadas O novo numero de jogadas
*/
void changeJogada(ESTADO *e, int new_num_jogadas);

/**
\brief Busca o valor de um eixo da coordenada da ultima jogada.
@param e Apontador para o estado
@param line_or_col Inteiro usado para optar pelo eixo das linhas ou colunas.
*/
int getLastPiece(ESTADO *e, int line_or_col);

/**
\brief Busca por um dos eixos da coordenada de uma jogada. Por exemplo, se a jogada foi d4, pode-se buscar ou pelo d ou pelo 4.
@param e Apontador para o estado do jogo.
@param jogada O numero da jogada
@param player O jogador que efetuou a jogada
@param decider Variavel a decidir se o eixo sera o dos X ou dos Y.
@param new_or_old Variavel a optar pelo array de jogadas actual ou antigo.
*/
int obter_coord_deJogada(ESTADO *e, int jogada, int player, int decider, int new_or_old);


#endif
