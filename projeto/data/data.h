#ifndef HEADER_FILE
#define HEADER_FILE

typedef enum {VAZIO, BRANCA, PRETA} CASA;


typedef struct {
	int linha;
	int coluna;
} COORDENADA;

typedef struct {
	COORDENADA jogador1;
	COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

//Estado do jogo
typedef struct {
	CASA tab[8][8];
	JOGADAS jogadas;
	int num_jogadas;
	int jogador_atual;
} ESTADO;
void incrJogada(ESTADO *e);
void coloca_preta (ESTADO *e);
ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
void coloca_jogada (ESTADO *e,int num_jogadas,COORDENADA c,int num_player);
void changePlayer(ESTADO *e);
void changePiece(ESTADO *e, COORDENADA c, CASA piece);
void gr(char *fileName, ESTADO *e);
#endif
