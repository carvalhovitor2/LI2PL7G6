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


void printArrayCoord(COORDENADA *A, int N){
	int i = 0;

	while (i < N){
		char l = 'a' + A[i].linha;
		printf("%c%d ", l, A[i].coluna);
		i ++;
	}
	putchar('\n');
}


void printListaCoord(LISTA L){
	while(L){
		printf("%d ", L->valor);
		L = L-> proximo;
	}
	putchar('\n');
}

LISTA fromArray(COORDENADA *A, int N, int decider){
	LISTA l = NULL;
	int i = 0;
	int *blah;
	while(i < N){
		if (decider)
			blah = A[i].linha;
		else
			blah = A[i].coluna
		l = insere_cabeca(l, blah);
		i ++;
	}
	return l;
}

LISTA 