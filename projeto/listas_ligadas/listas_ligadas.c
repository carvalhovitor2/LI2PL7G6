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

void printListaCoord(LISTA L){
	while(L){
		printf("%f ", *(float *)L->valor);
		L = L-> proximo;
	}
	putchar('\n');
}

LISTA fromArray(int A[], int N){
	LISTA r = NULL;
	for(int i = N - 1; i >= 0; i--){
		int fake = A[i];
		r = insere_cabeca(r, &fake);
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


LISTA fromArrayCoord(COORDENADA A[], int N){
	LISTA l = NULL;
	int i = N - 1;
	while(i >= 0){
		l = insere_cabeca(l, A + i);
		i --;
	}
	return l;
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

TRIPLA* retrieveMenor(LISTA L, int ind){
	for(int i = 0; L && i < ind; i++, L = L-> proximo);

	if(L){
		TRIPLA *t;
		t = malloc(sizeof(TRIPLA));
		t = devolve_cabeca(L);
		return t;
	}
	else
		return NULL;
}

LISTA fromArrayTripla(COORDENADA C[], int N, int player){
	LISTA l = NULL;

	for(int i = N - 1; i >= 0; i --){
		TRIPLA *t;
		t = criaTripla(C[i], calcula_dist(C[i], player));
		l = insere_cabeca(l, t);
	}

	return l;
}

void printTripla(TRIPLA t){
	char a = 'a' + t.c.linha;
	printf("%c%d - %f\n", a, t.c.coluna, t.dist);
}

void printListaTripla(LISTA L){
	while(L){
		TRIPLA *t;
		t = devolve_cabeca(L);
		printTripla(*t);
		L = L-> proximo;
	}
}