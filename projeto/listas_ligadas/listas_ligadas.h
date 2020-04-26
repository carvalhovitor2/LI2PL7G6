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

// Cria uma lista vazia (aloca a memoria a um ponteiro do tipo lista)
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
//Print lista ligadas
void printListaCoord(LISTA L);
//Calcula a menor distancia dentro de uma lista de distancias
int menorDist(LISTA L);
