#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct nodo {
   void *valor;
   struct nodo *proximo;
} NODO, *LISTA;


LISTA criar_lista(){
	LISTA r = malloc(sizeof(NODO));

	r = NULL;

	return r;
}

LISTA insere_cabeca(LISTA L, void *valor){
	LISTA r = malloc(sizeof(NODO));
	
	r-> proximo = L;
	r-> valor = valor;

	return r;
}

void *devolve_cabeca(LISTA L){
	return (L -> valor);
}

LISTA fromArray(int *A, int N){
	LISTA l = NULL;
	int i = N - 1;
	int *blah;
	while(i >= 0){
		blah = A + i;
		l = insere_cabeca(l, blah);
		i --;
	}
	return l;
}


LISTA fromArrayFloat(float *A, int N){
	LISTA l = NULL;
	int i = N - 1;
	float *blah;
	while(i >= 0){
		blah = A + i;
		l = insere_cabeca(l, blah);
		i --;
	}
	return l;
}


LISTA fromArrayINTTOFLOAT(int A[], int N){
	LISTA l = NULL;
	int a[N];
	for(int i = 0; i < N; i ++){
		a[i] = A[i];
	}
	l = fromArray(a, N);
	return l;
}


void printListaInt(LISTA L){
	while(L){
		int *blah;
		blah = L-> valor;
		printf("%d ", *blah);
		L = L-> proximo;
	}
	putchar('\n');
}

void printListaFloat(LISTA L){
	while(L){
		float *blah;
		blah = L-> valor;
		printf("%f ", *blah);
		L = L-> proximo;
	}
	putchar('\n');
}

float calcula_dist_dest(int x){
	float dist;

	dist = sqrt(pow(7 - x, 2) + pow(0 - x, 2));

	return dist;
}

LISTA lista_DistDest(int v[], int N){
	LISTA l = NULL;
	float dist;
	int i = 0;

	while (i < N){
		int x = v[i];
		dist = calcula_dist_dest(v[i]);
		l = insere_cabeca(l, &dist);
		i ++;
	}

	return l;
}

int indice_menorDist(LISTA L){
	int r = 0, i = 1;
	LISTA fake = L;
	int *x;
	x = devolve_cabeca(L);
	int *y; 

	if (fake && fake-> proximo){
		fake = fake-> proximo;
		y = devolve_cabeca(fake);
	}

	while(fake){
		if (*x > *y){
			r = i;
			x = y;
		}
		fake = fake-> proximo;
		if (fake)
			y = devolve_cabeca(fake);
		i ++;
	}

	return r;
}

int main(){
	LISTA l;
	int x;
	int v[4] = {40,30,20,10};
	float f[4] = {40,30,20,10};
	l = criar_lista();
	
	l = fromArray(v, 4);
	//printListaCoord2(l);
	printListaInt(l);
	float t[4];

	for(int j = 0; j < 4;j ++){
		t[j] = (float)calcula_dist_dest(v[j]);
	}

    LISTA k;
    k = criar_lista();
    k = fromArrayFloat(t, 4);
	printListaFloat(k);

	//k = fromArrayINTTOFLOAT(v,4);
	//printListaInt(k);
	x = indice_menorDist(l);
	printf("%d\n", x);
	
	return 0;
}