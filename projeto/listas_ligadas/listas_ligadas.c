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
		//free(L-> valor);
		free(L);
	}

	return r;
}


int lista_esta_vazia(LISTA L){
	return (L == NULL);
}
/**
void printListaCoord(LISTA L){
	while(L){
		printf("%f ", *(float *)L->valor);
		L = L-> proximo;
	}
	putchar('\n');
}

void printCoordenada(COORDENADA c){
        char a = 'a' + c.linha;
        printf("%c%d\n", a, c.coluna);
}


void printListaCoordenada(LISTA L){
	while(L){
		COORDENADA *blah;
		blah = L-> valor;
		L = L -> proximo;
		printCoordenada(*blah);
	}
}



void printArrayCoordenada(COORDENADA C[], int N){
	int i = 0;
	while (i < N){
		char a = 'a' + C[i].linha;
		printf("%c%d ", a, C[i].coluna + 1);
		i ++;
	}
	putchar('\n');
}
*/


LISTA fromArrayCoord(COORDENADA A[], int N){
    LISTA l = NULL;
    int i = N - 1;
    while(i >= 0){
        l = insere_cabeca(l, A + i);
        i --;
    }
    return l;
}

int menorDist(LISTA L){
	int r = -1, i = 0;
	float menor = 100;

	while(L){
		float *t;
		t = L-> valor;
		if(menor > *t){
			r = i;
			menor = *t;
		}
		i ++;
		L = L-> proximo;
	}

	return r;
}
