/**
@file listas_ligadas.h
Definição das listas ligadas e as funções que as manipulam
*/

#include <stdio.h>
#include <stdlib.h>
#include "../interface/interface.h"

typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO;

/**
\brief Função que cria uma lista
*/
LISTA criar_lista();

/**
\brief Função que dado a coordenada vê se a jogada é válida e se não for avisa o jogador
@param L A lista onde colocar a nova cabeça
@param valor O valor a inserir na cabeça da lista
*/
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Função que diz qual é o valor na cabeça da lista
@param L A lista donde queremos devolver a cabeça
*/
void *devolve_cabeca(LISTA L);

/**
\brief Função para passar para o proximo valor da lista
@param L A lista
*/
LISTA proximo(LISTA L);

/**
\brief Função que devolve a lista sem o elemento que se encontrava na cabeça
@param L A lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Função que retorna 1 se a lista se econtra vazia
@param L A lista
*/
int lista_esta_vazia(LISTA L);


/**
\brief Dada uma lista, calcula a posicao na lista que possui o menor valor do data (uma distancia)
@param L Uma lista
*/
int menorDist(LISTA L);


LISTA lista_DistDest(int N, COORDENADA C[], ESTADO *e);

void formar_LinCol(int decider, int A[], int N, COORDENADA C[]);

/**
\brief Transforma um array numa lista ligada
@param A Um array
@param N Número de elementos do array
*/
LISTA fromArray(int A[], int N);