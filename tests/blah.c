#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct nodo {
   void *valor;
   struct nodo *proximo;
} NODO, *LISTA;

typedef struct {
	int linha;
	int coluna;
} COORDENADA;


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

LISTA remove_cabeca(LISTA L){
	LISTA r = NULL;

	if(L){
		r = L -> proximo;
		free(L);
	}

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

LISTA fromArrayCoord(COORDENADA A[], int N){
	LISTA l = NULL;
	int i = N - 1;
	while(i >= 0){
		l = insere_cabeca(l, A + i);
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

void printCoordenada(COORDENADA c){
	char a = 'a' + c.linha;
	printf("%c%d\n", a, c.coluna);
}

void printArrayCoordenada(COORDENADA C[], int N){
	int i = 0;
	while (i < N){
		char a = 'a' + C[i].linha;
		printf("%c%d ", a, C[i].coluna);
		i ++;
	}
	putchar('\n');
}

void printListaCoord(LISTA L){
	while(L){
		COORDENADA *blah;
		blah = L-> valor;
		L = L -> proximo;
		printCoordenada(*blah);
	}
}

int main(){
	//srandom(time(NULL));
	LISTA l;

	//int x = random() % 5;

	l = criar_lista();
	COORDENADA r;
	r.linha = 1;
	r.coluna = 1;
	COORDENADA A[5];

	for(int i = 0; i <= 4; i ++){
		r.linha ++;
		r.coluna ++;
		A[i] = r;
	}

	l = fromArrayCoord(A, 5);
	//printListaCoord(l);

	//printf("\nx\n\n");

	l = remove_cabeca(l);
	l = remove_cabeca(l);

	//printListaCoord(l);

	COORDENADA *c;
	c = devolve_cabeca(l);

	//printf("\nx\n\n");

	//printCoordenada(*c);

	//printCoordenada(*(A + x));
	//printArrayCoordenada(A, 5);

	return 0;
}