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
} NODO, *LISTA;

// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);