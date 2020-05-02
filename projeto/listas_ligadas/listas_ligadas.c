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
	return (L == NULL);
}

int menorDist(LISTA L){
	int r = -1, i = 0;
	float menor = 100;

	while(L){
		float *t;
		t = L-> valor;

		if (menor > *t){
			r = i;
			menor = *t;
		}
		i ++;
		L = L-> proximo;
	}

	return r;
}
