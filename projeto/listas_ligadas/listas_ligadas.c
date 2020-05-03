//This file is designed to store the definition of the functions used in linked lists.
#include "listas_ligadas.h"
#include <stdlib.h>
#include <stdio.h>


LISTA criar_lista(){
	LISTA ret = malloc(sizeof(LISTA));

	ret = NULL;

	return ret;
}

LISTA insere_cabeca(LISTA L, void *valor){
	LISTA ret = malloc(sizeof(LISTA));
	
	ret -> proximo = L;
	ret -> valor = valor;

	return ret;
}

void *devolve_cabeca(LISTA L){
	return (L -> valor);
}

LISTA proximo(LISTA L){
	return (L -> proximo);
}

LISTA remove_cabeca(LISTA L){
	LISTA ret = NULL;

	if(L){
		ret = L -> proximo;
		free(L);
	}

	return ret;
}

int lista_esta_vazia(LISTA L){
	return (L == NULL);
}

int menorDist(LISTA L){
	int ret = -1, count = 0;
	float menor = 100;

	while(L){
		float *tmp;
		tmp = L-> valor;

		if (menor > *tmp){
			ret = count;
			menor = *tmp;
		}
		count ++;
		L = L-> proximo;
	}

	return ret;
}
