#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(int *ptr, int dim){

        printf("{ ");
        for(int i=0;i<dim;i++){
                if(i==dim-1){
                        printf("%d ", *(ptr+i));
                        break;
                }
                printf("%d, ", *(ptr+i));
        }
        printf("}\n");
}


void soma_elemento(int *arr, int dim, int idx){
        int aux = *(arr+idx);
        for(int i=0;i<5;i++){
                *(arr+i) += aux;
        }
}

void roda_esq(int *arr, int dim, int shifter){
	int temp[shifter], i;
	for(int j=0;j<shifter;j++)temp[j] = *(arr+j);
	for(i=0;i<(dim - shifter);i++)*(arr+i)=*(arr+i+shifter);
	for(int k=0;i<=dim;k++, i++)*(arr+i) = temp[k];
}


int remove_menores(int *arr, int dim, int valor){
	int estatic_dim=dim, *end=arr, aux, novaDim=dim;
	for(int j = 0; j < dim ; j++){
		while(*(arr+j) < valor){
			aux = *(arr+j);
			for(int i = j; i < dim; i++){
				*(arr+i) = *(arr+i+1);
			}
			*(arr+dim-1) = aux;
			j++;
		}
	}
	return dim;
}

int main(){
	int dim=0, *ptr, tarefa, argumento;
	printf("Escolha o numero da tarefa:\n");
	scanf("%d", &tarefa);
	printf("Insira a dimensao do array:\n");
	scanf("%d", &dim);
	//Allocating vector needed space in heap
	ptr = (int*) malloc(dim * sizeof(int));
	for(int elem=0;elem<dim;elem++){
		printf("Elem %d:\n", elem+1);
		scanf("%d", ptr+elem);
	}
	switch(tarefa){
		case 1: printf("Insira o index:\n");
			scanf("%d", &argumento);
		       	soma_elemento(ptr, dim, argumento);
			break;

		case 2: printf("Insira o shifter:\n");
			scanf("%d", &argumento);
			argumento %= dim;
			roda_esq(ptr, dim, argumento);
			break;

		case 3: printf("Insira o valor:\n");
			scanf("%d", &argumento);
			printf("nova dimensao: %d\n",remove_menores(ptr, dim, argumento));

		default:
			break;
	}

	print_array(ptr, dim);
	return 0;
}
