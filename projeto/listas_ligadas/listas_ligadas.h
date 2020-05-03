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
\brief Função que aloca o espaço e cria uma lista
*/
LISTA criar_lista();

/**
\brief Função que insere um apontador na cabeça de uma lista já existente
@param L A lista onde colocar a nova cabeça
@param valor O valor a inserir na cabeça da lista
*/
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Função que devolve um apontador que contém o primeiro elemento da lista
@param L A lista na qual queremos recuperar o primeiro elemento
*/
void *devolve_cabeca(LISTA L);

/**
\brief Função para passar para o proximo valor da lista, devolvendo o parâmetro proximo da struct
@param L A lista original
*/
LISTA proximo(LISTA L);

/**
\brief Função que retira o elemento que se encontra na cabeça da lista
@param L A lista original
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Função que retorna 1 se a lista se encontrar vazia
@param L A lista a testar
*/
int lista_esta_vazia(LISTA L);


/**
\brief Dada uma lista, calcula a posicão na lista que possui a menor distância (em float)
@param L A lista com as distàncias
*/
int menorDist(LISTA L);