//This file is designed to store the definition of the functions used in linked lists.
#include "listas_ligadas.h"
#include <stdlib.h>
#include <stdio.h>


LISTA criar_lista(){
	LISTA r = malloc(sizeof(LISTA));

	r = NULL;

	return r;
}


LISTA insere_cabeca(LISTA L, void *valor){
	LISTA r = malloc(sizeof(LISTA));
	
	r -> proximo = L;
	r -> valor = valor;

	return r;
}


void *devolve_cabeca(LISTA L){
	return (L -> valor);
}


LISTA proximo(LISTA L){
	return (L -> proximo);
}


LISTA remove_cabeca(LISTA L){
	LISTA r = NULL;

	if(L){
		r = L -> proximo;
		free(L);
	}

	return r;
}


int lista_esta_vazia(LISTA L){
	if (L == NULL)
		return 1;
	else
		return 0;
}

void printListaCoord(LISTA L){
	while(L){
		printf("%f ", L->valor);
		L = L-> proximo;
	}
	putchar('\n');
}

LISTA fromArray(int A[], int N){
	LISTA r = NULL;
	for(int i = N - 1; i >= 0; i--){
		int *fake = A[i];
		r = insere_cabeca(r, fake);
	}
	return r;
}

LISTA lista_DistDest(int N, COORDENADA C[], ESTADO *e){
	LISTA l = NULL;
	int *dist;

	for(int i = N - 1; i >= 0; i--){
		*dist = calcula_dist_dest(C[i], e);
		l = insere_cabeca(l, dist);
	}

	return l;
}

void formar_LinCol(int decider, int A[], int N, COORDENADA C[]){
	if (decider){
		for(int i = 0; i < N; i ++)
			A[i] = C[i].linha;
	}
	else{
		for(int i = 0; i < N; i ++)
			A[i] = C[i].coluna;
	}
}