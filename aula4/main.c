#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void soma_elemento(int *arr, int dim, int idx){
        int aux = *(arr+idx);
        for(int i=0;i<5;i++){
                *(arr+i) += aux;
        }
}

void roda_esq(int *arr, int dim, int shifter){
	int temp[shifter];
	int i;
	for(int j=0;j<shifter;j++){
		temp[j] = *(arr+j);
	}
	for(i=0;i<(dim - shifter);i++){
		*(arr+i)=*(arr+i+shifter);
	}
	for(int k=0;i<=dim;k++, i++){
		*(arr+i) = temp[k];
	}
}


int main(){
	int dim=0, shifter=0, *ptr, tarefa, argumento;
	printf("Escolha o numero da tarefa:\n");
	scanf("%d", &tarefa);
	printf("Insira a dimensao do array:\n");
	scanf("%d", &dim);
	ptr = (int*) malloc(dim * sizeof(int));
	for(int elem=0;elem<dim;elem++){
		printf("Elem %d:\n", elem+1);
		scanf("%d", ptr+elem);
	}
	shifter = shifter%dim;
	switch(tarefa){
		case 1: printf("Insira o index:\n");
			scanf("%d", &argumento);
		       	soma_elemento(ptr, dim, argumento);
			break;
		case 2: printf("Insira o shifter:\n");
			scanf("%d", &argumento);
			roda_esq(ptr, dim, argumento);
		default:
			break;
	}
        printf("{ ");
        for(int i=0;i<dim;i++){
                if(i==dim-1){
                        printf("%d ", *(ptr+i));
                        break;
                }
                printf("%d, ", *(ptr+i));
        }
        printf("}\n");
	return 0;
}
