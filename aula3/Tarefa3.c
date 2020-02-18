#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void hex(int n){
	int regulator = n - 4;
	char caracter=' ';
	//First line
	for(int i=0;i<2;i++, caracter+=3){
		for(int j=0;j<n;j++){
			printf("%c", caracter);
		}
	}
	printf("\n"); caracter=' '; // reset char to space and print newline
	//Ascending lines
	for(int linha=1, middleSpaces=n, initialSpaces=(n-1);linha<n;linha++, initialSpaces--, middleSpaces+=2){
		for(int j=0;j<initialSpaces;j++){
			printf(" ");
		}
		printf("#");
		for(int i=0;i<middleSpaces;i++){
			printf(" ");
		}
		printf("#");
		printf("\n");
	}
	//Descending lines
	for(int linha=1, middleSpaces=(n*2)-2, initialSpaces=2;linha<n-1;linha++, initialSpaces++, middleSpaces-=2){
		for(int j=0;j<initialSpaces;j++){
			printf(" ");
		}
		printf("#");
		for(int i=0;i<middleSpaces+regulator;i++){
			printf(" ");
		}
		printf("#");
		printf("\n");
	}
	//Last line
	for(int i=0;i<2;i++, caracter+=3){
		for(int j=0;j<n;j++){
			printf("%c", caracter);
		}
	}
	printf("\n");
}



int main(){
	int size=0;
	printf("Insira o tamanho do hexagono desejado\n");
	scanf("%d", &size);
	hex(size);
	return 0;
}
