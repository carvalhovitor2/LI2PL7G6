#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void ida(int size){
	int i, j=0, k=0;
	char c1='A', param='A';
	for( i = size;i>0;i--){
		while( j <= (i - 2)){
			printf("  ");
			j++;
		}
		while( k <= (size - i)){
			printf(" %c", c1);
			k++;
			c1++;
		}
		c1-=2;
		k = 0;
		while( k <= (size - (i+1))){
			printf(" %c", c1);
			k++;
			c1--;
		}

		printf("\n");
		j = 0;
		k = 0;
		c1='A';
	}
}

void volta(int size){
	int i, j=0, k=0;
	char c1='A', param='A';
	for( i = 1;i <= size;i++){
		while( j <= (i - 1)){
			printf("  ");
			j++;
		}
		while( k <= (size - i)){
			printf(" %c", c1);
			k++;
			c1++;
		}
		c1-=2;
		k = 0;
		while( k <= (size - (i+1))){
			printf(" %c", c1);
			k++;
			c1--;
		}

		printf("\n");
		j = 0;
		k = 0;
		c1='A';
	}
}


int main(){
	int size=4;
	printf("Insira o tamanho do losango\n");
	scanf("%d", &size);
	ida(size);
	volta(size-1);
	return 0;
}
