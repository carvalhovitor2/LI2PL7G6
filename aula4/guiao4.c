#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int qtsMai (int X[], int dim, int valor) {
    int numeroDeMaiores=0;
    for (int i = 0; i < dim; i++) {
            if( X[i] > valor )numeroDeMaiores++;
    }
    return numeroDeMaiores;
}

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

int remove_menores(int X[], int dim, int valor) {
    int p, m=0, M=0, n, somaM = qtsMai(X,dim,valor), somam = (dim - somaM), menores[somam], maiores[somaM];
    // Retirei o m =0 e M =0 de dentro do for pq em toda a iteracao fazia eles ficarem a 0, sendo que nao queres isso
    // A preencher os vectores dos maiores e dos menores 
    for(p = 0; p < dim; p++){
        if(X[p] < valor){
            menores[m]=X[p];
            m++;
          continue;
        }
        maiores[M]=X[p];
      M++;
    }
    for(p = 0; p < M; p++){
        //Tirei o espaco que tinha entre maiores e [p]
        X[p] = maiores[p];
    }
    //A adicionar os menores
    for(p = 0; p < m; p++){
        //Tirei o espaco que tinha entre menores e [p]
        X[M+p] = menores[p];
    }
    return M;
}


int main(){
	int dim=5, *ptr, tarefa=1, argumento;
	int arr1[5]={7, 1, 4, 2, 9};
	int arr2[5]={7, 1, 4, 2, 9};
	int arr3[5]={7, 1, 4, 2, 9};
	switch(tarefa){
		case 1: printf("Soma:\n");
			soma_elemento(arr1, dim, 2);
			print_array(arr1, dim);

		case 2: printf("Rodados:\n");
			roda_esq(arr2, dim, 8);
			print_array(arr2, dim);

		case 3: 
			printf("nova dimensao: %d\n",remove_menores(arr3, dim, 4));
			print_array(arr3, dim);

	}

	return 0;
}
