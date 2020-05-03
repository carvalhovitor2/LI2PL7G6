
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
\brief Obtém o estado atual da casa
@param e Apontador para o estado
@param coord A coordenada
@param decider_efeito Variável utilizada para parametrizar a chamada de coordenadas quando necessario
@param new_or_old A coordenada Variável utilizada para modularizar a funcao obter_estado_casa. Isto pois pode-se escolher se queremos o estado de uma peca do array de casas velhos ou novos.
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA coord, int decider_efeito, int new_or_old);

/**
\brief Devolve o jogador atual a jogar
@param e Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Devolve o número de jogadas do estado
@param e Apontador para o estado
@param new_or_old Variável booleana que decide se opta por ver a quantidade de jogadas no array de jogadas atual ou o antigo.
*/
int obter_numero_de_jogadas(ESTADO *estado, int new_or_old);

/**
\brief Busca por um dos eixos da coordenada de uma jogada. Por exemplo, se a jogada foi d4, pode-se buscar ou pelo d ou pelo 4.
@param e Apontador para o estado do jogo.
@param jogada O número da jogada
@param player O jogador que efetuou a jogada
@param decider Variável a decidir se o eixo sera o dos X ou dos Y.
@param new_or_old Variável a optar pelo array de jogadas atual ou antigo.
*/
int obter_coord_deJogada(ESTADO *e, int jogada, int player, int decider, int new_or_old);

/**
\brief Busca o valor de um eixo da coordenada da última jogada.
@param e Apontador para o estado
@param lin_or_col Inteiro usado para optar pelo eixo das linhas ou colunas.
*/
int getLastPiece(ESTADO *e, int lin_or_col);

/**
\brief Coloca a jogada efetuada no array JOGADAS do estado.
@param e Apontador para o estado
@param num_jogadas O num de jogadas já efetuadas
@param coord A coordenada
@param num_player Jogador atual
*/
void coloca_jogada (ESTADO *e, int num_jogadas, COORDENADA coord, int num_player);

/**
\brief Muda o conteúdo de uma anterior casa branca, no final da jogada.
@param e Apontador para o estado
*/
void coloca_preta (ESTADO *e);

/**
\brief Altera o jogador atual
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
\brief Modifica o número de jogadas
@param Apontador para o estado
@param new_num_jogadas O novo numero de jogadas
*/
void changeJogada(ESTADO *e, int new_num_jogadas);

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
\brief Cria o estado inicial do jogo
*/
ESTADO *inicializar_estado();

/**
\brief Obtém o numero de jogadas ocorridos num estado anterior
@param Apontador para o estado
*/
int obter_numero_de_jogadasOLD(ESTADO *estado);

/**
\brief Coloca o estado antigo igual ao atual
@param Apontador para o estado
*/
void replicaEstado(ESTADO *e);

#endif
