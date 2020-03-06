#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print_tabuleiro(char matriz[8][8]){
	for(int linhas = 0; linhas < 8; linhas++){
		for(int colunas=0; colunas < 8; colunas++){
			printf("%c", matriz[linhas][colunas]);	
		}
		printf("\n");
	}

}

int main(){
//print tabuleiro

	char tabuleiro[8][8];
	for(int linhas = 0; linhas < 8 ; linhas++){
		for(int colunas=0; colunas < 8 ; colunas++){
			if( linhas == 0 && colunas == 7)tabuleiro[linhas][colunas]='2';
			else if ( linhas == 7 && colunas == 0)tabuleiro[linhas][colunas]='1';
			else tabuleiro[linhas][colunas]='.';

		}
	}
	print_tabuleiro(tabuleiro);
	return 0;
}
